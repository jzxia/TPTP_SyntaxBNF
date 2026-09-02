/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "SyntaxBNF.y"

//-----------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//-----------------------------------------------------------------------------
int yylex();
//-----------------------------------------------------------------------------
//----Compile with -DP_VERBOSE=1 for verbose output.
#ifndef P_VERBOSE
#  define P_VERBOSE 0
#endif
int verbose = P_VERBOSE;

#define YYMAXDEPTH 32768

//----Compile with -DP_USERPROC=1 to #include p_user_proc.c. p_user_proc.c 
//----should #define P_ACT, P_BUILD, P_TOKEN, P_PRINT to different procedures 
//----from those below, and supply code.
#ifdef P_USERPROC
#  include "p_user_proc.c"
#else
#  define P_ACT(ss) if(verbose)printf("%7d %s\n",yylineno,ss);
#  define P_BUILD(sym,A,B,C,D,E,F,G,H,I,J) pBuildTree(sym,A,B,C,D,E,F,G,H,I,J)
#  define P_TOKEN(tok,symbolIndex) pToken(tok,symbolIndex)
#  define P_PRINT(ss) if(verbose){printf("\n\n");pPrintTree(ss,0);}
#endif

extern int yylineno;
extern int yychar;
extern char yytext[];

extern int tptp_store_size;
extern char* tptp_lval[];

