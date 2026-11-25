import importlib.util
import os
from pathlib import Path
import sys
import tempfile
import unittest

from antlr4 import CommonTokenStream, InputStream, Token
from antlr4.error.ErrorListener import ErrorListener

from BNFMetaGrammar.BNF2ANTLR.postprocessor.factor import ANTLR_JAR, factor, run


TRASH = os.environ.get('BNF2ANTLR_TRASH', 'trash')


class SyntaxErrors(ErrorListener):
    def __init__(self):
        self.messages = []

    def syntaxError(self, recognizer, offendingSymbol, line, column, msg, e):
        self.messages.append(msg)


def generated_class(directory, name):
    spec = importlib.util.spec_from_file_location(name, directory / f'{name}.py')
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return getattr(module, name)


def accepts(lexer_class, parser_class, text):
    errors = SyntaxErrors()
    lexer = lexer_class(InputStream(text))
    lexer.removeErrorListeners()
    lexer.addErrorListener(errors)
    tokens = CommonTokenStream(lexer)
    tokens.fill()
    parser = parser_class(tokens)
    parser.buildParseTrees = False
    parser.removeErrorListeners()
    parser.addErrorListener(errors)
    parser.tptp_file()
    return not errors.messages and tokens.LA(1) == Token.EOF


class PostprocessorTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        temporary = tempfile.TemporaryDirectory()
        cls.addClassCleanup(temporary.cleanup)
        cls.work = Path(temporary.name)
        cls.original = cls.work / 'original/TPTP.g4'
        cls.original.parent.mkdir()
        cls.factored = cls.work / 'factored/TPTP.g4'
        converter = Path(__file__).resolve().parents[1] / 'bnf2antlr_meta.py'
        run([sys.executable, str(converter), '-o', str(cls.original)])
        factor(cls.original, cls.factored, trash=TRASH)
        cls.parsers = {}
        for path in (cls.original, cls.factored):
            run(['java', '-jar', str(ANTLR_JAR), '-Dlanguage=Python3', '-no-listener',
                 '-o', 'generated', path.name], cwd=path.parent)
            generated = path.parent / 'generated'
            cls.parsers[path.parent.name] = (generated_class(generated, 'TPTPLexer'),
                                             generated_class(generated, 'TPTPParser'))

    def test_tff_membership(self):
        examples = {
            'p': True,
            'X': True,
            'p => q': True,
            'p & q & r': True,
            'p | q | r': True,
            '(p & q) | r': True,
            'p => q => r': False,
            'p & q | r': False,
            'p ~& q': True,
            'p ~| q': True,
            '1 = 2': True,
            '1': False,
            '[a,b] != X': True,
            '[a,b]': False,
            '(p => q) = (r | s)': True,
            '~(p = q)': True,
            '~p = q': False,
            '! [X:$i] : p(X) & q': True,
            '! [X:$i] : (p(X) & q)': True,
            'f == a': True,
            '[p] --> [q]': True,
        }
        for formula, expected in examples.items():
            text = f'tff(a,axiom,{formula}).'
            for variant, parser in self.parsers.items():
                with self.subTest(formula=formula, variant=variant):
                    self.assertEqual(expected, accepts(*parser, text))

    def test_unreviewed_inputs_preserve_an_existing_output(self):
        source = self.work / 'guard/TPTP.g4'
        source.parent.mkdir()
        original = self.original.read_text(encoding='utf-8')
        changed = original.replace("tff_unit_formula '&' tff_unit_formula",
                                   "tff_unit_formula '& ' tff_unit_formula", 1)
        self.assertNotEqual(original, changed)
        test_inputs = {
            'changed literal': changed,
            'helper collision': original + '\nbnf2antlr_tff_formula_term : variable ;\n',
            'repeat application': self.factored.read_text(encoding='utf-8'),
        }
        output = self.work / 'guard-output/TPTP.g4'
        output.parent.mkdir()
        sentinel = b'existing output\n'
        output.write_bytes(sentinel)
        for label, grammar in test_inputs.items():
            with self.subTest(label=label):
                source.write_text(grammar, encoding='utf-8')
                with self.assertRaisesRegex(RuntimeError, 'Expected the original action-free TFF rule structure'):
                    factor(source, output, trash=TRASH)
                self.assertEqual(sentinel, output.read_bytes())
