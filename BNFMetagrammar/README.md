# SyntaxBNF metagrammar

`BNFMeta.g4` is an ANTLR4 metagrammar for the four kinds of definition in
the TPTP SyntaxBNF notation:

- `::=` syntactic parser rules
- `:==` semantic restrictions
- `::-` lexer tokens
- `:::` lexer character-class macros

It also recognizes `%` comments, blank lines, and indented continuation lines.
The grammar is target-neutral and contains no embedded actions.

Generate and run a parser from this directory with:

```bash
java -jar ../ANTLRParsers/antlr-4.13.2-complete.jar BNFMeta.g4
javac -cp ../ANTLRParsers/antlr-4.13.2-complete.jar BNFMeta*.java
java -cp "../ANTLRParsers/antlr-4.13.2-complete.jar:." \
  org.antlr.v4.gui.TestRig BNFMeta document -tree ../SyntaxBNF-v9.2.1.4
```
