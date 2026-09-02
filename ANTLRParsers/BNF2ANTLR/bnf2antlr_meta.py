#!/usr/bin/env python3
"""Convert TPTP SyntaxBNF into an ANTLR4 combined grammar.

Unlike the historical line-oriented converter, this program generates and
uses a Python parser from BNFMetagrammar/BNFMeta.g4.  SyntaxBNF's four
definition operators are handled as follows:

* ::= becomes an ANTLR parser rule.
* :== is retained as a comment because it is a semantic restriction, not a
  context-free grammar production.
* ::- becomes an ANTLR lexer token.
* ::: becomes an ANTLR lexer fragment, except when a ::= rule references the
  name directly (for example, <vline> and <star>).
"""

from __future__ import annotations

import argparse
import importlib
import re
import subprocess
import sys
import tempfile
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Iterable, Sequence


SCRIPT_DIRECTORY = Path(__file__).resolve().parent
REPOSITORY_ROOT = SCRIPT_DIRECTORY.parents[1]
DEFAULT_METAGRAMMAR = REPOSITORY_ROOT / "BNFMetagrammar" / "BNFMeta.g4"
DEFAULT_ANTLR_JAR = REPOSITORY_ROOT / "ANTLRParsers" / "antlr-4.13.2-complete.jar"

NONTERMINAL_PATTERN = re.compile(r"^<([A-Za-z_][A-Za-z0-9_]*)>$")
GRAMMAR_NAME_PATTERN = re.compile(r"^[A-Za-z][A-Za-z0-9_]*$")
OCTAL_ESCAPE_PATTERN = re.compile(r"\\([0-7]{2,3})")
OPERATOR_CHARACTERS = frozenset("!#&*+-/:<=>?@^~|")


class ConversionError(RuntimeError):
    """A user-facing conversion failure."""


@dataclass(frozen=True)
class Definition:
    """One definition parsed by BNFMeta.g4."""

    name: str
    operator: str
    expression: Any
    context: Any

    @property
    def line(self) -> int:
        return self.context.start.line


class SyntaxErrorCollector:
    """ANTLR error listener that records lexer and parser diagnostics."""

    def __init__(self) -> None:
        self.messages: list[str] = []

    def syntaxError(
        self,
        recognizer: Any,
        offending_symbol: Any,
        line: int,
        column: int,
        message: str,
        error: Any,
    ) -> None:
        del recognizer, offending_symbol, error
        self.messages.append(f"{line}:{column}: {message}")


def parse_arguments(argv: Sequence[str]) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Convert a TPTP SyntaxBNF document to an ANTLR4 grammar."
    )
    parser.add_argument("input", type=Path, help="SyntaxBNF input file")
    parser.add_argument(
        "output",
        type=Path,
        help="output directory (or an explicit .g4 output path)",
    )
    parser.add_argument(
        "--grammar-name",
        default="TPTP",
        help="ANTLR grammar name and default output basename (default: TPTP)",
    )
    parser.add_argument(
        "--metagrammar",
        type=Path,
        default=DEFAULT_METAGRAMMAR,
        help=f"BNF metagrammar (default: {DEFAULT_METAGRAMMAR})",
    )
    parser.add_argument(
        "--antlr-jar",
        type=Path,
        default=DEFAULT_ANTLR_JAR,
        help=f"ANTLR complete jar (default: {DEFAULT_ANTLR_JAR})",
    )
    return parser.parse_args(argv)


def require_antlr_runtime() -> tuple[Any, Any]:
    try:
        antlr4 = importlib.import_module("antlr4")
        error_listener_module = importlib.import_module(
            "antlr4.error.ErrorListener"
        )
    except ModuleNotFoundError as error:
        raise ConversionError(
            "The ANTLR Python runtime is required. Install it with "
            "'python3 -m pip install antlr4-python3-runtime==4.13.2'."
        ) from error
    return antlr4, error_listener_module.ErrorListener


def generate_metaparser(
    metagrammar: Path, antlr_jar: Path, output_directory: Path
) -> None:
    if not metagrammar.is_file():
        raise ConversionError(f"metagrammar not found: {metagrammar}")
    if not antlr_jar.is_file():
        raise ConversionError(f"ANTLR jar not found: {antlr_jar}")

    command = [
        "java",
        "-jar",
        str(antlr_jar),
        "-Dlanguage=Python3",
        "-no-listener",
        "-Xexact-output-dir",
        "-o",
        str(output_directory),
        str(metagrammar),
    ]
    result = subprocess.run(command, text=True, capture_output=True, check=False)
    if result.returncode != 0:
        diagnostics = (result.stderr or result.stdout).strip()
        raise ConversionError(
            "ANTLR could not generate the BNF metaparser"
            + (f":\n{diagnostics}" if diagnostics else ".")
        )


