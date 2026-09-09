lexer grammar BNFMetaLexer;

// Modes describe where characters occur; BNFMetaParser.g4 gives them meaning.
// Only ::- and ::: enter REGEX, and only REGEX's [ enters CHARSET.
// Thus brackets and backslashes in syntactic rules stay literal punctuation.
// A physical newline ends a definition unless the next line is indented.

SYNTAX_DEFINITION      : '::=' -> pushMode(SYNTAX) ;
SEMANTIC_DEFINITION    : ':==' -> pushMode(SYNTAX) ;
TOKEN_DEFINITION       : '::-' -> pushMode(REGEX) ;
LEXER_MACRO_DEFINITION : ':::' -> pushMode(REGEX) ;
NONTERMINAL            : RULE_REFERENCE ;
COMMENT                : '%' ~[\r\n]* ;
CONTINUATION           : CONTINUED_LINE -> skip ;
HORIZONTAL_WHITESPACE  : [ \t]+ -> skip ;
NEWLINE                : LINE_BREAK ;
RAW_CHARACTER          : . ;

fragment RULE_REFERENCE : '<' [A-Za-z_] [A-Za-z0-9_]* '>' ;
fragment LINE_BREAK     : '\r'? '\n' ;
fragment CONTINUED_LINE : LINE_BREAK [ \t]+ ;

mode SYNTAX;
SYNTAX_NONTERMINAL : RULE_REFERENCE -> type(NONTERMINAL) ;
BARE_WORD         : [A-Za-z0-9_$]+ ;
PIPE              : '|' ;
STAR              : '*' ;
SYNTAX_CONTINUATION : CONTINUED_LINE -> skip ;
SYNTAX_WHITESPACE   : [ \t]+ -> skip ;
SYNTAX_NEWLINE      : LINE_BREAK -> type(NEWLINE), popMode ;
SYNTAX_CHARACTER    : . -> type(RAW_CHARACTER) ;

mode REGEX;
REGEX_NONTERMINAL : RULE_REFERENCE -> type(NONTERMINAL) ;
REGEX_PIPE       : '|' -> type(PIPE) ;
REGEX_STAR       : '*' -> type(STAR) ;
PLUS             : '+' ;
QUESTION         : '?' ;
WILDCARD         : '.' ;
LPAREN           : '(' ;
RPAREN           : ')' ;
// Consume leading negation with the opener; all carets inside CHARSET are literal.
NEGATED_LBRACKET : '[^' -> pushMode(CHARSET) ;
LBRACKET         : '[' -> pushMode(CHARSET) ;
REGEX_CONTINUATION : CONTINUED_LINE -> skip ;
REGEX_WHITESPACE   : [ \t]+ -> skip ;
REGEX_NEWLINE      : LINE_BREAK -> type(NEWLINE), popMode ;
REGEX_CHARACTER    : . -> type(RAW_CHARACTER) ;

mode CHARSET;
RBRACKET          : ']' -> popMode ;
BACKSLASH         : '\\' -> pushMode(QUOTED_CHARACTER) ;
DASH              : '-' ;
OCTAL_DIGIT       : [0-7] ;
CHARSET_NEWLINE   : LINE_BREAK -> type(NEWLINE) ;
CHARSET_CHARACTER : . ;

// Quote exactly one character so that \] cannot close the charset and \\
// cannot start another escape. Octal digits remain separate parser tokens.
mode QUOTED_CHARACTER;
QUOTED_OCTAL_DIGIT : [0-7] -> type(OCTAL_DIGIT), popMode ;
ESCAPED_CHARACTER  : [\\n\]\-^] -> popMode ;
QUOTED_NEWLINE     : LINE_BREAK -> type(NEWLINE), popMode ;
INVALID_ESCAPE    : . -> popMode ;