#define MAX_CHILDREN 1200
typedef struct pTreeNode * pTree;
struct pTreeNode {
    char* symbol; 
    int symbolIndex; 
    pTree children[MAX_CHILDREN+1];
};
//-----------------------------------------------------------------------------
int yyerror( char *s ) { 

    fprintf( stderr, "%s in line %d at item \"%s\".\n", s, yylineno, yytext); 
    return(0);
}
//-----------------------------------------------------------------------------
pTree pBuildTree(char* symbol,pTree A,pTree B,pTree C,pTree D,pTree E,pTree F, 
pTree G, pTree H, pTree I, pTree J) { 

    pTree ss = (pTree)calloc(1,sizeof(struct pTreeNode));

    ss->symbol = symbol;
    ss->symbolIndex = -1;
    ss->children[0] = A; 
    ss->children[1] = B; 
    ss->children[2] = C;
    ss->children[3] = D;
    ss->children[4] = E;
    ss->children[5] = F;
    ss->children[6] = G;
    ss->children[7] = H;
    ss->children[8] = I;
    ss->children[9] = J;
    ss->children[10] = NULL;

    return ss; 
}
//-----------------------------------------------------------------------------
pTree pToken(char* token, int symbolIndex) { 

    char pTokenBuf[8240];
    pTree ss;
    char* symbol = tptp_lval[symbolIndex];
    char* safeSym;

    strncpy(pTokenBuf, token, 39);
    strncat(pTokenBuf, symbol, 8193);
    safeSym = strdup(pTokenBuf);
    ss = pBuildTree(safeSym,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
    ss->symbolIndex = symbolIndex;

    return ss; 
}
//-----------------------------------------------------------------------------
void pPrintComments(int start, int depth) { 

    int d, j;
    char c1[4] = "%", c2[4] = "/*";

    j = start;
    while (tptp_lval[j] != NULL && (tptp_lval[j][0]==c1[0] || 
(tptp_lval[j][0]==c2[0] && tptp_lval[j][1]==c2[1]))) { 
        for (d=0; d<depth-1; d++) {
            printf("| ");
        }
        printf("%1d ",depth % 10);
        printf("%s\n",tptp_lval[j]);
        j = (j+1)%tptp_store_size; 
    }
    return; 
}
//-----------------------------------------------------------------------------
void pPrintTree(pTree ss, int depth) { 

//----pPrintIdx is where to find top-level comments to print before a sentence. 
//----yywrap() gets those after last sentence.
    static int pPrintIdx = 0;
    int i, d;

    if (pPrintIdx >= 0) { 
        pPrintComments(pPrintIdx, 0); 
        pPrintIdx = -1;
    }
    if (ss == NULL) {
        return;
    }
    for (d = 0; d < depth-1; d++) {
        printf("| ");
    }
    printf("%1d ",depth % 10);
    if (ss->children[0] == NULL) {
        printf("%s\n", ss->symbol);
    } else {
        printf("<%s>\n", ss->symbol);
    }
    if (strcmp(ss->symbol, "PERIOD .") == 0) {
        pPrintIdx = (ss->symbolIndex+1) % tptp_store_size;
    }
    if (ss->symbolIndex >= 0) {
        pPrintComments((ss->symbolIndex+1) % tptp_store_size, depth);
    }
    i = 0;
    while(ss->children[i] != NULL) {
        pPrintTree(ss->children[i],depth+1); 
        i++;
    }
    return; 
}
//-----------------------------------------------------------------------------
int yywrap(void) { 

    P_PRINT(NULL); 
    return 1; 
}
//-----------------------------------------------------------------------------

#line 221 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    AMPERSAND = 258,               /* AMPERSAND  */
    AT_AT_SIGN_MINUS = 259,        /* AT_AT_SIGN_MINUS  */
    AT_AT_SIGN_PLUS = 260,         /* AT_AT_SIGN_PLUS  */
    AT_SIGN = 261,                 /* AT_SIGN  */
    AT_SIGN_EQUALS = 262,          /* AT_SIGN_EQUALS  */
    AT_SIGN_MINUS = 263,           /* AT_SIGN_MINUS  */
    AT_SIGN_PLUS = 264,            /* AT_SIGN_PLUS  */
    CARET = 265,                   /* CARET  */
    COLON = 266,                   /* COLON  */
    COLON_EQUALS = 267,            /* COLON_EQUALS  */
    COMMA = 268,                   /* COMMA  */
    EQUALS = 269,                  /* EQUALS  */
    EQUALS_EQUALS = 270,           /* EQUALS_EQUALS  */
    EQUALS_GREATER = 271,          /* EQUALS_GREATER  */
    EXCLAMATION = 272,             /* EXCLAMATION  */
    EXCLAMATION_EQUALS = 273,      /* EXCLAMATION_EQUALS  */
    EXCLAMATION_EXCLAMATION = 274, /* EXCLAMATION_EXCLAMATION  */
    EXCLAMATION_GREATER = 275,     /* EXCLAMATION_GREATER  */
    LBRACE = 276,                  /* LBRACE  */
    LBRKT = 277,                   /* LBRKT  */
    LESS_EQUALS = 278,             /* LESS_EQUALS  */
    LESS_EQUALS_GREATER = 279,     /* LESS_EQUALS_GREATER  */
    LESS_LESS = 280,               /* LESS_LESS  */
    LESS_TILDE_GREATER = 281,      /* LESS_TILDE_GREATER  */
    LPAREN = 282,                  /* LPAREN  */
    MINUS = 283,                   /* MINUS  */
    MINUS_MINUS_GREATER = 284,     /* MINUS_MINUS_GREATER  */
    PERIOD = 285,                  /* PERIOD  */
    QUESTION = 286,                /* QUESTION  */
    QUESTION_QUESTION = 287,       /* QUESTION_QUESTION  */
    QUESTION_STAR = 288,           /* QUESTION_STAR  */
    RBRACE = 289,                  /* RBRACE  */
    RBRKT = 290,                   /* RBRKT  */
    RPAREN = 291,                  /* RPAREN  */
    STAR = 292,                    /* STAR  */
    TILDE = 293,                   /* TILDE  */
    TILDE_AMPERSAND = 294,         /* TILDE_AMPERSAND  */
    TILDE_VLINE = 295,             /* TILDE_VLINE  */
    VLINE = 296,                   /* VLINE  */
    _DLR_cnf = 297,                /* _DLR_cnf  */
    _DLR_fof = 298,                /* _DLR_fof  */
    _DLR_fot = 299,                /* _DLR_fot  */
    _DLR_let = 300,                /* _DLR_let  */
    _DLR_tff = 301,                /* _DLR_tff  */
    _DLR_thf = 302,                /* _DLR_thf  */
    _LIT_cnf = 303,                /* _LIT_cnf  */
    _LIT_file = 304,               /* _LIT_file  */
    _LIT_fof = 305,                /* _LIT_fof  */
    _LIT_include = 306,            /* _LIT_include  */
    _LIT_inference = 307,          /* _LIT_inference  */
    _LIT_introduced = 308,         /* _LIT_introduced  */
    _LIT_tcf = 309,                /* _LIT_tcf  */
    _LIT_tff = 310,                /* _LIT_tff  */
    _LIT_thf = 311,                /* _LIT_thf  */
    _LIT_tpi = 312,                /* _LIT_tpi  */
    _LIT_unknown = 313,            /* _LIT_unknown  */
    arrow = 314,                   /* arrow  */
    back_quoted = 315,             /* back_quoted  */
    distinct_object = 316,         /* distinct_object  */
    dollar_dollar_word = 317,      /* dollar_dollar_word  */
    dollar_word = 318,             /* dollar_word  */
    hash = 319,                    /* hash  */
    integer = 320,                 /* integer  */
    less_sign = 321,               /* less_sign  */
    lower_word = 322,              /* lower_word  */
    plus = 323,                    /* plus  */
    rational = 324,                /* rational  */
    real = 325,                    /* real  */
    single_quoted = 326,           /* single_quoted  */
    slash = 327,                   /* slash  */
    slosh = 328,                   /* slosh  */
    unrecognized = 329,            /* unrecognized  */
    upper_word = 330               /* upper_word  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define AMPERSAND 258
#define AT_AT_SIGN_MINUS 259
#define AT_AT_SIGN_PLUS 260
#define AT_SIGN 261
#define AT_SIGN_EQUALS 262
#define AT_SIGN_MINUS 263
#define AT_SIGN_PLUS 264
#define CARET 265
#define COLON 266
#define COLON_EQUALS 267
#define COMMA 268
#define EQUALS 269
#define EQUALS_EQUALS 270
#define EQUALS_GREATER 271
#define EXCLAMATION 272
#define EXCLAMATION_EQUALS 273
#define EXCLAMATION_EXCLAMATION 274
#define EXCLAMATION_GREATER 275
#define LBRACE 276
#define LBRKT 277
#define LESS_EQUALS 278
#define LESS_EQUALS_GREATER 279
#define LESS_LESS 280
#define LESS_TILDE_GREATER 281
#define LPAREN 282
#define MINUS 283
#define MINUS_MINUS_GREATER 284
#define PERIOD 285
#define QUESTION 286
#define QUESTION_QUESTION 287
#define QUESTION_STAR 288
#define RBRACE 289
#define RBRKT 290
#define RPAREN 291
#define STAR 292
#define TILDE 293
#define TILDE_AMPERSAND 294
#define TILDE_VLINE 295
#define VLINE 296
#define _DLR_cnf 297
#define _DLR_fof 298
#define _DLR_fot 299
#define _DLR_let 300
#define _DLR_tff 301
#define _DLR_thf 302
#define _LIT_cnf 303
#define _LIT_file 304
#define _LIT_fof 305
#define _LIT_include 306
#define _LIT_inference 307
#define _LIT_introduced 308
#define _LIT_tcf 309
#define _LIT_tff 310
#define _LIT_thf 311
#define _LIT_tpi 312
#define _LIT_unknown 313
#define arrow 314
#define back_quoted 315
#define distinct_object 316
#define dollar_dollar_word 317
#define dollar_word 318
#define hash 319
#define integer 320
#define less_sign 321
#define lower_word 322
#define plus 323
#define rational 324
#define real 325
#define single_quoted 326
#define slash 327
#define slosh 328
#define unrecognized 329
#define upper_word 330

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 152 "SyntaxBNF.y"
int ival; double dval; char* sval; void* pval;

#line 427 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_AMPERSAND = 3,                  /* AMPERSAND  */
  YYSYMBOL_AT_AT_SIGN_MINUS = 4,           /* AT_AT_SIGN_MINUS  */
  YYSYMBOL_AT_AT_SIGN_PLUS = 5,            /* AT_AT_SIGN_PLUS  */
  YYSYMBOL_AT_SIGN = 6,                    /* AT_SIGN  */
  YYSYMBOL_AT_SIGN_EQUALS = 7,             /* AT_SIGN_EQUALS  */
  YYSYMBOL_AT_SIGN_MINUS = 8,              /* AT_SIGN_MINUS  */
  YYSYMBOL_AT_SIGN_PLUS = 9,               /* AT_SIGN_PLUS  */
  YYSYMBOL_CARET = 10,                     /* CARET  */
  YYSYMBOL_COLON = 11,                     /* COLON  */
  YYSYMBOL_COLON_EQUALS = 12,              /* COLON_EQUALS  */
  YYSYMBOL_COMMA = 13,                     /* COMMA  */
  YYSYMBOL_EQUALS = 14,                    /* EQUALS  */
  YYSYMBOL_EQUALS_EQUALS = 15,             /* EQUALS_EQUALS  */
  YYSYMBOL_EQUALS_GREATER = 16,            /* EQUALS_GREATER  */
  YYSYMBOL_EXCLAMATION = 17,               /* EXCLAMATION  */
  YYSYMBOL_EXCLAMATION_EQUALS = 18,        /* EXCLAMATION_EQUALS  */
  YYSYMBOL_EXCLAMATION_EXCLAMATION = 19,   /* EXCLAMATION_EXCLAMATION  */
  YYSYMBOL_EXCLAMATION_GREATER = 20,       /* EXCLAMATION_GREATER  */
  YYSYMBOL_LBRACE = 21,                    /* LBRACE  */
  YYSYMBOL_LBRKT = 22,                     /* LBRKT  */
  YYSYMBOL_LESS_EQUALS = 23,               /* LESS_EQUALS  */
  YYSYMBOL_LESS_EQUALS_GREATER = 24,       /* LESS_EQUALS_GREATER  */
  YYSYMBOL_LESS_LESS = 25,                 /* LESS_LESS  */
  YYSYMBOL_LESS_TILDE_GREATER = 26,        /* LESS_TILDE_GREATER  */
  YYSYMBOL_LPAREN = 27,                    /* LPAREN  */
  YYSYMBOL_MINUS = 28,                     /* MINUS  */
  YYSYMBOL_MINUS_MINUS_GREATER = 29,       /* MINUS_MINUS_GREATER  */
  YYSYMBOL_PERIOD = 30,                    /* PERIOD  */
  YYSYMBOL_QUESTION = 31,                  /* QUESTION  */
  YYSYMBOL_QUESTION_QUESTION = 32,         /* QUESTION_QUESTION  */
  YYSYMBOL_QUESTION_STAR = 33,             /* QUESTION_STAR  */
  YYSYMBOL_RBRACE = 34,                    /* RBRACE  */
  YYSYMBOL_RBRKT = 35,                     /* RBRKT  */
  YYSYMBOL_RPAREN = 36,                    /* RPAREN  */
  YYSYMBOL_STAR = 37,                      /* STAR  */
  YYSYMBOL_TILDE = 38,                     /* TILDE  */
  YYSYMBOL_TILDE_AMPERSAND = 39,           /* TILDE_AMPERSAND  */
  YYSYMBOL_TILDE_VLINE = 40,               /* TILDE_VLINE  */
  YYSYMBOL_VLINE = 41,                     /* VLINE  */
  YYSYMBOL__DLR_cnf = 42,                  /* _DLR_cnf  */
  YYSYMBOL__DLR_fof = 43,                  /* _DLR_fof  */
  YYSYMBOL__DLR_fot = 44,                  /* _DLR_fot  */
  YYSYMBOL__DLR_let = 45,                  /* _DLR_let  */
  YYSYMBOL__DLR_tff = 46,                  /* _DLR_tff  */
  YYSYMBOL__DLR_thf = 47,                  /* _DLR_thf  */
  YYSYMBOL__LIT_cnf = 48,                  /* _LIT_cnf  */
  YYSYMBOL__LIT_file = 49,                 /* _LIT_file  */
  YYSYMBOL__LIT_fof = 50,                  /* _LIT_fof  */
  YYSYMBOL__LIT_include = 51,              /* _LIT_include  */
  YYSYMBOL__LIT_inference = 52,            /* _LIT_inference  */
  YYSYMBOL__LIT_introduced = 53,           /* _LIT_introduced  */
  YYSYMBOL__LIT_tcf = 54,                  /* _LIT_tcf  */
  YYSYMBOL__LIT_tff = 55,                  /* _LIT_tff  */
  YYSYMBOL__LIT_thf = 56,                  /* _LIT_thf  */
  YYSYMBOL__LIT_tpi = 57,                  /* _LIT_tpi  */
  YYSYMBOL__LIT_unknown = 58,              /* _LIT_unknown  */
  YYSYMBOL_arrow = 59,                     /* arrow  */
  YYSYMBOL_back_quoted = 60,               /* back_quoted  */
  YYSYMBOL_distinct_object = 61,           /* distinct_object  */
  YYSYMBOL_dollar_dollar_word = 62,        /* dollar_dollar_word  */
  YYSYMBOL_dollar_word = 63,               /* dollar_word  */
  YYSYMBOL_hash = 64,                      /* hash  */
  YYSYMBOL_integer = 65,                   /* integer  */
  YYSYMBOL_less_sign = 66,                 /* less_sign  */
  YYSYMBOL_lower_word = 67,                /* lower_word  */
  YYSYMBOL_plus = 68,                      /* plus  */
  YYSYMBOL_rational = 69,                  /* rational  */
  YYSYMBOL_real = 70,                      /* real  */
  YYSYMBOL_single_quoted = 71,             /* single_quoted  */
  YYSYMBOL_slash = 72,                     /* slash  */
  YYSYMBOL_slosh = 73,                     /* slosh  */
  YYSYMBOL_unrecognized = 74,              /* unrecognized  */
  YYSYMBOL_upper_word = 75,                /* upper_word  */
  YYSYMBOL_YYACCEPT = 76,                  /* $accept  */
  YYSYMBOL_TPTP_file = 77,                 /* TPTP_file  */
  YYSYMBOL_TPTP_input = 78,                /* TPTP_input  */
  YYSYMBOL_annotated_formula = 79,         /* annotated_formula  */
  YYSYMBOL_tpi_annotated = 80,             /* tpi_annotated  */
  YYSYMBOL_tpi_formula = 81,               /* tpi_formula  */
  YYSYMBOL_thf_annotated = 82,             /* thf_annotated  */
  YYSYMBOL_tff_annotated = 83,             /* tff_annotated  */
  YYSYMBOL_tcf_annotated = 84,             /* tcf_annotated  */
  YYSYMBOL_fof_annotated = 85,             /* fof_annotated  */
  YYSYMBOL_cnf_annotated = 86,             /* cnf_annotated  */
  YYSYMBOL_annotations = 87,               /* annotations  */
  YYSYMBOL_formula_role = 88,              /* formula_role  */
  YYSYMBOL_thf_formula = 89,               /* thf_formula  */
  YYSYMBOL_thf_logic_formula = 90,         /* thf_logic_formula  */
  YYSYMBOL_thf_binary_formula = 91,        /* thf_binary_formula  */
  YYSYMBOL_thf_binary_nonassoc = 92,       /* thf_binary_nonassoc  */
  YYSYMBOL_thf_binary_assoc = 93,          /* thf_binary_assoc  */
  YYSYMBOL_thf_or_formula = 94,            /* thf_or_formula  */
  YYSYMBOL_thf_and_formula = 95,           /* thf_and_formula  */
  YYSYMBOL_thf_apply_formula = 96,         /* thf_apply_formula  */
  YYSYMBOL_thf_unit_formula = 97,          /* thf_unit_formula  */
  YYSYMBOL_thf_preunit_formula = 98,       /* thf_preunit_formula  */
  YYSYMBOL_thf_unitary_formula = 99,       /* thf_unitary_formula  */
  YYSYMBOL_thf_quantified_formula = 100,   /* thf_quantified_formula  */
  YYSYMBOL_thf_quantification = 101,       /* thf_quantification  */
  YYSYMBOL_thf_variable_list = 102,        /* thf_variable_list  */
  YYSYMBOL_thf_typed_variable = 103,       /* thf_typed_variable  */
  YYSYMBOL_thf_unary_formula = 104,        /* thf_unary_formula  */
  YYSYMBOL_thf_prefix_unary = 105,         /* thf_prefix_unary  */
  YYSYMBOL_thf_infix_unary = 106,          /* thf_infix_unary  */
  YYSYMBOL_thf_atomic_formula = 107,       /* thf_atomic_formula  */
  YYSYMBOL_thf_plain_atomic = 108,         /* thf_plain_atomic  */
  YYSYMBOL_thf_defined_atomic = 109,       /* thf_defined_atomic  */
  YYSYMBOL_thf_defined_term = 110,         /* thf_defined_term  */
  YYSYMBOL_thf_defined_infix = 111,        /* thf_defined_infix  */
  YYSYMBOL_thf_system_atomic = 112,        /* thf_system_atomic  */
  YYSYMBOL_thf_let = 113,                  /* thf_let  */
  YYSYMBOL_thf_let_types = 114,            /* thf_let_types  */
  YYSYMBOL_thf_atom_typing_list = 115,     /* thf_atom_typing_list  */
  YYSYMBOL_thf_let_defns = 116,            /* thf_let_defns  */
  YYSYMBOL_thf_let_defn = 117,             /* thf_let_defn  */
  YYSYMBOL_thf_let_defn_list = 118,        /* thf_let_defn_list  */
  YYSYMBOL_thf_unitary_term = 119,         /* thf_unitary_term  */
  YYSYMBOL_thf_conn_term = 120,            /* thf_conn_term  */
  YYSYMBOL_thf_tuple = 121,                /* thf_tuple  */
  YYSYMBOL_thf_fof_function = 122,         /* thf_fof_function  */
  YYSYMBOL_thf_arguments = 123,            /* thf_arguments  */
  YYSYMBOL_thf_formula_list = 124,         /* thf_formula_list  */
  YYSYMBOL_thf_atom_typing = 125,          /* thf_atom_typing  */
  YYSYMBOL_thf_top_level_type = 126,       /* thf_top_level_type  */
  YYSYMBOL_thf_unitary_type = 127,         /* thf_unitary_type  */
  YYSYMBOL_thf_apply_type = 128,           /* thf_apply_type  */
  YYSYMBOL_thf_binary_type = 129,          /* thf_binary_type  */
  YYSYMBOL_thf_mapping_type = 130,         /* thf_mapping_type  */
  YYSYMBOL_thf_xprod_type = 131,           /* thf_xprod_type  */
  YYSYMBOL_thf_union_type = 132,           /* thf_union_type  */
  YYSYMBOL_thf_subtype = 133,              /* thf_subtype  */
  YYSYMBOL_thf_definition = 134,           /* thf_definition  */
  YYSYMBOL_thf_sequent = 135,              /* thf_sequent  */
  YYSYMBOL_tff_formula = 136,              /* tff_formula  */
  YYSYMBOL_tff_logic_formula = 137,        /* tff_logic_formula  */
  YYSYMBOL_tff_binary_formula = 138,       /* tff_binary_formula  */
  YYSYMBOL_tff_binary_nonassoc = 139,      /* tff_binary_nonassoc  */
  YYSYMBOL_tff_binary_assoc = 140,         /* tff_binary_assoc  */
  YYSYMBOL_tff_or_formula = 141,           /* tff_or_formula  */
  YYSYMBOL_tff_and_formula = 142,          /* tff_and_formula  */
  YYSYMBOL_tff_unit_formula = 143,         /* tff_unit_formula  */
  YYSYMBOL_tff_preunit_formula = 144,      /* tff_preunit_formula  */
  YYSYMBOL_tff_unitary_formula = 145,      /* tff_unitary_formula  */
  YYSYMBOL_txf_unitary_formula = 146,      /* txf_unitary_formula  */
  YYSYMBOL_tff_quantified_formula = 147,   /* tff_quantified_formula  */
  YYSYMBOL_tff_variable_list = 148,        /* tff_variable_list  */
  YYSYMBOL_tff_variable = 149,             /* tff_variable  */
  YYSYMBOL_tff_typed_variable = 150,       /* tff_typed_variable  */
  YYSYMBOL_tff_unary_formula = 151,        /* tff_unary_formula  */
  YYSYMBOL_tff_prefix_unary = 152,         /* tff_prefix_unary  */
  YYSYMBOL_tff_infix_unary = 153,          /* tff_infix_unary  */
  YYSYMBOL_tff_atomic_formula = 154,       /* tff_atomic_formula  */
  YYSYMBOL_tff_plain_atomic = 155,         /* tff_plain_atomic  */
  YYSYMBOL_tff_defined_atomic = 156,       /* tff_defined_atomic  */
  YYSYMBOL_tff_defined_plain = 157,        /* tff_defined_plain  */
  YYSYMBOL_tff_defined_infix = 158,        /* tff_defined_infix  */
  YYSYMBOL_tff_system_atomic = 159,        /* tff_system_atomic  */
  YYSYMBOL_txf_let = 160,                  /* txf_let  */
  YYSYMBOL_txf_let_types = 161,            /* txf_let_types  */
  YYSYMBOL_tff_atom_typing_list = 162,     /* tff_atom_typing_list  */
  YYSYMBOL_txf_let_defns = 163,            /* txf_let_defns  */
  YYSYMBOL_txf_let_defn = 164,             /* txf_let_defn  */
  YYSYMBOL_txf_let_LHS = 165,              /* txf_let_LHS  */
  YYSYMBOL_txf_let_defn_list = 166,        /* txf_let_defn_list  */
  YYSYMBOL_nxf_atom = 167,                 /* nxf_atom  */
  YYSYMBOL_tff_term = 168,                 /* tff_term  */
  YYSYMBOL_tff_unitary_term = 169,         /* tff_unitary_term  */
  YYSYMBOL_txf_tuple = 170,                /* txf_tuple  */
  YYSYMBOL_tff_arguments = 171,            /* tff_arguments  */
  YYSYMBOL_tff_atom_typing = 172,          /* tff_atom_typing  */
  YYSYMBOL_tff_top_level_type = 173,       /* tff_top_level_type  */
  YYSYMBOL_tff_non_atomic_type = 174,      /* tff_non_atomic_type  */
  YYSYMBOL_tf1_quantified_type = 175,      /* tf1_quantified_type  */
  YYSYMBOL_tff_monotype = 176,             /* tff_monotype  */
  YYSYMBOL_tff_unitary_type = 177,         /* tff_unitary_type  */
  YYSYMBOL_tff_atomic_type = 178,          /* tff_atomic_type  */
  YYSYMBOL_tff_type_arguments = 179,       /* tff_type_arguments  */
  YYSYMBOL_tff_mapping_type = 180,         /* tff_mapping_type  */
  YYSYMBOL_tff_xprod_type = 181,           /* tff_xprod_type  */
  YYSYMBOL_txf_tuple_type = 182,           /* txf_tuple_type  */
  YYSYMBOL_tff_type_list = 183,            /* tff_type_list  */
  YYSYMBOL_tff_subtype = 184,              /* tff_subtype  */
  YYSYMBOL_txf_definition = 185,           /* txf_definition  */
  YYSYMBOL_txf_sequent = 186,              /* txf_sequent  */
  YYSYMBOL_nhf_long_connective = 187,      /* nhf_long_connective  */
  YYSYMBOL_nhf_parameter_list = 188,       /* nhf_parameter_list  */
  YYSYMBOL_nhf_parameter = 189,            /* nhf_parameter  */
  YYSYMBOL_nhf_key_pair = 190,             /* nhf_key_pair  */
  YYSYMBOL_nxf_long_connective = 191,      /* nxf_long_connective  */
  YYSYMBOL_nxf_parameter_list = 192,       /* nxf_parameter_list  */
  YYSYMBOL_nxf_parameter = 193,            /* nxf_parameter  */
  YYSYMBOL_nxf_key_pair = 194,             /* nxf_key_pair  */
  YYSYMBOL_ntf_connective_name = 195,      /* ntf_connective_name  */
  YYSYMBOL_ntf_defined_connective = 196,   /* ntf_defined_connective  */
  YYSYMBOL_ntf_index = 197,                /* ntf_index  */
  YYSYMBOL_ntf_short_connective = 198,     /* ntf_short_connective  */
  YYSYMBOL_tcf_formula = 199,              /* tcf_formula  */
  YYSYMBOL_tcf_logic_formula = 200,        /* tcf_logic_formula  */
  YYSYMBOL_tcf_quantified_formula = 201,   /* tcf_quantified_formula  */
  YYSYMBOL_fof_formula = 202,              /* fof_formula  */
  YYSYMBOL_fof_logic_formula = 203,        /* fof_logic_formula  */
  YYSYMBOL_fof_binary_formula = 204,       /* fof_binary_formula  */
  YYSYMBOL_fof_binary_nonassoc = 205,      /* fof_binary_nonassoc  */
  YYSYMBOL_fof_binary_assoc = 206,         /* fof_binary_assoc  */
  YYSYMBOL_fof_or_formula = 207,           /* fof_or_formula  */
  YYSYMBOL_fof_and_formula = 208,          /* fof_and_formula  */
  YYSYMBOL_fof_unary_formula = 209,        /* fof_unary_formula  */
  YYSYMBOL_fof_infix_unary = 210,          /* fof_infix_unary  */
  YYSYMBOL_fof_unit_formula = 211,         /* fof_unit_formula  */
  YYSYMBOL_fof_unitary_formula = 212,      /* fof_unitary_formula  */
  YYSYMBOL_fof_quantified_formula = 213,   /* fof_quantified_formula  */
  YYSYMBOL_fof_variable_list = 214,        /* fof_variable_list  */
  YYSYMBOL_fof_atomic_formula = 215,       /* fof_atomic_formula  */
  YYSYMBOL_fof_plain_atomic_formula = 216, /* fof_plain_atomic_formula  */
  YYSYMBOL_fof_defined_atomic_formula = 217, /* fof_defined_atomic_formula  */
  YYSYMBOL_fof_defined_plain_formula = 218, /* fof_defined_plain_formula  */
  YYSYMBOL_fof_defined_infix_formula = 219, /* fof_defined_infix_formula  */
  YYSYMBOL_fof_system_atomic_formula = 220, /* fof_system_atomic_formula  */
  YYSYMBOL_fof_plain_term = 221,           /* fof_plain_term  */
  YYSYMBOL_fof_defined_term = 222,         /* fof_defined_term  */
  YYSYMBOL_fof_defined_atomic_term = 223,  /* fof_defined_atomic_term  */
  YYSYMBOL_fof_defined_plain_term = 224,   /* fof_defined_plain_term  */
  YYSYMBOL_fof_system_term = 225,          /* fof_system_term  */
  YYSYMBOL_fof_arguments = 226,            /* fof_arguments  */
  YYSYMBOL_fof_term = 227,                 /* fof_term  */
  YYSYMBOL_fof_function_term = 228,        /* fof_function_term  */
  YYSYMBOL_fof_sequent = 229,              /* fof_sequent  */
  YYSYMBOL_fof_formula_tuple = 230,        /* fof_formula_tuple  */
  YYSYMBOL_fof_formula_tuple_list = 231,   /* fof_formula_tuple_list  */
  YYSYMBOL_cnf_formula = 232,              /* cnf_formula  */
  YYSYMBOL_cnf_disjunction = 233,          /* cnf_disjunction  */
  YYSYMBOL_cnf_literal = 234,              /* cnf_literal  */
  YYSYMBOL_thf_quantifier = 235,           /* thf_quantifier  */
  YYSYMBOL_thf_unary_connective = 236,     /* thf_unary_connective  */
  YYSYMBOL_th0_quantifier = 237,           /* th0_quantifier  */
  YYSYMBOL_type_quantifier = 238,          /* type_quantifier  */
  YYSYMBOL_subtype_sign = 239,             /* subtype_sign  */
  YYSYMBOL_tff_unary_connective = 240,     /* tff_unary_connective  */
  YYSYMBOL_tff_quantifier = 241,           /* tff_quantifier  */
  YYSYMBOL_fof_quantifier = 242,           /* fof_quantifier  */
  YYSYMBOL_nonassoc_connective = 243,      /* nonassoc_connective  */
  YYSYMBOL_assoc_connective = 244,         /* assoc_connective  */
  YYSYMBOL_unary_connective = 245,         /* unary_connective  */
  YYSYMBOL_gentzen_arrow = 246,            /* gentzen_arrow  */
  YYSYMBOL_assignment = 247,               /* assignment  */
  YYSYMBOL_identical = 248,                /* identical  */
  YYSYMBOL_typeable_atom = 249,            /* typeable_atom  */
  YYSYMBOL_atomic_type = 250,              /* atomic_type  */
  YYSYMBOL_type_constant = 251,            /* type_constant  */
  YYSYMBOL_type_functor = 252,             /* type_functor  */
  YYSYMBOL_defined_type = 253,             /* defined_type  */
  YYSYMBOL_system_type = 254,              /* system_type  */
  YYSYMBOL_defined_infix_pred = 255,       /* defined_infix_pred  */
  YYSYMBOL_infix_equality = 256,           /* infix_equality  */
  YYSYMBOL_infix_inequality = 257,         /* infix_inequality  */
  YYSYMBOL_constant = 258,                 /* constant  */
  YYSYMBOL_functor = 259,                  /* functor  */
  YYSYMBOL_defined_constant = 260,         /* defined_constant  */
  YYSYMBOL_defined_functor = 261,          /* defined_functor  */
  YYSYMBOL_system_constant = 262,          /* system_constant  */
  YYSYMBOL_system_functor = 263,           /* system_functor  */
  YYSYMBOL_th1_defined_term = 264,         /* th1_defined_term  */
  YYSYMBOL_defined_term = 265,             /* defined_term  */
  YYSYMBOL_variable = 266,                 /* variable  */
  YYSYMBOL_source = 267,                   /* source  */
  YYSYMBOL_sources = 268,                  /* sources  */
  YYSYMBOL_dag_source = 269,               /* dag_source  */
  YYSYMBOL_inference_record = 270,         /* inference_record  */
  YYSYMBOL_inference_rule = 271,           /* inference_rule  */
  YYSYMBOL_internal_source = 272,          /* internal_source  */
  YYSYMBOL_intro_type = 273,               /* intro_type  */
  YYSYMBOL_external_source = 274,          /* external_source  */
  YYSYMBOL_file_source = 275,              /* file_source  */
  YYSYMBOL_file_info = 276,                /* file_info  */
  YYSYMBOL_parents = 277,                  /* parents  */
  YYSYMBOL_parent_list = 278,              /* parent_list  */
  YYSYMBOL_parent_info = 279,              /* parent_info  */
  YYSYMBOL_parent_details = 280,           /* parent_details  */
  YYSYMBOL_optional_info = 281,            /* optional_info  */
  YYSYMBOL_useful_info = 282,              /* useful_info  */
  YYSYMBOL_include = 283,                  /* include  */
  YYSYMBOL_include_optionals = 284,        /* include_optionals  */
  YYSYMBOL_formula_selection = 285,        /* formula_selection  */
  YYSYMBOL_name_list = 286,                /* name_list  */
  YYSYMBOL_space_name = 287,               /* space_name  */
  YYSYMBOL_general_term = 288,             /* general_term  */
  YYSYMBOL_general_data = 289,             /* general_data  */
  YYSYMBOL_general_function = 290,         /* general_function  */
  YYSYMBOL_formula_data = 291,             /* formula_data  */
  YYSYMBOL_general_list = 292,             /* general_list  */
  YYSYMBOL_general_terms = 293,            /* general_terms  */
  YYSYMBOL_name = 294,                     /* name  */
  YYSYMBOL_atomic_word = 295,              /* atomic_word  */
  YYSYMBOL_atomic_defined_word = 296,      /* atomic_defined_word  */
  YYSYMBOL_atomic_system_word = 297,       /* atomic_system_word  */
  YYSYMBOL_number = 298,                   /* number  */
  YYSYMBOL_file_name = 299,                /* file_name  */
  YYSYMBOL_nothing = 300                   /* nothing  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3458

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  225
/* YYNRULES -- Number of rules.  */
#define YYNRULES  441
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  816

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   330


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   229,   229,   230,   233,   234,   237,   238,   239,   240,
     241,   242,   245,   248,   251,   254,   257,   260,   263,   266,
     267,   270,   271,   274,   275,   276,   279,   280,   281,   282,
     283,   284,   287,   288,   289,   292,   295,   296,   297,   300,
     301,   304,   305,   308,   309,   312,   313,   314,   317,   318,
     321,   322,   323,   324,   327,   330,   333,   334,   337,   340,
     341,   344,   347,   350,   351,   352,   353,   356,   357,   360,
     361,   362,   363,   364,   367,   368,   371,   374,   377,   380,
     381,   384,   385,   388,   389,   392,   395,   396,   399,   400,
     401,   404,   405,   406,   407,   408,   411,   412,   415,   416,
     417,   420,   423,   424,   427,   428,   431,   432,   433,   436,
     439,   442,   443,   444,   447,   448,   451,   452,   455,   456,
     459,   462,   465,   468,   469,   470,   473,   474,   475,   476,
     477,   478,   481,   482,   485,   488,   489,   492,   493,   496,
     497,   500,   501,   502,   505,   506,   509,   510,   511,   512,
     515,   518,   521,   522,   525,   526,   529,   532,   533,   536,
     539,   542,   543,   544,   547,   548,   551,   554,   555,   556,
     557,   560,   563,   564,   567,   570,   571,   574,   575,   578,
     579,   582,   585,   586,   589,   590,   593,   596,   597,   598,
     601,   602,   603,   604,   605,   608,   609,   612,   613,   616,
     617,   620,   621,   624,   625,   626,   629,   632,   633,   634,
     637,   638,   641,   642,   643,   644,   645,   646,   649,   650,
     653,   656,   657,   660,   663,   664,   667,   670,   673,   676,
     677,   680,   681,   684,   685,   688,   691,   692,   695,   696,
     699,   700,   703,   706,   707,   710,   713,   716,   717,   718,
     719,   722,   723,   726,   727,   730,   733,   734,   737,   738,
     739,   742,   743,   746,   749,   750,   753,   754,   757,   758,
     761,   762,   765,   768,   769,   772,   773,   774,   777,   780,
     781,   784,   785,   786,   789,   792,   793,   796,   799,   802,
     805,   806,   809,   810,   813,   816,   817,   820,   821,   824,
     825,   828,   829,   832,   833,   834,   837,   838,   841,   842,
     845,   846,   849,   850,   853,   854,   857,   858,   859,   860,
     863,   864,   865,   868,   869,   872,   873,   874,   877,   878,
     881,   884,   885,   888,   889,   892,   893,   896,   897,   898,
     899,   900,   901,   904,   905,   908,   911,   914,   917,   920,
     921,   924,   925,   926,   929,   932,   935,   938,   941,   944,
     947,   950,   953,   956,   959,   962,   965,   968,   969,   970,
     971,   972,   975,   976,   979,   982,   983,   984,   985,   986,
     989,   990,   993,   994,   997,  1000,  1003,  1006,  1009,  1012,
    1015,  1016,  1019,  1020,  1023,  1024,  1027,  1030,  1031,  1034,
    1035,  1038,  1041,  1044,  1045,  1046,  1049,  1050,  1053,  1054,
    1057,  1060,  1061,  1062,  1065,  1066,  1067,  1068,  1069,  1070,
    1073,  1076,  1077,  1078,  1079,  1080,  1083,  1084,  1087,  1088,
    1091,  1092,  1095,  1096,  1097,  1100,  1103,  1106,  1107,  1108,
    1111,  1114
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "AMPERSAND",
  "AT_AT_SIGN_MINUS", "AT_AT_SIGN_PLUS", "AT_SIGN", "AT_SIGN_EQUALS",
  "AT_SIGN_MINUS", "AT_SIGN_PLUS", "CARET", "COLON", "COLON_EQUALS",
  "COMMA", "EQUALS", "EQUALS_EQUALS", "EQUALS_GREATER", "EXCLAMATION",
  "EXCLAMATION_EQUALS", "EXCLAMATION_EXCLAMATION", "EXCLAMATION_GREATER",
  "LBRACE", "LBRKT", "LESS_EQUALS", "LESS_EQUALS_GREATER", "LESS_LESS",
  "LESS_TILDE_GREATER", "LPAREN", "MINUS", "MINUS_MINUS_GREATER", "PERIOD",
  "QUESTION", "QUESTION_QUESTION", "QUESTION_STAR", "RBRACE", "RBRKT",
  "RPAREN", "STAR", "TILDE", "TILDE_AMPERSAND", "TILDE_VLINE", "VLINE",
  "_DLR_cnf", "_DLR_fof", "_DLR_fot", "_DLR_let", "_DLR_tff", "_DLR_thf",
  "_LIT_cnf", "_LIT_file", "_LIT_fof", "_LIT_include", "_LIT_inference",
  "_LIT_introduced", "_LIT_tcf", "_LIT_tff", "_LIT_thf", "_LIT_tpi",
  "_LIT_unknown", "arrow", "back_quoted", "distinct_object",
  "dollar_dollar_word", "dollar_word", "hash", "integer", "less_sign",
  "lower_word", "plus", "rational", "real", "single_quoted", "slash",
  "slosh", "unrecognized", "upper_word", "$accept", "TPTP_file",
  "TPTP_input", "annotated_formula", "tpi_annotated", "tpi_formula",
  "thf_annotated", "tff_annotated", "tcf_annotated", "fof_annotated",
  "cnf_annotated", "annotations", "formula_role", "thf_formula",
  "thf_logic_formula", "thf_binary_formula", "thf_binary_nonassoc",
  "thf_binary_assoc", "thf_or_formula", "thf_and_formula",
  "thf_apply_formula", "thf_unit_formula", "thf_preunit_formula",
  "thf_unitary_formula", "thf_quantified_formula", "thf_quantification",
  "thf_variable_list", "thf_typed_variable", "thf_unary_formula",
  "thf_prefix_unary", "thf_infix_unary", "thf_atomic_formula",
  "thf_plain_atomic", "thf_defined_atomic", "thf_defined_term",
  "thf_defined_infix", "thf_system_atomic", "thf_let", "thf_let_types",
  "thf_atom_typing_list", "thf_let_defns", "thf_let_defn",
  "thf_let_defn_list", "thf_unitary_term", "thf_conn_term", "thf_tuple",
  "thf_fof_function", "thf_arguments", "thf_formula_list",
  "thf_atom_typing", "thf_top_level_type", "thf_unitary_type",
  "thf_apply_type", "thf_binary_type", "thf_mapping_type",
  "thf_xprod_type", "thf_union_type", "thf_subtype", "thf_definition",
  "thf_sequent", "tff_formula", "tff_logic_formula", "tff_binary_formula",
  "tff_binary_nonassoc", "tff_binary_assoc", "tff_or_formula",
  "tff_and_formula", "tff_unit_formula", "tff_preunit_formula",
  "tff_unitary_formula", "txf_unitary_formula", "tff_quantified_formula",
  "tff_variable_list", "tff_variable", "tff_typed_variable",
  "tff_unary_formula", "tff_prefix_unary", "tff_infix_unary",
  "tff_atomic_formula", "tff_plain_atomic", "tff_defined_atomic",
  "tff_defined_plain", "tff_defined_infix", "tff_system_atomic", "txf_let",
  "txf_let_types", "tff_atom_typing_list", "txf_let_defns", "txf_let_defn",
  "txf_let_LHS", "txf_let_defn_list", "nxf_atom", "tff_term",
  "tff_unitary_term", "txf_tuple", "tff_arguments", "tff_atom_typing",
  "tff_top_level_type", "tff_non_atomic_type", "tf1_quantified_type",
  "tff_monotype", "tff_unitary_type", "tff_atomic_type",
  "tff_type_arguments", "tff_mapping_type", "tff_xprod_type",
  "txf_tuple_type", "tff_type_list", "tff_subtype", "txf_definition",
  "txf_sequent", "nhf_long_connective", "nhf_parameter_list",
  "nhf_parameter", "nhf_key_pair", "nxf_long_connective",
  "nxf_parameter_list", "nxf_parameter", "nxf_key_pair",
  "ntf_connective_name", "ntf_defined_connective", "ntf_index",
  "ntf_short_connective", "tcf_formula", "tcf_logic_formula",
  "tcf_quantified_formula", "fof_formula", "fof_logic_formula",
  "fof_binary_formula", "fof_binary_nonassoc", "fof_binary_assoc",
  "fof_or_formula", "fof_and_formula", "fof_unary_formula",
  "fof_infix_unary", "fof_unit_formula", "fof_unitary_formula",
  "fof_quantified_formula", "fof_variable_list", "fof_atomic_formula",
  "fof_plain_atomic_formula", "fof_defined_atomic_formula",
  "fof_defined_plain_formula", "fof_defined_infix_formula",
  "fof_system_atomic_formula", "fof_plain_term", "fof_defined_term",
  "fof_defined_atomic_term", "fof_defined_plain_term", "fof_system_term",
  "fof_arguments", "fof_term", "fof_function_term", "fof_sequent",
  "fof_formula_tuple", "fof_formula_tuple_list", "cnf_formula",
  "cnf_disjunction", "cnf_literal", "thf_quantifier",
  "thf_unary_connective", "th0_quantifier", "type_quantifier",
  "subtype_sign", "tff_unary_connective", "tff_quantifier",
  "fof_quantifier", "nonassoc_connective", "assoc_connective",
  "unary_connective", "gentzen_arrow", "assignment", "identical",
  "typeable_atom", "atomic_type", "type_constant", "type_functor",
  "defined_type", "system_type", "defined_infix_pred", "infix_equality",
  "infix_inequality", "constant", "functor", "defined_constant",
  "defined_functor", "system_constant", "system_functor",
  "th1_defined_term", "defined_term", "variable", "source", "sources",
  "dag_source", "inference_record", "inference_rule", "internal_source",
  "intro_type", "external_source", "file_source", "file_info", "parents",
  "parent_list", "parent_info", "parent_details", "optional_info",
  "useful_info", "include", "include_optionals", "formula_selection",
  "name_list", "space_name", "general_term", "general_data",
  "general_function", "formula_data", "general_list", "general_terms",
  "name", "atomic_word", "atomic_defined_word", "atomic_system_word",
  "number", "file_name", "nothing", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-545)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-358)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -545,   504,  -545,  -545,    79,    82,    88,   118,   141,   179,
     226,  -545,  -545,  -545,  -545,  -545,  -545,  -545,  -545,  -545,
     445,   445,   384,   445,   445,   445,   445,  -545,  -545,  -545,
    -545,    83,  -545,   150,  -545,   161,   243,   245,   254,   256,
     215,   215,    97,   260,  -545,   215,   215,   215,   215,   292,
     297,   312,   445,  -545,   328,   275,   341,   349,   355,   360,
    3383,  1903,  1041,   363,   395,   445,  -545,  1589,  2899,  3113,
    1041,  2739,   320,   393,   404,   427,   448,  -545,  -545,  -545,
    -545,  -545,  -545,  -545,   422,  -545,  -545,  -545,   476,  -545,
    1903,  2026,  -545,  -545,  -545,  -545,  -545,  -545,  -545,  -545,
    -545,  -545,   169,  -545,  -545,   201,   372,   386,  -545,   430,
     487,  -545,  -545,   503,  -545,   521,  -545,   540,  -545,  -545,
    -545,  -545,  -545,  -545,  -545,  2002,  1041,  -545,  -545,   430,
    -545,  -545,  -545,  -545,   496,   574,    76,  -545,  1123,   252,
    -545,  -545,  -545,   553,   570,   518,  -545,   445,  -545,  -545,
     577,  2461,   147,  -545,   430,  -545,  -545,  -545,   573,   589,
     146,  2282,  2348,   590,  -545,   576,   430,  -545,  -545,  -545,
    -545,   582,   615,  1476,   277,  -545,  -545,   282,  -545,  -545,
     285,  -545,  -545,  -545,   437,  -545,  -545,  -545,   386,   553,
    -545,  -545,  -545,  -545,   618,  -545,  1229,   603,  -545,  -545,
     573,   604,  -545,   189,   601,   611,   612,  -545,   620,  -545,
     400,   613,  -545,  -545,  -545,  -545,  -545,  -545,  -545,  -545,
     146,  1806,  2727,  -545,  -545,   621,   430,  -545,  -545,  -545,
    -545,   616,   639,   646,  1407,   953,  -545,  3182,   399,  -545,
    -545,   367,  -545,  -545,  -545,   506,  -545,  -545,   386,   553,
    -545,  -545,    87,  -545,  -545,   623,   585,  -545,  -545,  -545,
    -545,  -545,   640,  3251,  -545,  -545,  -545,  -545,   653,   604,
     189,   638,   611,   641,  -545,   644,  -545,  -545,   470,   430,
    -545,  -545,   660,   631,  1903,  1041,  2404,  2899,  3113,  3383,
    3383,   645,  2404,  -545,   662,  -545,  -545,  2404,  -545,  2404,
     104,   647,  -545,  2609,  2404,  2404,  2404,   518,  -545,   661,
     652,   657,   658,   659,   518,   518,   518,  -545,  -545,  -545,
    -545,  -545,  -545,   518,   518,  -545,   667,   605,  -545,  -545,
    -545,  -545,   605,   664,   665,   982,   663,   157,  -545,  -545,
    -545,  2537,   668,  -545,  -545,   685,   111,   670,  -545,  -545,
     478,   666,   671,   833,   649,   673,  3371,  3371,  3371,  3371,
    3371,  -545,  3371,  2380,  2380,   684,   688,   681,  2537,  -545,
    -545,  -545,  -545,  -545,   605,  -545,   397,  3371,  3371,  3371,
     232,  2833,  -545,   699,   682,  -545,  -545,  -545,  -545,   683,
     686,   687,  3251,  -545,  -545,   653,  -545,  -545,   946,   694,
    3182,  3182,  3182,  3182,  3182,  3182,  3182,  -545,  -545,  -545,
     484,  -545,  -545,  3182,  1734,  1734,   696,  1395,  1395,  1395,
    1395,  1395,   605,  2833,  -545,  -545,  -545,  -545,  -545,  3182,
     397,  3182,  3182,  3182,   701,  3383,  -545,   704,   706,  -545,
    -545,  -545,   717,   718,   719,  -545,   723,  -545,   731,  -545,
    -545,   104,   697,   708,   741,  -545,   757,  -545,  -545,  -545,
    -545,  -545,  -545,   691,  -545,   736,   762,   740,   743,   518,
    -545,  -545,  -545,   751,  -545,  -545,  -545,  -545,  -545,  -545,
     750,   776,   760,   779,  -545,   785,  -545,   767,   982,   982,
    -545,  -545,  -545,   739,   745,  -545,  -545,   777,  -545,   778,
    -545,  -545,  -545,  -545,  -545,   416,  -545,  -545,  3371,  -545,
    -545,   499,   106,   106,  -545,   787,  -545,  -545,  -545,  -545,
     783,  -545,  -545,  -545,   507,  -545,  -545,  -545,  -545,  -545,
    -545,  -545,   235,  1297,  3371,  -545,  -545,  -545,  -545,  -545,
    3371,   788,   780,  -545,  -545,  -545,  -545,  -545,   789,   790,
     791,  1521,  -545,  3182,  -545,   558,  -545,  -545,   502,   502,
     801,  -545,   800,  -545,  -545,  -545,  -545,  -545,  -545,  -545,
    -545,   235,  3044,  2972,  -545,  -545,  -545,  -545,  -545,  2972,
    -545,  -545,   772,  -545,  -545,  -545,  -545,   798,   819,   823,
     803,   646,   830,   831,  -545,   772,  -545,  -545,  -545,   808,
    -545,   809,   811,   818,  -545,  -545,  -545,  -545,  -545,  -545,
    -545,  -545,   841,   824,   384,   384,   384,   839,  -545,  -545,
    -545,  -545,  2404,  -545,  -545,  -545,  -545,   856,   605,   862,
     605,   711,  -545,   861,   840,   842,    73,   846,   334,   711,
     605,   711,  2380,   870,  -545,   850,   863,  -545,  -545,  -545,
     852,   864,   350,  -545,   854,   855,  -545,   886,  -545,  -545,
    -545,   725,   870,  -545,   860,   888,  -545,  -545,  -545,   867,
     890,  3320,  -545,   869,   887,   605,  3182,  -545,  -545,  -545,
    -545,  -545,   104,  -545,   899,   904,  -545,   907,  -545,  -545,
    -545,  -545,   518,  -545,  2099,  -545,   711,  -545,   982,  -545,
    -545,   711,  -545,  -545,   711,  -545,   891,   917,   895,  -545,
     865,   416,  -545,   106,  1297,  -545,   919,  -545,   924,  -545,
    -545,  -545,  3371,   909,   910,  -545,   903,  1521,  -545,   502,
    1806,   924,   932,  -545,  -545,  -545,  -545,  -545,  -545,   445,
     912,  -545,   839,   839,  -545,  -545,   846,  -545,  -545,  -545,
     938,   711,  -545,  -545,  -545,  -545,   939,   941,   921,   331,
    3371,  -545,  3371,  -545,  -545,  -545,  -545,   510,   944,   925,
    3182,  3182,  -545,  -545,   949,   951,  1934,  -545,   426,  -545,
     931,  -545,  3182,  -545,  -545,   934,   950,   950,   964,  -545,
    -545,  -545,  -545,  -545,  -545,  -545,  1163,   942,   956,   964,
     958,  -545,   963,   952,   988,  -545,  -545,   940,  -545,  3383,
    -545,  -545,  -545,   104,  -545,  -545
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     441,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     3,     4,    11,     6,     7,     8,     9,    10,     5,
       0,     0,     0,     0,     0,     0,     0,   434,   431,   432,
     433,     0,   430,     0,   440,   441,     0,     0,     0,     0,
       0,     0,     0,     0,   403,     0,     0,     0,     0,    21,
       0,     0,     0,   407,   404,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   408,     0,   402,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   418,   437,   438,
     439,   374,   416,    22,   411,   415,   419,   413,   414,   417,
       0,     0,   373,   436,   435,   319,   316,   281,   282,   285,
     286,   283,   284,   304,   293,   287,   289,     0,   301,   441,
     312,   314,   290,   361,   295,   363,   297,   365,   292,   302,
     362,   364,   366,   372,   335,     0,     0,   336,   345,   441,
     256,   258,   261,   262,   264,   265,   274,   271,     0,   273,
     275,   276,   257,     0,     0,     0,   406,     0,   405,   410,
       0,     0,   373,   252,   441,   251,   253,   254,     0,   290,
       0,     0,     0,     0,   334,     0,   441,   123,   128,   132,
     133,   135,   136,     0,   141,   148,   146,   142,   157,   158,
     147,   161,   162,   166,   143,   163,   170,   169,     0,   192,
     124,   125,   130,   131,     0,   332,     0,     0,   333,   331,
     351,     0,   353,   164,   361,   167,   363,   172,   365,   191,
     150,   366,   370,   369,   371,   327,   326,   325,   367,   328,
       0,     0,     0,   368,   329,     0,   441,    23,    28,    32,
      33,    36,    37,    38,     0,    45,    50,     0,    46,    59,
      60,    51,    63,    64,    70,    47,    65,    73,     0,    68,
      66,    24,     0,    34,   111,   112,   113,    25,    30,    31,
      72,   324,     0,     0,   321,   322,   320,   323,   351,     0,
      67,   361,    69,   363,    77,   365,    75,    74,    52,   441,
      13,   426,   428,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   317,     0,   359,   360,     0,   358,     0,
       0,     0,    20,     0,     0,     0,     0,     0,   308,   310,
       0,     0,     0,     0,     0,     0,     0,   338,   339,   337,
     340,   342,   341,     0,     0,   346,     0,     0,   274,   270,
     273,   409,     0,     0,     0,     0,     0,     0,   243,   245,
     244,     0,     0,   195,   187,   197,   189,     0,   164,   167,
     188,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   348,     0,     0,     0,     0,     0,     0,     0,   159,
     144,   145,   147,   150,     0,   330,     0,     0,     0,     0,
       0,     0,    96,   102,     0,    67,    69,   344,   343,     0,
       0,     0,    95,    91,    92,     0,    93,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    54,    45,    46,
      51,    47,    68,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    61,    48,    49,    51,    52,     0,
       0,     0,     0,     0,     0,     0,   427,     0,     0,   303,
     294,   305,     0,     0,     0,   412,     0,   313,     0,   288,
     272,     0,     0,     0,     0,   378,   441,   375,   383,   376,
     377,   388,   382,     0,   315,     0,   299,     0,     0,     0,
     309,   277,   307,     0,   267,   269,   268,   266,   263,   306,
       0,   279,     0,   152,   154,   155,   200,     0,     0,     0,
     199,   202,   204,     0,   201,   203,   217,     0,   212,   354,
     213,   214,   355,   356,   249,     0,   236,   247,     0,   196,
     250,   149,     0,     0,   350,     0,   175,   349,   361,   248,
       0,   138,   141,   142,   147,   143,   192,   140,   139,   137,
     134,   227,     0,     0,     0,   190,   171,   193,   160,   228,
       0,     0,     0,   351,   226,   352,   363,   357,     0,     0,
       0,     0,   229,     0,    97,    53,    71,   105,     0,     0,
       0,    79,     0,    40,    42,    44,    41,    43,    39,    35,
     121,     0,     0,     0,    88,    76,    89,    62,   122,     0,
     109,   116,   114,   115,   118,   117,   119,     0,    56,     0,
       0,   110,     0,   109,   104,   106,   108,   107,   120,     0,
     101,     0,     0,     0,   429,   424,   423,   425,   422,   421,
     420,   318,   380,     0,     0,     0,     0,     0,    19,   400,
      18,   291,     0,   296,   298,   311,    17,     0,     0,     0,
       0,     0,    16,   224,     0,     0,     0,   210,     0,     0,
       0,     0,     0,     0,   242,     0,   238,   241,   240,   198,
       0,   177,     0,    15,     0,     0,   149,     0,   165,   168,
     173,     0,     0,   235,     0,   231,   234,   233,   103,     0,
      81,     0,    14,     0,     0,     0,     0,    53,   100,    98,
      99,    12,     0,   379,   441,     0,   385,     0,   387,   399,
     401,   300,     0,   280,     0,   153,     0,   156,     0,   223,
     205,     0,   216,   211,     0,   220,     0,   218,     0,   246,
       0,     0,   176,     0,     0,   182,     0,   179,     0,   183,
     194,   186,     0,     0,     0,    95,     0,     0,    80,     0,
       0,     0,     0,    83,    90,    55,    57,    58,   381,     0,
       0,   391,     0,     0,   278,   255,     0,   225,   221,   222,
       0,     0,   215,   237,   239,   178,   161,   184,     0,   189,
       0,   347,     0,   151,   230,   232,    82,   102,    86,     0,
       0,     0,   390,   389,     0,     0,     0,   219,     0,   180,
       0,   181,     0,    84,    85,     0,     0,     0,     0,   209,
     206,   207,   185,   174,    87,    78,     0,     0,     0,     0,
       0,   392,   441,     0,   394,   384,   386,     0,   208,     0,
     396,   398,   393,     0,   397,   395
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -545,  -545,  -545,  -545,  -545,  -545,  -545,  -545,  -545,  -545,
    -545,   -36,   562,   715,   113,  -545,  -545,  -545,  -545,  -545,
    -401,    23,  -545,   579,  -545,  -545,   330,  -545,   406,  -227,
    -545,  1505,  -545,  -545,  -545,   417,  -545,  -545,  -545,   287,
    -545,   343,   236,   136,  -545,    58,  -545,   132,  -311,  -195,
     344,  -337,  -545,  -545,  -332,  -545,  -545,  -545,  -480,  -545,
     732,   -39,  -545,  -545,  -545,  -545,  -545,  -292,  -545,  -124,
    -545,  -545,  -336,  -545,  -545,  -282,   826,  -545,  -136,  -504,
    -545,  -545,  -257,  -545,  -545,  -545,   310,  -545,   373,  -545,
     248,  -545,  -313,  -302,   551,   -55,   -46,   693,   543,   253,
    -545,  -449,   162,   286,   250,  -545,  -545,   335,  -545,  -481,
    -545,  -545,   313,  -545,  -545,  -545,   332,  -545,  -545,  -172,
    -545,  -472,   773,  -545,   347,  -545,    -7,   -56,  -545,  -545,
    -545,  -545,  -545,  -135,   -53,  -122,   -98,  -545,   420,   -35,
    -545,  -545,  -545,  -545,  -545,  -155,  -545,  -545,  -145,   234,
    -255,    22,  -545,   918,   724,   583,    27,  -545,   748,  -545,
    -137,  -545,  -276,   786,  -545,   797,   -31,   -30,  -545,  2193,
     -52,   336,  -216,   -15,   -11,  -545,  -545,  -545,  -545,  -101,
      -3,    -2,   565,   885,  1316,  1413,  1826,  1923,  -545,  2336,
     -26,  -281,   374,  -545,  -545,  -545,  -545,  -545,  -545,  -545,
    -545,   272,   249,  -545,  -545,  -545,  -152,  -545,  -545,  -545,
     914,  -545,   -49,  -545,  -545,  -545,  -544,  -183,    -8,   -19,
    -130,    69,   -51,   450,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    11,    12,    13,   279,    14,    15,    16,    17,
      18,   301,    50,   226,   383,   228,   229,   230,   231,   232,
     233,   234,   424,   235,   236,   237,   587,   588,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   560,   669,
     732,   768,   769,   248,   390,   412,   250,   599,   384,   251,
     594,   252,   596,   253,   254,   255,   256,   257,   258,   259,
     166,   344,   168,   169,   170,   171,   172,   173,   369,   174,
     175,   176,   482,   483,   484,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   515,   650,   716,   757,   718,
     758,   187,   345,   188,   346,   347,   333,   633,   491,   492,
     790,   493,   494,   708,   495,   638,   496,   634,   191,   192,
     193,   260,   664,   665,   666,   194,   645,   646,   647,   337,
     338,   648,   261,   154,   155,   156,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   480,   141,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     465,   107,   108,   142,   143,   310,   157,   110,   111,   262,
     263,   264,   265,   376,   196,   266,   198,   393,   394,   267,
     365,   770,   362,   158,   201,   498,   499,   500,   202,   297,
     396,   397,   385,   271,   386,   273,   274,   275,   276,   277,
     119,   612,   613,   457,   458,   685,   459,   687,   460,   461,
     740,   797,   803,   804,   810,   618,   689,    19,    43,    54,
      63,   148,   282,    84,    85,    86,    87,   283,   462,   120,
     121,   122,   123,    35,   302
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       2,    32,    32,    34,    32,    32,    32,    32,    95,    89,
     328,    83,    31,    33,    95,    36,    37,    38,    39,   456,
      89,   153,   190,   329,   644,   413,    96,   391,   591,   167,
     339,   144,    96,    32,    82,    44,   426,    95,   542,   144,
     636,    88,   210,   278,    64,    82,    32,   330,   380,   531,
     467,   468,    88,   200,   268,    96,   293,   149,   269,   497,
     372,   536,   538,   280,   521,   527,   528,   529,   530,   309,
     311,   663,   370,   690,   523,   523,   523,   523,   523,   667,
     581,   582,   584,   585,   586,   392,   583,   363,   109,  -259,
     339,   326,   595,   313,   144,   144,    40,   597,    95,   525,
     525,   525,   525,   525,   298,   299,    20,   446,   324,    21,
     701,  -259,  -259,   294,   144,    22,    96,   291,   334,    52,
     600,   600,   600,   352,   417,  -192,   451,   249,    32,  -192,
     355,   439,   639,   513,    53,   210,   210,   211,   211,    64,
     325,   440,   439,   360,   439,    23,   418,   414,   715,   439,
     439,   439,   440,   452,   440,   419,   453,   454,  -350,   440,
     440,   440,   455,    41,    27,   426,    27,   514,    24,    28,
     373,    29,  -350,    29,    42,    30,   336,    30,   291,   328,
     328,   328,   227,  -303,   505,   298,   364,  -303,   328,   328,
     399,   506,   474,   475,   476,   278,   278,   416,   690,   690,
    -349,   477,   478,   561,   406,   503,    25,   395,    93,    94,
     756,   278,   497,   497,  -349,  -294,   330,   330,   330,  -294,
     524,   524,   524,   524,   524,   330,   330,   535,   535,   340,
     644,    95,   522,   522,   522,   522,   522,   428,    89,    89,
     445,   190,   668,   434,   392,   298,   415,   663,   167,    96,
      95,   311,   604,    26,   144,   667,    45,   448,    46,   551,
     407,   210,   278,    82,    82,  -260,   552,    47,    96,    48,
      88,    88,   200,   268,   715,   591,   144,   269,   438,   249,
     249,    32,    49,   144,   144,   144,   392,  -260,  -260,   340,
    -126,   298,   144,   144,   695,  -127,    55,    93,    94,  -190,
     361,   481,   352,  -190,   706,    66,   485,   516,   442,   501,
      61,   437,  -126,  -126,   294,   210,   502,  -127,  -127,   449,
      60,   450,   548,   549,   550,    62,   466,   466,   466,   541,
     210,   210,   210,   210,   210,   389,   210,   537,   537,   595,
     709,    65,   210,  -183,   597,  -192,   249,   284,   485,  -192,
     807,   210,   210,   210,    67,   278,   211,   211,   503,   503,
     325,   543,    68,   670,   391,   544,   428,   691,    69,   643,
     703,   704,   714,    70,   278,   278,   278,   278,   278,   278,
     278,   -88,   361,   395,    89,   -88,  -305,   278,   576,   576,
    -305,   428,   428,   428,   428,   428,   589,   278,   146,   380,
     295,   227,   339,   278,   296,   278,   278,   278,   147,    82,
      27,   -27,   -27,   309,  -193,   543,    88,    29,  -193,   598,
     285,    30,   497,   563,   564,   565,   566,   567,   568,   569,
     763,   286,    32,   289,   -27,   -27,   392,   532,   144,   249,
     523,   339,   392,   300,    27,   547,   413,   780,   533,   781,
    -129,    29,   592,   649,   287,    30,   619,    27,   514,    93,
      94,   163,   501,   501,    29,   525,   651,   439,    30,   502,
     502,   249,  -129,  -129,   578,   288,    27,   440,    93,    94,
     642,   249,   210,    29,   -89,   655,    27,    30,   -89,   249,
     249,   249,  -191,    29,   389,   654,  -191,    30,   -88,   547,
     497,   503,   -88,   290,     3,    27,   535,   210,   210,   503,
      28,   503,    29,  -194,   210,   802,    30,  -194,   -29,   -29,
     441,  -190,   761,   553,   725,  -190,   570,   278,   303,   559,
     304,   441,   802,   441,   670,   124,   590,   314,   441,   441,
     441,   -29,   -29,   395,   395,   307,   278,   278,   305,   127,
     575,   577,     4,   278,     5,     6,   128,   328,     7,     8,
       9,    10,    27,   514,   601,   602,   503,   306,   503,    29,
     744,   503,   -90,    30,   503,   643,   -90,   315,    27,    92,
      93,    94,   325,    78,   335,    29,   524,    79,    80,    30,
     774,   775,   327,    81,   330,    34,   686,   688,   522,   332,
    -349,   340,   481,    51,   485,   501,   354,    56,    57,    58,
      59,   249,   502,   501,   485,   501,   537,   353,   357,   189,
     502,   503,   502,   356,   366,   374,   112,   112,   377,   375,
     249,   249,   159,   203,   270,   112,  -352,   249,  -357,   378,
     340,    95,   401,   409,   466,   278,   503,   379,   398,   589,
     278,   637,   402,   421,   411,   112,   112,   400,   503,    96,
     420,   144,   422,    32,   429,   431,   436,   651,   432,   503,
     501,   433,   501,   435,   469,   501,   295,   502,   501,   502,
      81,   447,   502,   463,   741,   502,   673,   470,   210,   125,
     112,   112,   590,   471,   472,   473,   210,   504,   508,   592,
     486,   487,   510,   507,   278,   509,   533,   511,   519,   520,
     112,   342,   553,   189,   395,   540,   159,   554,   572,   555,
      32,   620,   556,   557,   614,   501,   348,   203,   387,   249,
     562,   772,   502,   488,   210,   615,   210,   603,   696,   295,
     605,   317,   606,   296,   278,   278,   723,   367,   318,   319,
     501,   320,   724,   607,   608,   609,   278,   502,    89,   610,
     814,   348,   501,   128,   321,   322,   388,   611,   616,   502,
     617,    27,   621,   501,    94,   622,   623,    32,    29,   624,
     502,   626,    30,    82,   731,   627,    81,   270,   249,   628,
      88,   165,   630,   697,    32,   629,   631,   632,   639,   640,
     652,   705,   811,   707,  -210,   641,   409,   409,   409,   409,
     409,   409,   409,   653,   671,   657,   408,   411,   411,   411,
     411,   411,   411,   411,   656,   658,   659,   660,   249,   249,
     672,   418,   675,   674,   676,   409,   404,   -45,   189,   677,
     249,   195,   425,   767,   678,   679,   411,   680,   681,   112,
     112,   112,   203,   270,   682,   512,   441,   112,   746,   683,
     513,    71,   112,   748,   112,   197,   749,   692,   112,   112,
     112,   112,   112,   694,   698,   699,   711,   713,   700,   112,
     112,   112,   702,   784,   785,   361,   710,   712,   112,   112,
     720,   721,   189,    27,   514,   731,   726,   722,   735,   753,
      29,   727,   728,   729,    30,   734,   348,   526,   526,   526,
     526,   526,   739,   707,   526,   526,   539,   742,   517,   189,
     743,   348,   348,   348,   348,   348,   750,   348,   348,   348,
     751,   752,   760,   348,   195,   195,   761,   764,   791,   336,
     351,   517,   348,   348,   348,   771,   113,   113,   773,   776,
     637,  -182,   113,   204,   778,   113,   779,   782,   197,   197,
     783,   637,   786,   517,   787,   -26,   -26,   793,   558,   195,
     795,   425,   796,   559,   809,   113,   113,   701,   805,   408,
     408,   408,   408,   408,   408,   408,   488,   812,   -26,   -26,
    -109,   799,   806,   197,   808,   517,   580,   580,   580,   580,
     580,   813,   219,   444,   488,   736,    27,   514,   593,   489,
     113,   113,  -109,    29,   733,   224,   766,    30,   794,   443,
     737,  -109,   371,   755,    27,   717,   792,    94,   490,   789,
     113,    29,   635,   747,   112,    30,   113,   777,   800,    81,
     765,   745,    27,   754,   312,    94,   204,   204,   693,    29,
     479,   464,   625,    30,   762,   430,   738,    81,   124,   798,
     195,   331,   815,   125,   684,     0,     0,     0,   126,     0,
     348,     0,   127,   348,     0,     0,     0,   517,   517,   128,
       0,   204,   409,     0,   197,   189,     0,     0,     0,     0,
       0,     0,     0,   411,     0,     0,     0,     0,   348,   348,
       0,    27,    92,    93,    94,   348,    78,     0,    29,     0,
      79,    80,    30,     0,   195,     0,    81,     0,     0,     0,
       0,     0,     0,   517,   517,     0,   316,     0,     0,   195,
     195,   195,   195,   195,     0,   195,     0,     0,   197,   317,
       0,   195,     0,     0,     0,     0,   318,   319,     0,   320,
     195,   195,   195,   197,   197,   197,   197,   197,     0,   197,
       0,     0,   321,   322,   323,   197,     0,     0,     0,   113,
     113,   113,   204,     0,   197,   197,   197,   113,     0,     0,
       0,     0,   113,     0,   113,   451,     0,   112,   113,   113,
     113,   113,   113,   526,     0,     0,     0,     0,   801,   113,
     113,   113,     0,   719,     0,     0,     0,   348,   113,   113,
       0,     0,   452,     0,     0,   453,   454,   348,     0,     0,
       0,   455,     0,    27,     0,     0,   204,     0,    28,     0,
      29,     0,     0,     0,    30,     0,     0,     0,   518,     0,
       0,   204,   204,   204,   204,   204,   124,   204,   204,   204,
     160,   367,     0,   204,     0,   593,   368,   112,     0,   112,
     127,   518,   204,   204,   204,   759,     0,   128,     0,     0,
       0,     0,     0,   526,   163,     0,   348,     0,   517,   348,
       0,   195,     0,   518,     0,     0,     0,   348,     0,    27,
       0,    93,    94,   164,   517,   165,    29,     0,     0,     0,
      30,     0,     0,     0,    81,   197,   195,   195,     0,     0,
       0,     0,     0,   195,   124,   518,     0,     0,   160,   161,
       0,     0,     0,     0,   341,   348,     0,   348,   127,   719,
     197,   197,   343,     0,     0,   128,     0,   197,     0,     0,
       0,     0,   163,   348,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   113,     0,     0,    27,    92,    93,
      94,   164,    78,   165,    29,     0,    79,    80,    30,     0,
       0,     0,    81,     0,     0,     0,     0,   114,   114,     0,
       0,     0,     0,   114,   205,   272,   114,     0,     0,     0,
     204,     0,     0,   204,     0,     0,     0,   518,   518,   212,
     213,     0,   214,   215,   216,   217,   114,   114,     0,     0,
     403,     0,   124,   404,   218,   219,   571,   572,   204,   204,
       0,     0,   579,   317,     0,   204,   127,   223,   224,     0,
     318,   319,     0,   320,     0,     0,     0,     0,     0,     0,
     225,   114,   114,   518,   518,     0,   321,   322,   405,     0,
       0,     0,     0,     0,     0,    27,    92,    93,    94,   164,
      78,   114,    29,     0,    79,    80,    30,   114,     0,     0,
      81,     0,     0,     0,   115,   115,     0,   349,   349,   358,
     115,   206,     0,   115,     0,     0,     0,   195,     0,     0,
       0,     0,   317,     0,     0,   195,     0,     0,     0,   318,
     319,     0,   320,   115,   115,     0,     0,   113,     0,     0,
       0,   197,   349,     0,     0,   321,   322,   359,     0,   197,
       0,     0,     0,     0,     0,   212,   213,   204,   214,     0,
       0,     0,     0,   195,     0,   195,     0,   204,   115,   115,
     218,     0,   571,   572,     0,     0,     0,     0,   661,     0,
       0,     0,     0,   223,     0,     0,     0,   197,   115,   197,
       0,     0,     0,     0,   115,     0,   225,     0,     0,     0,
       0,     0,     0,     0,   206,   206,     0,   113,     0,   113,
       0,    27,    92,    93,    94,   642,    78,     0,    29,     0,
      79,    80,    30,     0,     0,     0,   204,     0,   518,   204,
     114,   114,   114,   205,   272,     0,   150,   204,   114,   206,
       0,     0,     0,   114,   518,   114,   151,     0,     0,   114,
     114,   114,   114,   114,     0,     0,     0,    91,     0,     0,
     114,   114,   114,     0,     0,     0,     0,     0,     0,   114,
     114,     0,     0,     0,     0,   204,     0,   204,     0,    27,
     152,    93,    94,     0,    78,     0,    29,   349,    79,    80,
      30,     0,     0,   204,    81,     0,     0,     0,     0,     0,
       0,     0,   349,   349,   349,   349,   349,     0,   349,   349,
     349,     0,     0,     0,   349,     0,     0,     0,     0,     0,
       0,     0,   545,   349,   349,   349,     0,   115,   115,   115,
     206,     0,     0,     0,     0,   115,     0,     0,     0,     0,
     115,     0,   115,     0,     0,     0,   115,   115,   115,   115,
     115,     0,     0,     0,     0,     0,     0,   115,   115,   115,
       0,     0,     0,     0,     0,     0,   115,   115,   212,   213,
       0,   214,   410,     0,     0,     0,   545,     0,     0,     0,
       0,     0,     0,   218,   206,   571,   572,     0,     0,     0,
       0,   573,     0,     0,     0,     0,   223,     0,   427,   206,
     206,   206,   206,   206,     0,   206,   206,   206,     0,   225,
       0,   206,     0,     0,     0,   114,     0,     0,     0,   546,
     206,   206,   206,     0,    27,    92,    93,    94,     0,    78,
       0,    29,     0,    79,    80,    30,     0,     0,     0,    81,
     212,   213,     0,   214,   215,   216,   217,     0,     0,     0,
       0,   349,     0,   124,   349,   218,   219,   220,   221,     0,
       0,     0,     0,   381,     0,     0,   342,   127,   223,   224,
       0,   382,     0,   546,   128,     0,     0,     0,     0,   349,
     349,   225,     0,     0,     0,     0,   349,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,    92,    93,    94,
     164,    78,   165,    29,     0,    79,    80,    30,     0,     0,
       0,    81,   115,     0,     0,     0,     0,   116,   116,     0,
       0,     0,     0,   116,   207,     0,   116,   427,     0,     0,
       0,     0,     0,     0,     0,   410,   410,   410,   410,   410,
     410,   410,     0,     0,     0,     0,   116,   116,   206,   574,
     574,   206,   427,   427,   427,   427,   427,     0,     0,     0,
      90,     0,     0,     0,   410,     0,     0,     0,   114,     0,
       0,    91,     0,     0,     0,     0,   206,   206,     0,     0,
       0,   116,   116,   206,   219,     0,   488,     0,   349,     0,
       0,   788,     0,    27,    92,    93,    94,   224,    78,     0,
      29,   116,    79,    80,    30,     0,     0,   116,    81,     0,
       0,     0,     0,     0,   117,   117,     0,   207,   207,     0,
     117,   208,     0,   117,    27,     0,     0,    94,     0,     0,
       0,    29,     0,     0,     0,    30,     0,     0,   114,    81,
     114,     0,     0,   117,   117,     0,     0,     0,     0,   124,
       0,     0,   207,     0,     0,     0,     0,   349,     0,   307,
     349,     0,     0,   127,     0,   115,     0,   308,   349,     0,
     128,     0,     0,     0,     0,     0,     0,     0,   117,   117,
       0,     0,     0,   292,     0,   206,   662,     0,     0,     0,
       0,     0,    27,    92,    93,    94,     0,    78,   117,    29,
       0,    79,    80,    30,   117,     0,   349,    81,   349,     0,
       0,     0,     0,     0,   208,   208,    27,    92,    93,    94,
       0,    78,     0,    29,     0,    79,    80,    30,     0,     0,
       0,    81,     0,     0,     0,   115,     0,   115,     0,     0,
     116,   116,   116,   207,     0,     0,   150,     0,   116,   208,
       0,     0,     0,   116,   206,   116,    90,   206,     0,   116,
     116,   116,   116,   116,     0,   206,     0,    91,     0,     0,
     116,   116,   116,     0,     0,     0,     0,     0,     0,   116,
     116,     0,     0,     0,     0,     0,     0,     0,     0,    27,
      92,    93,    94,     0,    78,     0,    29,   207,    79,    80,
      30,     0,     0,   206,    81,   206,     0,     0,     0,     0,
       0,   410,   207,   207,   207,   207,   207,     0,   207,   207,
     207,     0,     0,     0,   207,     0,     0,     0,     0,     0,
       0,     0,     0,   207,   207,   207,     0,   117,   117,   117,
     208,     0,     0,     0,     0,   117,     0,     0,     0,     0,
     117,     0,   117,     0,     0,     0,   117,   117,   117,   117,
     117,     0,   662,     0,     0,     0,     0,   117,   117,   117,
       0,     0,     0,     0,     0,     0,   117,   117,     0,     0,
       0,     0,     0,     0,     0,   145,     0,     0,     0,     0,
       0,   199,     0,   145,   208,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   208,
     208,   208,   208,   208,     0,   208,   208,   208,     0,     0,
       0,   208,     0,     0,     0,   116,     0,     0,     0,   124,
     208,   208,   208,   160,   161,     0,     0,     0,     0,   341,
       0,     0,   342,   127,     0,     0,     0,   343,   145,   145,
     128,     0,     0,     0,     0,     0,     0,   163,     0,     0,
       0,   207,     0,     0,   207,     0,     0,     0,   145,     0,
       0,     0,    27,    92,    93,    94,   164,    78,   165,    29,
       0,    79,    80,    30,   199,   199,     0,    81,     0,   207,
     207,     0,     0,     0,     0,   124,   207,     0,     0,   160,
     161,     0,     0,     0,     0,   162,     0,     0,   351,   127,
       0,     0,     0,     0,     0,     0,   128,     0,     0,   199,
       0,     0,   117,   163,     0,     0,     0,   118,   118,     0,
       0,   532,   533,   118,   209,     0,   118,   534,    27,   152,
      93,    94,   164,    78,   165,    29,     0,    79,    80,    30,
       0,     0,     0,    81,     0,   163,   118,   118,   208,     0,
       0,   208,     0,     0,     0,     0,     0,     0,     0,     0,
      27,    92,    93,    94,     0,    78,     0,    29,   116,    79,
      80,    30,     0,     0,     0,    81,   208,   208,     0,     0,
       0,   118,   118,   208,    27,    92,    93,    94,   207,    78,
       0,    29,     0,    79,    80,    30,     0,     0,   145,    81,
     199,   118,     0,     0,     0,     0,     0,   118,   151,     0,
       0,     0,     0,     0,     0,     0,     0,   350,   209,    91,
     145,     0,     0,     0,     0,     0,     0,   145,   145,   145,
       0,     0,     0,     0,     0,     0,   145,   145,   116,     0,
     116,    27,   152,    93,    94,     0,    78,     0,    29,     0,
      79,    80,    30,     0,   199,     0,    81,   207,     0,     0,
     207,     0,     0,     0,     0,   117,     0,     0,   207,   199,
     199,   199,   199,   199,   124,   199,     0,     0,   160,   161,
       0,   199,     0,     0,   341,   208,     0,   351,   127,     0,
     199,   199,   199,     0,     0,   128,     0,     0,     0,     0,
       0,     0,   163,     0,     0,     0,   207,     0,   207,     0,
       0,     0,     0,     0,     0,     0,     0,    27,    92,    93,
      94,   164,    78,   165,    29,     0,    79,    80,    30,     0,
       0,     0,    81,     0,     0,   117,     0,   117,     0,     0,
     118,   118,   118,   209,     0,     0,     0,     0,   118,     0,
       0,     0,     0,   118,   208,   118,     0,   208,     0,   118,
     118,   118,   118,   118,     0,   208,     0,    91,     0,     0,
     118,   118,   118,     0,     0,     0,     0,     0,     0,   118,
     118,     0,   145,     0,     0,     0,     0,     0,     0,    27,
      92,    93,    94,     0,    78,     0,    29,   209,    79,    80,
      30,     0,     0,   208,    81,   208,     0,     0,     0,     0,
       0,     0,   209,   209,   209,   209,   209,     0,   350,   209,
     209,   199,     0,     0,   209,     0,     0,     0,     0,     0,
       0,     0,     0,   350,   350,   350,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   199,   199,     0,     0,
     387,   212,   213,   199,   214,   215,   216,   217,     0,     0,
       0,   295,     0,   317,   124,   296,   218,   219,   220,   221,
     318,   319,     0,   320,   222,     0,     0,   351,   127,   223,
     224,    71,     0,     0,     0,   128,   321,   322,   388,     0,
       0,     0,   225,     0,   281,     0,     0,     0,     0,     0,
       0,    72,    73,    74,     0,    75,    76,    27,   152,    93,
      94,   164,    78,   165,    29,     0,    79,    80,    30,    27,
      77,     0,    81,     0,    78,   118,    29,     0,    79,    80,
      30,     0,     0,     0,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   387,   212,   213,     0,
     214,   215,   216,   217,   350,     0,     0,   295,     0,   317,
     124,   296,   218,   219,   220,   221,   318,   319,     0,   320,
     381,     0,     0,   351,   127,   223,   224,     0,     0,   350,
     209,   128,   321,   322,   388,     0,   350,     0,   225,     0,
       0,     0,     0,     0,     0,   145,     0,     0,     0,     0,
       0,     0,     0,    27,    92,    93,    94,   164,    78,   165,
      29,     0,    79,    80,    30,     0,     0,   199,    81,     0,
       0,     0,     0,     0,     0,   199,   124,     0,     0,     0,
     160,   161,     0,     0,     0,     0,   162,     0,     0,     0,
     127,     0,     0,     0,     0,     0,     0,   128,     0,     0,
       0,     0,     0,     0,   163,     0,     0,     0,     0,     0,
       0,     0,     0,   199,     0,   199,     0,     0,   118,    27,
     152,    93,    94,   164,    78,   165,    29,     0,    79,    80,
      30,     0,     0,     0,    81,   387,   212,   213,   209,   214,
     215,   216,   217,     0,     0,     0,   295,     0,   317,   124,
     296,   218,   219,   220,   221,   318,   319,     0,   320,   381,
       0,     0,     0,   127,   223,   224,     0,     0,     0,     0,
     128,   321,   322,   388,     0,     0,     0,   225,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   118,     0,
     118,     0,    27,    92,    93,    94,   164,    78,   165,    29,
       0,    79,    80,    30,     0,     0,     0,    81,   212,   213,
     350,   214,   215,   216,   217,     0,     0,     0,   209,     0,
       0,   124,     0,   218,   219,   220,   221,     0,     0,     0,
       0,   381,     0,     0,     0,   127,   223,   224,     0,   382,
       0,     0,   128,     0,     0,     0,     0,     0,     0,   225,
       0,     0,     0,     0,     0,     0,   350,     0,   350,     0,
       0,     0,     0,     0,    27,    92,    93,    94,   164,    78,
     165,    29,     0,    79,    80,    30,     0,   212,   213,    81,
     214,   215,   216,   217,     0,     0,     0,     0,     0,     0,
     124,     0,   218,   219,   220,   221,     0,     0,     0,     0,
     222,     0,     0,     0,   127,   223,   224,     0,     0,     0,
       0,   128,     0,     0,     0,     0,     0,     0,   225,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,   152,    93,    94,   164,    78,   165,
      29,     0,    79,    80,    30,     0,   212,   213,    81,   214,
     215,   216,   217,     0,     0,     0,     0,     0,     0,   124,
       0,   218,   219,   220,   221,     0,     0,     0,     0,   381,
       0,     0,     0,   127,   223,   224,     0,     0,     0,     0,
     128,     0,     0,     0,     0,     0,     0,   225,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,    92,    93,    94,   164,    78,   165,    29,
       0,    79,    80,    30,     0,   212,   213,    81,   214,   215,
     216,   217,     0,     0,     0,     0,     0,     0,   124,     0,
     218,   219,   220,   221,     0,     0,     0,     0,   423,     0,
       0,     0,   127,   223,   224,     0,     0,     0,     0,   128,
       0,     0,     0,     0,     0,     0,   225,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,    92,    93,    94,   164,    78,   165,    29,     0,
      79,    80,    30,     0,   212,   213,    81,   214,   215,   216,
     217,     0,     0,     0,     0,     0,     0,   124,     0,   218,
     219,   220,   730,     0,     0,     0,     0,   381,     0,     0,
       0,   127,   223,   224,     0,     0,     0,     0,   128,     0,
       0,     0,     0,     0,     0,   225,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,    92,    93,    94,   164,    78,   165,    29,   124,    79,
      80,    30,   160,   161,     0,    81,     0,     0,   341,     0,
       0,     0,   127,     0,     0,    71,     0,     0,     0,   128,
       0,     0,     0,     0,     0,     0,   163,     0,     0,     0,
       0,     0,     0,     0,     0,    72,    73,    74,     0,    75,
      76,    27,    92,    93,    94,   164,    78,   165,    29,     0,
      79,    80,    30,    27,    77,     0,    81,     0,    78,     0,
      29,     0,    79,    80,    30,     0,     0,     0,    81
};