def import_generated_metaparser(output_directory: Path) -> tuple[Any, Any]:
    sys.path.insert(0, str(output_directory))
    try:
        lexer_module = importlib.import_module("BNFMetaLexer")
        parser_module = importlib.import_module("BNFMetaParser")
    except (ImportError, ModuleNotFoundError) as error:
        raise ConversionError(
            "BNFMeta.g4 must declare 'grammar BNFMeta' so the generated "
            "BNFMetaLexer and BNFMetaParser modules can be imported."
        ) from error
    return lexer_module.BNFMetaLexer, parser_module.BNFMetaParser


def parse_syntax_bnf(
    input_path: Path,
    metagrammar: Path,
    antlr_jar: Path,
) -> tuple[list[Definition], str, Any]:
    antlr4, error_listener_base = require_antlr_runtime()
    if not input_path.is_file():
        raise ConversionError(f"input file not found: {input_path}")

    source = input_path.read_text(encoding="utf-8")
    with tempfile.TemporaryDirectory(prefix="bnf2antlr-meta-") as temporary:
        generated_directory = Path(temporary)
        generate_metaparser(metagrammar, antlr_jar, generated_directory)
        lexer_class, parser_class = import_generated_metaparser(
            generated_directory
        )

        class AntlrSyntaxErrorCollector(
            SyntaxErrorCollector, error_listener_base
        ):
            pass

        diagnostics = AntlrSyntaxErrorCollector()
        input_stream = antlr4.InputStream(source)
        lexer = lexer_class(input_stream)
        lexer.removeErrorListeners()
        lexer.addErrorListener(diagnostics)
        token_stream = antlr4.CommonTokenStream(lexer)
        parser = parser_class(token_stream)
        parser.removeErrorListeners()
        parser.addErrorListener(diagnostics)
        tree = parser.document()

        if diagnostics.messages:
            formatted = "\n".join(
                f"  {input_path}:{message}" for message in diagnostics.messages
            )
            raise ConversionError(
                "SyntaxBNF does not conform to BNFMeta.g4:\n" + formatted
            )

        definitions = extract_definitions(tree)
        return definitions, source, lexer_class


def extract_definitions(document: Any) -> list[Definition]:
    definitions: list[Definition] = []
    rule_kinds = (
        ("syntacticRule", "::=", "syntaxExpression"),
        ("semanticRule", ":==", "syntaxExpression"),
        ("tokenRule", "::-", "regexExpression"),
        ("lexerMacroRule", ":::", "regexExpression"),
    )

    for item in document.documentItem():
        for accessor, operator, expression_accessor in rule_kinds:
            rule = getattr(item, accessor)()
            if rule is None:
                continue
            name = nonterminal_name(rule.ruleName().getText())
            expression = getattr(rule, expression_accessor)()
            definitions.append(
                Definition(name, operator, expression, rule)
            )
            break
    return definitions


def nonterminal_name(text: str) -> str:
    match = NONTERMINAL_PATTERN.fullmatch(text)
    if match is None:
        raise ConversionError(f"invalid SyntaxBNF nonterminal: {text!r}")
    return match.group(1)


def parser_rule_name(name: str) -> str:
    """ANTLR parser rules must begin with a lowercase letter."""

    return name.lower()


def lexer_rule_name(name: str) -> str:
    """ANTLR lexer rules must begin with an uppercase letter."""

    return name[0].upper() + name[1:]


def antlr_literal(text: str) -> str:
    escaped = (
        text.replace("\\", "\\\\")
        .replace("'", "\\'")
        .replace("\r", "\\r")
        .replace("\n", "\\n")
        .replace("\t", "\\t")
    )
    return f"'{escaped}'"


def all_names_with_operator(
    definitions: Iterable[Definition], operator: str
) -> set[str]:
    return {
        definition.name
        for definition in definitions
        if definition.operator == operator
    }


def syntax_nonterminal_references(
    definitions: Iterable[Definition],
) -> set[str]:
    references: set[str] = set()
    for definition in definitions:
        if definition.operator != "::=":
            continue
        for alternative in definition.expression.syntaxAlternative():
            for element in alternative.syntaxElement():
                token = element.NONTERMINAL()
                if token is not None:
                    references.add(nonterminal_name(token.getText()))
    return references


def discover_operator_literals(
    definitions: Iterable[Definition], bare_word_token: int
) -> set[str]:
    """Learn the indivisible punctuation operators declared by ::= rules."""

    operators: set[str] = set()
    for definition in definitions:
        if definition.operator != "::=":
            continue
        for alternative in definition.expression.syntaxAlternative():
            elements = alternative.syntaxElement()
            if not elements or any(
                element.syntaxTerminal() is None for element in elements
            ):
                continue
            terminals = [element.syntaxTerminal().start for element in elements]
            if any(token.type == bare_word_token for token in terminals):
                continue
            candidate = "".join(token.text for token in terminals)
            if candidate and set(candidate) <= OPERATOR_CHARACTERS:
                operators.add(candidate)
    return operators


