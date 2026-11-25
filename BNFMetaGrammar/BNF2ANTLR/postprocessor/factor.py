#!/usr/bin/env python3
"""Factor the TFF rules in an ANTLR grammar emitted by bnf2antlr_meta.py."""

import argparse
import io
from pathlib import Path
import subprocess
import tarfile
import tempfile


TRASH_VERSION = '5.0.0'
QUERY = Path(__file__).resolve().with_name('factor_tff.xq')
ANTLR_JAR = QUERY.parents[3] / 'ANTLRParsers/antlr-4.13.2-complete.jar'
LEXER_MARKER = b'\n// Lexer rules derived from'


def run(command, *, cwd=None, data=None):
    result = subprocess.run(command, cwd=cwd, input=data, capture_output=True, timeout=60)
    if result.returncode:
        diagnostic = (result.stderr or result.stdout).decode('utf-8', errors='replace').strip()
        raise RuntimeError(f'{command[0]} {command[1]} exited with status {result.returncode}\n'
                           f'{diagnostic}')
    return result.stdout


def read_bundle(data, filename, artifact_name):
    with tarfile.open(fileobj=io.BytesIO(data)) as bundle:
        def read(name):
            members = [member for member in bundle.getmembers() if member.name == name]
            if len(members) != 1 or not members[0].isfile():
                raise RuntimeError(f'Expected one regular {name} artifact from Trash')
            with bundle.extractfile(members[0]) as stream:
                return stream.read()

        errors = read(filename + '.errors').strip()
        if errors:
            raise RuntimeError(errors.decode('utf-8', errors='replace'))
        return read(artifact_name)


def parse(trash, path):
    parsed = run([trash, 'parse', str(path)])
    read_bundle(parsed, path.name, path.name + '.pt')
    return parsed


def render(trash, parsed, filename):
    return read_bundle(run([trash, 'text'], data=parsed), filename, filename)


def generate_lexer(antlr_jar, path):
    run(['java', '-XX:-UsePerfData', '-jar', str(antlr_jar), '-Dlanguage=JavaScript',
         '-no-listener', '-o', 'generated', path.name], cwd=path.parent)
    return (path.parent / 'generated' / (path.stem + 'Lexer.js')).read_bytes()


def factor(source, destination, *, trash='trash', antlr_jar=ANTLR_JAR):
    source = source.resolve()
    antlr_jar = antlr_jar.resolve()
    if source == destination.resolve():
        raise ValueError('Use a separate output directory to retain the original grammar')
    if source.suffix != '.g4' or source.name != destination.name:
        raise ValueError('Use the same .g4 filename in a separate output directory')
    if not antlr_jar.is_file():
        raise FileNotFoundError(f'ANTLR JAR not found at {antlr_jar}')
    version = run([trash, '--version']).decode('utf-8').strip()
    if version != TRASH_VERSION:
        raise RuntimeError(f'Expected Trash {TRASH_VERSION}, found {version}')

    original = source.read_bytes()
    _, marker, original_lexer = original.partition(LEXER_MARKER)
    if not marker:
        raise ValueError('Expected the lexer section emitted by bnf2antlr_meta.py')

    with tempfile.TemporaryDirectory(prefix='bnf2antlr-factor-') as temporary:
        work = Path(temporary)
        baseline = work / 'original' / source.name
        baseline.parent.mkdir()
        baseline.write_bytes(original)
        parsed = parse(trash, baseline)
        if render(trash, parsed, source.name) != original:
            raise RuntimeError('Trash changed the grammar during a no-op round trip')

        modified = run([trash, 'xquery', '-q', str(QUERY)], data=parsed)
        optimized = render(trash, modified, source.name)
        if optimized == original:
            raise RuntimeError('The factoring query produced no changes')
        if optimized.partition(LEXER_MARKER)[1:] != (marker, original_lexer):
            raise RuntimeError('The rewrite changed the lexer section')

        candidate = work / 'factored' / source.name
        candidate.parent.mkdir()
        candidate.write_bytes(optimized)
        parse(trash, candidate)
        if generate_lexer(antlr_jar, baseline) != generate_lexer(antlr_jar, candidate):
            raise RuntimeError('The generated lexers differ, including implicit tokens')

    destination.parent.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(prefix='.factored-', dir=destination.parent) as temporary:
        output = Path(temporary) / destination.name
        output.write_bytes(optimized)
        output.replace(destination)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('input', type=Path)
    parser.add_argument('-o', '--output', required=True, type=Path)
    parser.add_argument('--trash', default='trash', help='Trash 5.0.0 executable (default: trash on PATH)')
    parser.add_argument('--antlr-jar', type=Path, default=ANTLR_JAR,
                        help='ANTLR 4.13.2 complete JAR (defaults to the repository copy)')
    args = parser.parse_args()
    try:
        factor(args.input, args.output, trash=args.trash, antlr_jar=args.antlr_jar)
    except (OSError, ValueError, RuntimeError, subprocess.SubprocessError, tarfile.TarError) as error:
        parser.exit(1, f'Factoring failed: {error}\n')
    print(f'Wrote {args.output} using Trash {TRASH_VERSION} and verified identical generated lexers.')


if __name__ == '__main__':
    main()
