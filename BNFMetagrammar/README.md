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

The lexer keeps words such as `tpi` intact in syntactic and semantic rules.
Inside regex charsets, it emits individual literal characters and complete
escape tokens. The parser recognizes set elements and range endpoints; the
converter decodes each escape token. Lexer modes follow these contexts:

| Context | Entry | Exit |
| --- | --- | --- |
| Default: rule names and comments | Start of document or end of definition | A definition operator |
| Syntactic RHS | `::=` or `:==` | An uncontinued newline |
| Regex RHS | `::-` or `:::` | An uncontinued newline |
| Charset | `[` in a regex RHS | An unescaped `]` |

Indented continuation lines keep the RHS mode. Brackets in syntactic rules
and example definitions in comments do not enter charset mode. Literal charset
characters are printable ASCII (U+0020–U+007E), including space. Physical line
breaks, tabs, and other characters outside that range produce lexer errors;
use escapes to represent them.

Charset support is deliberately limited to SyntaxBNF notation:

- One or more octal digits after a backslash, `\\` for backslash, and `\n` for
  newline. These are the escape forms used in SyntaxBNF-v9.3.1.2.
- Leading `^` negation, such as `[^/*]`; a later `^` is literal.
- Ranges with literal or escaped endpoints: `A-Z`, `\40-\46`, `\123-X`.
- Literal hyphens at the edges, including `[+-]`, and the existing `.` wildcard.

The lexer recognizes `[^` as a `NEGATED_LBRACKET` token, so leading negation
cannot be interpreted as a literal caret. The parser requires nonempty
`charSetContent`, rejecting `[]` and `[^]` while allowing `[-]` and `[^-]`.
Edge hyphens are recorded as `leadingDash` and `trailingDash` on that content;
a lone hyphen is always `leadingDash`.

The parse tree also exposes `charSetRange` and `charSetEscape`. Escapes are
single `OCTAL_ESCAPE` or `QUOTED_ESCAPE` tokens. Longest-match lexing consumes
the entire octal digit sequence: `\1234` is one escape, while `\78` is `\7`
followed by literal `8`. Other backslashes fall back to literal characters;
for example, `\q` contributes both a backslash and `q` to the set.
The converter decodes octal values, emits ANTLR negation as `~[...]`, and
rejects descending ranges and values outside Unicode's U+0000–U+10FFFF range.
There is no limit on the number of octal digits, including leading zeros. Hex escapes,
Unicode properties, POSIX classes, and set operations are not implemented.

Generate and run a parser from this directory with:

```bash
java -jar ../ANTLRParsers/antlr-4.13.2-complete.jar BNFMetaLexer.g4 BNFMetaParser.g4
javac -cp ../ANTLRParsers/antlr-4.13.2-complete.jar BNFMeta*.java
java -cp "../ANTLRParsers/antlr-4.13.2-complete.jar:." \
  org.antlr.v4.gui.TestRig BNFMeta document -tree ../SyntaxBNF-v9.3.1.2
```