class GrammarConverter:
    def __init__(
        self,
        definitions: Sequence[Definition],
        source: str,
        lexer_class: Any,
        grammar_name: str,
        source_name: str,
        metagrammar_name: str,
    ) -> None:
        self.definitions = definitions
        self.source = source
        self.grammar_name = grammar_name
        self.source_name = source_name
        self.metagrammar_name = metagrammar_name
        self.syntax_names = all_names_with_operator(definitions, "::=")
        self.token_names = all_names_with_operator(definitions, "::-")
        self.macro_names = all_names_with_operator(definitions, ":::")
        self.syntax_references = syntax_nonterminal_references(definitions)
        self.exported_macros = self.macro_names & self.syntax_references
        self.bare_word_token = lexer_class.BARE_WORD
        self.operator_literals = discover_operator_literals(
            definitions, self.bare_word_token
        )

    def convert(self) -> str:
        parser_definitions = [
            definition
            for definition in self.definitions
            if definition.operator == "::="
        ]
        semantic_definitions = [
            definition
            for definition in self.definitions
            if definition.operator == ":=="
        ]
        lexer_definitions = [
            definition
            for definition in self.definitions
            if definition.operator in {"::-", ":::"}
        ]

        lines = [
            f"grammar {self.grammar_name};",
            "",
            f"// Generated from {self.source_name} using {self.metagrammar_name}.",
            "// ::= rules are parser rules; :== restrictions are comments;",
            "// ::- rules are tokens; ::: rules are lexer fragments unless",
            "// referenced directly by a parser rule.",
            "",
        ]

        for index, definition in enumerate(parser_definitions):
            append_eof = index == 0 and definition.name == "TPTP_file"
            lines.extend(self.convert_parser_rule(definition, append_eof))
            lines.append("")

        if semantic_definitions:
            lines.extend(
                [
                    "// Semantic restrictions from SyntaxBNF.",
                    "// They constrain the language semantically and are intentionally",
                    "// not added as alternative context-free productions.",
                ]
            )
            for definition in semantic_definitions:
                lines.append(self.convert_semantic_comment(definition))
            lines.append("")

        lines.append("// Lexer rules derived from ::- and ::: definitions.")
        for definition in lexer_definitions:
            lines.extend(self.convert_lexer_rule(definition))
            lines.append("")

        lines.extend(
            [
                "// SyntaxBNF permits whitespace between tokens.",
                "WS",
                "    : [ \\t\\r\\n]+ -> skip",
                "    ;",
                "",
            ]
        )
        return "\n".join(lines)

    def convert_parser_rule(
        self, definition: Definition, append_eof: bool
    ) -> list[str]:
        alternatives = [
            self.convert_syntax_alternative(alternative)
            for alternative in definition.expression.syntaxAlternative()
        ]
        if append_eof:
            alternatives = [
                f"{alternative} EOF".strip() for alternative in alternatives
            ]
        return format_rule(parser_rule_name(definition.name), alternatives)

    def convert_syntax_alternative(self, alternative: Any) -> str:
        rendered: list[str] = []
        punctuation = ""
        previous_stop: int | None = None

        def flush_punctuation() -> None:
            nonlocal punctuation
            if punctuation:
                rendered.extend(self.split_punctuation(punctuation))
                punctuation = ""

        for element in alternative.syntaxElement():
            nonterminal = element.NONTERMINAL()
            if nonterminal is not None:
                flush_punctuation()
                name = nonterminal_name(nonterminal.getText())
                reference = self.syntax_reference(name)
                if element.STAR() is not None:
                    reference += "*"
                rendered.append(reference)
                previous_stop = element.stop.stop
                continue

            terminal = element.syntaxTerminal().start
            if previous_stop is not None and terminal.start != previous_stop + 1:
                flush_punctuation()

            if terminal.type == self.bare_word_token:
                flush_punctuation()
                rendered.append(antlr_literal(terminal.text))
            else:
                punctuation += terminal.text
            previous_stop = terminal.stop

        flush_punctuation()
        return " ".join(rendered)

    def split_punctuation(self, punctuation: str) -> list[str]:
        rendered: list[str] = []
        operators = sorted(
            self.operator_literals, key=lambda item: (-len(item), item)
        )
        index = 0
        while index < len(punctuation):
            operator = next(
                (
                    candidate
                    for candidate in operators
                    if punctuation.startswith(candidate, index)
                ),
                None,
            )
            if operator is not None:
                rendered.append(antlr_literal(operator))
                index += len(operator)
            else:
                rendered.append(antlr_literal(punctuation[index]))
                index += 1
        return rendered

    def syntax_reference(self, name: str) -> str:
        if name in self.token_names or name in self.macro_names:
            return lexer_rule_name(name)
        return parser_rule_name(name)

    def convert_semantic_comment(self, definition: Definition) -> str:
        start = definition.context.start.start
        stop = definition.context.stop.stop + 1
        source_definition = re.sub(
            r"\s+", " ", self.source[start:stop]
        ).strip()
        return (
            f"// line {definition.line}: "
            f"{source_definition}"
        )

    def convert_lexer_rule(self, definition: Definition) -> list[str]:
        alternatives = [
            self.convert_regex_alternative(alternative)
            for alternative in definition.expression.regexAlternative()
        ]
        name = lexer_rule_name(definition.name)
        fragment = (
            definition.operator == ":::"
            and definition.name not in self.exported_macros
        )
        if fragment:
            name = "fragment " + name

        command = "-> skip" if definition.name == "comment" else ""
        if command and len(alternatives) > 1:
            alternatives = ["( " + " | ".join(alternatives) + " )"]
        return format_rule(name, alternatives, command)

    def convert_regex_alternative(self, alternative: Any) -> str:
        return " ".join(
            self.convert_regex_element(element)
            for element in alternative.regexElement()
        )

    def convert_regex_element(self, element: Any) -> str:
        primary = self.convert_regex_primary(element.regexPrimary())
        quantifier = element.regexQuantifier()
        if quantifier is not None:
            primary += quantifier.getText()
        return primary

    def convert_regex_primary(self, primary: Any) -> str:
        nonterminal = primary.NONTERMINAL()
        if nonterminal is not None:
            return lexer_rule_name(nonterminal_name(nonterminal.getText()))

        expression = primary.regexExpression()
        if expression is not None:
            alternatives = [
                self.convert_regex_alternative(alternative)
                for alternative in expression.regexAlternative()
            ]
            return "( " + " | ".join(alternatives) + " )"

        character_set = primary.characterSet()
        if character_set is not None:
            content = "".join(
                element.getText()
                for element in character_set.characterSetElement()
            )
            return "[" + convert_octal_escapes(content) + "]"

        literal = primary.regexLiteral().getText()
        if literal == ".":
            return "."
        return antlr_literal(literal)


