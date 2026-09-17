lexer grammar BNFMetaLexer;

// Modes describe where characters occur; BNFMetaParser.g4 gives them meaning.
// Only ::- and ::: enter REGEX, and only REGEX's [ enters CHARSET.
// Thus brackets and backslashes in syntactic rules stay literal punctuation.
// A physical newline ends a definition unless the next line is indented.

SYNTAX_DEFINITION      : '::=' -> mode(SYNTAX) ;
SEMANTIC_DEFINITION    : ':==' -> mode(SYNTAX) ;
TOKEN_DEFINITION       : '::-' -> mode(REGEX) ;
LEXER_MACRO_DEFINITION : ':::' -> mode(REGEX) ;
NONTERMINAL            : RULE_REFERENCE ;
COMMENT                : '%' ~[\r\n]* ;
WHITESPACE             : SPACING -> skip ;
NEWLINE                : LINE_BREAK ;
RAW_CHARACTER          : . ;

fragment RULE_REFERENCE : '<' [A-Za-z_] [A-Za-z0-9_]* '>' ;
fragment LINE_BREAK     : '\r'? '\n' ;
// A newline followed by indentation is whitespace, not a definition boundary.
fragment SPACING        : LINE_BREAK? [ \t]+ ;

mode SYNTAX;
SYNTAX_NONTERMINAL : RULE_REFERENCE -> type(NONTERMINAL) ;
BARE_WORD          : [A-Za-z0-9_$]+ ;
PIPE               : '|' ;
STAR               : '*' ;
SYNTAX_WHITESPACE  : SPACING -> skip ;
SYNTAX_NEWLINE     : LINE_BREAK -> type(NEWLINE), mode(DEFAULT_MODE) ;
SYNTAX_CHARACTER   : . -> type(RAW_CHARACTER) ;

mode REGEX;
REGEX_NONTERMINAL : RULE_REFERENCE -> type(NONTERMINAL) ;
REGEX_PIPE        : '|' -> type(PIPE) ;
REGEX_STAR        : '*' -> type(STAR) ;
PLUS              : '+' ;
QUESTION          : '?' ;
WILDCARD          : '.' ;
LPAREN            : '(' ;
RPAREN            : ')' ;
// Consume leading negation with the opener; all carets inside CHARSET are literal.
NEGATED_LBRACKET  : '[^' -> pushMode(CHARSET) ;
LBRACKET          : '['  -> pushMode(CHARSET) ;
REGEX_WHITESPACE  : SPACING -> skip ;
REGEX_NEWLINE     : LINE_BREAK -> type(NEWLINE), mode(DEFAULT_MODE) ;
REGEX_CHARACTER   : . -> type(RAW_CHARACTER) ;

mode CHARSET;
RBRACKET          : ']' -> popMode ;
OCTAL_ESCAPE      : '\\' [0-7]+ ;      // character code in base 8
QUOTED_ESCAPE     : '\\' [\\n] ;       // escaped backslash or newline
DASH              : '-' ;
CHARSET_CHARACTER : [\u0020-\u007E] ;  // printable ASCII, including space
