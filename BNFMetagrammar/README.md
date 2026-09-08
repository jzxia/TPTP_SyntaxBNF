# SyntaxBNF metagrammar

`BNFMetaParser.g4` is an ANTLR4 parser metagrammar for the four kinds of definition in
the TPTP SyntaxBNF notation:

- `::=` syntactic parser rules
- `:==` semantic restrictions
- `::-` lexer tokens
- `:::` lexer character-class macros

It also recognizes `%` comments, blank lines, and indented continuation lines.
The parser and its companion `BNFMetaLexer.g4` are target-neutral and contain
no embedded actions.
These two files replace the previous combined `BNFMeta.g4` grammar.

The lexer keeps words such as `tpi` intact in syntactic and semantic rules,
but emits individual characters inside regex charsets. The parser can then
recognize escapes and range endpoints without splitting token text in the
converter. Lexer modes follow these contexts:

| Context | Entry | Exit |
| --- | --- | --- |
| Default: rule names and comments | Start of document or end of definition | A definition operator |
| Syntactic RHS | `::=` or `:==` | An uncontinued newline |
| Regex RHS | `::-` or `:::` | An uncontinued newline |
| Charset | `[` in a regex RHS | An unescaped `]` |
| Quoted character | Backslash in a charset | After one character |

Indented continuation lines keep the RHS mode. Brackets in syntactic rules
and example definitions in comments do not enter charset mode. Whitespace
inside a charset is literal; a physical newline there is invalid.

Charset support is deliberately limited to SyntaxBNF notation:

- One to three octal digits after a backslash, `\\` for backslash, `\n` for
  newline, and `\]`, `\-`, `\^` for quoted charset punctuation.
- Leading `^` negation, such as `[^/*]`; a later `^` is literal.
- Ranges with literal or escaped endpoints: `A-Z`, `\40-\46`, `\123-X`.
- Literal hyphens at the edges, including `[+-]`, and the existing `.` wildcard.

The parse tree exposes `charSetNegation`, `charSetRange`, `charSetEscape`,
and `octalDigits`. The converter decodes octal values, emits ANTLR negation
as `~[...]`, and rejects empty sets and descending ranges. Hex escapes,
Unicode properties, POSIX classes, and set operations are not implemented.

Generate and run a parser from this directory with:

```bash
java -jar ../ANTLRParsers/antlr-4.13.2-complete.jar BNFMetaLexer.g4 BNFMetaParser.g4
javac -cp ../ANTLRParsers/antlr-4.13.2-complete.jar BNFMeta*.java
java -cp "../ANTLRParsers/antlr-4.13.2-complete.jar:." \
  org.antlr.v4.gui.TestRig BNFMeta document -tree ../SyntaxBNF-v9.3.1.2
```
