# HOW TO CONVERT BNF TO ANTLR

**Make sure your current working directory is `BNF2ANTLR`!**

## Direct SyntaxBNF converter

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

`bnf2antlr_meta.py` is the metagrammar-driven converter. It generates a
temporary Python parser from `BNFMetagrammar/BNFMetaParser.g4` and its companion
`BNFMetaLexer.g4`, parses the complete
SyntaxBNF document, and emits a combined ANTLR4 grammar.

Install the matching runtime once:

```bash
python3 -m pip install -r ANTLRParsers/BNF2ANTLR/requirements.txt
```

From the repository root, generate `TPTP.g4` in an output directory:

```bash
python3 ANTLRParsers/BNF2ANTLR/bnf2antlr_meta.py \
  SyntaxBNF-v9.3.1.2 \
  ANTLRParsers/ANTLRGrammar/meta
```

An explicit `.g4` output path and grammar name can also be supplied:

```bash
python3 ANTLRParsers/BNF2ANTLR/bnf2antlr_meta.py \
  SyntaxBNF-v9.3.1.2 \
  /tmp/TPTP92.g4 \
  --grammar-name TPTP92
```

The converter requires Java and the repository's
`ANTLRParsers/antlr-4.13.2-complete.jar`. Alternate metagrammar and jar paths
can be selected with `--metagrammar` and `--antlr-jar`.
The selected metagrammar must have `BNFMetaLexer.g4` in the same directory.

Run the charset conversion and generated-lexer checks from the repository root:

```bash
python3 -m unittest discover -s ANTLRParsers/BNF2ANTLR -p test_charsets.py
```

The other scripts are retained for comparison:

- `bnf2antlr.py` is the original, buggy line-oriented converter.
- `bnf2antlr_fix.py` contains incremental fixes to that original approach.
