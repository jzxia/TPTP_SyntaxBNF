parser grammar BNFMetaParser;

options { tokenVocab=BNFMetaLexer; }

// SyntaxBNF definitions conventionally start in column 1; indented lines
// continue the preceding definition. The lexer handles these continuations.
document : (definition | COMMENT lineEnd | NEWLINE)* EOF ;

// ::= defines syntax; :== restricts it semantically.
// ::- defines a token; ::: defines a lexer macro.
definition
    : name=NONTERMINAL
      ( separator=(SYNTAX_DEFINITION | SEMANTIC_DEFINITION) syntaxExpression
      | separator=(TOKEN_DEFINITION | LEXER_MACRO_DEFINITION) regexExpression
      ) lineEnd
    ;

// In ::= and :==, punctuation is literal except for | (alternation) and
// * after a nonterminal (repetition). Thus <input>* repeats, but ?* is literal.
// Parentheses and brackets are literal, as in tpi(<name>) and [<term>].
// Empty alternatives are allowed, including a definition with no RHS.
syntaxExpression  : syntaxAlternative (PIPE syntaxAlternative)* ;
syntaxAlternative : syntaxElement* ;
syntaxElement     : NONTERMINAL STAR? | syntaxTerminal ;
syntaxTerminal    : BARE_WORD | STAR | RAW_CHARACTER ;

// In ::- and :::, parentheses group, brackets delimit character sets,
// and *, +, ? quantify the preceding primary. | separates alternatives.
// Literal characters appear in sets: [|], [*], [(], etc.
regexExpression  : regexAlternative (PIPE regexAlternative)* ;
regexAlternative : regexElement* ;
regexElement     : regexPrimary regexQuantifier? ;
regexPrimary     : NONTERMINAL | LPAREN regexExpression RPAREN | charSet ;
regexQuantifier  : STAR | PLUS | QUESTION ;

// [^ starts a negated set; later carets are literal. The wildcard . is
// also treated as a character set. Escape values are decoded by the converter.
charSet
    : (LBRACKET | NEGATED_LBRACKET) charSetContent RBRACKET
    | WILDCARD
    ;

// Sets are nonempty. Edge hyphens are literal; an interior hyphen forms
// a range. Separate alternatives keep a lone dash unambiguously leading.
charSetContent
    : leadingDash=DASH charSetElement* trailingDash=DASH?
    | charSetElement+ trailingDash=DASH?
    ;
charSetElement   : charSetCharacter (DASH charSetCharacter)? ;
charSetCharacter : OCTAL_ESCAPE | QUOTED_ESCAPE | CHARSET_CHARACTER ;

lineEnd : NEWLINE | EOF ;