static const yytype_int16 yycheck[] =
{
       0,    20,    21,    22,    23,    24,    25,    26,    61,    60,
     145,    60,    20,    21,    67,    23,    24,    25,    26,   300,
      71,    67,    68,   145,   505,   241,    61,   222,   429,    68,
     160,    62,    67,    52,    60,    35,   263,    90,   374,    70,
     489,    60,    68,    69,    52,    71,    65,   145,   220,   362,
     305,   306,    71,    68,    69,    90,    91,    65,    69,   335,
     196,   363,   364,    70,   356,   357,   358,   359,   360,   125,
     126,   551,   196,   617,   356,   357,   358,   359,   360,   551,
     417,   418,   419,   420,   421,   222,   418,   188,    61,    13,
     220,   143,   429,   129,   125,   126,    13,   429,   151,   356,
     357,   358,   359,   360,   107,   107,    27,   290,   138,    27,
      37,    35,    36,    91,   145,    27,   151,    90,   154,    22,
     431,   432,   433,   162,    37,    14,    22,    69,   147,    18,
     166,   286,    59,    27,    37,   161,   162,    68,    69,   147,
      29,   286,   297,   173,   299,    27,    59,   248,   652,   304,
     305,   306,   297,    49,   299,    68,    52,    53,    11,   304,
     305,   306,    58,    13,    60,   392,    60,    61,    27,    65,
     196,    67,    25,    67,    13,    71,    30,    71,   151,   314,
     315,   316,    69,    14,    27,   188,   188,    18,   323,   324,
     226,    34,   314,   315,   316,   221,   222,   249,   742,   743,
      11,   323,   324,   398,   234,   335,    27,   222,    62,    63,
     714,   237,   488,   489,    25,    14,   314,   315,   316,    18,
     356,   357,   358,   359,   360,   323,   324,   363,   364,   160,
     711,   284,   356,   357,   358,   359,   360,   263,   289,   290,
     289,   287,   553,   279,   381,   248,   248,   727,   287,   284,
     303,   307,   435,    27,   285,   727,    13,   292,    13,    27,
     237,   287,   288,   289,   290,    13,    34,    13,   303,    13,
     289,   290,   287,   288,   778,   676,   307,   288,   285,   221,
     222,   300,    67,   314,   315,   316,   423,    35,    36,   220,
      13,   294,   323,   324,   630,    13,    36,    62,    63,    14,
      15,   327,   341,    18,   640,    30,   332,   353,   286,   335,
      13,   284,    35,    36,   292,   341,   335,    35,    36,   297,
      28,   299,   377,   378,   379,    13,   304,   305,   306,   368,
     356,   357,   358,   359,   360,   222,   362,   363,   364,   676,
     642,    13,   368,    12,   676,    14,   288,    27,   374,    18,
     799,   377,   378,   379,    13,   381,   287,   288,   488,   489,
      29,   376,    13,   558,   559,   376,   392,   622,    13,   505,
      36,    37,    22,    13,   400,   401,   402,   403,   404,   405,
     406,    14,    15,   398,   435,    18,    14,   413,   414,   415,
      18,   417,   418,   419,   420,   421,   422,   423,    35,   571,
      14,   288,   532,   429,    18,   431,   432,   433,    13,   435,
      60,    12,    13,   469,    14,   430,   435,    67,    18,   430,
      27,    71,   698,   400,   401,   402,   403,   404,   405,   406,
     722,    27,   451,    11,    35,    36,   573,    21,   469,   381,
     722,   571,   579,    13,    60,   376,   662,   760,    22,   762,
      13,    67,   429,   508,    27,    71,   456,    60,    61,    62,
      63,    45,   488,   489,    67,   722,   512,   622,    71,   488,
     489,   413,    35,    36,   416,    27,    60,   622,    62,    63,
      64,   423,   508,    67,    14,   540,    60,    71,    18,   431,
     432,   433,    14,    67,   381,   534,    18,    71,    14,   430,
     776,   631,    18,    27,     0,    60,   642,   533,   534,   639,
      65,   641,    67,    14,   540,   796,    71,    18,    12,    13,
     286,    14,    12,    13,   661,    18,   413,   553,    41,    27,
      27,   297,   813,   299,   729,    17,   423,    41,   304,   305,
     306,    35,    36,   558,   559,    27,   572,   573,    27,    31,
     414,   415,    48,   579,    50,    51,    38,   692,    54,    55,
      56,    57,    60,    61,   432,   433,   696,    27,   698,    67,
     692,   701,    14,    71,   704,   711,    18,     3,    60,    61,
      62,    63,    29,    65,    11,    67,   722,    69,    70,    71,
     742,   743,    22,    75,   692,   614,   615,   616,   722,    22,
      11,   532,   628,    41,   630,   631,    30,    45,    46,    47,
      48,   553,   631,   639,   640,   641,   642,    27,     3,    68,
     639,   751,   641,    41,     6,    22,    61,    62,    27,    25,
     572,   573,    67,    68,    69,    70,    25,   579,    25,    27,
     571,   694,     3,   237,   622,   671,   776,    27,    27,   675,
     676,   489,     6,    68,   237,    90,    91,    41,   788,   694,
      37,   692,    22,   682,    11,    27,    35,   713,    27,   799,
     696,    27,   698,    13,    13,   701,    14,   696,   704,   698,
      75,    36,   701,    36,   684,   704,   573,    35,   714,    22,
     125,   126,   579,    36,    36,    36,   722,    34,    13,   676,
      36,    36,    36,    35,   730,    35,    22,    36,    59,    36,
     145,    30,    13,   162,   729,    27,   151,    35,    22,    36,
     739,    30,    36,    36,    27,   751,   161,   162,     3,   671,
      36,   739,   751,    22,   760,    27,   762,    36,    27,    14,
      36,    16,    36,    18,   770,   771,    21,    22,    23,    24,
     776,    26,    27,    36,    36,    36,   782,   776,   809,    36,
     809,   196,   788,    38,    39,    40,    41,    36,    27,   788,
      13,    60,    36,   799,    63,    13,    36,   796,    67,    36,
     799,    30,    71,   809,   671,    35,    75,   222,   730,    13,
     809,    66,    13,   631,   813,    35,    11,    30,    59,    22,
      13,   639,   802,   641,    59,    27,   400,   401,   402,   403,
     404,   405,   406,    30,    13,    35,   237,   400,   401,   402,
     403,   404,   405,   406,    36,    36,    36,    36,   770,   771,
      30,    59,    13,    35,    11,   429,     6,     6,   287,    36,
     782,    68,   263,   730,    36,    36,   429,    36,    30,   284,
     285,   286,   287,   288,    13,    22,   622,   292,   696,    35,
      27,    22,   297,   701,   299,    68,   704,    11,   303,   304,
     305,   306,   307,    11,    13,    35,    13,    13,    36,   314,
     315,   316,    36,   770,   771,    15,    36,    35,   323,   324,
      36,    36,   341,    60,    61,   782,    36,    11,    11,    34,
      67,    13,    35,    13,    71,    36,   341,   356,   357,   358,
     359,   360,    13,   751,   363,   364,   365,    13,   353,   368,
      13,   356,   357,   358,   359,   360,    35,   362,   363,   364,
      13,    36,    13,   368,   161,   162,    12,    34,   776,    30,
      30,   376,   377,   378,   379,    13,    61,    62,    36,    11,
     788,    12,    67,    68,    13,    70,    35,    13,   161,   162,
      35,   799,    13,   398,    13,    12,    13,    36,    22,   196,
      36,   392,    22,    27,    11,    90,    91,    37,    36,   400,
     401,   402,   403,   404,   405,   406,    22,    35,    35,    36,
      37,    27,    36,   196,    36,   430,   417,   418,   419,   420,
     421,    13,    20,   288,    22,   675,    60,    61,   429,    27,
     125,   126,    59,    67,   671,    33,   729,    71,   782,   287,
     676,    68,   196,   713,    60,   652,   778,    63,   335,   776,
     145,    67,   489,   698,   469,    71,   151,   751,   788,    75,
     727,   694,    60,   711,   126,    63,   161,   162,   628,    67,
     326,   303,   469,    71,   718,   269,   682,    75,    17,   787,
     287,   147,   813,    22,   614,    -1,    -1,    -1,    27,    -1,
     505,    -1,    31,   508,    -1,    -1,    -1,   512,   513,    38,
      -1,   196,   676,    -1,   287,   534,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   676,    -1,    -1,    -1,    -1,   533,   534,
      -1,    60,    61,    62,    63,   540,    65,    -1,    67,    -1,
      69,    70,    71,    -1,   341,    -1,    75,    -1,    -1,    -1,
      -1,    -1,    -1,   558,   559,    -1,     3,    -1,    -1,   356,
     357,   358,   359,   360,    -1,   362,    -1,    -1,   341,    16,
      -1,   368,    -1,    -1,    -1,    -1,    23,    24,    -1,    26,
     377,   378,   379,   356,   357,   358,   359,   360,    -1,   362,
      -1,    -1,    39,    40,    41,   368,    -1,    -1,    -1,   284,
     285,   286,   287,    -1,   377,   378,   379,   292,    -1,    -1,
      -1,    -1,   297,    -1,   299,    22,    -1,   622,   303,   304,
     305,   306,   307,   642,    -1,    -1,    -1,    -1,    35,   314,
     315,   316,    -1,   652,    -1,    -1,    -1,   642,   323,   324,
      -1,    -1,    49,    -1,    -1,    52,    53,   652,    -1,    -1,
      -1,    58,    -1,    60,    -1,    -1,   341,    -1,    65,    -1,
      67,    -1,    -1,    -1,    71,    -1,    -1,    -1,   353,    -1,
      -1,   356,   357,   358,   359,   360,    17,   362,   363,   364,
      21,    22,    -1,   368,    -1,   676,    27,   692,    -1,   694,
      31,   376,   377,   378,   379,   714,    -1,    38,    -1,    -1,
      -1,    -1,    -1,   722,    45,    -1,   711,    -1,   713,   714,
      -1,   508,    -1,   398,    -1,    -1,    -1,   722,    -1,    60,
      -1,    62,    63,    64,   729,    66,    67,    -1,    -1,    -1,
      71,    -1,    -1,    -1,    75,   508,   533,   534,    -1,    -1,
      -1,    -1,    -1,   540,    17,   430,    -1,    -1,    21,    22,
      -1,    -1,    -1,    -1,    27,   760,    -1,   762,    31,   778,
     533,   534,    35,    -1,    -1,    38,    -1,   540,    -1,    -1,
      -1,    -1,    45,   778,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   469,    -1,    -1,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    -1,
      -1,    -1,    75,    -1,    -1,    -1,    -1,    61,    62,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    -1,    -1,    -1,
     505,    -1,    -1,   508,    -1,    -1,    -1,   512,   513,     4,
       5,    -1,     7,     8,     9,    10,    90,    91,    -1,    -1,
       3,    -1,    17,     6,    19,    20,    21,    22,   533,   534,
      -1,    -1,    27,    16,    -1,   540,    31,    32,    33,    -1,
      23,    24,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      45,   125,   126,   558,   559,    -1,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    62,    63,    64,
      65,   145,    67,    -1,    69,    70,    71,   151,    -1,    -1,
      75,    -1,    -1,    -1,    61,    62,    -1,   161,   162,     3,
      67,    68,    -1,    70,    -1,    -1,    -1,   714,    -1,    -1,
      -1,    -1,    16,    -1,    -1,   722,    -1,    -1,    -1,    23,
      24,    -1,    26,    90,    91,    -1,    -1,   622,    -1,    -1,
      -1,   714,   196,    -1,    -1,    39,    40,    41,    -1,   722,
      -1,    -1,    -1,    -1,    -1,     4,     5,   642,     7,    -1,
      -1,    -1,    -1,   760,    -1,   762,    -1,   652,   125,   126,
      19,    -1,    21,    22,    -1,    -1,    -1,    -1,    27,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,   760,   145,   762,
      -1,    -1,    -1,    -1,   151,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   161,   162,    -1,   692,    -1,   694,
      -1,    60,    61,    62,    63,    64,    65,    -1,    67,    -1,
      69,    70,    71,    -1,    -1,    -1,   711,    -1,   713,   714,
     284,   285,   286,   287,   288,    -1,    17,   722,   292,   196,
      -1,    -1,    -1,   297,   729,   299,    27,    -1,    -1,   303,
     304,   305,   306,   307,    -1,    -1,    -1,    38,    -1,    -1,
     314,   315,   316,    -1,    -1,    -1,    -1,    -1,    -1,   323,
     324,    -1,    -1,    -1,    -1,   760,    -1,   762,    -1,    60,
      61,    62,    63,    -1,    65,    -1,    67,   341,    69,    70,
      71,    -1,    -1,   778,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   356,   357,   358,   359,   360,    -1,   362,   363,
     364,    -1,    -1,    -1,   368,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   376,   377,   378,   379,    -1,   284,   285,   286,
     287,    -1,    -1,    -1,    -1,   292,    -1,    -1,    -1,    -1,
     297,    -1,   299,    -1,    -1,    -1,   303,   304,   305,   306,
     307,    -1,    -1,    -1,    -1,    -1,    -1,   314,   315,   316,
      -1,    -1,    -1,    -1,    -1,    -1,   323,   324,     4,     5,
      -1,     7,   237,    -1,    -1,    -1,   430,    -1,    -1,    -1,
      -1,    -1,    -1,    19,   341,    21,    22,    -1,    -1,    -1,
      -1,    27,    -1,    -1,    -1,    -1,    32,    -1,   263,   356,
     357,   358,   359,   360,    -1,   362,   363,   364,    -1,    45,
      -1,   368,    -1,    -1,    -1,   469,    -1,    -1,    -1,   376,
     377,   378,   379,    -1,    60,    61,    62,    63,    -1,    65,
      -1,    67,    -1,    69,    70,    71,    -1,    -1,    -1,    75,
       4,     5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,   505,    -1,    17,   508,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    27,    -1,    -1,    30,    31,    32,    33,
      -1,    35,    -1,   430,    38,    -1,    -1,    -1,    -1,   533,
     534,    45,    -1,    -1,    -1,    -1,   540,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    -1,    -1,
      -1,    75,   469,    -1,    -1,    -1,    -1,    61,    62,    -1,
      -1,    -1,    -1,    67,    68,    -1,    70,   392,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   400,   401,   402,   403,   404,
     405,   406,    -1,    -1,    -1,    -1,    90,    91,   505,   414,
     415,   508,   417,   418,   419,   420,   421,    -1,    -1,    -1,
      27,    -1,    -1,    -1,   429,    -1,    -1,    -1,   622,    -1,
      -1,    38,    -1,    -1,    -1,    -1,   533,   534,    -1,    -1,
      -1,   125,   126,   540,    20,    -1,    22,    -1,   642,    -1,
      -1,    27,    -1,    60,    61,    62,    63,    33,    65,    -1,
      67,   145,    69,    70,    71,    -1,    -1,   151,    75,    -1,
      -1,    -1,    -1,    -1,    61,    62,    -1,   161,   162,    -1,
      67,    68,    -1,    70,    60,    -1,    -1,    63,    -1,    -1,
      -1,    67,    -1,    -1,    -1,    71,    -1,    -1,   692,    75,
     694,    -1,    -1,    90,    91,    -1,    -1,    -1,    -1,    17,
      -1,    -1,   196,    -1,    -1,    -1,    -1,   711,    -1,    27,
     714,    -1,    -1,    31,    -1,   622,    -1,    35,   722,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,   126,
      -1,    -1,    -1,    27,    -1,   642,   551,    -1,    -1,    -1,
      -1,    -1,    60,    61,    62,    63,    -1,    65,   145,    67,
      -1,    69,    70,    71,   151,    -1,   760,    75,   762,    -1,
      -1,    -1,    -1,    -1,   161,   162,    60,    61,    62,    63,
      -1,    65,    -1,    67,    -1,    69,    70,    71,    -1,    -1,
      -1,    75,    -1,    -1,    -1,   692,    -1,   694,    -1,    -1,
     284,   285,   286,   287,    -1,    -1,    17,    -1,   292,   196,
      -1,    -1,    -1,   297,   711,   299,    27,   714,    -1,   303,
     304,   305,   306,   307,    -1,   722,    -1,    38,    -1,    -1,
     314,   315,   316,    -1,    -1,    -1,    -1,    -1,    -1,   323,
     324,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    62,    63,    -1,    65,    -1,    67,   341,    69,    70,
      71,    -1,    -1,   760,    75,   762,    -1,    -1,    -1,    -1,
      -1,   676,   356,   357,   358,   359,   360,    -1,   362,   363,
     364,    -1,    -1,    -1,   368,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   377,   378,   379,    -1,   284,   285,   286,
     287,    -1,    -1,    -1,    -1,   292,    -1,    -1,    -1,    -1,
     297,    -1,   299,    -1,    -1,    -1,   303,   304,   305,   306,
     307,    -1,   727,    -1,    -1,    -1,    -1,   314,   315,   316,
      -1,    -1,    -1,    -1,    -1,    -1,   323,   324,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    70,   341,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   356,
     357,   358,   359,   360,    -1,   362,   363,   364,    -1,    -1,
      -1,   368,    -1,    -1,    -1,   469,    -1,    -1,    -1,    17,
     377,   378,   379,    21,    22,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    30,    31,    -1,    -1,    -1,    35,   125,   126,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,
      -1,   505,    -1,    -1,   508,    -1,    -1,    -1,   145,    -1,
      -1,    -1,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,   161,   162,    -1,    75,    -1,   533,
     534,    -1,    -1,    -1,    -1,    17,   540,    -1,    -1,    21,
      22,    -1,    -1,    -1,    -1,    27,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,   196,
      -1,    -1,   469,    45,    -1,    -1,    -1,    61,    62,    -1,
      -1,    21,    22,    67,    68,    -1,    70,    27,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      -1,    -1,    -1,    75,    -1,    45,    90,    91,   505,    -1,
      -1,   508,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    61,    62,    63,    -1,    65,    -1,    67,   622,    69,
      70,    71,    -1,    -1,    -1,    75,   533,   534,    -1,    -1,
      -1,   125,   126,   540,    60,    61,    62,    63,   642,    65,
      -1,    67,    -1,    69,    70,    71,    -1,    -1,   285,    75,
     287,   145,    -1,    -1,    -1,    -1,    -1,   151,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,    38,
     307,    -1,    -1,    -1,    -1,    -1,    -1,   314,   315,   316,
      -1,    -1,    -1,    -1,    -1,    -1,   323,   324,   692,    -1,
     694,    60,    61,    62,    63,    -1,    65,    -1,    67,    -1,
      69,    70,    71,    -1,   341,    -1,    75,   711,    -1,    -1,
     714,    -1,    -1,    -1,    -1,   622,    -1,    -1,   722,   356,
     357,   358,   359,   360,    17,   362,    -1,    -1,    21,    22,
      -1,   368,    -1,    -1,    27,   642,    -1,    30,    31,    -1,
     377,   378,   379,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    -1,    -1,    -1,   760,    -1,   762,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    -1,
      -1,    -1,    75,    -1,    -1,   692,    -1,   694,    -1,    -1,
     284,   285,   286,   287,    -1,    -1,    -1,    -1,   292,    -1,
      -1,    -1,    -1,   297,   711,   299,    -1,   714,    -1,   303,
     304,   305,   306,   307,    -1,   722,    -1,    38,    -1,    -1,
     314,   315,   316,    -1,    -1,    -1,    -1,    -1,    -1,   323,
     324,    -1,   469,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    62,    63,    -1,    65,    -1,    67,   341,    69,    70,
      71,    -1,    -1,   760,    75,   762,    -1,    -1,    -1,    -1,
      -1,    -1,   356,   357,   358,   359,   360,    -1,   362,   363,
     364,   508,    -1,    -1,   368,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   377,   378,   379,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   533,   534,    -1,    -1,
       3,     4,     5,   540,     7,     8,     9,    10,    -1,    -1,
      -1,    14,    -1,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    26,    27,    -1,    -1,    30,    31,    32,
      33,    22,    -1,    -1,    -1,    38,    39,    40,    41,    -1,
      -1,    -1,    45,    -1,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    44,    -1,    46,    47,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    60,
      61,    -1,    75,    -1,    65,   469,    67,    -1,    69,    70,
      71,    -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
       7,     8,     9,    10,   508,    -1,    -1,    14,    -1,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    26,
      27,    -1,    -1,    30,    31,    32,    33,    -1,    -1,   533,
     534,    38,    39,    40,    41,    -1,   540,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,   692,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    -1,    -1,   714,    75,    -1,
      -1,    -1,    -1,    -1,    -1,   722,    17,    -1,    -1,    -1,
      21,    22,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   760,    -1,   762,    -1,    -1,   622,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    -1,    -1,    -1,    75,     3,     4,     5,   642,     7,
       8,     9,    10,    -1,    -1,    -1,    14,    -1,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    26,    27,
      -1,    -1,    -1,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   692,    -1,
     694,    -1,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    -1,    -1,    -1,    75,     4,     5,
     714,     7,     8,     9,    10,    -1,    -1,    -1,   722,    -1,
      -1,    17,    -1,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    33,    -1,    35,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,   760,    -1,   762,    -1,
      -1,    -1,    -1,    -1,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    -1,     4,     5,    75,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    -1,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      27,    -1,    -1,    -1,    31,    32,    33,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    -1,     4,     5,    75,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      -1,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    -1,    31,    32,    33,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    -1,     4,     5,    75,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    27,    -1,
      -1,    -1,    31,    32,    33,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    -1,     4,     5,    75,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    33,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    61,    62,    63,    64,    65,    66,    67,    17,    69,
      70,    71,    21,    22,    -1,    75,    -1,    -1,    27,    -1,
      -1,    -1,    31,    -1,    -1,    22,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    -1,    46,
      47,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    60,    61,    -1,    75,    -1,    65,    -1,
      67,    -1,    69,    70,    71,    -1,    -1,    -1,    75
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,    77,   300,     0,    48,    50,    51,    54,    55,    56,
      57,    78,    79,    80,    82,    83,    84,    85,    86,   283,
      27,    27,    27,    27,    27,    27,    27,    60,    65,    67,
      71,   294,   295,   294,   295,   299,   294,   294,   294,   294,
      13,    13,    13,   284,   300,    13,    13,    13,    13,    67,
      88,    88,    22,    37,   285,    36,    88,    88,    88,    88,
      28,    13,    13,   286,   294,    13,    30,    13,    13,    13,
      13,    22,    42,    43,    44,    46,    47,    61,    65,    69,
      70,    75,   266,   288,   289,   290,   291,   292,   295,   298,
      27,    38,    61,    62,    63,   210,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   227,   228,   232,
     233,   234,   258,   259,   260,   261,   262,   263,   265,   266,
     295,   296,   297,   298,    17,    22,    27,    31,    38,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   215,   229,   230,   242,   245,    35,    13,   287,   294,
      17,    27,    61,   172,   199,   200,   201,   232,   249,   258,
      21,    22,    27,    45,    64,    66,   136,   137,   138,   139,
     140,   141,   142,   143,   145,   146,   147,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   167,   169,   170,
     172,   184,   185,   186,   191,   198,   240,   241,   242,   245,
     249,   250,   254,   258,   259,   260,   261,   262,   263,   265,
     266,   297,     4,     5,     7,     8,     9,    10,    19,    20,
      21,    22,    27,    32,    33,    45,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    99,   100,   101,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   119,   121,
     122,   125,   127,   129,   130,   131,   132,   133,   134,   135,
     187,   198,   235,   236,   237,   238,   241,   245,   249,   250,
     258,   259,   260,   261,   262,   263,   264,   265,   266,    81,
     202,    35,   288,   293,    27,    27,    27,    27,    27,    11,
      27,   232,    27,   215,   227,    14,    18,   255,   256,   257,
      13,    87,   300,    41,    27,    27,    27,    27,    35,   203,
     231,   203,   229,    87,    41,     3,     3,    16,    23,    24,
      26,    39,    40,    41,   243,    29,   246,    22,   209,   211,
     212,   286,    22,   172,    87,    11,    30,   195,   196,   296,
     297,    27,    30,    35,   137,   168,   170,   171,   258,   260,
     265,    30,   137,    27,    30,    87,    41,     3,     3,    41,
     243,    15,   248,   255,   257,   246,     6,    22,    27,   144,
     145,   152,   154,   266,    22,    25,   239,    27,    27,    27,
     195,    27,    35,    90,   124,   258,   260,     3,    41,    90,
     120,   125,   236,   243,   244,   249,   256,   257,    27,    87,
      41,     3,     6,     3,     6,    41,   243,    97,    99,   104,
     107,   111,   121,   248,   255,   257,   246,    37,    59,    68,
      37,    68,    22,    27,    98,    99,   105,   107,   266,    11,
     239,    27,    27,    27,    87,    13,    35,   232,   202,   221,
     224,   225,   227,   136,    89,   288,   293,    36,   215,   227,
     227,    22,    49,    52,    53,    58,   267,   269,   270,   272,
     274,   275,   294,    36,   234,   226,   227,   226,   226,    13,
      35,    36,    36,    36,   211,   211,   211,   211,   211,   230,
     214,   266,   148,   149,   150,   266,    36,    36,    22,    27,
     173,   174,   175,   177,   178,   180,   182,   238,   251,   252,
     253,   266,   295,   296,    34,    27,    34,    35,    13,    35,
      36,    36,    22,    27,    61,   161,   172,   258,   259,    59,
      36,   143,   145,   151,   154,   158,   170,   143,   143,   143,
     143,   168,    21,    22,    27,   154,   169,   266,   169,   170,
      27,   137,   148,   249,   250,   260,   261,   297,   171,   171,
     171,    27,    34,    13,    35,    36,    36,    36,    22,    27,
     114,   125,    36,    97,    97,    97,    97,    97,    97,    97,
      90,    21,    22,    27,   107,   119,   266,   119,   121,    27,
      99,   127,   127,   130,   127,   127,   127,   102,   103,   266,
      90,    96,    97,    99,   126,   127,   128,   130,   250,   123,
     124,   123,   123,    36,   293,    36,    36,    36,    36,    36,
      36,    36,   267,   268,    27,    27,    27,    13,   281,   300,
      30,    36,    13,    36,    36,   231,    30,    35,    13,    35,
      13,    11,    30,   173,   183,   174,   177,   178,   181,    59,
      22,    27,    64,   154,   185,   192,   193,   194,   197,   171,
     162,   172,    13,    30,   137,   171,    36,    35,    36,    36,
      36,    27,   107,   134,   188,   189,   190,   197,   124,   115,
     125,    13,    30,    90,    35,    13,    11,    36,    36,    36,
      36,    30,    13,    35,   299,   271,   295,   273,   295,   282,
     292,   226,    11,   214,    11,   148,    27,   178,    13,    35,
      36,    37,    36,    36,    37,   178,   148,   178,   179,   169,
      36,    13,    35,    13,    22,   155,   163,   164,   165,   170,
      36,    36,    11,    21,    27,   236,    36,    13,    35,    13,
      22,    90,   116,   117,    36,    11,   102,   126,   268,    13,
     276,   300,    13,    13,   211,   200,   178,   183,   178,   178,
      35,    13,    36,    34,   192,   162,   155,   164,   166,   170,
      13,    12,   247,   143,    34,   188,   115,    90,   117,   118,
     247,    13,   294,    36,   282,   282,    11,   179,    13,    35,
     168,   168,    13,    35,    90,    90,    13,    13,    27,   175,
     176,   178,   166,    36,   118,    36,    22,   277,   277,    27,
     180,    35,   267,   278,   279,    36,    36,   177,    36,    11,
     280,   300,    35,    13,   288,   278
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,    76,    77,    77,    78,    78,    79,    79,    79,    79,
      79,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      87,    88,    88,    89,    89,    89,    90,    90,    90,    90,
      90,    90,    91,    91,    91,    92,    93,    93,    93,    94,
      94,    95,    95,    96,    96,    97,    97,    97,    98,    98,
      99,    99,    99,    99,   100,   101,   102,   102,   103,   104,
     104,   105,   106,   107,   107,   107,   107,   108,   108,   109,
     109,   109,   109,   109,   110,   110,   111,   112,   113,   114,
     114,   115,   115,   116,   116,   117,   118,   118,   119,   119,
     119,   120,   120,   120,   120,   120,   121,   121,   122,   122,
     122,   123,   124,   124,   125,   125,   126,   126,   126,   127,
     128,   129,   129,   129,   130,   130,   131,   131,   132,   132,
     133,   134,   135,   136,   136,   136,   137,   137,   137,   137,
     137,   137,   138,   138,   139,   140,   140,   141,   141,   142,
     142,   143,   143,   143,   144,   144,   145,   145,   145,   145,
     146,   147,   148,   148,   149,   149,   150,   151,   151,   152,
     153,   154,   154,   154,   155,   155,   156,   157,   157,   157,
     157,   158,   159,   159,   160,   161,   161,   162,   162,   163,
     163,   164,   165,   165,   166,   166,   167,   168,   168,   168,
     169,   169,   169,   169,   169,   170,   170,   171,   171,   172,
     172,   173,   173,   174,   174,   174,   175,   176,   176,   176,
     177,   177,   178,   178,   178,   178,   178,   178,   179,   179,
     180,   181,   181,   182,   183,   183,   184,   185,   186,   187,
     187,   188,   188,   189,   189,   190,   191,   191,   192,   192,
     193,   193,   194,   195,   195,   196,   197,   198,   198,   198,
     198,   199,   199,   200,   200,   201,   202,   202,   203,   203,
     203,   204,   204,   205,   206,   206,   207,   207,   208,   208,
     209,   209,   210,   211,   211,   212,   212,   212,   213,   214,
     214,   215,   215,   215,   216,   217,   217,   218,   219,   220,
     221,   221,   222,   222,   223,   224,   224,   225,   225,   226,
     226,   227,   227,   228,   228,   228,   229,   229,   230,   230,
     231,   231,   232,   232,   233,   233,   234,   234,   234,   234,
     235,   235,   235,   236,   236,   237,   237,   237,   238,   238,
     239,   240,   240,   241,   241,   242,   242,   243,   243,   243,
     243,   243,   243,   244,   244,   245,   246,   247,   248,   249,
     249,   250,   250,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   264,   264,
     264,   264,   265,   265,   266,   267,   267,   267,   267,   267,
     268,   268,   269,   269,   270,   271,   272,   273,   274,   275,
     276,   276,   277,   277,   278,   278,   279,   280,   280,   281,
     281,   282,   283,   284,   284,   284,   285,   285,   286,   286,
     287,   288,   288,   288,   289,   289,   289,   289,   289,   289,
     290,   291,   291,   291,   291,   291,   292,   292,   293,   293,
     294,   294,   295,   295,   295,   296,   297,   298,   298,   298,
     299,   300
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,    10,     1,    10,    10,    10,    10,    10,     3,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     5,     1,     3,     3,     1,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     3,     1,     8,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     1,     1,
       3,     1,     1,     1,     1,     1,     2,     3,     4,     4,
       4,     1,     1,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     6,     1,     3,     1,     1,     3,     1,     1,     2,
       3,     1,     1,     1,     1,     4,     1,     1,     4,     1,
       1,     3,     1,     4,     8,     1,     3,     1,     3,     1,
       3,     3,     1,     1,     1,     3,     5,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     3,     1,     3,     3,
       3,     1,     1,     1,     1,     3,     6,     1,     3,     1,
       1,     3,     1,     1,     1,     4,     3,     1,     1,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     3,     3,
       6,     1,     3,     1,     1,     1,     3,     6,     1,     3,
       1,     1,     1,     1,     1,     1,     2,     3,     3,     3,
       3,     1,     1,     1,     1,     6,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     3,     3,     3,     3,
       2,     1,     3,     1,     1,     1,     1,     3,     6,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     4,     1,     1,     1,     1,     4,     1,     4,     1,
       3,     1,     1,     1,     1,     1,     3,     3,     2,     3,
       1,     3,     1,     3,     1,     3,     1,     2,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     3,     1,     1,     8,     1,     8,     1,     1,     5,
       2,     1,     2,     3,     1,     3,     2,     2,     1,     2,
       1,     1,     6,     1,     2,     4,     3,     1,     1,     3,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     2,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* TPTP_file: nothing  */
#line 229 "SyntaxBNF.y"
                    {}
#line 2889 "y.tab.c"
    break;

  case 3: /* TPTP_file: TPTP_file TPTP_input  */
#line 230 "SyntaxBNF.y"
                                           {}
#line 2895 "y.tab.c"
    break;

  case 4: /* TPTP_input: annotated_formula  */
#line 233 "SyntaxBNF.y"
                               {P_PRINT((yyval.pval));}
#line 2901 "y.tab.c"
    break;

  case 5: /* TPTP_input: include  */
#line 234 "SyntaxBNF.y"
                              {P_PRINT((yyval.pval));}
#line 2907 "y.tab.c"
    break;

  case 6: /* annotated_formula: thf_annotated  */
#line 237 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2913 "y.tab.c"
    break;

  case 7: /* annotated_formula: tff_annotated  */
#line 238 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2919 "y.tab.c"
    break;

  case 8: /* annotated_formula: tcf_annotated  */
#line 239 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2925 "y.tab.c"
    break;

  case 9: /* annotated_formula: fof_annotated  */
#line 240 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2931 "y.tab.c"
    break;

  case 10: /* annotated_formula: cnf_annotated  */
#line 241 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2937 "y.tab.c"
    break;

  case 11: /* annotated_formula: tpi_annotated  */
#line 242 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2943 "y.tab.c"
    break;

  case 12: /* tpi_annotated: _LIT_tpi LPAREN name COMMA formula_role COMMA tpi_formula annotations RPAREN PERIOD  */
#line 245 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("tpi_annotated", P_TOKEN("_LIT_tpi ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2949 "y.tab.c"
    break;

  case 13: /* tpi_formula: fof_formula  */
#line 248 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("tpi_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2955 "y.tab.c"
    break;

  case 14: /* thf_annotated: _LIT_thf LPAREN name COMMA formula_role COMMA thf_formula annotations RPAREN PERIOD  */
#line 251 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("thf_annotated", P_TOKEN("_LIT_thf ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2961 "y.tab.c"
    break;

  case 15: /* tff_annotated: _LIT_tff LPAREN name COMMA formula_role COMMA tff_formula annotations RPAREN PERIOD  */
#line 254 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("tff_annotated", P_TOKEN("_LIT_tff ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2967 "y.tab.c"
    break;

  case 16: /* tcf_annotated: _LIT_tcf LPAREN name COMMA formula_role COMMA tcf_formula annotations RPAREN PERIOD  */
#line 257 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("tcf_annotated", P_TOKEN("_LIT_tcf ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2973 "y.tab.c"
    break;

  case 17: /* fof_annotated: _LIT_fof LPAREN name COMMA formula_role COMMA fof_formula annotations RPAREN PERIOD  */
#line 260 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("fof_annotated", P_TOKEN("_LIT_fof ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2979 "y.tab.c"
    break;

  case 18: /* cnf_annotated: _LIT_cnf LPAREN name COMMA formula_role COMMA cnf_formula annotations RPAREN PERIOD  */
#line 263 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("cnf_annotated", P_TOKEN("_LIT_cnf ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2985 "y.tab.c"
    break;

  case 19: /* annotations: COMMA source optional_info  */
#line 266 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("annotations", P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2991 "y.tab.c"
    break;

  case 20: /* annotations: nothing  */
#line 267 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("annotations", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2997 "y.tab.c"
    break;

  case 21: /* formula_role: lower_word  */
#line 270 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("formula_role", P_TOKEN("lower_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3003 "y.tab.c"
    break;

  case 22: /* formula_role: lower_word MINUS general_term  */
#line 271 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("formula_role", P_TOKEN("lower_word ", (yyvsp[-2].ival)), P_TOKEN("MINUS ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3009 "y.tab.c"
    break;

  case 23: /* thf_formula: thf_logic_formula  */
#line 274 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3015 "y.tab.c"
    break;

  case 24: /* thf_formula: thf_atom_typing  */
#line 275 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3021 "y.tab.c"
    break;

  case 25: /* thf_formula: thf_subtype  */
#line 276 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("thf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3027 "y.tab.c"
    break;

  case 26: /* thf_logic_formula: thf_unitary_formula  */
#line 279 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3033 "y.tab.c"
    break;

  case 27: /* thf_logic_formula: thf_unary_formula  */
#line 280 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3039 "y.tab.c"
    break;

  case 28: /* thf_logic_formula: thf_binary_formula  */
#line 281 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3045 "y.tab.c"
    break;

  case 29: /* thf_logic_formula: thf_defined_infix  */
#line 282 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3051 "y.tab.c"
    break;

  case 30: /* thf_logic_formula: thf_definition  */
#line 283 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3057 "y.tab.c"
    break;

  case 31: /* thf_logic_formula: thf_sequent  */
#line 284 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3063 "y.tab.c"
    break;

  case 32: /* thf_binary_formula: thf_binary_nonassoc  */
#line 287 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3069 "y.tab.c"
    break;

  case 33: /* thf_binary_formula: thf_binary_assoc  */
#line 288 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3075 "y.tab.c"
    break;

  case 34: /* thf_binary_formula: thf_binary_type  */
#line 289 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3081 "y.tab.c"
    break;

  case 35: /* thf_binary_nonassoc: thf_unit_formula nonassoc_connective thf_unit_formula  */
#line 292 "SyntaxBNF.y"
                                                                            {(yyval.pval) = P_BUILD("thf_binary_nonassoc", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3087 "y.tab.c"
    break;

  case 36: /* thf_binary_assoc: thf_or_formula  */
#line 295 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("thf_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3093 "y.tab.c"
    break;

  case 37: /* thf_binary_assoc: thf_and_formula  */
#line 296 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3099 "y.tab.c"
    break;

  case 38: /* thf_binary_assoc: thf_apply_formula  */
#line 297 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3105 "y.tab.c"
    break;

  case 39: /* thf_or_formula: thf_unit_formula VLINE thf_unit_formula  */
#line 300 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("thf_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3111 "y.tab.c"
    break;

  case 40: /* thf_or_formula: thf_or_formula VLINE thf_unit_formula  */
#line 301 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("thf_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3117 "y.tab.c"
    break;

  case 41: /* thf_and_formula: thf_unit_formula AMPERSAND thf_unit_formula  */
#line 304 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3123 "y.tab.c"
    break;

  case 42: /* thf_and_formula: thf_and_formula AMPERSAND thf_unit_formula  */
#line 305 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3129 "y.tab.c"
    break;

  case 43: /* thf_apply_formula: thf_unit_formula AT_SIGN thf_unit_formula  */
#line 308 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_apply_formula", (yyvsp[-2].pval), P_TOKEN("AT_SIGN ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3135 "y.tab.c"
    break;

  case 44: /* thf_apply_formula: thf_apply_formula AT_SIGN thf_unit_formula  */
#line 309 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_apply_formula", (yyvsp[-2].pval), P_TOKEN("AT_SIGN ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3141 "y.tab.c"
    break;

  case 45: /* thf_unit_formula: thf_unitary_formula  */
#line 312 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3147 "y.tab.c"
    break;

  case 46: /* thf_unit_formula: thf_unary_formula  */
#line 313 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3153 "y.tab.c"
    break;

  case 47: /* thf_unit_formula: thf_defined_infix  */
#line 314 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3159 "y.tab.c"
    break;

  case 48: /* thf_preunit_formula: thf_unitary_formula  */
#line 317 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("thf_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3165 "y.tab.c"
    break;

  case 49: /* thf_preunit_formula: thf_prefix_unary  */
#line 318 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3171 "y.tab.c"
    break;

  case 50: /* thf_unitary_formula: thf_quantified_formula  */
#line 321 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("thf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3177 "y.tab.c"
    break;

  case 51: /* thf_unitary_formula: thf_atomic_formula  */
#line 322 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3183 "y.tab.c"
    break;

  case 52: /* thf_unitary_formula: variable  */
#line 323 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("thf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3189 "y.tab.c"
    break;

  case 53: /* thf_unitary_formula: LPAREN thf_logic_formula RPAREN  */
#line 324 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("thf_unitary_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3195 "y.tab.c"
    break;

  case 54: /* thf_quantified_formula: thf_quantification thf_unit_formula  */
#line 327 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("thf_quantified_formula", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3201 "y.tab.c"
    break;

  case 55: /* thf_quantification: thf_quantifier LBRKT thf_variable_list RBRKT COLON  */
#line 330 "SyntaxBNF.y"
                                                                        {(yyval.pval) = P_BUILD("thf_quantification", (yyvsp[-4].pval), P_TOKEN("LBRKT ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("RBRKT ", (yyvsp[-1].ival)), P_TOKEN("COLON ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 3207 "y.tab.c"
    break;

  case 56: /* thf_variable_list: thf_typed_variable  */
#line 333 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_variable_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3213 "y.tab.c"
    break;

  case 57: /* thf_variable_list: thf_typed_variable COMMA thf_variable_list  */
#line 334 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_variable_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3219 "y.tab.c"
    break;

  case 58: /* thf_typed_variable: variable COLON thf_top_level_type  */
#line 337 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("thf_typed_variable", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3225 "y.tab.c"
    break;

  case 59: /* thf_unary_formula: thf_prefix_unary  */
#line 340 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3231 "y.tab.c"
    break;

  case 60: /* thf_unary_formula: thf_infix_unary  */
#line 341 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3237 "y.tab.c"
    break;

  case 61: /* thf_prefix_unary: thf_unary_connective thf_preunit_formula  */
#line 344 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("thf_prefix_unary", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3243 "y.tab.c"
    break;

  case 62: /* thf_infix_unary: thf_unitary_term infix_inequality thf_unitary_term  */
#line 347 "SyntaxBNF.y"
                                                                     {(yyval.pval) = P_BUILD("thf_infix_unary", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3249 "y.tab.c"
    break;

  case 63: /* thf_atomic_formula: thf_plain_atomic  */
#line 350 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3255 "y.tab.c"
    break;

  case 64: /* thf_atomic_formula: thf_defined_atomic  */
#line 351 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3261 "y.tab.c"
    break;

  case 65: /* thf_atomic_formula: thf_system_atomic  */
#line 352 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3267 "y.tab.c"
    break;

  case 66: /* thf_atomic_formula: thf_fof_function  */
#line 353 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3273 "y.tab.c"
    break;

  case 67: /* thf_plain_atomic: constant  */
#line 356 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("thf_plain_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3279 "y.tab.c"
    break;

  case 68: /* thf_plain_atomic: thf_tuple  */
#line 357 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_plain_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3285 "y.tab.c"
    break;

  case 69: /* thf_defined_atomic: defined_constant  */
#line 360 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3291 "y.tab.c"
    break;

  case 70: /* thf_defined_atomic: thf_defined_term  */
#line 361 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3297 "y.tab.c"
    break;

  case 71: /* thf_defined_atomic: LPAREN thf_conn_term RPAREN  */
#line 362 "SyntaxBNF.y"
                                                  {(yyval.pval) = P_BUILD("thf_defined_atomic", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3303 "y.tab.c"
    break;

  case 72: /* thf_defined_atomic: nhf_long_connective  */
#line 363 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3309 "y.tab.c"
    break;

  case 73: /* thf_defined_atomic: thf_let  */
#line 364 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3315 "y.tab.c"
    break;

  case 74: /* thf_defined_term: defined_term  */
#line 367 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3321 "y.tab.c"
    break;

  case 75: /* thf_defined_term: th1_defined_term  */
#line 368 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3327 "y.tab.c"
    break;

  case 76: /* thf_defined_infix: thf_unitary_term defined_infix_pred thf_unitary_term  */
#line 371 "SyntaxBNF.y"
                                                                         {(yyval.pval) = P_BUILD("thf_defined_infix", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3333 "y.tab.c"
    break;

  case 77: /* thf_system_atomic: system_constant  */
#line 374 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("thf_system_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3339 "y.tab.c"
    break;

  case 78: /* thf_let: _DLR_let LPAREN thf_let_types COMMA thf_let_defns COMMA thf_logic_formula RPAREN  */
#line 377 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("thf_let", P_TOKEN("_DLR_let ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 3345 "y.tab.c"
    break;

  case 79: /* thf_let_types: thf_atom_typing  */
#line 380 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_let_types", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3351 "y.tab.c"
    break;

  case 80: /* thf_let_types: LBRKT thf_atom_typing_list RBRKT  */
#line 381 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("thf_let_types", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3357 "y.tab.c"
    break;

  case 81: /* thf_atom_typing_list: thf_atom_typing  */
#line 384 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_atom_typing_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3363 "y.tab.c"
    break;

  case 82: /* thf_atom_typing_list: thf_atom_typing COMMA thf_atom_typing_list  */
#line 385 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_atom_typing_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3369 "y.tab.c"
    break;

  case 83: /* thf_let_defns: thf_let_defn  */
#line 388 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("thf_let_defns", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3375 "y.tab.c"
    break;

  case 84: /* thf_let_defns: LBRKT thf_let_defn_list RBRKT  */
#line 389 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("thf_let_defns", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3381 "y.tab.c"
    break;

  case 85: /* thf_let_defn: thf_logic_formula assignment thf_logic_formula  */
#line 392 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_let_defn", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3387 "y.tab.c"
    break;

  case 86: /* thf_let_defn_list: thf_let_defn  */
#line 395 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("thf_let_defn_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3393 "y.tab.c"
    break;

  case 87: /* thf_let_defn_list: thf_let_defn COMMA thf_let_defn_list  */
#line 396 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_let_defn_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3399 "y.tab.c"
    break;

  case 88: /* thf_unitary_term: thf_atomic_formula  */
#line 399 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3405 "y.tab.c"
    break;

  case 89: /* thf_unitary_term: variable  */
#line 400 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("thf_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3411 "y.tab.c"
    break;

  case 90: /* thf_unitary_term: LPAREN thf_logic_formula RPAREN  */
#line 401 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("thf_unitary_term", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3417 "y.tab.c"
    break;

  case 91: /* thf_conn_term: nonassoc_connective  */
#line 404 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3423 "y.tab.c"
    break;

  case 92: /* thf_conn_term: assoc_connective  */
#line 405 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3429 "y.tab.c"
    break;

  case 93: /* thf_conn_term: infix_equality  */
#line 406 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3435 "y.tab.c"
    break;

  case 94: /* thf_conn_term: infix_inequality  */
#line 407 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3441 "y.tab.c"
    break;

  case 95: /* thf_conn_term: thf_unary_connective  */
#line 408 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3447 "y.tab.c"
    break;

  case 96: /* thf_tuple: LBRKT RBRKT  */
#line 411 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("thf_tuple", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3453 "y.tab.c"
    break;

  case 97: /* thf_tuple: LBRKT thf_formula_list RBRKT  */
#line 412 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("thf_tuple", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3459 "y.tab.c"
    break;

  case 98: /* thf_fof_function: defined_functor LPAREN thf_arguments RPAREN  */
#line 415 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("thf_fof_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3465 "y.tab.c"
    break;

  case 99: /* thf_fof_function: system_functor LPAREN thf_arguments RPAREN  */
#line 416 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_fof_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3471 "y.tab.c"
    break;

  case 100: /* thf_fof_function: functor LPAREN thf_arguments RPAREN  */
#line 417 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("thf_fof_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3477 "y.tab.c"
    break;

  case 101: /* thf_arguments: thf_formula_list  */
#line 420 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("thf_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3483 "y.tab.c"
    break;

  case 102: /* thf_formula_list: thf_logic_formula  */
#line 423 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_formula_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3489 "y.tab.c"
    break;

  case 103: /* thf_formula_list: thf_logic_formula COMMA thf_formula_list  */
#line 424 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("thf_formula_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3495 "y.tab.c"
    break;

  case 104: /* thf_atom_typing: typeable_atom COLON thf_top_level_type  */
#line 427 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("thf_atom_typing", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3501 "y.tab.c"
    break;

  case 105: /* thf_atom_typing: LPAREN thf_atom_typing RPAREN  */
#line 428 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("thf_atom_typing", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3507 "y.tab.c"
    break;

  case 106: /* thf_top_level_type: thf_unitary_type  */
#line 431 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3513 "y.tab.c"
    break;

  case 107: /* thf_top_level_type: thf_mapping_type  */
#line 432 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3519 "y.tab.c"
    break;

  case 108: /* thf_top_level_type: thf_apply_type  */
#line 433 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3525 "y.tab.c"
    break;

  case 109: /* thf_unitary_type: thf_unitary_formula  */
#line 436 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_unitary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3531 "y.tab.c"
    break;

  case 110: /* thf_apply_type: thf_apply_formula  */
#line 439 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("thf_apply_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3537 "y.tab.c"
    break;

  case 111: /* thf_binary_type: thf_mapping_type  */
#line 442 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("thf_binary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3543 "y.tab.c"
    break;

  case 112: /* thf_binary_type: thf_xprod_type  */
#line 443 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_binary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3549 "y.tab.c"
    break;

  case 113: /* thf_binary_type: thf_union_type  */
#line 444 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_binary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3555 "y.tab.c"
    break;

  case 114: /* thf_mapping_type: thf_unitary_type arrow thf_unitary_type  */
#line 447 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_mapping_type", (yyvsp[-2].pval), P_TOKEN("arrow ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3561 "y.tab.c"
    break;

  case 115: /* thf_mapping_type: thf_unitary_type arrow thf_mapping_type  */
#line 448 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_mapping_type", (yyvsp[-2].pval), P_TOKEN("arrow ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3567 "y.tab.c"
    break;

  case 116: /* thf_xprod_type: thf_unitary_type STAR thf_unitary_type  */
#line 451 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("thf_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3573 "y.tab.c"
    break;

  case 117: /* thf_xprod_type: thf_xprod_type STAR thf_unitary_type  */
#line 452 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3579 "y.tab.c"
    break;

  case 118: /* thf_union_type: thf_unitary_type plus thf_unitary_type  */
#line 455 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("thf_union_type", (yyvsp[-2].pval), P_TOKEN("plus ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3585 "y.tab.c"
    break;

  case 119: /* thf_union_type: thf_union_type plus thf_unitary_type  */
#line 456 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_union_type", (yyvsp[-2].pval), P_TOKEN("plus ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3591 "y.tab.c"
    break;

  case 120: /* thf_subtype: atomic_type subtype_sign atomic_type  */
#line 459 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("thf_subtype", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3597 "y.tab.c"
    break;

  case 121: /* thf_definition: thf_atomic_formula identical thf_logic_formula  */
#line 462 "SyntaxBNF.y"
                                                                {(yyval.pval) = P_BUILD("thf_definition", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3603 "y.tab.c"
    break;

  case 122: /* thf_sequent: thf_tuple gentzen_arrow thf_tuple  */
#line 465 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("thf_sequent", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3609 "y.tab.c"
    break;

  case 123: /* tff_formula: tff_logic_formula  */
#line 468 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3615 "y.tab.c"
    break;

  case 124: /* tff_formula: tff_atom_typing  */
#line 469 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3621 "y.tab.c"
    break;

  case 125: /* tff_formula: tff_subtype  */
#line 470 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3627 "y.tab.c"
    break;

  case 126: /* tff_logic_formula: tff_unitary_formula  */
#line 473 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3633 "y.tab.c"
    break;

  case 127: /* tff_logic_formula: tff_unary_formula  */
#line 474 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3639 "y.tab.c"
    break;

  case 128: /* tff_logic_formula: tff_binary_formula  */
#line 475 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3645 "y.tab.c"
    break;

  case 129: /* tff_logic_formula: tff_defined_infix  */
#line 476 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3651 "y.tab.c"
    break;

  case 130: /* tff_logic_formula: txf_definition  */
#line 477 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3657 "y.tab.c"
    break;

  case 131: /* tff_logic_formula: txf_sequent  */
#line 478 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3663 "y.tab.c"
    break;

  case 132: /* tff_binary_formula: tff_binary_nonassoc  */
#line 481 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3669 "y.tab.c"
    break;

  case 133: /* tff_binary_formula: tff_binary_assoc  */
#line 482 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3675 "y.tab.c"
    break;

  case 134: /* tff_binary_nonassoc: tff_unit_formula nonassoc_connective tff_unit_formula  */
#line 485 "SyntaxBNF.y"
                                                                            {(yyval.pval) = P_BUILD("tff_binary_nonassoc", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3681 "y.tab.c"
    break;

  case 135: /* tff_binary_assoc: tff_or_formula  */
#line 488 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3687 "y.tab.c"
    break;

  case 136: /* tff_binary_assoc: tff_and_formula  */
#line 489 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3693 "y.tab.c"
    break;

  case 137: /* tff_or_formula: tff_unit_formula VLINE tff_unit_formula  */
#line 492 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("tff_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3699 "y.tab.c"
    break;

  case 138: /* tff_or_formula: tff_or_formula VLINE tff_unit_formula  */
#line 493 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("tff_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3705 "y.tab.c"
    break;

  case 139: /* tff_and_formula: tff_unit_formula AMPERSAND tff_unit_formula  */
#line 496 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("tff_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3711 "y.tab.c"
    break;

  case 140: /* tff_and_formula: tff_and_formula AMPERSAND tff_unit_formula  */
#line 497 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("tff_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3717 "y.tab.c"
    break;

  case 141: /* tff_unit_formula: tff_unitary_formula  */
#line 500 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3723 "y.tab.c"
    break;

  case 142: /* tff_unit_formula: tff_unary_formula  */
#line 501 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3729 "y.tab.c"
    break;

  case 143: /* tff_unit_formula: tff_defined_infix  */
#line 502 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3735 "y.tab.c"
    break;

  case 144: /* tff_preunit_formula: tff_unitary_formula  */
#line 505 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3741 "y.tab.c"
    break;

  case 145: /* tff_preunit_formula: tff_prefix_unary  */
#line 506 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3747 "y.tab.c"
    break;

  case 146: /* tff_unitary_formula: tff_quantified_formula  */
#line 509 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("tff_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3753 "y.tab.c"
    break;

  case 147: /* tff_unitary_formula: tff_atomic_formula  */
#line 510 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3759 "y.tab.c"
    break;

  case 148: /* tff_unitary_formula: txf_unitary_formula  */
#line 511 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3765 "y.tab.c"
    break;

  case 149: /* tff_unitary_formula: LPAREN tff_logic_formula RPAREN  */
#line 512 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("tff_unitary_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3771 "y.tab.c"
    break;

  case 150: /* txf_unitary_formula: variable  */
#line 515 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("txf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3777 "y.tab.c"
    break;

  case 151: /* tff_quantified_formula: tff_quantifier LBRKT tff_variable_list RBRKT COLON tff_unit_formula  */
#line 518 "SyntaxBNF.y"
                                                                                             {(yyval.pval) = P_BUILD("tff_quantified_formula", (yyvsp[-5].pval), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 3783 "y.tab.c"
    break;

  case 152: /* tff_variable_list: tff_variable  */
#line 521 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("tff_variable_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3789 "y.tab.c"
    break;

  case 153: /* tff_variable_list: tff_variable COMMA tff_variable_list  */
#line 522 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("tff_variable_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3795 "y.tab.c"
    break;

  case 154: /* tff_variable: tff_typed_variable  */
#line 525 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_variable", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3801 "y.tab.c"
    break;

  case 155: /* tff_variable: variable  */
#line 526 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_variable", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3807 "y.tab.c"
    break;

  case 156: /* tff_typed_variable: variable COLON tff_atomic_type  */
#line 529 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("tff_typed_variable", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3813 "y.tab.c"
    break;

  case 157: /* tff_unary_formula: tff_prefix_unary  */
#line 532 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3819 "y.tab.c"
    break;

  case 158: /* tff_unary_formula: tff_infix_unary  */
#line 533 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3825 "y.tab.c"
    break;

  case 159: /* tff_prefix_unary: tff_unary_connective tff_preunit_formula  */
#line 536 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("tff_prefix_unary", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3831 "y.tab.c"
    break;

  case 160: /* tff_infix_unary: tff_unitary_term infix_inequality tff_unitary_term  */
#line 539 "SyntaxBNF.y"
                                                                     {(yyval.pval) = P_BUILD("tff_infix_unary", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3837 "y.tab.c"
    break;

  case 161: /* tff_atomic_formula: tff_plain_atomic  */
#line 542 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3843 "y.tab.c"
    break;

  case 162: /* tff_atomic_formula: tff_defined_atomic  */
#line 543 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3849 "y.tab.c"
    break;

  case 163: /* tff_atomic_formula: tff_system_atomic  */
#line 544 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3855 "y.tab.c"
    break;

  case 164: /* tff_plain_atomic: constant  */
#line 547 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("tff_plain_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3861 "y.tab.c"
    break;

  case 165: /* tff_plain_atomic: functor LPAREN tff_arguments RPAREN  */
#line 548 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("tff_plain_atomic", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3867 "y.tab.c"
    break;

  case 166: /* tff_defined_atomic: tff_defined_plain  */
#line 551 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3873 "y.tab.c"
    break;

  case 167: /* tff_defined_plain: defined_constant  */
#line 554 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3879 "y.tab.c"
    break;

  case 168: /* tff_defined_plain: defined_functor LPAREN tff_arguments RPAREN  */
#line 555 "SyntaxBNF.y"
                                                                  {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3885 "y.tab.c"
    break;

  case 169: /* tff_defined_plain: nxf_atom  */
#line 556 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3891 "y.tab.c"
    break;

  case 170: /* tff_defined_plain: txf_let  */
#line 557 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3897 "y.tab.c"
    break;

  case 171: /* tff_defined_infix: tff_unitary_term defined_infix_pred tff_unitary_term  */
#line 560 "SyntaxBNF.y"
                                                                         {(yyval.pval) = P_BUILD("tff_defined_infix", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3903 "y.tab.c"
    break;

  case 172: /* tff_system_atomic: system_constant  */
#line 563 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("tff_system_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3909 "y.tab.c"
    break;

  case 173: /* tff_system_atomic: system_functor LPAREN tff_arguments RPAREN  */
#line 564 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("tff_system_atomic", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3915 "y.tab.c"
    break;

  case 174: /* txf_let: _DLR_let LPAREN txf_let_types COMMA txf_let_defns COMMA tff_term RPAREN  */
#line 567 "SyntaxBNF.y"
                                                                                  {(yyval.pval) = P_BUILD("txf_let", P_TOKEN("_DLR_let ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 3921 "y.tab.c"
    break;

  case 175: /* txf_let_types: tff_atom_typing  */
#line 570 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("txf_let_types", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3927 "y.tab.c"
    break;

  case 176: /* txf_let_types: LBRKT tff_atom_typing_list RBRKT  */
#line 571 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("txf_let_types", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3933 "y.tab.c"
    break;

  case 177: /* tff_atom_typing_list: tff_atom_typing  */
#line 574 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_atom_typing_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3939 "y.tab.c"
    break;

  case 178: /* tff_atom_typing_list: tff_atom_typing COMMA tff_atom_typing_list  */
#line 575 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("tff_atom_typing_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3945 "y.tab.c"
    break;

  case 179: /* txf_let_defns: txf_let_defn  */
#line 578 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("txf_let_defns", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3951 "y.tab.c"
    break;

  case 180: /* txf_let_defns: LBRKT txf_let_defn_list RBRKT  */
#line 579 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("txf_let_defns", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3957 "y.tab.c"
    break;

  case 181: /* txf_let_defn: txf_let_LHS assignment tff_term  */
#line 582 "SyntaxBNF.y"
                                               {(yyval.pval) = P_BUILD("txf_let_defn", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3963 "y.tab.c"
    break;

  case 182: /* txf_let_LHS: tff_plain_atomic  */
#line 585 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("txf_let_LHS", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3969 "y.tab.c"
    break;

  case 183: /* txf_let_LHS: txf_tuple  */
#line 586 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("txf_let_LHS", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3975 "y.tab.c"
    break;

  case 184: /* txf_let_defn_list: txf_let_defn  */
#line 589 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("txf_let_defn_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3981 "y.tab.c"
    break;

  case 185: /* txf_let_defn_list: txf_let_defn COMMA txf_let_defn_list  */
#line 590 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("txf_let_defn_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3987 "y.tab.c"
    break;

  case 186: /* nxf_atom: nxf_long_connective AT_SIGN LPAREN tff_arguments RPAREN  */
#line 593 "SyntaxBNF.y"
                                                                   {(yyval.pval) = P_BUILD("nxf_atom", (yyvsp[-4].pval), P_TOKEN("AT_SIGN ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 3993 "y.tab.c"
    break;

  case 187: /* tff_term: tff_logic_formula  */
#line 596 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("tff_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3999 "y.tab.c"
    break;

  case 188: /* tff_term: defined_term  */
#line 597 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4005 "y.tab.c"
    break;

  case 189: /* tff_term: txf_tuple  */
#line 598 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4011 "y.tab.c"
    break;

  case 190: /* tff_unitary_term: tff_atomic_formula  */
#line 601 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4017 "y.tab.c"
    break;

  case 191: /* tff_unitary_term: defined_term  */
#line 602 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4023 "y.tab.c"
    break;

  case 192: /* tff_unitary_term: txf_tuple  */
#line 603 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4029 "y.tab.c"
    break;

  case 193: /* tff_unitary_term: variable  */
#line 604 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4035 "y.tab.c"
    break;

  case 194: /* tff_unitary_term: LPAREN tff_logic_formula RPAREN  */
#line 605 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("tff_unitary_term", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4041 "y.tab.c"
    break;

  case 195: /* txf_tuple: LBRKT RBRKT  */
#line 608 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("txf_tuple", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4047 "y.tab.c"
    break;

  case 196: /* txf_tuple: LBRKT tff_arguments RBRKT  */
#line 609 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("txf_tuple", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4053 "y.tab.c"
    break;

  case 197: /* tff_arguments: tff_term  */
#line 612 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4059 "y.tab.c"
    break;

  case 198: /* tff_arguments: tff_term COMMA tff_arguments  */
#line 613 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("tff_arguments", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4065 "y.tab.c"
    break;

  case 199: /* tff_atom_typing: typeable_atom COLON tff_top_level_type  */
#line 616 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("tff_atom_typing", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4071 "y.tab.c"
    break;

  case 200: /* tff_atom_typing: LPAREN tff_atom_typing RPAREN  */
#line 617 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("tff_atom_typing", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4077 "y.tab.c"
    break;

  case 201: /* tff_top_level_type: tff_atomic_type  */
#line 620 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4083 "y.tab.c"
    break;

  case 202: /* tff_top_level_type: tff_non_atomic_type  */
#line 621 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4089 "y.tab.c"
    break;

  case 203: /* tff_non_atomic_type: tff_mapping_type  */
#line 624 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_non_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4095 "y.tab.c"
    break;

  case 204: /* tff_non_atomic_type: tf1_quantified_type  */
#line 625 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_non_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4101 "y.tab.c"
    break;

  case 205: /* tff_non_atomic_type: LPAREN tff_non_atomic_type RPAREN  */
#line 626 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("tff_non_atomic_type", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4107 "y.tab.c"
    break;

  case 206: /* tf1_quantified_type: type_quantifier LBRKT tff_variable_list RBRKT COLON tff_monotype  */
#line 629 "SyntaxBNF.y"
                                                                                       {(yyval.pval) = P_BUILD("tf1_quantified_type", (yyvsp[-5].pval), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4113 "y.tab.c"
    break;

  case 207: /* tff_monotype: tff_atomic_type  */
#line 632 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_monotype", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4119 "y.tab.c"
    break;

  case 208: /* tff_monotype: LPAREN tff_mapping_type RPAREN  */
#line 633 "SyntaxBNF.y"
                                                     {(yyval.pval) = P_BUILD("tff_monotype", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4125 "y.tab.c"
    break;

  case 209: /* tff_monotype: tf1_quantified_type  */
#line 634 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_monotype", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4131 "y.tab.c"
    break;

  case 210: /* tff_unitary_type: tff_atomic_type  */
#line 637 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_unitary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4137 "y.tab.c"
    break;

  case 211: /* tff_unitary_type: LPAREN tff_xprod_type RPAREN  */
#line 638 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("tff_unitary_type", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4143 "y.tab.c"
    break;

  case 212: /* tff_atomic_type: type_constant  */
#line 641 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4149 "y.tab.c"
    break;

  case 213: /* tff_atomic_type: defined_type  */
#line 642 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4155 "y.tab.c"
    break;

  case 214: /* tff_atomic_type: variable  */
#line 643 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4161 "y.tab.c"
    break;

  case 215: /* tff_atomic_type: type_functor LPAREN tff_type_arguments RPAREN  */
#line 644 "SyntaxBNF.y"
                                                                    {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4167 "y.tab.c"
    break;

  case 216: /* tff_atomic_type: LPAREN tff_atomic_type RPAREN  */
#line 645 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("tff_atomic_type", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4173 "y.tab.c"
    break;

  case 217: /* tff_atomic_type: txf_tuple_type  */
#line 646 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4179 "y.tab.c"
    break;

  case 218: /* tff_type_arguments: tff_atomic_type  */
#line 649 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_type_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4185 "y.tab.c"
    break;

  case 219: /* tff_type_arguments: tff_atomic_type COMMA tff_type_arguments  */
#line 650 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("tff_type_arguments", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4191 "y.tab.c"
    break;

  case 220: /* tff_mapping_type: tff_unitary_type arrow tff_atomic_type  */
#line 653 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("tff_mapping_type", (yyvsp[-2].pval), P_TOKEN("arrow ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4197 "y.tab.c"
    break;

  case 221: /* tff_xprod_type: tff_unitary_type STAR tff_atomic_type  */
#line 656 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("tff_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4203 "y.tab.c"
    break;

  case 222: /* tff_xprod_type: tff_xprod_type STAR tff_atomic_type  */
#line 657 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("tff_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4209 "y.tab.c"
    break;

  case 223: /* txf_tuple_type: LBRKT tff_type_list RBRKT  */
#line 660 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("txf_tuple_type", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4215 "y.tab.c"
    break;

  case 224: /* tff_type_list: tff_top_level_type  */
#line 663 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_type_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4221 "y.tab.c"
    break;

  case 225: /* tff_type_list: tff_top_level_type COMMA tff_type_list  */
#line 664 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("tff_type_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4227 "y.tab.c"
    break;

  case 226: /* tff_subtype: atomic_type subtype_sign atomic_type  */
#line 667 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("tff_subtype", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4233 "y.tab.c"
    break;

  case 227: /* txf_definition: tff_atomic_formula identical tff_term  */
#line 670 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("txf_definition", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4239 "y.tab.c"
    break;

  case 228: /* txf_sequent: txf_tuple gentzen_arrow txf_tuple  */
#line 673 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("txf_sequent", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4245 "y.tab.c"
    break;

  case 229: /* nhf_long_connective: LBRACE ntf_connective_name RBRACE  */
#line 676 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("nhf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4251 "y.tab.c"
    break;

  case 230: /* nhf_long_connective: LBRACE ntf_connective_name LPAREN nhf_parameter_list RPAREN RBRACE  */
#line 677 "SyntaxBNF.y"
                                                                                         {(yyval.pval) = P_BUILD("nhf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-5].ival)), (yyvsp[-4].pval), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL);}
#line 4257 "y.tab.c"
    break;

  case 231: /* nhf_parameter_list: nhf_parameter  */
#line 680 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nhf_parameter_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4263 "y.tab.c"
    break;

  case 232: /* nhf_parameter_list: nhf_parameter COMMA nhf_parameter_list  */
#line 681 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("nhf_parameter_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4269 "y.tab.c"
    break;

  case 233: /* nhf_parameter: ntf_index  */
#line 684 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("nhf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4275 "y.tab.c"
    break;

  case 234: /* nhf_parameter: nhf_key_pair  */
#line 685 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nhf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4281 "y.tab.c"
    break;

  case 235: /* nhf_key_pair: thf_definition  */
#line 688 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("nhf_key_pair", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4287 "y.tab.c"
    break;

  case 236: /* nxf_long_connective: LBRACE ntf_connective_name RBRACE  */
#line 691 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("nxf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4293 "y.tab.c"
    break;

  case 237: /* nxf_long_connective: LBRACE ntf_connective_name LPAREN nxf_parameter_list RPAREN RBRACE  */
#line 692 "SyntaxBNF.y"
                                                                                         {(yyval.pval) = P_BUILD("nxf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-5].ival)), (yyvsp[-4].pval), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL);}
#line 4299 "y.tab.c"
    break;

  case 238: /* nxf_parameter_list: nxf_parameter  */
#line 695 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nxf_parameter_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4305 "y.tab.c"
    break;

  case 239: /* nxf_parameter_list: nxf_parameter COMMA nxf_parameter_list  */
#line 696 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("nxf_parameter_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4311 "y.tab.c"
    break;

  case 240: /* nxf_parameter: ntf_index  */
#line 699 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("nxf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4317 "y.tab.c"
    break;

  case 241: /* nxf_parameter: nxf_key_pair  */
#line 700 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nxf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4323 "y.tab.c"
    break;

  case 242: /* nxf_key_pair: txf_definition  */
#line 703 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("nxf_key_pair", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4329 "y.tab.c"
    break;

  case 243: /* ntf_connective_name: ntf_defined_connective  */
#line 706 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("ntf_connective_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4335 "y.tab.c"
    break;

  case 244: /* ntf_connective_name: atomic_system_word  */
#line 707 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("ntf_connective_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4341 "y.tab.c"
    break;

  case 245: /* ntf_defined_connective: atomic_defined_word  */
#line 710 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("ntf_defined_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4347 "y.tab.c"
    break;

  case 246: /* ntf_index: hash tff_unitary_term  */
#line 713 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("ntf_index", P_TOKEN("hash ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4353 "y.tab.c"
    break;

  case 247: /* ntf_short_connective: LBRKT PERIOD RBRKT  */
#line 716 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4359 "y.tab.c"
    break;

  case 248: /* ntf_short_connective: less_sign PERIOD arrow  */
#line 717 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("less_sign ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("arrow ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4365 "y.tab.c"
    break;

  case 249: /* ntf_short_connective: LBRACE PERIOD RBRACE  */
#line 718 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("LBRACE ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4371 "y.tab.c"
    break;

  case 250: /* ntf_short_connective: LPAREN PERIOD RPAREN  */
#line 719 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4377 "y.tab.c"
    break;

  case 251: /* tcf_formula: tcf_logic_formula  */
#line 722 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tcf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4383 "y.tab.c"
    break;

  case 252: /* tcf_formula: tff_atom_typing  */
#line 723 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tcf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4389 "y.tab.c"
    break;

  case 253: /* tcf_logic_formula: tcf_quantified_formula  */
#line 726 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("tcf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4395 "y.tab.c"
    break;

  case 254: /* tcf_logic_formula: cnf_formula  */
#line 727 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tcf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4401 "y.tab.c"
    break;

  case 255: /* tcf_quantified_formula: EXCLAMATION LBRKT tff_variable_list RBRKT COLON tcf_logic_formula  */
#line 730 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("tcf_quantified_formula", P_TOKEN("EXCLAMATION ", (yyvsp[-5].ival)), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4407 "y.tab.c"
    break;

  case 256: /* fof_formula: fof_logic_formula  */
#line 733 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("fof_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4413 "y.tab.c"
    break;

  case 257: /* fof_formula: fof_sequent  */
#line 734 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("fof_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4419 "y.tab.c"
    break;

  case 258: /* fof_logic_formula: fof_binary_formula  */
#line 737 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4425 "y.tab.c"
    break;

  case 259: /* fof_logic_formula: fof_unary_formula  */
#line 738 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("fof_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4431 "y.tab.c"
    break;

  case 260: /* fof_logic_formula: fof_unitary_formula  */
#line 739 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4437 "y.tab.c"
    break;

  case 261: /* fof_binary_formula: fof_binary_nonassoc  */
#line 742 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("fof_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4443 "y.tab.c"
    break;

  case 262: /* fof_binary_formula: fof_binary_assoc  */
#line 743 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4449 "y.tab.c"
    break;

  case 263: /* fof_binary_nonassoc: fof_unit_formula nonassoc_connective fof_unit_formula  */
#line 746 "SyntaxBNF.y"
                                                                            {(yyval.pval) = P_BUILD("fof_binary_nonassoc", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4455 "y.tab.c"
    break;

  case 264: /* fof_binary_assoc: fof_or_formula  */
#line 749 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("fof_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4461 "y.tab.c"
    break;

  case 265: /* fof_binary_assoc: fof_and_formula  */
#line 750 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4467 "y.tab.c"
    break;

  case 266: /* fof_or_formula: fof_unit_formula VLINE fof_unit_formula  */
#line 753 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("fof_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4473 "y.tab.c"
    break;

  case 267: /* fof_or_formula: fof_or_formula VLINE fof_unit_formula  */
#line 754 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("fof_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4479 "y.tab.c"
    break;

  case 268: /* fof_and_formula: fof_unit_formula AMPERSAND fof_unit_formula  */
#line 757 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("fof_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4485 "y.tab.c"
    break;

  case 269: /* fof_and_formula: fof_and_formula AMPERSAND fof_unit_formula  */
#line 758 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("fof_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4491 "y.tab.c"
    break;

  case 270: /* fof_unary_formula: unary_connective fof_unit_formula  */
#line 761 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("fof_unary_formula", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4497 "y.tab.c"
    break;

  case 271: /* fof_unary_formula: fof_infix_unary  */
#line 762 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4503 "y.tab.c"
    break;

  case 272: /* fof_infix_unary: fof_term infix_inequality fof_term  */
#line 765 "SyntaxBNF.y"
                                                     {(yyval.pval) = P_BUILD("fof_infix_unary", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4509 "y.tab.c"
    break;

  case 273: /* fof_unit_formula: fof_unitary_formula  */
#line 768 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4515 "y.tab.c"
    break;

  case 274: /* fof_unit_formula: fof_unary_formula  */
#line 769 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("fof_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4521 "y.tab.c"
    break;

  case 275: /* fof_unitary_formula: fof_quantified_formula  */
#line 772 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("fof_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4527 "y.tab.c"
    break;

  case 276: /* fof_unitary_formula: fof_atomic_formula  */
#line 773 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("fof_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4533 "y.tab.c"
    break;

  case 277: /* fof_unitary_formula: LPAREN fof_logic_formula RPAREN  */
#line 774 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("fof_unitary_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4539 "y.tab.c"
    break;

  case 278: /* fof_quantified_formula: fof_quantifier LBRKT fof_variable_list RBRKT COLON fof_unit_formula  */
#line 777 "SyntaxBNF.y"
                                                                                             {(yyval.pval) = P_BUILD("fof_quantified_formula", (yyvsp[-5].pval), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4545 "y.tab.c"
    break;

  case 279: /* fof_variable_list: variable  */
#line 780 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("fof_variable_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4551 "y.tab.c"
    break;

  case 280: /* fof_variable_list: variable COMMA fof_variable_list  */
#line 781 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("fof_variable_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4557 "y.tab.c"
    break;

  case 281: /* fof_atomic_formula: fof_plain_atomic_formula  */
#line 784 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("fof_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4563 "y.tab.c"
    break;

  case 282: /* fof_atomic_formula: fof_defined_atomic_formula  */
#line 785 "SyntaxBNF.y"
                                                 {(yyval.pval) = P_BUILD("fof_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4569 "y.tab.c"
    break;

  case 283: /* fof_atomic_formula: fof_system_atomic_formula  */
#line 786 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("fof_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4575 "y.tab.c"
    break;

  case 284: /* fof_plain_atomic_formula: fof_plain_term  */
#line 789 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_plain_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4581 "y.tab.c"
    break;

  case 285: /* fof_defined_atomic_formula: fof_defined_plain_formula  */
#line 792 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("fof_defined_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4587 "y.tab.c"
    break;

  case 286: /* fof_defined_atomic_formula: fof_defined_infix_formula  */
#line 793 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("fof_defined_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4593 "y.tab.c"
    break;

  case 287: /* fof_defined_plain_formula: fof_defined_plain_term  */
#line 796 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("fof_defined_plain_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4599 "y.tab.c"
    break;

  case 288: /* fof_defined_infix_formula: fof_term defined_infix_pred fof_term  */
#line 799 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("fof_defined_infix_formula", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4605 "y.tab.c"
    break;

  case 289: /* fof_system_atomic_formula: fof_system_term  */
#line 802 "SyntaxBNF.y"
                                            {(yyval.pval) = P_BUILD("fof_system_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4611 "y.tab.c"
    break;

  case 290: /* fof_plain_term: constant  */
#line 805 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("fof_plain_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4617 "y.tab.c"
    break;

  case 291: /* fof_plain_term: functor LPAREN fof_arguments RPAREN  */
#line 806 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("fof_plain_term", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4623 "y.tab.c"
    break;

  case 292: /* fof_defined_term: defined_term  */
#line 809 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("fof_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4629 "y.tab.c"
    break;

  case 293: /* fof_defined_term: fof_defined_atomic_term  */
#line 810 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("fof_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4635 "y.tab.c"
    break;

  case 294: /* fof_defined_atomic_term: fof_defined_plain_term  */
#line 813 "SyntaxBNF.y"
                                                 {(yyval.pval) = P_BUILD("fof_defined_atomic_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4641 "y.tab.c"
    break;

  case 295: /* fof_defined_plain_term: defined_constant  */
#line 816 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_defined_plain_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4647 "y.tab.c"
    break;

  case 296: /* fof_defined_plain_term: defined_functor LPAREN fof_arguments RPAREN  */
#line 817 "SyntaxBNF.y"
                                                                  {(yyval.pval) = P_BUILD("fof_defined_plain_term", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4653 "y.tab.c"
    break;

  case 297: /* fof_system_term: system_constant  */
#line 820 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("fof_system_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4659 "y.tab.c"
    break;

  case 298: /* fof_system_term: system_functor LPAREN fof_arguments RPAREN  */
#line 821 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("fof_system_term", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4665 "y.tab.c"
    break;

  case 299: /* fof_arguments: fof_term  */
#line 824 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("fof_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4671 "y.tab.c"
    break;

  case 300: /* fof_arguments: fof_term COMMA fof_arguments  */
#line 825 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("fof_arguments", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4677 "y.tab.c"
    break;

  case 301: /* fof_term: fof_function_term  */
#line 828 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("fof_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4683 "y.tab.c"
    break;

  case 302: /* fof_term: variable  */
#line 829 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("fof_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4689 "y.tab.c"
    break;

  case 303: /* fof_function_term: fof_plain_term  */
#line 832 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("fof_function_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4695 "y.tab.c"
    break;

  case 304: /* fof_function_term: fof_defined_term  */
#line 833 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_function_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4701 "y.tab.c"
    break;

  case 305: /* fof_function_term: fof_system_term  */
#line 834 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_function_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4707 "y.tab.c"
    break;

  case 306: /* fof_sequent: fof_formula_tuple gentzen_arrow fof_formula_tuple  */
#line 837 "SyntaxBNF.y"
                                                                {(yyval.pval) = P_BUILD("fof_sequent", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4713 "y.tab.c"
    break;

  case 307: /* fof_sequent: LPAREN fof_sequent RPAREN  */
#line 838 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("fof_sequent", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4719 "y.tab.c"
    break;

  case 308: /* fof_formula_tuple: LBRKT RBRKT  */
#line 841 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("fof_formula_tuple", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4725 "y.tab.c"
    break;

  case 309: /* fof_formula_tuple: LBRKT fof_formula_tuple_list RBRKT  */
#line 842 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("fof_formula_tuple", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4731 "y.tab.c"
    break;

  case 310: /* fof_formula_tuple_list: fof_logic_formula  */
#line 845 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("fof_formula_tuple_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4737 "y.tab.c"
    break;

  case 311: /* fof_formula_tuple_list: fof_logic_formula COMMA fof_formula_tuple_list  */
#line 846 "SyntaxBNF.y"
                                                                     {(yyval.pval) = P_BUILD("fof_formula_tuple_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4743 "y.tab.c"
    break;

  case 312: /* cnf_formula: cnf_disjunction  */
#line 849 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("cnf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4749 "y.tab.c"
    break;

  case 313: /* cnf_formula: LPAREN cnf_formula RPAREN  */
#line 850 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("cnf_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4755 "y.tab.c"
    break;

  case 314: /* cnf_disjunction: cnf_literal  */
#line 853 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("cnf_disjunction", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4761 "y.tab.c"
    break;

  case 315: /* cnf_disjunction: cnf_disjunction VLINE cnf_literal  */
#line 854 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("cnf_disjunction", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4767 "y.tab.c"
    break;

  case 316: /* cnf_literal: fof_atomic_formula  */
#line 857 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("cnf_literal", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4773 "y.tab.c"
    break;

  case 317: /* cnf_literal: TILDE fof_atomic_formula  */
#line 858 "SyntaxBNF.y"
                                               {(yyval.pval) = P_BUILD("cnf_literal", P_TOKEN("TILDE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4779 "y.tab.c"
    break;

  case 318: /* cnf_literal: TILDE LPAREN fof_atomic_formula RPAREN  */
#line 859 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("cnf_literal", P_TOKEN("TILDE ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4785 "y.tab.c"
    break;

  case 319: /* cnf_literal: fof_infix_unary  */
#line 860 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("cnf_literal", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4791 "y.tab.c"
    break;

  case 320: /* thf_quantifier: tff_quantifier  */
#line 863 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4797 "y.tab.c"
    break;

  case 321: /* thf_quantifier: th0_quantifier  */
#line 864 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4803 "y.tab.c"
    break;

  case 322: /* thf_quantifier: type_quantifier  */
#line 865 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4809 "y.tab.c"
    break;

  case 323: /* thf_unary_connective: unary_connective  */
#line 868 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4815 "y.tab.c"
    break;

  case 324: /* thf_unary_connective: ntf_short_connective  */
#line 869 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("thf_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4821 "y.tab.c"
    break;

  case 325: /* th0_quantifier: CARET  */
#line 872 "SyntaxBNF.y"
                       {(yyval.pval) = P_BUILD("th0_quantifier", P_TOKEN("CARET ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4827 "y.tab.c"
    break;

  case 326: /* th0_quantifier: AT_SIGN_PLUS  */
#line 873 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("th0_quantifier", P_TOKEN("AT_SIGN_PLUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4833 "y.tab.c"
    break;

  case 327: /* th0_quantifier: AT_SIGN_MINUS  */
#line 874 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("th0_quantifier", P_TOKEN("AT_SIGN_MINUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4839 "y.tab.c"
    break;

  case 328: /* type_quantifier: EXCLAMATION_GREATER  */
#line 877 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("type_quantifier", P_TOKEN("EXCLAMATION_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4845 "y.tab.c"
    break;

  case 329: /* type_quantifier: QUESTION_STAR  */
#line 878 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("type_quantifier", P_TOKEN("QUESTION_STAR ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4851 "y.tab.c"
    break;

  case 330: /* subtype_sign: LESS_LESS  */
#line 881 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("subtype_sign", P_TOKEN("LESS_LESS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4857 "y.tab.c"
    break;

  case 331: /* tff_unary_connective: unary_connective  */
#line 884 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4863 "y.tab.c"
    break;

  case 332: /* tff_unary_connective: ntf_short_connective  */
#line 885 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("tff_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4869 "y.tab.c"
    break;

  case 333: /* tff_quantifier: fof_quantifier  */
#line 888 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4875 "y.tab.c"
    break;

  case 334: /* tff_quantifier: hash  */
#line 889 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("tff_quantifier", P_TOKEN("hash ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4881 "y.tab.c"
    break;

  case 335: /* fof_quantifier: EXCLAMATION  */
#line 892 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("fof_quantifier", P_TOKEN("EXCLAMATION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4887 "y.tab.c"
    break;

  case 336: /* fof_quantifier: QUESTION  */
#line 893 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("fof_quantifier", P_TOKEN("QUESTION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4893 "y.tab.c"
    break;

  case 337: /* nonassoc_connective: LESS_EQUALS_GREATER  */
#line 896 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("LESS_EQUALS_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4899 "y.tab.c"
    break;

  case 338: /* nonassoc_connective: EQUALS_GREATER  */
#line 897 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("EQUALS_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4905 "y.tab.c"
    break;

  case 339: /* nonassoc_connective: LESS_EQUALS  */
#line 898 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("LESS_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4911 "y.tab.c"
    break;

  case 340: /* nonassoc_connective: LESS_TILDE_GREATER  */
#line 899 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("LESS_TILDE_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4917 "y.tab.c"
    break;

  case 341: /* nonassoc_connective: TILDE_VLINE  */
#line 900 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("TILDE_VLINE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4923 "y.tab.c"
    break;

  case 342: /* nonassoc_connective: TILDE_AMPERSAND  */
#line 901 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("TILDE_AMPERSAND ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4929 "y.tab.c"
    break;

  case 343: /* assoc_connective: VLINE  */
#line 904 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("assoc_connective", P_TOKEN("VLINE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4935 "y.tab.c"
    break;

  case 344: /* assoc_connective: AMPERSAND  */
#line 905 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("assoc_connective", P_TOKEN("AMPERSAND ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4941 "y.tab.c"
    break;

  case 345: /* unary_connective: TILDE  */
#line 908 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("unary_connective", P_TOKEN("TILDE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4947 "y.tab.c"
    break;

  case 346: /* gentzen_arrow: MINUS_MINUS_GREATER  */
#line 911 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("gentzen_arrow", P_TOKEN("MINUS_MINUS_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4953 "y.tab.c"
    break;

  case 347: /* assignment: COLON_EQUALS  */
#line 914 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("assignment", P_TOKEN("COLON_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4959 "y.tab.c"
    break;

  case 348: /* identical: EQUALS_EQUALS  */
#line 917 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("identical", P_TOKEN("EQUALS_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4965 "y.tab.c"
    break;

  case 349: /* typeable_atom: constant  */
#line 920 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("typeable_atom", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4971 "y.tab.c"
    break;

  case 350: /* typeable_atom: distinct_object  */
#line 921 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("typeable_atom", P_TOKEN("distinct_object ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4977 "y.tab.c"
    break;

  case 351: /* atomic_type: typeable_atom  */
#line 924 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4983 "y.tab.c"
    break;

  case 352: /* atomic_type: defined_constant  */
#line 925 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4989 "y.tab.c"
    break;

  case 353: /* atomic_type: system_type  */
#line 926 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4995 "y.tab.c"
    break;

  case 354: /* type_constant: type_functor  */
#line 929 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("type_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5001 "y.tab.c"
    break;

  case 355: /* type_functor: atomic_word  */
#line 932 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("type_functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5007 "y.tab.c"
    break;

  case 356: /* defined_type: atomic_defined_word  */
#line 935 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("defined_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5013 "y.tab.c"
    break;

  case 357: /* system_type: atomic_system_word  */
#line 938 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("system_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5019 "y.tab.c"
    break;

  case 358: /* defined_infix_pred: infix_equality  */
#line 941 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("defined_infix_pred", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5025 "y.tab.c"
    break;

  case 359: /* infix_equality: EQUALS  */
#line 944 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("infix_equality", P_TOKEN("EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5031 "y.tab.c"
    break;

  case 360: /* infix_inequality: EXCLAMATION_EQUALS  */
#line 947 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("infix_inequality", P_TOKEN("EXCLAMATION_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5037 "y.tab.c"
    break;

  case 361: /* constant: functor  */
#line 950 "SyntaxBNF.y"
                   {(yyval.pval) = P_BUILD("constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5043 "y.tab.c"
    break;

  case 362: /* functor: atomic_word  */
#line 953 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5049 "y.tab.c"
    break;

  case 363: /* defined_constant: defined_functor  */
#line 956 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("defined_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5055 "y.tab.c"
    break;

  case 364: /* defined_functor: atomic_defined_word  */
#line 959 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("defined_functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5061 "y.tab.c"
    break;

  case 365: /* system_constant: system_functor  */
#line 962 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("system_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5067 "y.tab.c"
    break;

  case 366: /* system_functor: atomic_system_word  */
#line 965 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("system_functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5073 "y.tab.c"
    break;

  case 367: /* th1_defined_term: EXCLAMATION_EXCLAMATION  */
#line 968 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("EXCLAMATION_EXCLAMATION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5079 "y.tab.c"
    break;

  case 368: /* th1_defined_term: QUESTION_QUESTION  */
#line 969 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("QUESTION_QUESTION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5085 "y.tab.c"
    break;

  case 369: /* th1_defined_term: AT_AT_SIGN_PLUS  */
#line 970 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("AT_AT_SIGN_PLUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5091 "y.tab.c"
    break;

  case 370: /* th1_defined_term: AT_AT_SIGN_MINUS  */
#line 971 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("AT_AT_SIGN_MINUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5097 "y.tab.c"
    break;

  case 371: /* th1_defined_term: AT_SIGN_EQUALS  */
#line 972 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("AT_SIGN_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5103 "y.tab.c"
    break;

  case 372: /* defined_term: number  */
#line 975 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5109 "y.tab.c"
    break;

  case 373: /* defined_term: distinct_object  */
#line 976 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("defined_term", P_TOKEN("distinct_object ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5115 "y.tab.c"
    break;

  case 374: /* variable: upper_word  */
#line 979 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("variable", P_TOKEN("upper_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5121 "y.tab.c"
    break;

  case 375: /* source: dag_source  */
#line 982 "SyntaxBNF.y"
                    {(yyval.pval) = P_BUILD("source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5127 "y.tab.c"
    break;

  case 376: /* source: internal_source  */
#line 983 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5133 "y.tab.c"
    break;

  case 377: /* source: external_source  */
#line 984 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5139 "y.tab.c"
    break;

  case 378: /* source: _LIT_unknown  */
#line 985 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("source", P_TOKEN("_LIT_unknown ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5145 "y.tab.c"
    break;

  case 379: /* source: LBRKT sources RBRKT  */
#line 986 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("source", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5151 "y.tab.c"
    break;

  case 380: /* sources: source  */
#line 989 "SyntaxBNF.y"
                 {(yyval.pval) = P_BUILD("sources", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5157 "y.tab.c"
    break;

  case 381: /* sources: source COMMA sources  */
#line 990 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("sources", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5163 "y.tab.c"
    break;

  case 382: /* dag_source: name  */
#line 993 "SyntaxBNF.y"
                  {(yyval.pval) = P_BUILD("dag_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5169 "y.tab.c"
    break;

  case 383: /* dag_source: inference_record  */
#line 994 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("dag_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5175 "y.tab.c"
    break;

  case 384: /* inference_record: _LIT_inference LPAREN inference_rule COMMA useful_info COMMA parents RPAREN  */
#line 997 "SyntaxBNF.y"
                                                                                               {(yyval.pval) = P_BUILD("inference_record", P_TOKEN("_LIT_inference ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 5181 "y.tab.c"
    break;

  case 385: /* inference_rule: atomic_word  */
#line 1000 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("inference_rule", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5187 "y.tab.c"
    break;

  case 386: /* internal_source: _LIT_introduced LPAREN intro_type COMMA useful_info COMMA parents RPAREN  */
#line 1003 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("internal_source", P_TOKEN("_LIT_introduced ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 5193 "y.tab.c"
    break;

  case 387: /* intro_type: atomic_word  */
#line 1006 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("intro_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5199 "y.tab.c"
    break;

  case 388: /* external_source: file_source  */
#line 1009 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("external_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5205 "y.tab.c"
    break;

  case 389: /* file_source: _LIT_file LPAREN file_name file_info RPAREN  */
#line 1012 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("file_source", P_TOKEN("_LIT_file ", (yyvsp[-4].ival)), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 5211 "y.tab.c"
    break;

  case 390: /* file_info: COMMA name  */
#line 1015 "SyntaxBNF.y"
                       {(yyval.pval) = P_BUILD("file_info", P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5217 "y.tab.c"
    break;

  case 391: /* file_info: nothing  */
#line 1016 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("file_info", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5223 "y.tab.c"
    break;

  case 392: /* parents: LBRKT RBRKT  */
#line 1019 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("parents", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5229 "y.tab.c"
    break;

  case 393: /* parents: LBRKT parent_list RBRKT  */
#line 1020 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("parents", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5235 "y.tab.c"
    break;

  case 394: /* parent_list: parent_info  */
#line 1023 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("parent_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5241 "y.tab.c"
    break;

  case 395: /* parent_list: parent_info COMMA parent_list  */
#line 1024 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("parent_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5247 "y.tab.c"
    break;

  case 396: /* parent_info: source parent_details  */
#line 1027 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("parent_info", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5253 "y.tab.c"
    break;

  case 397: /* parent_details: COLON general_term  */
#line 1030 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("parent_details", P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5259 "y.tab.c"
    break;

  case 398: /* parent_details: nothing  */
#line 1031 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("parent_details", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5265 "y.tab.c"
    break;

  case 399: /* optional_info: COMMA useful_info  */
#line 1034 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("optional_info", P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5271 "y.tab.c"
    break;

  case 400: /* optional_info: nothing  */
#line 1035 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("optional_info", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5277 "y.tab.c"
    break;

  case 401: /* useful_info: general_list  */
#line 1038 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("useful_info", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5283 "y.tab.c"
    break;

  case 402: /* include: _LIT_include LPAREN file_name include_optionals RPAREN PERIOD  */
#line 1041 "SyntaxBNF.y"
                                                                        {(yyval.pval) = P_BUILD("include", P_TOKEN("_LIT_include ", (yyvsp[-5].ival)), P_TOKEN("LPAREN ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL);}
#line 5289 "y.tab.c"
    break;

  case 403: /* include_optionals: nothing  */
#line 1044 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("include_optionals", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5295 "y.tab.c"
    break;

  case 404: /* include_optionals: COMMA formula_selection  */
#line 1045 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("include_optionals", P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5301 "y.tab.c"
    break;

  case 405: /* include_optionals: COMMA formula_selection COMMA space_name  */
#line 1046 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("include_optionals", P_TOKEN("COMMA ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5307 "y.tab.c"
    break;

  case 406: /* formula_selection: LBRKT name_list RBRKT  */
#line 1049 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("formula_selection", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5313 "y.tab.c"
    break;

  case 407: /* formula_selection: STAR  */
#line 1050 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("formula_selection", P_TOKEN("STAR ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5319 "y.tab.c"
    break;

  case 408: /* name_list: name  */
#line 1053 "SyntaxBNF.y"
                 {(yyval.pval) = P_BUILD("name_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5325 "y.tab.c"
    break;

  case 409: /* name_list: name COMMA name_list  */
#line 1054 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("name_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5331 "y.tab.c"
    break;

  case 410: /* space_name: name  */
#line 1057 "SyntaxBNF.y"
                  {(yyval.pval) = P_BUILD("space_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5337 "y.tab.c"
    break;

  case 411: /* general_term: general_data  */
#line 1060 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("general_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5343 "y.tab.c"
    break;

  case 412: /* general_term: general_data COLON general_term  */
#line 1061 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("general_term", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5349 "y.tab.c"
    break;

  case 413: /* general_term: general_list  */
#line 1062 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5355 "y.tab.c"
    break;

  case 414: /* general_data: atomic_word  */
#line 1065 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5361 "y.tab.c"
    break;

  case 415: /* general_data: general_function  */
#line 1066 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5367 "y.tab.c"
    break;

  case 416: /* general_data: variable  */
#line 1067 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5373 "y.tab.c"
    break;

  case 417: /* general_data: number  */
#line 1068 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5379 "y.tab.c"
    break;

  case 418: /* general_data: distinct_object  */
#line 1069 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("general_data", P_TOKEN("distinct_object ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5385 "y.tab.c"
    break;

  case 419: /* general_data: formula_data  */
#line 1070 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5391 "y.tab.c"
    break;

  case 420: /* general_function: atomic_word LPAREN general_terms RPAREN  */
#line 1073 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("general_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5397 "y.tab.c"
    break;

  case 421: /* formula_data: _DLR_thf LPAREN thf_formula RPAREN  */
#line 1076 "SyntaxBNF.y"
                                                  {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_thf ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5403 "y.tab.c"
    break;

  case 422: /* formula_data: _DLR_tff LPAREN tff_formula RPAREN  */
#line 1077 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_tff ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5409 "y.tab.c"
    break;

  case 423: /* formula_data: _DLR_fof LPAREN fof_formula RPAREN  */
#line 1078 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_fof ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5415 "y.tab.c"
    break;

  case 424: /* formula_data: _DLR_cnf LPAREN cnf_formula RPAREN  */
#line 1079 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_cnf ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5421 "y.tab.c"
    break;

  case 425: /* formula_data: _DLR_fot LPAREN fof_term RPAREN  */
#line 1080 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_fot ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5427 "y.tab.c"
    break;

  case 426: /* general_list: LBRKT RBRKT  */
#line 1083 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("general_list", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5433 "y.tab.c"
    break;

  case 427: /* general_list: LBRKT general_terms RBRKT  */
#line 1084 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("general_list", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5439 "y.tab.c"
    break;

  case 428: /* general_terms: general_term  */
#line 1087 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_terms", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5445 "y.tab.c"
    break;

  case 429: /* general_terms: general_term COMMA general_terms  */
#line 1088 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("general_terms", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5451 "y.tab.c"
    break;

  case 430: /* name: atomic_word  */
#line 1091 "SyntaxBNF.y"
                   {(yyval.pval) = P_BUILD("name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5457 "y.tab.c"
    break;

  case 431: /* name: integer  */
#line 1092 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("name", P_TOKEN("integer ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5463 "y.tab.c"
    break;

  case 432: /* atomic_word: lower_word  */
#line 1095 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("atomic_word", P_TOKEN("lower_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5469 "y.tab.c"
    break;

  case 433: /* atomic_word: single_quoted  */
#line 1096 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("atomic_word", P_TOKEN("single_quoted ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5475 "y.tab.c"
    break;

  case 434: /* atomic_word: back_quoted  */
#line 1097 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("atomic_word", P_TOKEN("back_quoted ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5481 "y.tab.c"
    break;

  case 435: /* atomic_defined_word: dollar_word  */
#line 1100 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("atomic_defined_word", P_TOKEN("dollar_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5487 "y.tab.c"
    break;

  case 436: /* atomic_system_word: dollar_dollar_word  */
#line 1103 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("atomic_system_word", P_TOKEN("dollar_dollar_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5493 "y.tab.c"
    break;

  case 437: /* number: integer  */
#line 1106 "SyntaxBNF.y"
                 {(yyval.pval) = P_BUILD("number", P_TOKEN("integer ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5499 "y.tab.c"
    break;

  case 438: /* number: rational  */
#line 1107 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("number", P_TOKEN("rational ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5505 "y.tab.c"
    break;

  case 439: /* number: real  */
#line 1108 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("number", P_TOKEN("real ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5511 "y.tab.c"
    break;

  case 440: /* file_name: atomic_word  */
#line 1111 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("file_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5517 "y.tab.c"
    break;

  case 441: /* nothing: %empty  */
#line 1114 "SyntaxBNF.y"
          {(yyval.pval) = P_BUILD("nothing",NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5523 "y.tab.c"
    break;


#line 5527 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

