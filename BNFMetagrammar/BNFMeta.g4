grammar BNFMeta;

// Meta-grammar for the TPTP SyntaxBNF notation.
//
// IMPORTANT: SyntaxBNF uses two different right-hand-side sublanguages.
// The main differences between the two sublanguages are:
//
// 1. Parentheses and square brackets
//
//    In syntactic (::=) and semantic (:==) rules, they are normally literal
//    punctuation in the TPTP language being defined:
//
//      Line 45 (SyntaxBNF-v9.3.0.3):
//      <tpi_annotated> ::= tpi(<name>,<formula_role>,<tpi_formula><annotations>).
//
//      Line 142:
//      <thf_tuple> ::= [] | [<thf_formula_list>]
//
//      Line 303:
//      <ntf_semantics_spec> :==
//          <ntf_logic_name> <identical> [<ntf_logic_spec_list>]
//
//    In token (::-) and character-class macro (:::) rules, parentheses group
//    regular expressions and square brackets delimit character sets:
//
//      Line 651:
//      <real> ::- (<signed_real>|<unsigned_real>)
//
//      Line 670:
//      <vline> ::: [|]
//
// 2. Postfix *, +, and ?
//
//    In ::= and :== rules, * is repetition only immediately after a
//    nonterminal. Otherwise *, +, and ? are literal terminal punctuation:
//
//      Line 38:  <TPTP_file> ::= <TPTP_input>*
//      Line 429: <th0_quantifier> ::= ^ | @+ | @-
//      Line 431: <type_quantifier> ::= !> | ?*
//
//    In ::- and ::: rules, *, +, and ? are regular-expression quantifiers
//    when they follow a regex primary. Inside a character set they are literal:
//
//      Line 631:
//      <single_quoted> ::- <single_quote><sq_char><sq_char>*<single_quote>
//
//      Line 671:
//      <star> ::: [*]
//
// 3. Curly braces
//
//    In ::= and :== rules, curly braces are literal TPTP punctuation:
//
//      Line 293:
//      <ntf_connective_name> :== $box | $dia | {$necessary} | {$possible} | ...
//
//    In ::- and ::: rules, {name} is a lexer-macro reference:
//
//      Line 680:
//      <comment_block> :::
//          {slash_char}{star}<not_star_slash>{star}{star}*{slash_char}
//
// 4. Vertical bars
//
//    Outside a character set, | separates alternatives in both sublanguages.
//    A syntactic rule uses <vline> for a literal vertical bar, while a regex
//    puts the literal character in a character set:
//
//      Line 439: <assoc_connective> ::= <vline> | &
//      Line 670: <vline> ::: [|]
//
// These contextual differences are why the parser below has separate
// syntaxExpression and regexExpression rule families.
//
// - A definition starts in column 1.
// - An indented physical line (i.e., one whose first character is horizontal whitespace)
//   continues the preceding definition.
// - CONTINUATION implements that convention without target-language actions.

document
    : documentItem* EOF
    ;

documentItem
    : commentLine
    | syntacticRule
    | semanticRule
    | tokenRule
    | characterClassRule
    | blankLine
    ;

// ::= defines the context-free grammar used by a parser.
syntacticRule
    : ruleName SYNTAX_DEFINITION syntaxExpression lineEnd
    ;

// :== records a semantic restriction on a syntactically broader rule.
semanticRule
    : ruleName SEMANTIC_DEFINITION syntaxExpression lineEnd
    ;

// ::- defines a token emitted by the lexical scanner.
tokenRule
    : ruleName TOKEN_DEFINITION regexExpression lineEnd
    ;

// ::: defines a regular-expression macro used inside token rules.
characterClassRule
    : ruleName CHARACTER_CLASS_DEFINITION regexExpression lineEnd
    ;

ruleName
    : NONTERMINAL
    ;