def convert_octal_escapes(character_set: str) -> str:
    """Translate SyntaxBNF's POSIX octal escapes into ANTLR Unicode escapes."""

    return OCTAL_ESCAPE_PATTERN.sub(
        lambda match: f"\\u{int(match.group(1), 8):04X}",
        character_set,
    )


def format_rule(
    name: str, alternatives: Sequence[str], command: str = ""
) -> list[str]:
    if not alternatives:
        alternatives = [""]
    first_alternative = (
        f"    : {alternatives[0]}" if alternatives[0] else "    :"
    )
    lines = [name, first_alternative]
    lines.extend(
        f"    | {alternative}" if alternative else "    |"
        for alternative in alternatives[1:]
    )
    lines.append(f"    {command};" if command else "    ;")
    return lines


def resolve_output_path(output: Path, grammar_name: str) -> Path:
    if output.suffix == ".g4":
        return output
    return output / f"{grammar_name}.g4"


def main(argv: Sequence[str] | None = None) -> int:
    arguments = parse_arguments(sys.argv[1:] if argv is None else argv)
    if GRAMMAR_NAME_PATTERN.fullmatch(arguments.grammar_name) is None:
        print(
            f"error: invalid ANTLR grammar name: {arguments.grammar_name!r}",
            file=sys.stderr,
        )
        return 2

    try:
        definitions, source, lexer_class = parse_syntax_bnf(
            arguments.input.resolve(),
            arguments.metagrammar.resolve(),
            arguments.antlr_jar.resolve(),
        )
        converter = GrammarConverter(
            definitions,
            source,
            lexer_class,
            arguments.grammar_name,
            arguments.input.name,
            arguments.metagrammar.name,
        )
        grammar = converter.convert()
        output_path = resolve_output_path(
            arguments.output, arguments.grammar_name
        )
        output_path.parent.mkdir(parents=True, exist_ok=True)
        output_path.write_text(grammar, encoding="utf-8")
    except (ConversionError, OSError) as error:
        print(f"error: {error}", file=sys.stderr)
        return 1

    parser_count = sum(
        definition.operator == "::=" for definition in definitions
    )
    semantic_count = sum(
        definition.operator == ":==" for definition in definitions
    )
    token_count = sum(
        definition.operator == "::-" for definition in definitions
    )
    macro_count = sum(
        definition.operator == ":::" for definition in definitions
    )
    print(
        f"Wrote {output_path} "
        f"({parser_count} parser rules, {token_count} tokens, "
        f"{macro_count} macros, {semantic_count} semantic restrictions)."
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
