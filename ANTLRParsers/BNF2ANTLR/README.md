# HOW TO CONVERT BNF TO ANTLR

## Direct SyntaxBNF converter

**Make sure your current working directory is `BNF2ANTLR`!**

bnf2antlr.py will take input from the BNF file given as a command line argument ,convert it 
all to antlr grammar, and then outputs it to g4/TPTP.g4

- To convert files, run this command:

```bash
python3 bnf2antlr.py SyntaxBNF-vR.E.P.F output_directory_eg_../ANTLRGrammar
```

- If this fails run this:

```bash
  python bnf2antlr.py
```

## Metagrammar-driven converter

`bnf2antlr_meta.py` is the metagrammar-driven converter.
It generates a temporary Python parser
from `BNFMetaGrammar/BNFMetaParser.g4` and its companion `BNFMetaLexer.g4`,
parses the complete SyntaxBNF document,
and emits a combined ANTLR4 grammar.

The converter follows the existing SyntaxBNF conventions directly:
`TPTP_file` is the entry rule,
`comment` tokens are skipped,
and macros referenced by parser rules become tokens.
It relies on the metagrammar to validate definitions
and stops at the first syntax error.
Charset conversion also checks range order and octal values.

### How to run the metagrammar-driven converter

Install the matching runtime once:

```bash
python3 -m pip install -r ANTLRParsers/BNF2ANTLR/requirements.txt
```

From the repository root, run the converter:

```bash
python3 ANTLRParsers/BNF2ANTLR/bnf2antlr_meta.py
```

By default, the converter takes as its input
the file under the repository root whose name begins with `SyntaxBNF`,
and generates `TPTP.g4` in the default output directory,
`ANTLRParsers/ANTLRGrammar/converted_by_meta`.

Alternatively, you can specify the input and output as follows:

```bash
python3 ANTLRParsers/BNF2ANTLR/bnf2antlr_meta.py \
  /path/to/Syntax/BNF \
  ANTLRParsers/ANTLRGrammar/CustomTPTP.g4 \
  --output-grammar-name CustomTPTP
```

The converter requires Java and the repository's `ANTLRParsers/antlr-4.13.2-complete.jar`.
Alternative metagrammar and jar paths can be selected with `--metagrammar` and `--antlr-jar`.
The selected metagrammar must have its companion `BNFMetaLexer.g4` in the same directory.

### How to test the metagrammar-driven converter

Run the charset conversion and generated-lexer checks from the repository root:

```bash
python3 -m unittest discover -s ANTLRParsers/BNF2ANTLR -p 'test_*.py'
```
