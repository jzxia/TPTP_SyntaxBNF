# TFF grammar postprocessor

`factor.py` applies an optional TFF grammar rewrite to the combined ANTLR grammar
emitted by `bnf2antlr_meta.py`. Generate the parser from the resulting `.g4` using
your usual ANTLR command. The checked-in examples and checks use
`SyntaxBNF-v10.0.0.1`.

## Run it

Use Python 3, Java, and [Trash 5.0.0](https://github.com/kaby76/Trash/releases/tag/5.0.0).
Install Trash with the .NET 11 SDK and ensure the `trash` executable is on `PATH`.
From the repository root, run the following commands.

```sh
dotnet tool install --global trash --version 5.0.0
python3 -m pip install -r BNFMetaGrammar/BNF2ANTLR/requirements.txt
python3 BNFMetaGrammar/BNF2ANTLR/bnf2antlr_meta.py -o /tmp/tptp-raw/TPTP.g4
python3 BNFMetaGrammar/BNF2ANTLR/postprocessor/factor.py \
  /tmp/tptp-raw/TPTP.g4 -o /tmp/tptp-factored/TPTP.g4
```

Use the same grammar filename in a separate directory. `--trash` selects a Trash
executable and `--antlr-jar` overrides the repository’s ANTLR 4.13.2 JAR. The
postprocessor itself uses the Python standard library. Node.js is only needed
to run a generated JavaScript parser.

Trash parses the source, applies [the XQuery rewrite](factor_tff.xq), and renders
the grammar. The script requires a byte-identical no-op round trip before the
rewrite. The query checks the exact tokens in the expanded productions, an
action-free grammar, and two unused helper names. The script reparses the result,
compiles both grammars with stock ANTLR, and requires both the lexer section and
the generated JavaScript lexers to match byte for byte. The second comparison
also checks the implicit tokens derived from parser literals. Only after all
checks succeed does the script atomically replace the output.

## Why it is faster

The original grammar makes ANTLR choose between a standalone TFF formula, a
binary formula, and an infix comparison before it has consumed their shared
prefix. For `(p => (q => r))`, for example, a parenthesized formula can also be a
term or the left operand of a larger formula. ANTLR's adaptive LL(*) predictor can
look through the whole nested expression to see which alternatives survive.
Decisions at inner levels can examine the same tokens again. The rewrite puts
the shared operand before the suffix decision, so the relevant choice happens
where the next operator is visible. Conjunctions and disjunctions are then
consumed as same-operator repetitions. [ANTLR's ALL(*) technical report](https://www.antlr.org/papers/allstar-techreport.pdf)

At 64 nested implications, stock ANTLR 4.13.2's Java profiling runtime recorded
8,320 lookahead token visits in `tff_unit_formula` adaptive decisions before
factoring and 322 afterward. The corresponding `tff_logic_formula` decisions
went from 386 visits to 129. These inputs used the default prediction mode.

The JavaScript target showed the following results with ANTLR 4.13.2 and Node
24.12.0. Each measurement used a fresh process with parse trees disabled and
included lexing and parsing. The synthetic input was `tff(a,axiom,` followed by
`(p => ` repeated to the specified depth, `q`, matching closing parentheses,
and `).`.

| Input | Original | Factored |
| --- | ---: | ---: |
| 16 nested implications | 847 ms | 51 ms |
| 32 nested implications | 1,652 ms | 53 ms |
| 64 nested implications | 3,181 ms | 52 ms |
| 107 nested implications | 7,221 ms | 61 ms |
| `ITP006_7.p` | 10 s process deadline | 373 ms |

These are single observations. The factored corpus parse reached `EOF` with
213 statements and zero errors. Factoring and its validation run once at
grammar generation time.

## Why the accepted language is the same

The following equations use `|` for alternatives, juxtaposition for concatenation,
and `ε` for the empty string. Each named operand stands for its complete token
language, including any recursive expansion it can make.

1. **Unit formulas.** Let `A` be an atomic formula, a variable, or a parenthesized
   logic formula. Let `D` be a `defined_term` or tuple, `Q` a quantified formula,
   `P` a prefix-unary formula, `I` either `defined_infix_pred` or `infix_inequality`,
   and `T` the existing `tff_unitary_term`. Expanding the guarded original rules
   gives `Q | P | A | (A | D) I T`. Distributing concatenation over the alternatives
   gives `Q | P | A (ε | I T) | D I T`, the new rule. Expansion in either direction
   keeps exactly the same token sequence. In particular, a number or tuple
   still requires an infix predicate, and the right operand is still `T`.
   Quantified and prefix-unary formulas keep their original operand rules.
2. **Logic formulas.** Let `U` be a unit formula, `N` a nonassociative connective,
   `O` the `Vline` token, and `C` the `&` token. The original standalone alternatives
   together are `U`. The binary pair is `U N U`. Each original list has a base
   of two units and adds one unit with the same connective per recursive step.
   Thus the lists are exactly `U O U (O U)*` and `U C U (C U)*`. A list of any such
   length can be converted back to the original base followed by the corresponding
   number of recursive steps. Factoring out the first `U` gives
   `U (ε | N U | O U (O U)* | C U (C U)*)`. The definition and sequent alternatives
   remain direct alternatives of `tff_logic_formula`. This preserves the single
   nonassociative operator and the same-operator constraint on each list.

These substitutions work inside recursive rules too. In any finite derivation,
replace each affected rule expansion by its counterpart and apply the same
mapping to its children. The inverse mapping gives a derivation in the other
grammar with the same terminal tokens. Every other production and the
`tptp_file` entry point are identical, so the equality applies to the whole
file through `EOF`. The generated lexer check extends the argument from token
sequences to input text.

The guarantee concerns syntactic membership. The rewritten rules can produce
different parse trees and error diagnostics. The parser checks define acceptance
as reaching `EOF` with zero lexer and parser errors.

## Verification

With the converter's Python requirements and Trash installed, run the focused
integration checks from the repository root.

```sh
python3 -m unittest discover -s BNFMetaGrammar/BNF2ANTLR/postprocessor
```

Set `BNF2ANTLR_TRASH` to use a specific executable for the tests. The checks
build both Python parsers from fresh converter output and exercise both sides of
the membership restrictions above. They also verify that changed rule tokens,
helper name collisions, and repeated application fail without replacing an
existing output.

A separate validation run with ANTLR 4.13.2 and Node.js checked 355 cases against
both parsers. It also checked the factored parser on 12 known valid corpus files
and four malformed edits of `ITP006_7.p`. All 371 checks passed. Accepted cases
also matched their expected statement counts.