// The * character has four context-dependent meanings in SyntaxBNF:
//
// 1. EBNF repetition after a nonterminal in a ::= or :== expression:
//      Line 38:  <TPTP_file> ::= <TPTP_input>*
//      Line 143: <thf_formula_list> ::=
//                    <thf_logic_formula><comma_thf_logic_formula>*
//    The NONTERMINAL STAR alternative in syntaxElement handles this case.
//
// 2. Literal terminal punctuation in a ::= or :== expression:
//      Line 431: <type_quantifier> ::= !> | ?*
//    Here * is part of the literal TPTP operator ?*, not repetition, because
//    it does not immediately follow a nonterminal. syntaxTerminal accepts it.
//
// 3. A postfix regular-expression quantifier in a ::- or ::: expression:
//      Line 631: <single_quoted> ::-
//                    <single_quote><sq_char><sq_char>*<single_quote>
//    regexQuantifier handles this case.
//
// 4. A literal character inside a regular-expression character set:
//      Line 671: <star> ::: [*]
//      Line 681: <not_star_slash> ::: ([^*]*[*][*]*[^/*])*[^*]*
//    characterSetElement accepts STAR as set content, so stars inside [...]
//    are not parsed as postfix quantifiers.
//
// At the metagrammar level, an unquoted * after an ANTLR rule reference,
// such as documentItem*, is ANTLR's own "zero or more" operator.
//
// In ::= and :== rules, | is alternation.
syntaxExpression
    : syntaxAlternative (PIPE syntaxAlternative)*
    ;

syntaxAlternative
    : syntaxElement*
    ;

syntaxElement
    : NONTERMINAL STAR
    | NONTERMINAL
    | syntaxTerminal
    ;

syntaxTerminal
    : ~(NONTERMINAL | PIPE | NEWLINE)
    ;

// ::- and ::: use the regular-expression notation documented by SyntaxBNF.
// Parentheses group, square brackets form character classes, and postfix
// *, +, and ? are quantifiers. Curly-braced names are accepted for the
// macro-reference notation used by the comment_block definition.
regexExpression
    : regexAlternative (PIPE regexAlternative)*
    ;

regexAlternative
    : regexElement*
    ;

regexElement
    : regexPrimary regexQuantifier?
    ;

regexPrimary
    : NONTERMINAL
    | LPAREN regexExpression RPAREN
    | characterSet
    | macroReference
    | regexLiteral
    ;

regexQuantifier
    : STAR
    | PLUS
    | QUESTION
    ;

characterSet
    : LBRACK characterSetElement* RBRACK
    ;

characterSetElement
    : ~(RBRACK | NEWLINE)
    ;

macroReference
    : LBRACE macroReferenceElement+ RBRACE
    ;

macroReferenceElement
    : ~(RBRACE | NEWLINE)
    ;

regexLiteral
    : ~(
        NONTERMINAL
        | PIPE
        | STAR
        | PLUS
        | QUESTION
        | LPAREN
        | RPAREN
        | LBRACK
        | RBRACK
        | LBRACE
        | RBRACE
        | NEWLINE
      )
    ;

// PERCENT is allowed inside a character set.
// Example from SyntaxBNF-v9.3.0.3:
//   <percentage_sign>      ::: [%]
commentLine
    : PERCENT (~NEWLINE)* lineEnd
    ;

blankLine
    : NEWLINE
    ;

lineEnd
    : NEWLINE
    | EOF
    ;

SYNTAX_DEFINITION
    : '::='
    ;

SEMANTIC_DEFINITION
    : ':=='
    ;

TOKEN_DEFINITION
    : '::-'
    ;

CHARACTER_CLASS_DEFINITION
    : ':::'
    ;

NONTERMINAL
    : '<' [A-Za-z_] [A-Za-z0-9_]* '>'
    ;

PIPE
    : '|'
    ;

STAR
    : '*'
    ;

PLUS
    : '+'
    ;

QUESTION
    : '?'
    ;

LPAREN
    : '('
    ;

RPAREN
    : ')'
    ;

LBRACK
    : '['
    ;

RBRACK
    : ']'
    ;

LBRACE
    : '{'
    ;

RBRACE
    : '}'
    ;

PERCENT
    : '%'
    ;

BARE_WORD
    : [A-Za-z0-9_$]+
    ;

// This token must precede NEWLINE. It turns an indented physical line into
// part of the current logical definition.
CONTINUATION
    : '\r'? '\n' [ \t]+ -> skip
    ;

HORIZONTAL_WHITESPACE
    : [ \t]+ -> skip
    ;

NEWLINE
    : '\r'? '\n'
    ;

RAW_CHARACTER
    : .
    ;
