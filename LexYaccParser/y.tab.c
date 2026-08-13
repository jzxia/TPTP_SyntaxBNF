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
#define YYLAST   3467

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  225
/* YYNRULES -- Number of rules.  */
#define YYNRULES  440
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  812

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
     419,   422,   423,   426,   427,   430,   431,   432,   435,   438,
     441,   442,   443,   446,   447,   450,   451,   454,   455,   458,
     461,   464,   467,   468,   469,   472,   473,   474,   475,   476,
     477,   480,   481,   484,   487,   488,   491,   492,   495,   496,
     499,   500,   501,   504,   505,   508,   509,   510,   511,   514,
     517,   520,   521,   524,   525,   528,   531,   532,   535,   538,
     541,   542,   543,   546,   547,   550,   553,   554,   555,   556,
     559,   562,   563,   566,   569,   570,   573,   574,   577,   578,
     581,   584,   585,   588,   589,   592,   595,   596,   597,   600,
     601,   602,   603,   604,   607,   608,   611,   612,   615,   616,
     619,   620,   623,   624,   625,   628,   631,   632,   633,   636,
     637,   640,   641,   642,   643,   644,   645,   648,   649,   652,
     655,   656,   659,   662,   663,   666,   669,   672,   675,   676,
     679,   680,   683,   684,   687,   690,   691,   694,   695,   698,
     699,   702,   705,   706,   709,   712,   715,   716,   717,   718,
     721,   722,   725,   726,   729,   732,   733,   736,   737,   738,
     741,   742,   745,   748,   749,   752,   753,   756,   757,   760,
     761,   764,   767,   768,   771,   772,   773,   776,   779,   780,
     783,   784,   785,   788,   791,   792,   795,   798,   801,   804,
     805,   808,   809,   812,   815,   816,   819,   820,   823,   824,
     827,   828,   831,   832,   833,   836,   837,   840,   841,   844,
     845,   848,   849,   852,   853,   856,   857,   858,   859,   862,
     863,   864,   867,   868,   871,   872,   873,   876,   877,   880,
     883,   884,   887,   888,   891,   892,   895,   896,   897,   898,
     899,   900,   903,   904,   907,   910,   913,   916,   919,   920,
     923,   924,   925,   928,   931,   934,   937,   940,   943,   946,
     949,   952,   955,   958,   961,   964,   967,   968,   969,   970,
     971,   974,   975,   978,   981,   982,   983,   984,   985,   988,
     989,   992,   993,   996,   999,  1002,  1005,  1008,  1011,  1014,
    1015,  1018,  1019,  1022,  1023,  1026,  1029,  1030,  1033,  1034,
    1037,  1040,  1043,  1044,  1045,  1048,  1049,  1052,  1053,  1056,
    1059,  1060,  1061,  1064,  1065,  1066,  1067,  1068,  1069,  1072,
    1075,  1076,  1077,  1078,  1079,  1082,  1083,  1086,  1087,  1090,
    1091,  1094,  1095,  1096,  1099,  1102,  1105,  1106,  1107,  1110,
    1113
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

#define YYPACT_NINF (-571)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-357)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -571,   460,  -571,  -571,    68,    99,   119,   134,   142,   151,
     172,  -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,
     412,   412,   217,   412,   412,   412,   412,  -571,  -571,  -571,
    -571,   146,  -571,   161,  -571,   188,   194,   196,   199,   231,
     179,   179,    75,   213,  -571,   179,   179,   179,   179,   252,
     280,   292,   412,  -571,   295,   289,   297,   315,   331,   341,
    1245,  2154,  1541,   322,   356,   412,  -571,   757,  3329,  2879,
    1541,  3392,   380,   382,   389,   394,   397,  -571,  -571,  -571,
    -571,  -571,  -571,  -571,   388,  -571,  -571,  -571,   405,  -571,
    2154,  1936,  -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,
    -571,  -571,   173,  -571,  -571,   210,   218,   261,  -571,   445,
     429,  -571,  -571,   455,  -571,   474,  -571,   480,  -571,  -571,
    -571,  -571,  -571,  -571,  -571,  1783,  1541,  -571,  -571,   445,
    -571,  -571,  -571,  -571,   446,   519,   131,  -571,   962,   140,
    -571,  -571,  -571,   499,   524,  2035,  -571,   412,  -571,  -571,
     530,  2445,   147,  -571,   445,  -571,  -571,  -571,   544,   547,
      80,  2621,  3176,   532,  -571,   535,   445,  -571,  -571,  -571,
    -571,   525,   567,  1353,   440,  -571,  -571,   450,  -571,  -571,
     506,  -571,  -571,  -571,   458,  -571,  -571,  -571,   261,   499,
    -571,  -571,  -571,  -571,   569,  -571,   516,   555,  -571,  -571,
     544,   564,  -571,   160,   559,   571,   573,  -571,   579,  -571,
     282,   583,  -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,
      80,  2372,  2549,  -571,  -571,   587,   445,  -571,  -571,  -571,
    -571,   556,   595,   609,   910,   536,  -571,  2948,   314,  -571,
    -571,   570,  -571,  -571,  -571,   400,  -571,  -571,   261,   499,
    -571,  -571,    95,  -571,  -571,   581,   548,  -571,  -571,  -571,
    -571,  -571,   598,  3017,  -571,  -571,  -571,  -571,   610,   564,
     160,  -571,   571,   597,  -571,   599,  -571,  -571,   311,   445,
    -571,  -571,   612,   601,  2154,  1541,  1146,  3329,  2879,  1245,
    1245,   602,  1146,  -571,   626,  -571,  -571,  1146,  -571,  1146,
    1124,   605,  -571,  1515,  1146,  1146,  1146,  2035,  -571,   632,
     613,   614,   617,   619,  2035,  2035,  2035,  -571,  -571,  -571,
    -571,  -571,  -571,  2035,  2035,  -571,   634,   585,  -571,  -571,
    -571,  -571,   585,   625,   629,  1127,   624,   150,  -571,  -571,
    -571,  3227,   627,  -571,  -571,   654,   306,   635,  -571,  -571,
     353,   633,   636,   622,   618,   643,  3380,  3380,  3380,  3380,
    3380,  -571,  3380,  2094,  2094,   672,   669,   674,  3227,  -571,
    -571,  -571,  -571,  -571,   585,  -571,   572,  3380,  3380,  3380,
     152,  2708,  -571,   686,   667,  -571,  -571,  -571,  -571,   675,
     677,   679,  3017,  -571,  -571,   610,  -571,  -571,   733,   681,
    2948,  2948,  2948,  2948,  2948,  2948,  2948,  -571,  -571,  -571,
     372,  -571,  -571,  2948,  1471,  1471,   683,  3155,  3155,  3155,
    3155,  3155,   585,  2708,  -571,  -571,  -571,  -571,  -571,  2948,
     572,  2948,  2948,   688,  1245,  -571,   693,   695,  -571,  -571,
    -571,   697,   698,   702,  -571,   706,  -571,   709,  -571,  -571,
    1124,   692,   708,   721,  -571,   736,  -571,  -571,  -571,  -571,
    -571,  -571,   720,  -571,   728,   754,   732,   742,  2035,  -571,
    -571,  -571,   745,  -571,  -571,  -571,  -571,  -571,  -571,   737,
     767,   747,   772,  -571,   776,  -571,   761,  1127,  1127,  -571,
    -571,  -571,   738,   740,  -571,  -571,   770,  -571,   769,  -571,
    -571,  -571,  -571,  -571,   699,  -571,  -571,  3380,  -571,  -571,
     466,   496,   496,  -571,   788,  -571,  -571,  -571,   773,  -571,
    -571,  -571,   485,  -571,  -571,  -571,  -571,  -571,  -571,  -571,
     189,  3278,  3380,  -571,  -571,  -571,  -571,  -571,  3380,   766,
     771,  -571,  -571,  -571,  -571,  -571,   774,   775,   785,  1276,
    -571,  2948,  -571,   495,  -571,  -571,   630,   630,   796,  -571,
     782,  -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,   189,
    1858,  2805,  -571,  -571,  -571,  -571,  -571,  2805,  -571,  -571,
     764,  -571,  -571,  -571,  -571,   790,   817,   820,   797,   609,
     828,   829,  -571,   764,  -571,  -571,  -571,   802,  -571,   803,
     810,  -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,   831,
     806,   217,   217,   217,   830,  -571,  -571,  -571,  -571,  1146,
    -571,  -571,  -571,  -571,   840,   585,   843,   585,   676,  -571,
     844,   824,   825,    88,   826,   101,   676,   585,   676,  2094,
     854,  -571,   842,   867,  -571,  -571,  -571,   847,   870,    74,
    -571,   851,   853,  -571,   882,  -571,  -571,  -571,  1604,   854,
    -571,   858,   877,  -571,  -571,  -571,   860,   883,  3086,  -571,
     862,   888,   585,  2948,  -571,  -571,  -571,  -571,  1124,  -571,
     887,   892,  -571,   896,  -571,  -571,  -571,  -571,  2035,  -571,
    1019,  -571,   676,  -571,  1127,  -571,  -571,   676,  -571,  -571,
     676,  -571,   866,   897,   875,  -571,   878,   699,  -571,   496,
    3278,  -571,   909,  -571,   915,  -571,  -571,  -571,  3380,   898,
     900,  -571,   901,  1276,  -571,   630,  2372,   915,   918,  -571,
    -571,  -571,  -571,  -571,  -571,   412,   905,  -571,   830,   830,
    -571,  -571,   826,  -571,  -571,  -571,   921,   676,  -571,  -571,
    -571,  -571,   931,   932,   911,   327,  3380,  -571,  3380,  -571,
    -571,  -571,  -571,   352,   935,   925,  2948,  2948,  -571,  -571,
     948,   949,  1485,  -571,   351,  -571,   927,  -571,  2948,  -571,
    -571,   928,   946,   946,   996,  -571,  -571,  -571,  -571,  -571,
    -571,  -571,   821,   938,   939,   996,   941,  -571,   968,   945,
     969,  -571,  -571,   950,  -571,  1245,  -571,  -571,  -571,  1124,
    -571,  -571
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     440,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     3,     4,    11,     6,     7,     8,     9,    10,     5,
       0,     0,     0,     0,     0,     0,     0,   433,   430,   431,
     432,     0,   429,     0,   439,   440,     0,     0,     0,     0,
       0,     0,     0,     0,   402,     0,     0,     0,     0,    21,
       0,     0,     0,   406,   403,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   407,     0,   401,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   417,   436,   437,
     438,   373,   415,    22,   410,   414,   418,   412,   413,   416,
       0,     0,   372,   435,   434,   318,   315,   280,   281,   284,
     285,   282,   283,   303,   292,   286,   288,     0,   300,   440,
     311,   313,   289,   360,   294,   362,   296,   364,   291,   301,
     361,   363,   365,   371,   334,     0,     0,   335,   344,   440,
     255,   257,   260,   261,   263,   264,   273,   270,     0,   272,
     274,   275,   256,     0,     0,     0,   405,     0,   404,   409,
       0,     0,   372,   251,   440,   250,   252,   253,     0,   289,
       0,     0,     0,     0,   333,     0,   440,   122,   127,   131,
     132,   134,   135,     0,   140,   147,   145,   141,   156,   157,
     146,   160,   161,   165,   142,   162,   169,   168,     0,   191,
     123,   124,   129,   130,     0,   331,     0,     0,   332,   330,
     350,     0,   352,   163,   360,   166,   362,   171,   364,   190,
     149,   365,   369,   368,   370,   326,   325,   324,   366,   327,
       0,     0,     0,   367,   328,     0,   440,    23,    28,    32,
      33,    36,    37,    38,     0,    45,    50,     0,    46,    59,
      60,    51,    63,    64,    70,    47,    65,    73,     0,    68,
      66,    24,     0,    34,   110,   111,   112,    25,    30,    31,
      72,   323,     0,     0,   320,   321,   319,   322,   350,     0,
      67,   360,    69,   362,    77,   364,    75,    74,    52,   440,
      13,   425,   427,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   316,     0,   358,   359,     0,   357,     0,
       0,     0,    20,     0,     0,     0,     0,     0,   307,   309,
       0,     0,     0,     0,     0,     0,     0,   337,   338,   336,
     339,   341,   340,     0,     0,   345,     0,     0,   273,   269,
     272,   408,     0,     0,     0,     0,     0,     0,   242,   244,
     243,     0,     0,   194,   186,   196,   188,     0,   163,   166,
     187,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   347,     0,     0,     0,     0,     0,     0,     0,   158,
     143,   144,   146,   149,     0,   329,     0,     0,     0,     0,
       0,     0,    96,   101,     0,    67,    69,   343,   342,     0,
       0,     0,    95,    91,    92,     0,    93,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    54,    45,    46,
      51,    47,    68,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    61,    48,    49,    51,    52,     0,
       0,     0,     0,     0,     0,   426,     0,     0,   302,   293,
     304,     0,     0,     0,   411,     0,   312,     0,   287,   271,
       0,     0,     0,     0,   377,   440,   374,   382,   375,   376,
     387,   381,     0,   314,     0,   298,     0,     0,     0,   308,
     276,   306,     0,   266,   268,   267,   265,   262,   305,     0,
     278,     0,   151,   153,   154,   199,     0,     0,     0,   198,
     201,   203,     0,   200,   202,   216,     0,   211,   353,   212,
     213,   354,   355,   248,     0,   235,   246,     0,   195,   249,
     148,     0,     0,   349,     0,   174,   348,   247,     0,   137,
     140,   141,   146,   142,   191,   139,   138,   136,   133,   226,
       0,     0,     0,   189,   170,   192,   159,   227,     0,     0,
       0,   350,   225,   351,   362,   356,     0,     0,     0,     0,
     228,     0,    97,    53,    71,   104,     0,     0,     0,    79,
       0,    40,    42,    44,    41,    43,    39,    35,   120,     0,
       0,     0,    88,    76,    89,    62,   121,     0,   108,   115,
     113,   114,   117,   116,   118,     0,    56,     0,     0,   109,
       0,   108,   103,   105,   107,   106,   119,     0,   100,     0,
       0,   428,   423,   422,   424,   421,   420,   419,   317,   379,
       0,     0,     0,     0,     0,    19,   399,    18,   290,     0,
     295,   297,   310,    17,     0,     0,     0,     0,     0,    16,
     223,     0,     0,     0,   209,     0,     0,     0,     0,     0,
       0,   241,     0,   237,   240,   239,   197,     0,   176,     0,
      15,     0,     0,   148,     0,   164,   167,   172,     0,     0,
     234,     0,   230,   233,   232,   102,     0,    81,     0,    14,
       0,     0,     0,     0,    53,    98,    99,    12,     0,   378,
     440,     0,   384,     0,   386,   398,   400,   299,     0,   279,
       0,   152,     0,   155,     0,   222,   204,     0,   215,   210,
       0,   219,     0,   217,     0,   245,     0,     0,   175,     0,
       0,   181,     0,   178,     0,   182,   193,   185,     0,     0,
       0,    95,     0,     0,    80,     0,     0,     0,     0,    83,
      90,    55,    57,    58,   380,     0,     0,   390,     0,     0,
     277,   254,     0,   224,   220,   221,     0,     0,   214,   236,
     238,   177,   160,   183,     0,   188,     0,   346,     0,   150,
     229,   231,    82,   101,    86,     0,     0,     0,   389,   388,
       0,     0,     0,   218,     0,   179,     0,   180,     0,    84,
      85,     0,     0,     0,     0,   208,   205,   206,   184,   173,
      87,    78,     0,     0,     0,     0,     0,   391,   440,     0,
     393,   383,   385,     0,   207,     0,   395,   397,   392,     0,
     396,   394
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,  -571,
    -571,    39,   494,   701,   -41,  -571,  -571,  -571,  -571,  -571,
    -376,    37,  -571,   592,  -571,  -571,   318,  -571,    45,  -212,
    -571,   552,  -571,  -571,  -571,   739,  -571,  -571,  -571,   258,
    -571,   332,   221,   117,  -571,   137,  -571,   574,  -275,  -196,
     334,  -269,  -571,  -571,  -356,  -571,  -571,  -571,  -520,  -571,
     717,     2,  -571,  -571,  -571,  -571,  -571,  -266,  -571,  -137,
    -571,  -571,  -314,  -571,  -571,  -251,   809,  -571,    70,  -570,
    -571,  -571,  -240,  -571,  -571,  -571,   299,  -571,   365,  -571,
     242,  -571,  -299,  -340,   132,  -278,   -46,   682,   531,   248,
    -571,  -432,   527,   275,   240,  -571,  -571,   333,  -571,  -477,
    -571,  -571,   302,  -571,  -571,  -571,   319,  -571,  -571,  -188,
    -571,  -468,   879,  -571,   338,  -571,   -40,   -54,  -571,  -571,
    -571,  -571,  -571,  -126,   -53,   -98,   -81,  -571,   409,   -36,
    -571,  -571,  -571,  -571,  -571,  -221,  -571,  -571,  -217,  -175,
    -257,   -14,  -571,   913,   711,   576,    14,  -571,   744,  -571,
    -154,  -571,  -274,   779,  -571,  1300,   -12,   -52,  -571,  1889,
     -76,   321,  -205,   -30,   -29,  -571,  -571,  -571,  -571,   -65,
      20,   -33,   561,   746,  1067,  1404,  1668,  1987,  -571,  2172,
     -26,  -290,   364,  -571,  -571,  -571,  -571,  -571,  -571,  -571,
    -571,   271,   246,  -571,  -571,  -571,  -354,  -571,  -571,  -571,
     917,  -571,   -49,  -571,  -571,  -571,  -452,  -224,    -8,   -19,
    1104,    34,   -51,   447,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    11,    12,    13,   279,    14,    15,    16,    17,
      18,   301,    50,   226,   383,   228,   229,   230,   231,   232,
     233,   234,   424,   235,   236,   237,   585,   586,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   558,   666,
     728,   764,   765,   248,   390,   412,   250,   597,   384,   251,
     592,   252,   594,   253,   254,   255,   256,   257,   258,   259,
     166,   344,   168,   169,   170,   171,   172,   173,   369,   174,
     175,   176,   481,   482,   483,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   514,   647,   712,   753,   714,
     754,   187,   345,   188,   346,   347,   333,   630,   490,   491,
     786,   492,   493,   704,   494,   635,   495,   631,   191,   192,
     193,   260,   661,   662,   663,   194,   642,   643,   644,   337,
     338,   645,   261,   154,   155,   156,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   479,   141,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     464,   107,   108,   142,   143,   310,   157,   110,   111,   262,
     263,   264,   265,   376,   196,   266,   198,   393,   394,   267,
     365,   766,   362,   158,   201,   497,   498,   499,   202,   297,
     396,   397,   385,   271,   386,   273,   274,   275,   276,   277,
     119,   609,   610,   456,   457,   681,   458,   683,   459,   460,
     736,   793,   799,   800,   806,   615,   685,    19,    43,    54,
      63,   148,   282,    84,    85,    86,    87,   283,   461,   120,
     121,   122,   123,    35,   302
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       2,    32,    32,    34,    32,    32,    32,    32,    95,    89,
     455,    83,    31,    33,    95,    36,    37,    38,    39,   328,
      89,   153,   190,   534,   536,    96,   391,   641,   227,   660,
     280,    96,   380,    32,    82,    44,   413,    95,   200,   268,
     269,    88,   210,   278,    64,    82,    32,   329,   466,   467,
     144,   426,    88,   589,    96,   293,   633,   149,   144,   370,
     540,   496,   581,   529,   330,   438,   445,   326,   392,   439,
     167,   309,   311,   595,   299,   109,   438,   294,   438,   711,
     439,   664,   439,   438,   438,   438,   324,   439,   439,   439,
     519,   525,   526,   527,   528,    20,   710,    52,    95,   546,
     547,   548,   211,   211,   291,   521,   521,   521,   521,   521,
     336,   440,    53,   144,   144,    96,   523,   523,   523,   523,
     523,   360,   440,   363,   440,   697,    21,   298,    32,   440,
     440,   440,   417,   144,    27,   210,   210,   699,   700,    64,
     752,    29,    93,    94,  -258,    30,    22,   636,   579,   580,
     582,   583,   584,  -259,   418,   364,   598,   598,  -349,    40,
     593,    23,   686,   419,   352,   291,  -258,  -258,   313,    24,
     373,  -348,  -349,   416,    41,  -259,  -259,   504,    25,   549,
     426,   389,   406,   414,   505,  -348,   550,  -302,   328,   328,
     328,  -302,   395,   334,   340,   278,   278,   328,   328,    26,
     189,    42,   559,   660,   711,   355,   249,    45,   298,    46,
     601,   278,    47,   496,   496,   415,   473,   474,   475,   520,
     520,   520,   520,   520,  -293,   476,   477,   392,  -293,   646,
     641,    95,  -304,   330,   330,   330,  -304,   428,    89,    89,
     444,   190,   330,   330,    48,   437,    49,   227,    96,    55,
      95,    93,    94,   311,   340,   664,   447,   200,   268,   269,
     652,   210,   278,    82,    82,   399,   372,    96,   298,   392,
      88,    88,   441,   144,   407,   295,   665,    27,   294,   296,
      60,    32,   409,   448,    29,   449,   686,   686,    30,   167,
     465,   465,   465,    61,   189,   144,  -192,   589,   436,   705,
    -192,   480,   144,   144,   144,    62,   484,   515,    65,   500,
      67,   144,   144,   691,   298,   210,   501,   595,   433,    66,
    -191,   211,   211,   702,  -191,   -89,   -27,   -27,    68,   -89,
     210,   210,   210,   210,   210,   325,   210,   535,   535,  -182,
     389,  -191,   210,   352,    69,  -191,   541,   542,   484,   -27,
     -27,   210,   210,   210,    70,   278,   325,   146,   249,   249,
     667,   391,   687,   803,   757,   551,   428,  -190,   395,   147,
     539,  -190,   568,   531,   278,   278,   278,   278,   278,   278,
     278,   380,   588,    89,   770,   771,   -88,   278,   574,   574,
     -88,   428,   428,   428,   428,   428,   587,   278,   438,   289,
     541,   596,   439,   278,   593,   278,   278,   284,    82,   285,
     545,    27,   -29,   -29,   309,    88,   286,   392,    29,   189,
     496,   287,    30,   392,   288,   249,   522,   522,   522,   522,
     522,    32,   290,   533,   533,   -29,   -29,   561,   562,   563,
     564,   565,   566,   567,   440,   409,   409,   409,   409,   409,
     409,   409,   759,  -125,   413,   616,   144,   776,   300,   777,
       3,   500,   500,  -126,   545,   648,   590,   521,   501,   501,
     303,  -128,    27,   189,   409,  -125,  -125,    28,   523,    29,
    -193,   210,   304,    30,  -193,  -126,  -126,   314,   524,   524,
     524,   524,   524,  -128,  -128,   524,   524,   537,   496,  -189,
     189,   305,   798,  -189,   721,   210,   210,   306,     4,   -90,
       5,     6,   210,   -90,     7,     8,     9,    10,   249,   798,
    -189,   361,   315,   512,  -189,   278,   395,   395,   325,   667,
     670,   573,   575,   124,   651,    51,   588,   160,   367,    56,
      57,    58,    59,   368,   278,   278,   327,   127,   -26,   -26,
     249,   278,   332,   576,   128,   335,    27,   513,  -348,   353,
     249,   163,   328,    29,   340,   354,   356,    30,   249,   249,
     357,   -26,   -26,  -108,   640,   366,    27,   374,    93,    94,
     164,   520,   165,    29,   -88,   361,   377,    30,   -88,   375,
     740,    81,    34,   682,   684,  -108,  -351,   400,   401,   480,
     378,   484,   500,   340,  -108,   465,   379,   330,  -356,   501,
     500,   484,   500,   535,   398,   402,   421,   501,   420,   501,
     422,   429,   112,   112,   431,   434,   432,   727,   159,   203,
     270,   112,    27,   513,    93,    94,   435,    95,   446,    29,
     295,   462,   278,    30,   511,   468,   587,   278,   469,   512,
     470,   112,   112,   471,    96,   472,   125,   557,   503,    32,
      81,   485,   506,   648,   189,   486,   500,   507,   500,   509,
     508,   500,   510,   501,   500,   501,   144,   517,   501,   518,
     737,   501,    27,   513,   210,   763,   112,   112,   249,    29,
      27,   513,   210,    30,   531,   395,   538,    29,   487,   551,
     278,    30,   552,   692,   342,   570,   112,   249,   249,   533,
     590,   553,   159,   554,   249,   555,    32,   560,   409,   611,
     530,   500,   348,   203,   600,   780,   781,   768,   501,   602,
     210,   603,   210,   604,   605,   612,    27,   727,   606,    94,
     278,   278,   607,    29,   163,   608,   500,    30,   613,   614,
     617,    81,   278,   501,    89,   556,   810,   348,   500,    27,
     557,    93,    94,   639,   618,   501,    29,   619,   620,   500,
      30,   524,   624,    32,   150,   623,   501,   640,   621,    82,
     625,   715,   626,   270,   151,   627,    88,   628,   522,   410,
      32,   629,   637,    27,   513,    91,   638,   636,   807,  -209,
      29,   649,   653,   650,    30,   249,   654,   113,   113,   668,
     655,   656,   669,   113,   204,   427,   113,    27,   152,    93,
      94,   657,    78,   418,    29,   671,    79,    80,    30,   408,
     672,   673,    81,   674,   404,   -45,   113,   113,   675,   676,
     677,   679,   755,   450,   678,   112,   112,   112,   203,   270,
     524,   688,    71,   112,   690,   425,   797,   694,   112,   695,
     112,   696,   698,   249,   112,   112,   112,   112,   112,   361,
     451,   113,   113,   452,   453,   112,   112,   112,   706,   454,
     707,    27,   708,   709,   112,   112,    28,   716,    29,   717,
     723,   113,    30,   718,   722,   724,   725,   113,   730,   731,
     735,   746,   348,   249,   249,   738,   715,   204,   204,   739,
     747,   748,   749,   403,   516,   249,   404,   348,   348,   348,
     348,   348,   756,   348,   348,   348,   317,   757,   336,   348,
     351,   767,   772,   318,   319,   760,   320,   516,   348,   348,
     348,   769,   204,  -181,   427,   774,   775,   195,   778,   321,
     322,   405,   410,   410,   410,   410,   410,   410,   410,   516,
     779,   782,   783,   789,   791,   316,   572,   572,   792,   427,
     427,   427,   427,   427,   801,   802,   411,   804,   317,   805,
     808,   410,   809,   762,   425,   318,   319,   697,   320,   443,
     732,   516,   408,   408,   408,   408,   408,   408,   408,   790,
     729,   321,   322,   323,   442,   371,   599,   733,   751,   578,
     578,   578,   578,   578,   713,   634,   788,   489,   487,   632,
     785,   591,   773,   795,   796,   761,   750,   743,   741,   112,
     113,   113,   113,   204,   689,   758,   150,   478,   113,   312,
     195,   195,   734,   113,   622,   113,    90,   463,   430,   113,
     113,   113,   113,   113,   794,   811,    27,    91,   680,    94,
     113,   113,   113,    29,   331,   348,     0,    30,   348,   113,
     113,    81,   516,   516,     0,   195,     0,     0,     0,    27,
      92,    93,    94,     0,    78,     0,    29,   204,    79,    80,
      30,     0,   348,   348,    81,     0,     0,     0,     0,   348,
       0,   659,   204,   204,   204,   204,   204,     0,   204,   204,
     204,     0,     0,     0,   204,     0,     0,   516,   516,     0,
       0,     0,     0,   204,   204,   204,     0,     0,   114,   114,
       0,     0,     0,     0,   114,   205,   272,   114,     0,   411,
     411,   411,   411,   411,   411,   411,   450,   219,     0,   487,
       0,     0,     0,     0,   488,   693,     0,   114,   114,     0,
     224,     0,     0,   701,     0,   703,   195,     0,   411,     0,
       0,     0,     0,   451,     0,     0,   452,   453,     0,     0,
     112,     0,   454,     0,    27,     0,     0,    27,     0,    28,
      94,    29,   114,   114,    29,    30,     0,     0,    30,     0,
     348,     0,    81,     0,     0,     0,    27,    92,    93,    94,
     348,    78,   114,    29,   113,    79,    80,    30,   114,   742,
     195,    81,     0,     0,   744,   410,     0,   745,   349,   349,
       0,     0,     0,     0,     0,   195,   195,   195,   195,   195,
       0,   195,     0,     0,     0,     0,     0,   195,     0,   112,
     204,   112,     0,   204,     0,     0,   195,   195,   195,     0,
       0,     0,     0,   349,   339,   591,     0,    71,   348,     0,
     516,   348,     0,     0,   703,   659,     0,   204,   204,   348,
     212,   213,     0,   214,   204,     0,   516,    72,    73,    74,
       0,    75,    76,     0,     0,   218,     0,   569,   570,   787,
       0,     0,     0,   658,     0,    27,    77,     0,   223,     0,
      78,   634,    29,     0,    79,    80,    30,   348,     0,   348,
      81,   225,   634,     0,   339,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   348,    27,    92,    93,    94,
     639,    78,     0,    29,     0,    79,    80,    30,     0,     0,
       0,   114,   114,   114,   205,   272,   358,     0,     0,   114,
       0,     0,     0,     0,   114,   113,   114,     0,   197,   317,
     114,   114,   114,   114,   114,     0,   318,   319,     0,   320,
       0,   114,   114,   114,     0,   204,   195,     0,     0,     0,
     114,   114,   321,   322,   359,   204,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   349,     0,
     195,   195,   411,     0,     0,     0,     0,   195,     0,     0,
       0,     0,     0,   349,   349,   349,   349,   349,     0,   349,
     349,   349,     0,     0,   113,   349,   113,     0,     0,   502,
       0,     0,     0,   543,   349,   349,   349,     0,     0,     0,
       0,     0,     0,   204,     0,     0,   204,     0,     0,     0,
       0,   197,   197,     0,   204,   115,   115,     0,     0,     0,
       0,   115,   206,     0,   115,   212,   213,     0,   214,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     218,     0,   569,   570,   115,   115,   197,   543,   571,     0,
       0,     0,   204,   223,   204,   219,     0,   487,     0,     0,
       0,     0,   784,     0,     0,     0,   225,     0,   224,     0,
     204,     0,     0,     0,     0,     0,     0,     0,     0,   115,
     115,    27,    92,    93,    94,   114,    78,     0,    29,     0,
      79,    80,    30,     0,     0,    27,    81,     0,    94,   115,
       0,     0,    29,    91,     0,   115,    30,     0,   124,     0,
      81,     0,     0,   125,     0,   206,   206,     0,   126,     0,
       0,   349,   127,     0,   349,    27,    92,    93,    94,   128,
      78,     0,    29,     0,    79,    80,    30,   197,     0,   195,
      81,   502,   502,     0,     0,     0,     0,   195,   349,   349,
     206,    27,    92,    93,    94,   349,    78,   387,    29,     0,
      79,    80,    30,     0,     0,     0,    81,     0,   295,     0,
     317,     0,   296,     0,     0,   719,   367,   318,   319,     0,
     320,   720,     0,     0,   339,   195,     0,   195,     0,     0,
       0,   197,   128,   321,   322,   388,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   197,   197,   197,   197,
     197,     0,   197,     0,     0,     0,     0,     0,   197,     0,
     165,     0,     0,   339,     0,     0,     0,   197,   197,   197,
       0,     0,     0,     0,     0,     0,   114,     0,   115,   115,
     115,   206,     0,     0,     0,     0,   115,     0,     0,     0,
       0,   115,     0,   115,     0,     0,   349,   115,   115,   115,
     115,   115,     0,     0,     0,     0,     0,     0,   115,   115,
     115,     0,     0,     0,     0,     0,     0,   115,   115,   116,
     116,     0,   502,     0,     0,   116,   207,     0,   116,     0,
     502,     0,   502,     0,     0,   206,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   114,     0,   114,   116,   116,
     206,   206,   206,   206,   206,     0,   206,   206,   206,     0,
       0,     0,   206,     0,   349,     0,     0,   349,     0,     0,
     544,   206,   206,   206,     0,   349,     0,     0,     0,     0,
       0,     0,     0,   116,   116,     0,   502,     0,   502,     0,
     124,   502,     0,     0,   502,     0,     0,   197,     0,     0,
     307,     0,     0,   116,   127,     0,     0,     0,   308,   116,
       0,   128,     0,   349,     0,   349,     0,     0,     0,   207,
     207,   197,   197,     0,   544,     0,     0,     0,   197,     0,
       0,     0,     0,    27,    92,    93,    94,     0,    78,     0,
      29,   502,    79,    80,    30,     0,     0,     0,    81,     0,
       0,     0,   212,   213,   207,   214,   215,   216,   217,     0,
       0,     0,   115,     0,     0,   124,   502,   218,   219,   220,
     221,     0,     0,     0,     0,   381,     0,     0,   502,   127,
     223,   224,     0,   382,     0,     0,   128,     0,     0,   502,
       0,     0,     0,   225,     0,     0,     0,     0,   206,     0,
       0,   206,     0,     0,     0,     0,     0,     0,    27,    92,
      93,    94,   164,    78,   165,    29,     0,    79,    80,    30,
       0,     0,     0,    81,     0,   206,   206,     0,     0,     0,
       0,     0,   206,     0,     0,     0,     0,     0,     0,     0,
       0,   145,   116,   116,   116,   207,     0,   199,     0,   145,
     116,     0,     0,   292,     0,   116,     0,   116,     0,     0,
       0,   116,   116,   116,   116,   116,     0,     0,     0,     0,
       0,     0,   116,   116,   116,     0,     0,     0,     0,     0,
       0,   116,   116,     0,     0,     0,    27,    92,    93,    94,
       0,    78,     0,    29,     0,    79,    80,    30,     0,   207,
     197,    81,     0,     0,   145,   145,     0,     0,   197,     0,
       0,     0,     0,   115,   207,   207,   207,   207,   207,     0,
     207,   207,   207,     0,   145,     0,   207,     0,     0,     0,
       0,     0,     0,   206,     0,   207,   207,   207,   117,   117,
     199,   199,   124,     0,   117,   208,   197,   117,   197,     0,
       0,     0,   307,     0,     0,     0,   127,     0,     0,     0,
       0,     0,     0,   128,     0,     0,     0,   117,   117,     0,
       0,     0,     0,     0,     0,   199,     0,     0,     0,     0,
       0,     0,   115,     0,   115,    27,    92,    93,    94,     0,
      78,     0,    29,     0,    79,    80,    30,     0,     0,     0,
      81,   206,   117,   117,   206,   530,   531,     0,     0,     0,
       0,   532,   206,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   117,     0,     0,     0,   116,     0,   117,   163,
       0,     0,     0,     0,     0,     0,     0,     0,   208,   208,
       0,     0,     0,     0,    27,    92,    93,    94,     0,    78,
     206,    29,   206,    79,    80,    30,     0,     0,     0,    81,
       0,     0,   207,     0,   145,   207,   199,     0,     0,     0,
       0,    90,     0,   208,     0,     0,     0,     0,     0,     0,
       0,     0,    91,     0,     0,     0,   145,     0,     0,   207,
     207,     0,     0,   145,   145,   145,   207,     0,     0,     0,
       0,     0,   145,   145,    27,    92,    93,    94,     0,    78,
       0,    29,     0,    79,    80,    30,     0,     0,     0,    81,
     199,     0,     0,   118,   118,     0,     0,     0,     0,   118,
     209,     0,   118,     0,     0,   199,   199,   199,   199,   199,
       0,   199,     0,     0,     0,     0,     0,   199,     0,     0,
       0,     0,   118,   118,     0,     0,   199,   199,   199,     0,
       0,   117,   117,   117,   208,     0,     0,     0,     0,   117,
       0,     0,     0,     0,   117,     0,   117,   116,     0,     0,
     117,   117,   117,   117,   117,     0,     0,   118,   118,     0,
       0,   117,   117,   117,     0,     0,     0,   207,     0,     0,
     117,   117,     0,     0,     0,     0,     0,   118,     0,     0,
       0,     0,     0,   118,     0,     0,     0,     0,   208,     0,
       0,     0,     0,   350,   209,     0,     0,     0,     0,     0,
       0,     0,     0,   208,   208,   208,   208,   208,     0,   208,
     208,   208,     0,     0,     0,   208,   116,   145,   116,     0,
       0,     0,     0,     0,   208,   208,   208,     0,     0,     0,
       0,     0,     0,     0,     0,   207,   212,   213,   207,   214,
     215,   216,   217,     0,     0,     0,   207,     0,     0,   124,
       0,   218,   219,   220,   221,     0,   199,     0,     0,   381,
       0,     0,   342,   127,   223,   224,     0,   382,     0,     0,
     128,     0,     0,     0,     0,     0,     0,   225,     0,     0,
     199,   199,     0,     0,   207,     0,   207,   199,     0,     0,
       0,     0,    27,    92,    93,    94,   164,    78,   165,    29,
       0,    79,    80,    30,     0,     0,     0,    81,     0,     0,
       0,     0,     0,     0,     0,   117,   118,   118,   118,   209,
       0,     0,     0,     0,   118,     0,     0,     0,     0,   118,
       0,   118,   151,     0,     0,   118,   118,   118,   118,   118,
       0,     0,     0,    91,     0,     0,   118,   118,   118,     0,
       0,   208,     0,     0,   208,   118,   118,     0,     0,     0,
       0,     0,     0,     0,     0,    27,   152,    93,    94,     0,
      78,     0,    29,   209,    79,    80,    30,     0,   208,   208,
      81,     0,     0,     0,     0,   208,     0,     0,   209,   209,
     209,   209,   209,     0,   350,   209,   209,     0,     0,     0,
     209,     0,     0,     0,     0,     0,     0,     0,     0,   350,
     350,   350,   387,   212,   213,     0,   214,   215,   216,   217,
       0,     0,     0,   295,     0,   317,   124,   296,   218,   219,
     220,   221,   318,   319,     0,   320,   222,   145,     0,   351,
     127,   223,   224,     0,     0,     0,     0,   128,   321,   322,
     388,     0,     0,     0,   225,     0,     0,     0,     0,   199,
       0,     0,     0,     0,     0,     0,   117,   199,     0,    27,
     152,    93,    94,   164,    78,   165,    29,     0,    79,    80,
      30,     0,     0,     0,    81,     0,   208,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   124,     0,
     118,     0,   160,   161,     0,   199,     0,   199,   341,     0,
       0,   342,   127,     0,     0,     0,   343,     0,     0,   128,
       0,     0,     0,     0,     0,     0,   163,     0,     0,     0,
       0,     0,     0,     0,     0,   117,     0,   117,     0,   350,
       0,    27,    92,    93,    94,   164,    78,   165,    29,     0,
      79,    80,    30,     0,   208,     0,    81,   208,     0,     0,
       0,     0,     0,   350,   209,   208,     0,     0,     0,     0,
     350,   387,   212,   213,     0,   214,   215,   216,   217,     0,
       0,     0,   295,     0,   317,   124,   296,   218,   219,   220,
     221,   318,   319,     0,   320,   381,     0,     0,   351,   127,
     223,   224,     0,   208,     0,   208,   128,   321,   322,   388,
       0,     0,     0,   225,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,    92,
      93,    94,   164,    78,   165,    29,     0,    79,    80,    30,
       0,     0,     0,    81,     0,     0,     0,     0,     0,     0,
       0,   118,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   387,   212,
     213,   209,   214,   215,   216,   217,     0,     0,     0,   295,
       0,   317,   124,   296,   218,   219,   220,   221,   318,   319,
       0,   320,   381,     0,     0,     0,   127,   223,   224,     0,
       0,     0,     0,   128,   321,   322,   388,     0,     0,     0,
     225,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     118,     0,   118,     0,     0,    27,    92,    93,    94,   164,
      78,   165,    29,     0,    79,    80,    30,     0,     0,     0,
      81,     0,   350,   212,   213,     0,   214,   215,   216,   217,
     209,     0,     0,     0,     0,     0,   124,     0,   218,   219,
     220,   221,     0,     0,     0,     0,   222,     0,     0,     0,
     127,   223,   224,     0,     0,     0,     0,   128,     0,     0,
       0,     0,     0,     0,   225,     0,     0,     0,   350,     0,
     350,     0,     0,     0,     0,     0,     0,     0,     0,    27,
     152,    93,    94,   164,    78,   165,    29,     0,    79,    80,
      30,     0,   212,   213,    81,   214,   215,   216,   217,     0,
       0,     0,     0,     0,     0,   124,     0,   218,   219,   220,
     221,     0,     0,     0,     0,   381,     0,     0,     0,   127,
     223,   224,     0,     0,     0,     0,   128,     0,     0,     0,
       0,     0,     0,   225,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,    92,
      93,    94,   164,    78,   165,    29,     0,    79,    80,    30,
       0,   212,   213,    81,   214,   215,   216,   217,     0,     0,
       0,     0,     0,     0,   124,     0,   218,   219,   220,   221,
       0,     0,     0,     0,   423,     0,     0,     0,   127,   223,
     224,     0,     0,     0,     0,   128,     0,     0,     0,     0,
       0,     0,   225,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,    92,    93,
      94,   164,    78,   165,    29,     0,    79,    80,    30,     0,
     212,   213,    81,   214,   215,   216,   217,     0,     0,     0,
       0,     0,     0,   124,     0,   218,   219,   220,   726,     0,
       0,     0,     0,   381,     0,     0,     0,   127,   223,   224,
       0,     0,     0,     0,   128,     0,     0,     0,     0,     0,
       0,   225,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,    92,    93,    94,
     164,    78,   165,    29,     0,    79,    80,    30,     0,   212,
     213,    81,   214,   215,   216,   217,     0,     0,     0,     0,
       0,     0,   124,     0,   218,   219,   569,   570,     0,     0,
       0,     0,   577,     0,     0,     0,   127,   223,   224,     0,
       0,     0,     0,   124,     0,     0,     0,   160,   161,     0,
     225,     0,     0,   162,     0,     0,   351,   127,     0,     0,
       0,     0,     0,     0,   128,    27,    92,    93,    94,   164,
      78,   163,    29,     0,    79,    80,    30,     0,     0,     0,
      81,     0,     0,     0,     0,     0,    27,   152,    93,    94,
     164,    78,   165,    29,   124,    79,    80,    30,   160,   161,
       0,    81,     0,     0,   341,     0,     0,   351,   127,     0,
       0,     0,     0,     0,     0,   128,     0,     0,     0,     0,
       0,     0,   163,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,    92,    93,
      94,   164,    78,   165,    29,   124,    79,    80,    30,   160,
     161,     0,    81,     0,     0,   341,     0,     0,     0,   127,
       0,     0,     0,   343,     0,     0,   128,     0,     0,     0,
       0,     0,     0,   163,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,    92,
      93,    94,   164,    78,   165,    29,   124,    79,    80,    30,
     160,   161,     0,    81,     0,     0,   162,     0,     0,     0,
     127,     0,     0,     0,     0,     0,     0,   128,     0,     0,
       0,     0,     0,     0,   163,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
     152,    93,    94,   164,    78,   165,    29,   124,    79,    80,
      30,   160,   161,     0,    81,     0,     0,   341,     0,     0,
       0,   127,     0,     0,    71,     0,     0,     0,   128,     0,
       0,     0,     0,     0,     0,   163,     0,   281,     0,     0,
       0,     0,     0,     0,    72,    73,    74,     0,    75,    76,
      27,    92,    93,    94,   164,    78,   165,    29,     0,    79,
      80,    30,    27,    77,     0,    81,     0,    78,     0,    29,
       0,    79,    80,    30,     0,     0,     0,    81
};

static const yytype_int16 yycheck[] =
{
       0,    20,    21,    22,    23,    24,    25,    26,    61,    60,
     300,    60,    20,    21,    67,    23,    24,    25,    26,   145,
      71,    67,    68,   363,   364,    61,   222,   504,    69,   549,
      70,    67,   220,    52,    60,    35,   241,    90,    68,    69,
      69,    60,    68,    69,    52,    71,    65,   145,   305,   306,
      62,   263,    71,   429,    90,    91,   488,    65,    70,   196,
     374,   335,   418,   362,   145,   286,   290,   143,   222,   286,
      68,   125,   126,   429,   107,    61,   297,    91,   299,   649,
     297,   549,   299,   304,   305,   306,   138,   304,   305,   306,
     356,   357,   358,   359,   360,    27,    22,    22,   151,   377,
     378,   379,    68,    69,    90,   356,   357,   358,   359,   360,
      30,   286,    37,   125,   126,   151,   356,   357,   358,   359,
     360,   173,   297,   188,   299,    37,    27,   107,   147,   304,
     305,   306,    37,   145,    60,   161,   162,    36,    37,   147,
     710,    67,    62,    63,    13,    71,    27,    59,   417,   418,
     419,   420,   421,    13,    59,   188,   431,   432,    11,    13,
     429,    27,   614,    68,   162,   151,    35,    36,   129,    27,
     196,    11,    25,   249,    13,    35,    36,    27,    27,    27,
     392,   222,   234,   248,    34,    25,    34,    14,   314,   315,
     316,    18,   222,   154,   160,   221,   222,   323,   324,    27,
      68,    13,   398,   723,   774,   166,    69,    13,   188,    13,
     434,   237,    13,   487,   488,   248,   314,   315,   316,   356,
     357,   358,   359,   360,    14,   323,   324,   381,    18,   507,
     707,   284,    14,   314,   315,   316,    18,   263,   289,   290,
     289,   287,   323,   324,    13,   285,    67,   288,   284,    36,
     303,    62,    63,   307,   220,   723,   292,   287,   288,   288,
     538,   287,   288,   289,   290,   226,   196,   303,   248,   423,
     289,   290,   286,   285,   237,    14,   551,    60,   292,    18,
      28,   300,   237,   297,    67,   299,   738,   739,    71,   287,
     304,   305,   306,    13,   162,   307,    14,   673,   284,   639,
      18,   327,   314,   315,   316,    13,   332,   353,    13,   335,
      13,   323,   324,   627,   294,   341,   335,   673,   279,    30,
      14,   287,   288,   637,    18,    14,    12,    13,    13,    18,
     356,   357,   358,   359,   360,    29,   362,   363,   364,    12,
     381,    14,   368,   341,    13,    18,   376,   376,   374,    35,
      36,   377,   378,   379,    13,   381,    29,    35,   221,   222,
     556,   557,   619,   795,    12,    13,   392,    14,   398,    13,
     368,    18,   413,    22,   400,   401,   402,   403,   404,   405,
     406,   569,   423,   434,   738,   739,    14,   413,   414,   415,
      18,   417,   418,   419,   420,   421,   422,   423,   619,    11,
     430,   430,   619,   429,   673,   431,   432,    27,   434,    27,
     376,    60,    12,    13,   468,   434,    27,   571,    67,   287,
     694,    27,    71,   577,    27,   288,   356,   357,   358,   359,
     360,   450,    27,   363,   364,    35,    36,   400,   401,   402,
     403,   404,   405,   406,   619,   400,   401,   402,   403,   404,
     405,   406,   718,    13,   659,   455,   468,   756,    13,   758,
       0,   487,   488,    13,   430,   511,   429,   718,   487,   488,
      41,    13,    60,   341,   429,    35,    36,    65,   718,    67,
      14,   507,    27,    71,    18,    35,    36,    41,   356,   357,
     358,   359,   360,    35,    36,   363,   364,   365,   772,    14,
     368,    27,   792,    18,   658,   531,   532,    27,    48,    14,
      50,    51,   538,    18,    54,    55,    56,    57,   381,   809,
      14,    15,     3,    27,    18,   551,   556,   557,    29,   725,
     571,   414,   415,    17,   532,    41,   577,    21,    22,    45,
      46,    47,    48,    27,   570,   571,    22,    31,    12,    13,
     413,   577,    22,   416,    38,    11,    60,    61,    11,    27,
     423,    45,   688,    67,   530,    30,    41,    71,   431,   432,
       3,    35,    36,    37,   504,     6,    60,    22,    62,    63,
      64,   718,    66,    67,    14,    15,    27,    71,    18,    25,
     688,    75,   611,   612,   613,    59,    25,    41,     3,   625,
      27,   627,   628,   569,    68,   619,    27,   688,    25,   628,
     636,   637,   638,   639,    27,     6,    68,   636,    37,   638,
      22,    11,    61,    62,    27,    13,    27,   668,    67,    68,
      69,    70,    60,    61,    62,    63,    35,   690,    36,    67,
      14,    36,   668,    71,    22,    13,   672,   673,    35,    27,
      36,    90,    91,    36,   690,    36,    22,    27,    34,   678,
      75,    36,    35,   709,   532,    36,   692,    13,   694,    36,
      35,   697,    36,   692,   700,   694,   688,    59,   697,    36,
     680,   700,    60,    61,   710,   726,   125,   126,   551,    67,
      60,    61,   718,    71,    22,   725,    27,    67,    22,    13,
     726,    71,    35,    27,    30,    22,   145,   570,   571,   639,
     673,    36,   151,    36,   577,    36,   735,    36,   673,    27,
      21,   747,   161,   162,    36,   766,   767,   735,   747,    36,
     756,    36,   758,    36,    36,    27,    60,   778,    36,    63,
     766,   767,    36,    67,    45,    36,   772,    71,    27,    13,
      30,    75,   778,   772,   805,    22,   805,   196,   784,    60,
      27,    62,    63,    64,    36,   784,    67,    13,    36,   795,
      71,   639,    35,   792,    17,    30,   795,   707,    36,   805,
      13,   649,    35,   222,    27,    13,   805,    11,   718,   237,
     809,    30,    22,    60,    61,    38,    27,    59,   798,    59,
      67,    13,    36,    30,    71,   668,    35,    61,    62,    13,
      36,    36,    30,    67,    68,   263,    70,    60,    61,    62,
      63,    36,    65,    59,    67,    35,    69,    70,    71,   237,
      13,    11,    75,    36,     6,     6,    90,    91,    36,    36,
      30,    35,   710,    22,    13,   284,   285,   286,   287,   288,
     718,    11,    22,   292,    11,   263,    35,    13,   297,    35,
     299,    36,    36,   726,   303,   304,   305,   306,   307,    15,
      49,   125,   126,    52,    53,   314,   315,   316,    36,    58,
      13,    60,    35,    13,   323,   324,    65,    36,    67,    36,
      13,   145,    71,    11,    36,    35,    13,   151,    36,    11,
      13,    35,   341,   766,   767,    13,   774,   161,   162,    13,
      13,    36,    34,     3,   353,   778,     6,   356,   357,   358,
     359,   360,    13,   362,   363,   364,    16,    12,    30,   368,
      30,    13,    11,    23,    24,    34,    26,   376,   377,   378,
     379,    36,   196,    12,   392,    13,    35,    68,    13,    39,
      40,    41,   400,   401,   402,   403,   404,   405,   406,   398,
      35,    13,    13,    36,    36,     3,   414,   415,    22,   417,
     418,   419,   420,   421,    36,    36,   237,    36,    16,    11,
      35,   429,    13,   725,   392,    23,    24,    37,    26,   288,
     672,   430,   400,   401,   402,   403,   404,   405,   406,   778,
     668,    39,    40,    41,   287,   196,   432,   673,   709,   417,
     418,   419,   420,   421,   649,   488,   774,   335,    22,   488,
     772,   429,   747,    27,   784,   723,   707,   694,   690,   468,
     284,   285,   286,   287,   625,   714,    17,   326,   292,   126,
     161,   162,   678,   297,   468,   299,    27,   303,   269,   303,
     304,   305,   306,   307,   783,   809,    60,    38,   611,    63,
     314,   315,   316,    67,   147,   504,    -1,    71,   507,   323,
     324,    75,   511,   512,    -1,   196,    -1,    -1,    -1,    60,
      61,    62,    63,    -1,    65,    -1,    67,   341,    69,    70,
      71,    -1,   531,   532,    75,    -1,    -1,    -1,    -1,   538,
      -1,   549,   356,   357,   358,   359,   360,    -1,   362,   363,
     364,    -1,    -1,    -1,   368,    -1,    -1,   556,   557,    -1,
      -1,    -1,    -1,   377,   378,   379,    -1,    -1,    61,    62,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    -1,   400,
     401,   402,   403,   404,   405,   406,    22,    20,    -1,    22,
      -1,    -1,    -1,    -1,    27,   628,    -1,    90,    91,    -1,
      33,    -1,    -1,   636,    -1,   638,   287,    -1,   429,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    52,    53,    -1,    -1,
     619,    -1,    58,    -1,    60,    -1,    -1,    60,    -1,    65,
      63,    67,   125,   126,    67,    71,    -1,    -1,    71,    -1,
     639,    -1,    75,    -1,    -1,    -1,    60,    61,    62,    63,
     649,    65,   145,    67,   468,    69,    70,    71,   151,   692,
     341,    75,    -1,    -1,   697,   673,    -1,   700,   161,   162,
      -1,    -1,    -1,    -1,    -1,   356,   357,   358,   359,   360,
      -1,   362,    -1,    -1,    -1,    -1,    -1,   368,    -1,   688,
     504,   690,    -1,   507,    -1,    -1,   377,   378,   379,    -1,
      -1,    -1,    -1,   196,   160,   673,    -1,    22,   707,    -1,
     709,   710,    -1,    -1,   747,   723,    -1,   531,   532,   718,
       4,     5,    -1,     7,   538,    -1,   725,    42,    43,    44,
      -1,    46,    47,    -1,    -1,    19,    -1,    21,    22,   772,
      -1,    -1,    -1,    27,    -1,    60,    61,    -1,    32,    -1,
      65,   784,    67,    -1,    69,    70,    71,   756,    -1,   758,
      75,    45,   795,    -1,   220,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   774,    60,    61,    62,    63,
      64,    65,    -1,    67,    -1,    69,    70,    71,    -1,    -1,
      -1,   284,   285,   286,   287,   288,     3,    -1,    -1,   292,
      -1,    -1,    -1,    -1,   297,   619,   299,    -1,    68,    16,
     303,   304,   305,   306,   307,    -1,    23,    24,    -1,    26,
      -1,   314,   315,   316,    -1,   639,   507,    -1,    -1,    -1,
     323,   324,    39,    40,    41,   649,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   341,    -1,
     531,   532,   673,    -1,    -1,    -1,    -1,   538,    -1,    -1,
      -1,    -1,    -1,   356,   357,   358,   359,   360,    -1,   362,
     363,   364,    -1,    -1,   688,   368,   690,    -1,    -1,   335,
      -1,    -1,    -1,   376,   377,   378,   379,    -1,    -1,    -1,
      -1,    -1,    -1,   707,    -1,    -1,   710,    -1,    -1,    -1,
      -1,   161,   162,    -1,   718,    61,    62,    -1,    -1,    -1,
      -1,    67,    68,    -1,    70,     4,     5,    -1,     7,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    -1,    21,    22,    90,    91,   196,   430,    27,    -1,
      -1,    -1,   756,    32,   758,    20,    -1,    22,    -1,    -1,
      -1,    -1,    27,    -1,    -1,    -1,    45,    -1,    33,    -1,
     774,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,
     126,    60,    61,    62,    63,   468,    65,    -1,    67,    -1,
      69,    70,    71,    -1,    -1,    60,    75,    -1,    63,   145,
      -1,    -1,    67,    38,    -1,   151,    71,    -1,    17,    -1,
      75,    -1,    -1,    22,    -1,   161,   162,    -1,    27,    -1,
      -1,   504,    31,    -1,   507,    60,    61,    62,    63,    38,
      65,    -1,    67,    -1,    69,    70,    71,   287,    -1,   710,
      75,   487,   488,    -1,    -1,    -1,    -1,   718,   531,   532,
     196,    60,    61,    62,    63,   538,    65,     3,    67,    -1,
      69,    70,    71,    -1,    -1,    -1,    75,    -1,    14,    -1,
      16,    -1,    18,    -1,    -1,    21,    22,    23,    24,    -1,
      26,    27,    -1,    -1,   530,   756,    -1,   758,    -1,    -1,
      -1,   341,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   356,   357,   358,   359,
     360,    -1,   362,    -1,    -1,    -1,    -1,    -1,   368,    -1,
      66,    -1,    -1,   569,    -1,    -1,    -1,   377,   378,   379,
      -1,    -1,    -1,    -1,    -1,    -1,   619,    -1,   284,   285,
     286,   287,    -1,    -1,    -1,    -1,   292,    -1,    -1,    -1,
      -1,   297,    -1,   299,    -1,    -1,   639,   303,   304,   305,
     306,   307,    -1,    -1,    -1,    -1,    -1,    -1,   314,   315,
     316,    -1,    -1,    -1,    -1,    -1,    -1,   323,   324,    61,
      62,    -1,   628,    -1,    -1,    67,    68,    -1,    70,    -1,
     636,    -1,   638,    -1,    -1,   341,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   688,    -1,   690,    90,    91,
     356,   357,   358,   359,   360,    -1,   362,   363,   364,    -1,
      -1,    -1,   368,    -1,   707,    -1,    -1,   710,    -1,    -1,
     376,   377,   378,   379,    -1,   718,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   125,   126,    -1,   692,    -1,   694,    -1,
      17,   697,    -1,    -1,   700,    -1,    -1,   507,    -1,    -1,
      27,    -1,    -1,   145,    31,    -1,    -1,    -1,    35,   151,
      -1,    38,    -1,   756,    -1,   758,    -1,    -1,    -1,   161,
     162,   531,   532,    -1,   430,    -1,    -1,    -1,   538,    -1,
      -1,    -1,    -1,    60,    61,    62,    63,    -1,    65,    -1,
      67,   747,    69,    70,    71,    -1,    -1,    -1,    75,    -1,
      -1,    -1,     4,     5,   196,     7,     8,     9,    10,    -1,
      -1,    -1,   468,    -1,    -1,    17,   772,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    27,    -1,    -1,   784,    31,
      32,    33,    -1,    35,    -1,    -1,    38,    -1,    -1,   795,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,   504,    -1,
      -1,   507,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      -1,    -1,    -1,    75,    -1,   531,   532,    -1,    -1,    -1,
      -1,    -1,   538,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,   284,   285,   286,   287,    -1,    68,    -1,    70,
     292,    -1,    -1,    27,    -1,   297,    -1,   299,    -1,    -1,
      -1,   303,   304,   305,   306,   307,    -1,    -1,    -1,    -1,
      -1,    -1,   314,   315,   316,    -1,    -1,    -1,    -1,    -1,
      -1,   323,   324,    -1,    -1,    -1,    60,    61,    62,    63,
      -1,    65,    -1,    67,    -1,    69,    70,    71,    -1,   341,
     710,    75,    -1,    -1,   125,   126,    -1,    -1,   718,    -1,
      -1,    -1,    -1,   619,   356,   357,   358,   359,   360,    -1,
     362,   363,   364,    -1,   145,    -1,   368,    -1,    -1,    -1,
      -1,    -1,    -1,   639,    -1,   377,   378,   379,    61,    62,
     161,   162,    17,    -1,    67,    68,   756,    70,   758,    -1,
      -1,    -1,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    90,    91,    -1,
      -1,    -1,    -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,
      -1,    -1,   688,    -1,   690,    60,    61,    62,    63,    -1,
      65,    -1,    67,    -1,    69,    70,    71,    -1,    -1,    -1,
      75,   707,   125,   126,   710,    21,    22,    -1,    -1,    -1,
      -1,    27,   718,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   145,    -1,    -1,    -1,   468,    -1,   151,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,
      -1,    -1,    -1,    -1,    60,    61,    62,    63,    -1,    65,
     756,    67,   758,    69,    70,    71,    -1,    -1,    -1,    75,
      -1,    -1,   504,    -1,   285,   507,   287,    -1,    -1,    -1,
      -1,    27,    -1,   196,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    -1,   307,    -1,    -1,   531,
     532,    -1,    -1,   314,   315,   316,   538,    -1,    -1,    -1,
      -1,    -1,   323,   324,    60,    61,    62,    63,    -1,    65,
      -1,    67,    -1,    69,    70,    71,    -1,    -1,    -1,    75,
     341,    -1,    -1,    61,    62,    -1,    -1,    -1,    -1,    67,
      68,    -1,    70,    -1,    -1,   356,   357,   358,   359,   360,
      -1,   362,    -1,    -1,    -1,    -1,    -1,   368,    -1,    -1,
      -1,    -1,    90,    91,    -1,    -1,   377,   378,   379,    -1,
      -1,   284,   285,   286,   287,    -1,    -1,    -1,    -1,   292,
      -1,    -1,    -1,    -1,   297,    -1,   299,   619,    -1,    -1,
     303,   304,   305,   306,   307,    -1,    -1,   125,   126,    -1,
      -1,   314,   315,   316,    -1,    -1,    -1,   639,    -1,    -1,
     323,   324,    -1,    -1,    -1,    -1,    -1,   145,    -1,    -1,
      -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,   341,    -1,
      -1,    -1,    -1,   161,   162,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   356,   357,   358,   359,   360,    -1,   362,
     363,   364,    -1,    -1,    -1,   368,   688,   468,   690,    -1,
      -1,    -1,    -1,    -1,   377,   378,   379,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   707,     4,     5,   710,     7,
       8,     9,    10,    -1,    -1,    -1,   718,    -1,    -1,    17,
      -1,    19,    20,    21,    22,    -1,   507,    -1,    -1,    27,
      -1,    -1,    30,    31,    32,    33,    -1,    35,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,
     531,   532,    -1,    -1,   756,    -1,   758,   538,    -1,    -1,
      -1,    -1,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    -1,    -1,    -1,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   468,   284,   285,   286,   287,
      -1,    -1,    -1,    -1,   292,    -1,    -1,    -1,    -1,   297,
      -1,   299,    27,    -1,    -1,   303,   304,   305,   306,   307,
      -1,    -1,    -1,    38,    -1,    -1,   314,   315,   316,    -1,
      -1,   504,    -1,    -1,   507,   323,   324,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,    62,    63,    -1,
      65,    -1,    67,   341,    69,    70,    71,    -1,   531,   532,
      75,    -1,    -1,    -1,    -1,   538,    -1,    -1,   356,   357,
     358,   359,   360,    -1,   362,   363,   364,    -1,    -1,    -1,
     368,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   377,
     378,   379,     3,     4,     5,    -1,     7,     8,     9,    10,
      -1,    -1,    -1,    14,    -1,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    26,    27,   688,    -1,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,   710,
      -1,    -1,    -1,    -1,    -1,    -1,   619,   718,    -1,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    -1,    -1,    -1,    75,    -1,   639,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,
     468,    -1,    21,    22,    -1,   756,    -1,   758,    27,    -1,
      -1,    30,    31,    -1,    -1,    -1,    35,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   688,    -1,   690,    -1,   507,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    -1,   707,    -1,    75,   710,    -1,    -1,
      -1,    -1,    -1,   531,   532,   718,    -1,    -1,    -1,    -1,
     538,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
      -1,    -1,    14,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    26,    27,    -1,    -1,    30,    31,
      32,    33,    -1,   756,    -1,   758,    38,    39,    40,    41,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   619,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,   639,     7,     8,     9,    10,    -1,    -1,    -1,    14,
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    26,    27,    -1,    -1,    -1,    31,    32,    33,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     688,    -1,   690,    -1,    -1,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    -1,    -1,    -1,
      75,    -1,   710,     4,     5,    -1,     7,     8,     9,    10,
     718,    -1,    -1,    -1,    -1,    -1,    17,    -1,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,
      31,    32,    33,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,   756,    -1,
     758,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    -1,     4,     5,    75,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    31,
      32,    33,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      -1,     4,     5,    75,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    -1,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,
      33,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    -1,
       4,     5,    75,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    -1,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,    33,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    -1,     4,
       5,    75,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    27,    -1,    -1,    -1,    31,    32,    33,    -1,
      -1,    -1,    -1,    17,    -1,    -1,    -1,    21,    22,    -1,
      45,    -1,    -1,    27,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    60,    61,    62,    63,    64,
      65,    45,    67,    -1,    69,    70,    71,    -1,    -1,    -1,
      75,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,    63,
      64,    65,    66,    67,    17,    69,    70,    71,    21,    22,
      -1,    75,    -1,    -1,    27,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,
      63,    64,    65,    66,    67,    17,    69,    70,    71,    21,
      22,    -1,    75,    -1,    -1,    27,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    35,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,
      62,    63,    64,    65,    66,    67,    17,    69,    70,    71,
      21,    22,    -1,    75,    -1,    -1,    27,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    62,    63,    64,    65,    66,    67,    17,    69,    70,
      71,    21,    22,    -1,    75,    -1,    -1,    27,    -1,    -1,
      -1,    31,    -1,    -1,    22,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    44,    -1,    46,    47,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    60,    61,    -1,    75,    -1,    65,    -1,    67,
      -1,    69,    70,    71,    -1,    -1,    -1,    75
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
     239,    27,    27,    87,    13,    35,   232,   202,   221,   224,
     225,   227,   136,    89,   288,   293,    36,   215,   227,   227,
      22,    49,    52,    53,    58,   267,   269,   270,   272,   274,
     275,   294,    36,   234,   226,   227,   226,   226,    13,    35,
      36,    36,    36,   211,   211,   211,   211,   211,   230,   214,
     266,   148,   149,   150,   266,    36,    36,    22,    27,   173,
     174,   175,   177,   178,   180,   182,   238,   251,   252,   253,
     266,   295,   296,    34,    27,    34,    35,    13,    35,    36,
      36,    22,    27,    61,   161,   172,   258,    59,    36,   143,
     145,   151,   154,   158,   170,   143,   143,   143,   143,   168,
      21,    22,    27,   154,   169,   266,   169,   170,    27,   137,
     148,   249,   250,   260,   261,   297,   171,   171,   171,    27,
      34,    13,    35,    36,    36,    36,    22,    27,   114,   125,
      36,    97,    97,    97,    97,    97,    97,    97,    90,    21,
      22,    27,   107,   119,   266,   119,   121,    27,    99,   127,
     127,   130,   127,   127,   127,   102,   103,   266,    90,    96,
      97,    99,   126,   127,   128,   130,   250,   123,   124,   123,
      36,   293,    36,    36,    36,    36,    36,    36,    36,   267,
     268,    27,    27,    27,    13,   281,   300,    30,    36,    13,
      36,    36,   231,    30,    35,    13,    35,    13,    11,    30,
     173,   183,   174,   177,   178,   181,    59,    22,    27,    64,
     154,   185,   192,   193,   194,   197,   171,   162,   172,    13,
      30,   137,   171,    36,    35,    36,    36,    36,    27,   107,
     134,   188,   189,   190,   197,   124,   115,   125,    13,    30,
      90,    35,    13,    11,    36,    36,    36,    30,    13,    35,
     299,   271,   295,   273,   295,   282,   292,   226,    11,   214,
      11,   148,    27,   178,    13,    35,    36,    37,    36,    36,
      37,   178,   148,   178,   179,   169,    36,    13,    35,    13,
      22,   155,   163,   164,   165,   170,    36,    36,    11,    21,
      27,   236,    36,    13,    35,    13,    22,    90,   116,   117,
      36,    11,   102,   126,   268,    13,   276,   300,    13,    13,
     211,   200,   178,   183,   178,   178,    35,    13,    36,    34,
     192,   162,   155,   164,   166,   170,    13,    12,   247,   143,
      34,   188,   115,    90,   117,   118,   247,    13,   294,    36,
     282,   282,    11,   179,    13,    35,   168,   168,    13,    35,
      90,    90,    13,    13,    27,   175,   176,   178,   166,    36,
     118,    36,    22,   277,   277,    27,   180,    35,   267,   278,
     279,    36,    36,   177,    36,    11,   280,   300,    35,    13,
     288,   278
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
     123,   124,   124,   125,   125,   126,   126,   126,   127,   128,
     129,   129,   129,   130,   130,   131,   131,   132,   132,   133,
     134,   135,   136,   136,   136,   137,   137,   137,   137,   137,
     137,   138,   138,   139,   140,   140,   141,   141,   142,   142,
     143,   143,   143,   144,   144,   145,   145,   145,   145,   146,
     147,   148,   148,   149,   149,   150,   151,   151,   152,   153,
     154,   154,   154,   155,   155,   156,   157,   157,   157,   157,
     158,   159,   159,   160,   161,   161,   162,   162,   163,   163,
     164,   165,   165,   166,   166,   167,   168,   168,   168,   169,
     169,   169,   169,   169,   170,   170,   171,   171,   172,   172,
     173,   173,   174,   174,   174,   175,   176,   176,   176,   177,
     177,   178,   178,   178,   178,   178,   178,   179,   179,   180,
     181,   181,   182,   183,   183,   184,   185,   186,   187,   187,
     188,   188,   189,   189,   190,   191,   191,   192,   192,   193,
     193,   194,   195,   195,   196,   197,   198,   198,   198,   198,
     199,   199,   200,   200,   201,   202,   202,   203,   203,   203,
     204,   204,   205,   206,   206,   207,   207,   208,   208,   209,
     209,   210,   211,   211,   212,   212,   212,   213,   214,   214,
     215,   215,   215,   216,   217,   217,   218,   219,   220,   221,
     221,   222,   222,   223,   224,   224,   225,   225,   226,   226,
     227,   227,   228,   228,   228,   229,   229,   230,   230,   231,
     231,   232,   232,   233,   233,   234,   234,   234,   234,   235,
     235,   235,   236,   236,   237,   237,   237,   238,   238,   239,
     240,   240,   241,   241,   242,   242,   243,   243,   243,   243,
     243,   243,   244,   244,   245,   246,   247,   248,   249,   249,
     250,   250,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   264,   264,   264,
     264,   265,   265,   266,   267,   267,   267,   267,   267,   268,
     268,   269,   269,   270,   271,   272,   273,   274,   275,   276,
     276,   277,   277,   278,   278,   279,   280,   280,   281,   281,
     282,   283,   284,   284,   284,   285,   285,   286,   286,   287,
     288,   288,   288,   289,   289,   289,   289,   289,   289,   290,
     291,   291,   291,   291,   291,   292,   292,   293,   293,   294,
     294,   295,   295,   295,   296,   297,   298,   298,   298,   299,
     300
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
       1,     1,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       6,     1,     3,     1,     1,     3,     1,     1,     2,     3,
       1,     1,     1,     1,     4,     1,     1,     4,     1,     1,
       3,     1,     4,     8,     1,     3,     1,     3,     1,     3,
       3,     1,     1,     1,     3,     5,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     3,     1,     3,     3,     3,
       1,     1,     1,     1,     3,     6,     1,     3,     1,     1,
       3,     1,     1,     1,     4,     3,     1,     1,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     3,     3,     6,
       1,     3,     1,     1,     1,     3,     6,     1,     3,     1,
       1,     1,     1,     1,     1,     2,     3,     3,     3,     3,
       1,     1,     1,     1,     6,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     3,     3,     3,     3,     2,
       1,     3,     1,     1,     1,     1,     3,     6,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       4,     1,     1,     1,     1,     4,     1,     4,     1,     3,
       1,     1,     1,     1,     1,     3,     3,     2,     3,     1,
       3,     1,     3,     1,     3,     1,     2,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     1,     8,     1,     8,     1,     1,     5,     2,
       1,     2,     3,     1,     3,     2,     2,     1,     2,     1,
       1,     6,     1,     2,     4,     3,     1,     1,     3,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     2,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0
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
#line 2891 "y.tab.c"
    break;

  case 3: /* TPTP_file: TPTP_file TPTP_input  */
#line 230 "SyntaxBNF.y"
                                           {}
#line 2897 "y.tab.c"
    break;

  case 4: /* TPTP_input: annotated_formula  */
#line 233 "SyntaxBNF.y"
                               {P_PRINT((yyval.pval));}
#line 2903 "y.tab.c"
    break;

  case 5: /* TPTP_input: include  */
#line 234 "SyntaxBNF.y"
                              {P_PRINT((yyval.pval));}
#line 2909 "y.tab.c"
    break;

  case 6: /* annotated_formula: thf_annotated  */
#line 237 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2915 "y.tab.c"
    break;

  case 7: /* annotated_formula: tff_annotated  */
#line 238 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2921 "y.tab.c"
    break;

  case 8: /* annotated_formula: tcf_annotated  */
#line 239 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2927 "y.tab.c"
    break;

  case 9: /* annotated_formula: fof_annotated  */
#line 240 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2933 "y.tab.c"
    break;

  case 10: /* annotated_formula: cnf_annotated  */
#line 241 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2939 "y.tab.c"
    break;

  case 11: /* annotated_formula: tpi_annotated  */
#line 242 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("annotated_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2945 "y.tab.c"
    break;

  case 12: /* tpi_annotated: _LIT_tpi LPAREN name COMMA formula_role COMMA tpi_formula annotations RPAREN PERIOD  */
#line 245 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("tpi_annotated", P_TOKEN("_LIT_tpi ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2951 "y.tab.c"
    break;

  case 13: /* tpi_formula: fof_formula  */
#line 248 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("tpi_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2957 "y.tab.c"
    break;

  case 14: /* thf_annotated: _LIT_thf LPAREN name COMMA formula_role COMMA thf_formula annotations RPAREN PERIOD  */
#line 251 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("thf_annotated", P_TOKEN("_LIT_thf ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2963 "y.tab.c"
    break;

  case 15: /* tff_annotated: _LIT_tff LPAREN name COMMA formula_role COMMA tff_formula annotations RPAREN PERIOD  */
#line 254 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("tff_annotated", P_TOKEN("_LIT_tff ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2969 "y.tab.c"
    break;

  case 16: /* tcf_annotated: _LIT_tcf LPAREN name COMMA formula_role COMMA tcf_formula annotations RPAREN PERIOD  */
#line 257 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("tcf_annotated", P_TOKEN("_LIT_tcf ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2975 "y.tab.c"
    break;

  case 17: /* fof_annotated: _LIT_fof LPAREN name COMMA formula_role COMMA fof_formula annotations RPAREN PERIOD  */
#line 260 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("fof_annotated", P_TOKEN("_LIT_fof ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2981 "y.tab.c"
    break;

  case 18: /* cnf_annotated: _LIT_cnf LPAREN name COMMA formula_role COMMA cnf_formula annotations RPAREN PERIOD  */
#line 263 "SyntaxBNF.y"
                                                                                                    {(yyval.pval) = P_BUILD("cnf_annotated", P_TOKEN("_LIT_cnf ", (yyvsp[-9].ival)), P_TOKEN("LPAREN ", (yyvsp[-8].ival)), (yyvsp[-7].pval), P_TOKEN("COMMA ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)));}
#line 2987 "y.tab.c"
    break;

  case 19: /* annotations: COMMA source optional_info  */
#line 266 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("annotations", P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2993 "y.tab.c"
    break;

  case 20: /* annotations: nothing  */
#line 267 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("annotations", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 2999 "y.tab.c"
    break;

  case 21: /* formula_role: lower_word  */
#line 270 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("formula_role", P_TOKEN("lower_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3005 "y.tab.c"
    break;

  case 22: /* formula_role: lower_word MINUS general_term  */
#line 271 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("formula_role", P_TOKEN("lower_word ", (yyvsp[-2].ival)), P_TOKEN("MINUS ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3011 "y.tab.c"
    break;

  case 23: /* thf_formula: thf_logic_formula  */
#line 274 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3017 "y.tab.c"
    break;

  case 24: /* thf_formula: thf_atom_typing  */
#line 275 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3023 "y.tab.c"
    break;

  case 25: /* thf_formula: thf_subtype  */
#line 276 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("thf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3029 "y.tab.c"
    break;

  case 26: /* thf_logic_formula: thf_unitary_formula  */
#line 279 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3035 "y.tab.c"
    break;

  case 27: /* thf_logic_formula: thf_unary_formula  */
#line 280 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3041 "y.tab.c"
    break;

  case 28: /* thf_logic_formula: thf_binary_formula  */
#line 281 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3047 "y.tab.c"
    break;

  case 29: /* thf_logic_formula: thf_defined_infix  */
#line 282 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3053 "y.tab.c"
    break;

  case 30: /* thf_logic_formula: thf_definition  */
#line 283 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3059 "y.tab.c"
    break;

  case 31: /* thf_logic_formula: thf_sequent  */
#line 284 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("thf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3065 "y.tab.c"
    break;

  case 32: /* thf_binary_formula: thf_binary_nonassoc  */
#line 287 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3071 "y.tab.c"
    break;

  case 33: /* thf_binary_formula: thf_binary_assoc  */
#line 288 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3077 "y.tab.c"
    break;

  case 34: /* thf_binary_formula: thf_binary_type  */
#line 289 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3083 "y.tab.c"
    break;

  case 35: /* thf_binary_nonassoc: thf_unit_formula nonassoc_connective thf_unit_formula  */
#line 292 "SyntaxBNF.y"
                                                                            {(yyval.pval) = P_BUILD("thf_binary_nonassoc", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3089 "y.tab.c"
    break;

  case 36: /* thf_binary_assoc: thf_or_formula  */
#line 295 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("thf_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3095 "y.tab.c"
    break;

  case 37: /* thf_binary_assoc: thf_and_formula  */
#line 296 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3101 "y.tab.c"
    break;

  case 38: /* thf_binary_assoc: thf_apply_formula  */
#line 297 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3107 "y.tab.c"
    break;

  case 39: /* thf_or_formula: thf_unit_formula VLINE thf_unit_formula  */
#line 300 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("thf_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3113 "y.tab.c"
    break;

  case 40: /* thf_or_formula: thf_or_formula VLINE thf_unit_formula  */
#line 301 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("thf_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3119 "y.tab.c"
    break;

  case 41: /* thf_and_formula: thf_unit_formula AMPERSAND thf_unit_formula  */
#line 304 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3125 "y.tab.c"
    break;

  case 42: /* thf_and_formula: thf_and_formula AMPERSAND thf_unit_formula  */
#line 305 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3131 "y.tab.c"
    break;

  case 43: /* thf_apply_formula: thf_unit_formula AT_SIGN thf_unit_formula  */
#line 308 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_apply_formula", (yyvsp[-2].pval), P_TOKEN("AT_SIGN ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3137 "y.tab.c"
    break;

  case 44: /* thf_apply_formula: thf_apply_formula AT_SIGN thf_unit_formula  */
#line 309 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_apply_formula", (yyvsp[-2].pval), P_TOKEN("AT_SIGN ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3143 "y.tab.c"
    break;

  case 45: /* thf_unit_formula: thf_unitary_formula  */
#line 312 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3149 "y.tab.c"
    break;

  case 46: /* thf_unit_formula: thf_unary_formula  */
#line 313 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3155 "y.tab.c"
    break;

  case 47: /* thf_unit_formula: thf_defined_infix  */
#line 314 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3161 "y.tab.c"
    break;

  case 48: /* thf_preunit_formula: thf_unitary_formula  */
#line 317 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("thf_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3167 "y.tab.c"
    break;

  case 49: /* thf_preunit_formula: thf_prefix_unary  */
#line 318 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3173 "y.tab.c"
    break;

  case 50: /* thf_unitary_formula: thf_quantified_formula  */
#line 321 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("thf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3179 "y.tab.c"
    break;

  case 51: /* thf_unitary_formula: thf_atomic_formula  */
#line 322 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3185 "y.tab.c"
    break;

  case 52: /* thf_unitary_formula: variable  */
#line 323 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("thf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3191 "y.tab.c"
    break;

  case 53: /* thf_unitary_formula: LPAREN thf_logic_formula RPAREN  */
#line 324 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("thf_unitary_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3197 "y.tab.c"
    break;

  case 54: /* thf_quantified_formula: thf_quantification thf_unit_formula  */
#line 327 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("thf_quantified_formula", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3203 "y.tab.c"
    break;

  case 55: /* thf_quantification: thf_quantifier LBRKT thf_variable_list RBRKT COLON  */
#line 330 "SyntaxBNF.y"
                                                                        {(yyval.pval) = P_BUILD("thf_quantification", (yyvsp[-4].pval), P_TOKEN("LBRKT ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("RBRKT ", (yyvsp[-1].ival)), P_TOKEN("COLON ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 3209 "y.tab.c"
    break;

  case 56: /* thf_variable_list: thf_typed_variable  */
#line 333 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_variable_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3215 "y.tab.c"
    break;

  case 57: /* thf_variable_list: thf_typed_variable COMMA thf_variable_list  */
#line 334 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_variable_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3221 "y.tab.c"
    break;

  case 58: /* thf_typed_variable: variable COLON thf_top_level_type  */
#line 337 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("thf_typed_variable", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3227 "y.tab.c"
    break;

  case 59: /* thf_unary_formula: thf_prefix_unary  */
#line 340 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3233 "y.tab.c"
    break;

  case 60: /* thf_unary_formula: thf_infix_unary  */
#line 341 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3239 "y.tab.c"
    break;

  case 61: /* thf_prefix_unary: thf_unary_connective thf_preunit_formula  */
#line 344 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("thf_prefix_unary", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3245 "y.tab.c"
    break;

  case 62: /* thf_infix_unary: thf_unitary_term infix_inequality thf_unitary_term  */
#line 347 "SyntaxBNF.y"
                                                                     {(yyval.pval) = P_BUILD("thf_infix_unary", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3251 "y.tab.c"
    break;

  case 63: /* thf_atomic_formula: thf_plain_atomic  */
#line 350 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3257 "y.tab.c"
    break;

  case 64: /* thf_atomic_formula: thf_defined_atomic  */
#line 351 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3263 "y.tab.c"
    break;

  case 65: /* thf_atomic_formula: thf_system_atomic  */
#line 352 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3269 "y.tab.c"
    break;

  case 66: /* thf_atomic_formula: thf_fof_function  */
#line 353 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3275 "y.tab.c"
    break;

  case 67: /* thf_plain_atomic: constant  */
#line 356 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("thf_plain_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3281 "y.tab.c"
    break;

  case 68: /* thf_plain_atomic: thf_tuple  */
#line 357 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_plain_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3287 "y.tab.c"
    break;

  case 69: /* thf_defined_atomic: defined_constant  */
#line 360 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3293 "y.tab.c"
    break;

  case 70: /* thf_defined_atomic: thf_defined_term  */
#line 361 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3299 "y.tab.c"
    break;

  case 71: /* thf_defined_atomic: LPAREN thf_conn_term RPAREN  */
#line 362 "SyntaxBNF.y"
                                                  {(yyval.pval) = P_BUILD("thf_defined_atomic", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3305 "y.tab.c"
    break;

  case 72: /* thf_defined_atomic: nhf_long_connective  */
#line 363 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3311 "y.tab.c"
    break;

  case 73: /* thf_defined_atomic: thf_let  */
#line 364 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("thf_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3317 "y.tab.c"
    break;

  case 74: /* thf_defined_term: defined_term  */
#line 367 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3323 "y.tab.c"
    break;

  case 75: /* thf_defined_term: th1_defined_term  */
#line 368 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3329 "y.tab.c"
    break;

  case 76: /* thf_defined_infix: thf_unitary_term defined_infix_pred thf_unitary_term  */
#line 371 "SyntaxBNF.y"
                                                                         {(yyval.pval) = P_BUILD("thf_defined_infix", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3335 "y.tab.c"
    break;

  case 77: /* thf_system_atomic: system_constant  */
#line 374 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("thf_system_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3341 "y.tab.c"
    break;

  case 78: /* thf_let: _DLR_let LPAREN thf_let_types COMMA thf_let_defns COMMA thf_logic_formula RPAREN  */
#line 377 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("thf_let", P_TOKEN("_DLR_let ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 3347 "y.tab.c"
    break;

  case 79: /* thf_let_types: thf_atom_typing  */
#line 380 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_let_types", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3353 "y.tab.c"
    break;

  case 80: /* thf_let_types: LBRKT thf_atom_typing_list RBRKT  */
#line 381 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("thf_let_types", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3359 "y.tab.c"
    break;

  case 81: /* thf_atom_typing_list: thf_atom_typing  */
#line 384 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_atom_typing_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3365 "y.tab.c"
    break;

  case 82: /* thf_atom_typing_list: thf_atom_typing COMMA thf_atom_typing_list  */
#line 385 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_atom_typing_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3371 "y.tab.c"
    break;

  case 83: /* thf_let_defns: thf_let_defn  */
#line 388 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("thf_let_defns", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3377 "y.tab.c"
    break;

  case 84: /* thf_let_defns: LBRKT thf_let_defn_list RBRKT  */
#line 389 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("thf_let_defns", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3383 "y.tab.c"
    break;

  case 85: /* thf_let_defn: thf_logic_formula assignment thf_logic_formula  */
#line 392 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_let_defn", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3389 "y.tab.c"
    break;

  case 86: /* thf_let_defn_list: thf_let_defn  */
#line 395 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("thf_let_defn_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3395 "y.tab.c"
    break;

  case 87: /* thf_let_defn_list: thf_let_defn COMMA thf_let_defn_list  */
#line 396 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_let_defn_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3401 "y.tab.c"
    break;

  case 88: /* thf_unitary_term: thf_atomic_formula  */
#line 399 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3407 "y.tab.c"
    break;

  case 89: /* thf_unitary_term: variable  */
#line 400 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("thf_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3413 "y.tab.c"
    break;

  case 90: /* thf_unitary_term: LPAREN thf_logic_formula RPAREN  */
#line 401 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("thf_unitary_term", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3419 "y.tab.c"
    break;

  case 91: /* thf_conn_term: nonassoc_connective  */
#line 404 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3425 "y.tab.c"
    break;

  case 92: /* thf_conn_term: assoc_connective  */
#line 405 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3431 "y.tab.c"
    break;

  case 93: /* thf_conn_term: infix_equality  */
#line 406 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3437 "y.tab.c"
    break;

  case 94: /* thf_conn_term: infix_inequality  */
#line 407 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3443 "y.tab.c"
    break;

  case 95: /* thf_conn_term: thf_unary_connective  */
#line 408 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("thf_conn_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3449 "y.tab.c"
    break;

  case 96: /* thf_tuple: LBRKT RBRKT  */
#line 411 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("thf_tuple", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3455 "y.tab.c"
    break;

  case 97: /* thf_tuple: LBRKT thf_formula_list RBRKT  */
#line 412 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("thf_tuple", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3461 "y.tab.c"
    break;

  case 98: /* thf_fof_function: defined_functor LPAREN thf_arguments RPAREN  */
#line 415 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("thf_fof_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3467 "y.tab.c"
    break;

  case 99: /* thf_fof_function: system_functor LPAREN thf_arguments RPAREN  */
#line 416 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("thf_fof_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3473 "y.tab.c"
    break;

  case 100: /* thf_arguments: thf_formula_list  */
#line 419 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("thf_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3479 "y.tab.c"
    break;

  case 101: /* thf_formula_list: thf_logic_formula  */
#line 422 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_formula_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3485 "y.tab.c"
    break;

  case 102: /* thf_formula_list: thf_logic_formula COMMA thf_formula_list  */
#line 423 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("thf_formula_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3491 "y.tab.c"
    break;

  case 103: /* thf_atom_typing: typeable_atom COLON thf_top_level_type  */
#line 426 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("thf_atom_typing", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3497 "y.tab.c"
    break;

  case 104: /* thf_atom_typing: LPAREN thf_atom_typing RPAREN  */
#line 427 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("thf_atom_typing", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3503 "y.tab.c"
    break;

  case 105: /* thf_top_level_type: thf_unitary_type  */
#line 430 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3509 "y.tab.c"
    break;

  case 106: /* thf_top_level_type: thf_mapping_type  */
#line 431 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3515 "y.tab.c"
    break;

  case 107: /* thf_top_level_type: thf_apply_type  */
#line 432 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3521 "y.tab.c"
    break;

  case 108: /* thf_unitary_type: thf_unitary_formula  */
#line 435 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("thf_unitary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3527 "y.tab.c"
    break;

  case 109: /* thf_apply_type: thf_apply_formula  */
#line 438 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("thf_apply_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3533 "y.tab.c"
    break;

  case 110: /* thf_binary_type: thf_mapping_type  */
#line 441 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("thf_binary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3539 "y.tab.c"
    break;

  case 111: /* thf_binary_type: thf_xprod_type  */
#line 442 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_binary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3545 "y.tab.c"
    break;

  case 112: /* thf_binary_type: thf_union_type  */
#line 443 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_binary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3551 "y.tab.c"
    break;

  case 113: /* thf_mapping_type: thf_unitary_type arrow thf_unitary_type  */
#line 446 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_mapping_type", (yyvsp[-2].pval), P_TOKEN("arrow ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3557 "y.tab.c"
    break;

  case 114: /* thf_mapping_type: thf_unitary_type arrow thf_mapping_type  */
#line 447 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("thf_mapping_type", (yyvsp[-2].pval), P_TOKEN("arrow ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3563 "y.tab.c"
    break;

  case 115: /* thf_xprod_type: thf_unitary_type STAR thf_unitary_type  */
#line 450 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("thf_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3569 "y.tab.c"
    break;

  case 116: /* thf_xprod_type: thf_xprod_type STAR thf_unitary_type  */
#line 451 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3575 "y.tab.c"
    break;

  case 117: /* thf_union_type: thf_unitary_type plus thf_unitary_type  */
#line 454 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("thf_union_type", (yyvsp[-2].pval), P_TOKEN("plus ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3581 "y.tab.c"
    break;

  case 118: /* thf_union_type: thf_union_type plus thf_unitary_type  */
#line 455 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("thf_union_type", (yyvsp[-2].pval), P_TOKEN("plus ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3587 "y.tab.c"
    break;

  case 119: /* thf_subtype: atomic_type subtype_sign atomic_type  */
#line 458 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("thf_subtype", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3593 "y.tab.c"
    break;

  case 120: /* thf_definition: thf_atomic_formula identical thf_logic_formula  */
#line 461 "SyntaxBNF.y"
                                                                {(yyval.pval) = P_BUILD("thf_definition", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3599 "y.tab.c"
    break;

  case 121: /* thf_sequent: thf_tuple gentzen_arrow thf_tuple  */
#line 464 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("thf_sequent", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3605 "y.tab.c"
    break;

  case 122: /* tff_formula: tff_logic_formula  */
#line 467 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3611 "y.tab.c"
    break;

  case 123: /* tff_formula: tff_atom_typing  */
#line 468 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3617 "y.tab.c"
    break;

  case 124: /* tff_formula: tff_subtype  */
#line 469 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3623 "y.tab.c"
    break;

  case 125: /* tff_logic_formula: tff_unitary_formula  */
#line 472 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3629 "y.tab.c"
    break;

  case 126: /* tff_logic_formula: tff_unary_formula  */
#line 473 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3635 "y.tab.c"
    break;

  case 127: /* tff_logic_formula: tff_binary_formula  */
#line 474 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3641 "y.tab.c"
    break;

  case 128: /* tff_logic_formula: tff_defined_infix  */
#line 475 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3647 "y.tab.c"
    break;

  case 129: /* tff_logic_formula: txf_definition  */
#line 476 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3653 "y.tab.c"
    break;

  case 130: /* tff_logic_formula: txf_sequent  */
#line 477 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3659 "y.tab.c"
    break;

  case 131: /* tff_binary_formula: tff_binary_nonassoc  */
#line 480 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3665 "y.tab.c"
    break;

  case 132: /* tff_binary_formula: tff_binary_assoc  */
#line 481 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3671 "y.tab.c"
    break;

  case 133: /* tff_binary_nonassoc: tff_unit_formula nonassoc_connective tff_unit_formula  */
#line 484 "SyntaxBNF.y"
                                                                            {(yyval.pval) = P_BUILD("tff_binary_nonassoc", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3677 "y.tab.c"
    break;

  case 134: /* tff_binary_assoc: tff_or_formula  */
#line 487 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3683 "y.tab.c"
    break;

  case 135: /* tff_binary_assoc: tff_and_formula  */
#line 488 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3689 "y.tab.c"
    break;

  case 136: /* tff_or_formula: tff_unit_formula VLINE tff_unit_formula  */
#line 491 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("tff_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3695 "y.tab.c"
    break;

  case 137: /* tff_or_formula: tff_or_formula VLINE tff_unit_formula  */
#line 492 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("tff_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3701 "y.tab.c"
    break;

  case 138: /* tff_and_formula: tff_unit_formula AMPERSAND tff_unit_formula  */
#line 495 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("tff_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3707 "y.tab.c"
    break;

  case 139: /* tff_and_formula: tff_and_formula AMPERSAND tff_unit_formula  */
#line 496 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("tff_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3713 "y.tab.c"
    break;

  case 140: /* tff_unit_formula: tff_unitary_formula  */
#line 499 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3719 "y.tab.c"
    break;

  case 141: /* tff_unit_formula: tff_unary_formula  */
#line 500 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3725 "y.tab.c"
    break;

  case 142: /* tff_unit_formula: tff_defined_infix  */
#line 501 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3731 "y.tab.c"
    break;

  case 143: /* tff_preunit_formula: tff_unitary_formula  */
#line 504 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3737 "y.tab.c"
    break;

  case 144: /* tff_preunit_formula: tff_prefix_unary  */
#line 505 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_preunit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3743 "y.tab.c"
    break;

  case 145: /* tff_unitary_formula: tff_quantified_formula  */
#line 508 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("tff_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3749 "y.tab.c"
    break;

  case 146: /* tff_unitary_formula: tff_atomic_formula  */
#line 509 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3755 "y.tab.c"
    break;

  case 147: /* tff_unitary_formula: txf_unitary_formula  */
#line 510 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3761 "y.tab.c"
    break;

  case 148: /* tff_unitary_formula: LPAREN tff_logic_formula RPAREN  */
#line 511 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("tff_unitary_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3767 "y.tab.c"
    break;

  case 149: /* txf_unitary_formula: variable  */
#line 514 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("txf_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3773 "y.tab.c"
    break;

  case 150: /* tff_quantified_formula: tff_quantifier LBRKT tff_variable_list RBRKT COLON tff_unit_formula  */
#line 517 "SyntaxBNF.y"
                                                                                             {(yyval.pval) = P_BUILD("tff_quantified_formula", (yyvsp[-5].pval), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 3779 "y.tab.c"
    break;

  case 151: /* tff_variable_list: tff_variable  */
#line 520 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("tff_variable_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3785 "y.tab.c"
    break;

  case 152: /* tff_variable_list: tff_variable COMMA tff_variable_list  */
#line 521 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("tff_variable_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3791 "y.tab.c"
    break;

  case 153: /* tff_variable: tff_typed_variable  */
#line 524 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tff_variable", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3797 "y.tab.c"
    break;

  case 154: /* tff_variable: variable  */
#line 525 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_variable", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3803 "y.tab.c"
    break;

  case 155: /* tff_typed_variable: variable COLON tff_atomic_type  */
#line 528 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("tff_typed_variable", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3809 "y.tab.c"
    break;

  case 156: /* tff_unary_formula: tff_prefix_unary  */
#line 531 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3815 "y.tab.c"
    break;

  case 157: /* tff_unary_formula: tff_infix_unary  */
#line 532 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3821 "y.tab.c"
    break;

  case 158: /* tff_prefix_unary: tff_unary_connective tff_preunit_formula  */
#line 535 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("tff_prefix_unary", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3827 "y.tab.c"
    break;

  case 159: /* tff_infix_unary: tff_unitary_term infix_inequality tff_unitary_term  */
#line 538 "SyntaxBNF.y"
                                                                     {(yyval.pval) = P_BUILD("tff_infix_unary", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3833 "y.tab.c"
    break;

  case 160: /* tff_atomic_formula: tff_plain_atomic  */
#line 541 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3839 "y.tab.c"
    break;

  case 161: /* tff_atomic_formula: tff_defined_atomic  */
#line 542 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("tff_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3845 "y.tab.c"
    break;

  case 162: /* tff_atomic_formula: tff_system_atomic  */
#line 543 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3851 "y.tab.c"
    break;

  case 163: /* tff_plain_atomic: constant  */
#line 546 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("tff_plain_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3857 "y.tab.c"
    break;

  case 164: /* tff_plain_atomic: functor LPAREN tff_arguments RPAREN  */
#line 547 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("tff_plain_atomic", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3863 "y.tab.c"
    break;

  case 165: /* tff_defined_atomic: tff_defined_plain  */
#line 550 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_defined_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3869 "y.tab.c"
    break;

  case 166: /* tff_defined_plain: defined_constant  */
#line 553 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3875 "y.tab.c"
    break;

  case 167: /* tff_defined_plain: defined_functor LPAREN tff_arguments RPAREN  */
#line 554 "SyntaxBNF.y"
                                                                  {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3881 "y.tab.c"
    break;

  case 168: /* tff_defined_plain: nxf_atom  */
#line 555 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3887 "y.tab.c"
    break;

  case 169: /* tff_defined_plain: txf_let  */
#line 556 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("tff_defined_plain", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3893 "y.tab.c"
    break;

  case 170: /* tff_defined_infix: tff_unitary_term defined_infix_pred tff_unitary_term  */
#line 559 "SyntaxBNF.y"
                                                                         {(yyval.pval) = P_BUILD("tff_defined_infix", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3899 "y.tab.c"
    break;

  case 171: /* tff_system_atomic: system_constant  */
#line 562 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("tff_system_atomic", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3905 "y.tab.c"
    break;

  case 172: /* tff_system_atomic: system_functor LPAREN tff_arguments RPAREN  */
#line 563 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("tff_system_atomic", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3911 "y.tab.c"
    break;

  case 173: /* txf_let: _DLR_let LPAREN txf_let_types COMMA txf_let_defns COMMA tff_term RPAREN  */
#line 566 "SyntaxBNF.y"
                                                                                  {(yyval.pval) = P_BUILD("txf_let", P_TOKEN("_DLR_let ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 3917 "y.tab.c"
    break;

  case 174: /* txf_let_types: tff_atom_typing  */
#line 569 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("txf_let_types", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3923 "y.tab.c"
    break;

  case 175: /* txf_let_types: LBRKT tff_atom_typing_list RBRKT  */
#line 570 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("txf_let_types", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3929 "y.tab.c"
    break;

  case 176: /* tff_atom_typing_list: tff_atom_typing  */
#line 573 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_atom_typing_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3935 "y.tab.c"
    break;

  case 177: /* tff_atom_typing_list: tff_atom_typing COMMA tff_atom_typing_list  */
#line 574 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("tff_atom_typing_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3941 "y.tab.c"
    break;

  case 178: /* txf_let_defns: txf_let_defn  */
#line 577 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("txf_let_defns", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3947 "y.tab.c"
    break;

  case 179: /* txf_let_defns: LBRKT txf_let_defn_list RBRKT  */
#line 578 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("txf_let_defns", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3953 "y.tab.c"
    break;

  case 180: /* txf_let_defn: txf_let_LHS assignment tff_term  */
#line 581 "SyntaxBNF.y"
                                               {(yyval.pval) = P_BUILD("txf_let_defn", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3959 "y.tab.c"
    break;

  case 181: /* txf_let_LHS: tff_plain_atomic  */
#line 584 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("txf_let_LHS", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3965 "y.tab.c"
    break;

  case 182: /* txf_let_LHS: txf_tuple  */
#line 585 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("txf_let_LHS", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3971 "y.tab.c"
    break;

  case 183: /* txf_let_defn_list: txf_let_defn  */
#line 588 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("txf_let_defn_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3977 "y.tab.c"
    break;

  case 184: /* txf_let_defn_list: txf_let_defn COMMA txf_let_defn_list  */
#line 589 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("txf_let_defn_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3983 "y.tab.c"
    break;

  case 185: /* nxf_atom: nxf_long_connective AT_SIGN LPAREN tff_arguments RPAREN  */
#line 592 "SyntaxBNF.y"
                                                                   {(yyval.pval) = P_BUILD("nxf_atom", (yyvsp[-4].pval), P_TOKEN("AT_SIGN ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 3989 "y.tab.c"
    break;

  case 186: /* tff_term: tff_logic_formula  */
#line 595 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("tff_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 3995 "y.tab.c"
    break;

  case 187: /* tff_term: defined_term  */
#line 596 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4001 "y.tab.c"
    break;

  case 188: /* tff_term: txf_tuple  */
#line 597 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4007 "y.tab.c"
    break;

  case 189: /* tff_unitary_term: tff_atomic_formula  */
#line 600 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4013 "y.tab.c"
    break;

  case 190: /* tff_unitary_term: defined_term  */
#line 601 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4019 "y.tab.c"
    break;

  case 191: /* tff_unitary_term: txf_tuple  */
#line 602 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4025 "y.tab.c"
    break;

  case 192: /* tff_unitary_term: variable  */
#line 603 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_unitary_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4031 "y.tab.c"
    break;

  case 193: /* tff_unitary_term: LPAREN tff_logic_formula RPAREN  */
#line 604 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("tff_unitary_term", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4037 "y.tab.c"
    break;

  case 194: /* txf_tuple: LBRKT RBRKT  */
#line 607 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("txf_tuple", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4043 "y.tab.c"
    break;

  case 195: /* txf_tuple: LBRKT tff_arguments RBRKT  */
#line 608 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("txf_tuple", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4049 "y.tab.c"
    break;

  case 196: /* tff_arguments: tff_term  */
#line 611 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4055 "y.tab.c"
    break;

  case 197: /* tff_arguments: tff_term COMMA tff_arguments  */
#line 612 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("tff_arguments", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4061 "y.tab.c"
    break;

  case 198: /* tff_atom_typing: typeable_atom COLON tff_top_level_type  */
#line 615 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("tff_atom_typing", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4067 "y.tab.c"
    break;

  case 199: /* tff_atom_typing: LPAREN tff_atom_typing RPAREN  */
#line 616 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("tff_atom_typing", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4073 "y.tab.c"
    break;

  case 200: /* tff_top_level_type: tff_atomic_type  */
#line 619 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4079 "y.tab.c"
    break;

  case 201: /* tff_top_level_type: tff_non_atomic_type  */
#line 620 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_top_level_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4085 "y.tab.c"
    break;

  case 202: /* tff_non_atomic_type: tff_mapping_type  */
#line 623 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("tff_non_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4091 "y.tab.c"
    break;

  case 203: /* tff_non_atomic_type: tf1_quantified_type  */
#line 624 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_non_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4097 "y.tab.c"
    break;

  case 204: /* tff_non_atomic_type: LPAREN tff_non_atomic_type RPAREN  */
#line 625 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("tff_non_atomic_type", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4103 "y.tab.c"
    break;

  case 205: /* tf1_quantified_type: type_quantifier LBRKT tff_variable_list RBRKT COLON tff_monotype  */
#line 628 "SyntaxBNF.y"
                                                                                       {(yyval.pval) = P_BUILD("tf1_quantified_type", (yyvsp[-5].pval), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4109 "y.tab.c"
    break;

  case 206: /* tff_monotype: tff_atomic_type  */
#line 631 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_monotype", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4115 "y.tab.c"
    break;

  case 207: /* tff_monotype: LPAREN tff_mapping_type RPAREN  */
#line 632 "SyntaxBNF.y"
                                                     {(yyval.pval) = P_BUILD("tff_monotype", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4121 "y.tab.c"
    break;

  case 208: /* tff_monotype: tf1_quantified_type  */
#line 633 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("tff_monotype", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4127 "y.tab.c"
    break;

  case 209: /* tff_unitary_type: tff_atomic_type  */
#line 636 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_unitary_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4133 "y.tab.c"
    break;

  case 210: /* tff_unitary_type: LPAREN tff_xprod_type RPAREN  */
#line 637 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("tff_unitary_type", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4139 "y.tab.c"
    break;

  case 211: /* tff_atomic_type: type_constant  */
#line 640 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4145 "y.tab.c"
    break;

  case 212: /* tff_atomic_type: defined_type  */
#line 641 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4151 "y.tab.c"
    break;

  case 213: /* tff_atomic_type: variable  */
#line 642 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4157 "y.tab.c"
    break;

  case 214: /* tff_atomic_type: type_functor LPAREN tff_type_arguments RPAREN  */
#line 643 "SyntaxBNF.y"
                                                                    {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4163 "y.tab.c"
    break;

  case 215: /* tff_atomic_type: LPAREN tff_atomic_type RPAREN  */
#line 644 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("tff_atomic_type", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4169 "y.tab.c"
    break;

  case 216: /* tff_atomic_type: txf_tuple_type  */
#line 645 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4175 "y.tab.c"
    break;

  case 217: /* tff_type_arguments: tff_atomic_type  */
#line 648 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("tff_type_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4181 "y.tab.c"
    break;

  case 218: /* tff_type_arguments: tff_atomic_type COMMA tff_type_arguments  */
#line 649 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("tff_type_arguments", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4187 "y.tab.c"
    break;

  case 219: /* tff_mapping_type: tff_unitary_type arrow tff_atomic_type  */
#line 652 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("tff_mapping_type", (yyvsp[-2].pval), P_TOKEN("arrow ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4193 "y.tab.c"
    break;

  case 220: /* tff_xprod_type: tff_unitary_type STAR tff_atomic_type  */
#line 655 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("tff_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4199 "y.tab.c"
    break;

  case 221: /* tff_xprod_type: tff_xprod_type STAR tff_atomic_type  */
#line 656 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("tff_xprod_type", (yyvsp[-2].pval), P_TOKEN("STAR ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4205 "y.tab.c"
    break;

  case 222: /* txf_tuple_type: LBRKT tff_type_list RBRKT  */
#line 659 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("txf_tuple_type", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4211 "y.tab.c"
    break;

  case 223: /* tff_type_list: tff_top_level_type  */
#line 662 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("tff_type_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4217 "y.tab.c"
    break;

  case 224: /* tff_type_list: tff_top_level_type COMMA tff_type_list  */
#line 663 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("tff_type_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4223 "y.tab.c"
    break;

  case 225: /* tff_subtype: atomic_type subtype_sign atomic_type  */
#line 666 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("tff_subtype", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4229 "y.tab.c"
    break;

  case 226: /* txf_definition: tff_atomic_formula identical tff_term  */
#line 669 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("txf_definition", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4235 "y.tab.c"
    break;

  case 227: /* txf_sequent: txf_tuple gentzen_arrow txf_tuple  */
#line 672 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("txf_sequent", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4241 "y.tab.c"
    break;

  case 228: /* nhf_long_connective: LBRACE ntf_connective_name RBRACE  */
#line 675 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("nhf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4247 "y.tab.c"
    break;

  case 229: /* nhf_long_connective: LBRACE ntf_connective_name LPAREN nhf_parameter_list RPAREN RBRACE  */
#line 676 "SyntaxBNF.y"
                                                                                         {(yyval.pval) = P_BUILD("nhf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-5].ival)), (yyvsp[-4].pval), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL);}
#line 4253 "y.tab.c"
    break;

  case 230: /* nhf_parameter_list: nhf_parameter  */
#line 679 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nhf_parameter_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4259 "y.tab.c"
    break;

  case 231: /* nhf_parameter_list: nhf_parameter COMMA nhf_parameter_list  */
#line 680 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("nhf_parameter_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4265 "y.tab.c"
    break;

  case 232: /* nhf_parameter: ntf_index  */
#line 683 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("nhf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4271 "y.tab.c"
    break;

  case 233: /* nhf_parameter: nhf_key_pair  */
#line 684 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nhf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4277 "y.tab.c"
    break;

  case 234: /* nhf_key_pair: thf_definition  */
#line 687 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("nhf_key_pair", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4283 "y.tab.c"
    break;

  case 235: /* nxf_long_connective: LBRACE ntf_connective_name RBRACE  */
#line 690 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("nxf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4289 "y.tab.c"
    break;

  case 236: /* nxf_long_connective: LBRACE ntf_connective_name LPAREN nxf_parameter_list RPAREN RBRACE  */
#line 691 "SyntaxBNF.y"
                                                                                         {(yyval.pval) = P_BUILD("nxf_long_connective", P_TOKEN("LBRACE ", (yyvsp[-5].ival)), (yyvsp[-4].pval), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL);}
#line 4295 "y.tab.c"
    break;

  case 237: /* nxf_parameter_list: nxf_parameter  */
#line 694 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nxf_parameter_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4301 "y.tab.c"
    break;

  case 238: /* nxf_parameter_list: nxf_parameter COMMA nxf_parameter_list  */
#line 695 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("nxf_parameter_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4307 "y.tab.c"
    break;

  case 239: /* nxf_parameter: ntf_index  */
#line 698 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("nxf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4313 "y.tab.c"
    break;

  case 240: /* nxf_parameter: nxf_key_pair  */
#line 699 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("nxf_parameter", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4319 "y.tab.c"
    break;

  case 241: /* nxf_key_pair: txf_definition  */
#line 702 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("nxf_key_pair", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4325 "y.tab.c"
    break;

  case 242: /* ntf_connective_name: ntf_defined_connective  */
#line 705 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("ntf_connective_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4331 "y.tab.c"
    break;

  case 243: /* ntf_connective_name: atomic_system_word  */
#line 706 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("ntf_connective_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4337 "y.tab.c"
    break;

  case 244: /* ntf_defined_connective: atomic_defined_word  */
#line 709 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("ntf_defined_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4343 "y.tab.c"
    break;

  case 245: /* ntf_index: hash tff_unitary_term  */
#line 712 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("ntf_index", P_TOKEN("hash ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4349 "y.tab.c"
    break;

  case 246: /* ntf_short_connective: LBRKT PERIOD RBRKT  */
#line 715 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4355 "y.tab.c"
    break;

  case 247: /* ntf_short_connective: less_sign PERIOD arrow  */
#line 716 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("less_sign ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("arrow ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4361 "y.tab.c"
    break;

  case 248: /* ntf_short_connective: LBRACE PERIOD RBRACE  */
#line 717 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("LBRACE ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("RBRACE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4367 "y.tab.c"
    break;

  case 249: /* ntf_short_connective: LPAREN PERIOD RPAREN  */
#line 718 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("ntf_short_connective", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), P_TOKEN("PERIOD ", (yyvsp[-1].ival)), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4373 "y.tab.c"
    break;

  case 250: /* tcf_formula: tcf_logic_formula  */
#line 721 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tcf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4379 "y.tab.c"
    break;

  case 251: /* tcf_formula: tff_atom_typing  */
#line 722 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("tcf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4385 "y.tab.c"
    break;

  case 252: /* tcf_logic_formula: tcf_quantified_formula  */
#line 725 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("tcf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4391 "y.tab.c"
    break;

  case 253: /* tcf_logic_formula: cnf_formula  */
#line 726 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("tcf_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4397 "y.tab.c"
    break;

  case 254: /* tcf_quantified_formula: EXCLAMATION LBRKT tff_variable_list RBRKT COLON tcf_logic_formula  */
#line 729 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("tcf_quantified_formula", P_TOKEN("EXCLAMATION ", (yyvsp[-5].ival)), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4403 "y.tab.c"
    break;

  case 255: /* fof_formula: fof_logic_formula  */
#line 732 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("fof_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4409 "y.tab.c"
    break;

  case 256: /* fof_formula: fof_sequent  */
#line 733 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("fof_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4415 "y.tab.c"
    break;

  case 257: /* fof_logic_formula: fof_binary_formula  */
#line 736 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4421 "y.tab.c"
    break;

  case 258: /* fof_logic_formula: fof_unary_formula  */
#line 737 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("fof_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4427 "y.tab.c"
    break;

  case 259: /* fof_logic_formula: fof_unitary_formula  */
#line 738 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_logic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4433 "y.tab.c"
    break;

  case 260: /* fof_binary_formula: fof_binary_nonassoc  */
#line 741 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("fof_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4439 "y.tab.c"
    break;

  case 261: /* fof_binary_formula: fof_binary_assoc  */
#line 742 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_binary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4445 "y.tab.c"
    break;

  case 262: /* fof_binary_nonassoc: fof_unit_formula nonassoc_connective fof_unit_formula  */
#line 745 "SyntaxBNF.y"
                                                                            {(yyval.pval) = P_BUILD("fof_binary_nonassoc", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4451 "y.tab.c"
    break;

  case 263: /* fof_binary_assoc: fof_or_formula  */
#line 748 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("fof_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4457 "y.tab.c"
    break;

  case 264: /* fof_binary_assoc: fof_and_formula  */
#line 749 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_binary_assoc", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4463 "y.tab.c"
    break;

  case 265: /* fof_or_formula: fof_unit_formula VLINE fof_unit_formula  */
#line 752 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("fof_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4469 "y.tab.c"
    break;

  case 266: /* fof_or_formula: fof_or_formula VLINE fof_unit_formula  */
#line 753 "SyntaxBNF.y"
                                                            {(yyval.pval) = P_BUILD("fof_or_formula", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4475 "y.tab.c"
    break;

  case 267: /* fof_and_formula: fof_unit_formula AMPERSAND fof_unit_formula  */
#line 756 "SyntaxBNF.y"
                                                              {(yyval.pval) = P_BUILD("fof_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4481 "y.tab.c"
    break;

  case 268: /* fof_and_formula: fof_and_formula AMPERSAND fof_unit_formula  */
#line 757 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("fof_and_formula", (yyvsp[-2].pval), P_TOKEN("AMPERSAND ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4487 "y.tab.c"
    break;

  case 269: /* fof_unary_formula: unary_connective fof_unit_formula  */
#line 760 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("fof_unary_formula", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4493 "y.tab.c"
    break;

  case 270: /* fof_unary_formula: fof_infix_unary  */
#line 761 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_unary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4499 "y.tab.c"
    break;

  case 271: /* fof_infix_unary: fof_term infix_inequality fof_term  */
#line 764 "SyntaxBNF.y"
                                                     {(yyval.pval) = P_BUILD("fof_infix_unary", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4505 "y.tab.c"
    break;

  case 272: /* fof_unit_formula: fof_unitary_formula  */
#line 767 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4511 "y.tab.c"
    break;

  case 273: /* fof_unit_formula: fof_unary_formula  */
#line 768 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("fof_unit_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4517 "y.tab.c"
    break;

  case 274: /* fof_unitary_formula: fof_quantified_formula  */
#line 771 "SyntaxBNF.y"
                                             {(yyval.pval) = P_BUILD("fof_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4523 "y.tab.c"
    break;

  case 275: /* fof_unitary_formula: fof_atomic_formula  */
#line 772 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("fof_unitary_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4529 "y.tab.c"
    break;

  case 276: /* fof_unitary_formula: LPAREN fof_logic_formula RPAREN  */
#line 773 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("fof_unitary_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4535 "y.tab.c"
    break;

  case 277: /* fof_quantified_formula: fof_quantifier LBRKT fof_variable_list RBRKT COLON fof_unit_formula  */
#line 776 "SyntaxBNF.y"
                                                                                             {(yyval.pval) = P_BUILD("fof_quantified_formula", (yyvsp[-5].pval), P_TOKEN("LBRKT ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("RBRKT ", (yyvsp[-2].ival)), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL);}
#line 4541 "y.tab.c"
    break;

  case 278: /* fof_variable_list: variable  */
#line 779 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("fof_variable_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4547 "y.tab.c"
    break;

  case 279: /* fof_variable_list: variable COMMA fof_variable_list  */
#line 780 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("fof_variable_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4553 "y.tab.c"
    break;

  case 280: /* fof_atomic_formula: fof_plain_atomic_formula  */
#line 783 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("fof_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4559 "y.tab.c"
    break;

  case 281: /* fof_atomic_formula: fof_defined_atomic_formula  */
#line 784 "SyntaxBNF.y"
                                                 {(yyval.pval) = P_BUILD("fof_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4565 "y.tab.c"
    break;

  case 282: /* fof_atomic_formula: fof_system_atomic_formula  */
#line 785 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("fof_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4571 "y.tab.c"
    break;

  case 283: /* fof_plain_atomic_formula: fof_plain_term  */
#line 788 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_plain_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4577 "y.tab.c"
    break;

  case 284: /* fof_defined_atomic_formula: fof_defined_plain_formula  */
#line 791 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("fof_defined_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4583 "y.tab.c"
    break;

  case 285: /* fof_defined_atomic_formula: fof_defined_infix_formula  */
#line 792 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("fof_defined_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4589 "y.tab.c"
    break;

  case 286: /* fof_defined_plain_formula: fof_defined_plain_term  */
#line 795 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("fof_defined_plain_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4595 "y.tab.c"
    break;

  case 287: /* fof_defined_infix_formula: fof_term defined_infix_pred fof_term  */
#line 798 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("fof_defined_infix_formula", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4601 "y.tab.c"
    break;

  case 288: /* fof_system_atomic_formula: fof_system_term  */
#line 801 "SyntaxBNF.y"
                                            {(yyval.pval) = P_BUILD("fof_system_atomic_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4607 "y.tab.c"
    break;

  case 289: /* fof_plain_term: constant  */
#line 804 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("fof_plain_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4613 "y.tab.c"
    break;

  case 290: /* fof_plain_term: functor LPAREN fof_arguments RPAREN  */
#line 805 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("fof_plain_term", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4619 "y.tab.c"
    break;

  case 291: /* fof_defined_term: defined_term  */
#line 808 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("fof_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4625 "y.tab.c"
    break;

  case 292: /* fof_defined_term: fof_defined_atomic_term  */
#line 809 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("fof_defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4631 "y.tab.c"
    break;

  case 293: /* fof_defined_atomic_term: fof_defined_plain_term  */
#line 812 "SyntaxBNF.y"
                                                 {(yyval.pval) = P_BUILD("fof_defined_atomic_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4637 "y.tab.c"
    break;

  case 294: /* fof_defined_plain_term: defined_constant  */
#line 815 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("fof_defined_plain_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4643 "y.tab.c"
    break;

  case 295: /* fof_defined_plain_term: defined_functor LPAREN fof_arguments RPAREN  */
#line 816 "SyntaxBNF.y"
                                                                  {(yyval.pval) = P_BUILD("fof_defined_plain_term", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4649 "y.tab.c"
    break;

  case 296: /* fof_system_term: system_constant  */
#line 819 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("fof_system_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4655 "y.tab.c"
    break;

  case 297: /* fof_system_term: system_functor LPAREN fof_arguments RPAREN  */
#line 820 "SyntaxBNF.y"
                                                                 {(yyval.pval) = P_BUILD("fof_system_term", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4661 "y.tab.c"
    break;

  case 298: /* fof_arguments: fof_term  */
#line 823 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("fof_arguments", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4667 "y.tab.c"
    break;

  case 299: /* fof_arguments: fof_term COMMA fof_arguments  */
#line 824 "SyntaxBNF.y"
                                                   {(yyval.pval) = P_BUILD("fof_arguments", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4673 "y.tab.c"
    break;

  case 300: /* fof_term: fof_function_term  */
#line 827 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("fof_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4679 "y.tab.c"
    break;

  case 301: /* fof_term: variable  */
#line 828 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("fof_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4685 "y.tab.c"
    break;

  case 302: /* fof_function_term: fof_plain_term  */
#line 831 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("fof_function_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4691 "y.tab.c"
    break;

  case 303: /* fof_function_term: fof_defined_term  */
#line 832 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("fof_function_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4697 "y.tab.c"
    break;

  case 304: /* fof_function_term: fof_system_term  */
#line 833 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("fof_function_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4703 "y.tab.c"
    break;

  case 305: /* fof_sequent: fof_formula_tuple gentzen_arrow fof_formula_tuple  */
#line 836 "SyntaxBNF.y"
                                                                {(yyval.pval) = P_BUILD("fof_sequent", (yyvsp[-2].pval), (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4709 "y.tab.c"
    break;

  case 306: /* fof_sequent: LPAREN fof_sequent RPAREN  */
#line 837 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("fof_sequent", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4715 "y.tab.c"
    break;

  case 307: /* fof_formula_tuple: LBRKT RBRKT  */
#line 840 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("fof_formula_tuple", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4721 "y.tab.c"
    break;

  case 308: /* fof_formula_tuple: LBRKT fof_formula_tuple_list RBRKT  */
#line 841 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("fof_formula_tuple", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4727 "y.tab.c"
    break;

  case 309: /* fof_formula_tuple_list: fof_logic_formula  */
#line 844 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("fof_formula_tuple_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4733 "y.tab.c"
    break;

  case 310: /* fof_formula_tuple_list: fof_logic_formula COMMA fof_formula_tuple_list  */
#line 845 "SyntaxBNF.y"
                                                                     {(yyval.pval) = P_BUILD("fof_formula_tuple_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4739 "y.tab.c"
    break;

  case 311: /* cnf_formula: cnf_disjunction  */
#line 848 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("cnf_formula", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4745 "y.tab.c"
    break;

  case 312: /* cnf_formula: LPAREN cnf_formula RPAREN  */
#line 849 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("cnf_formula", P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4751 "y.tab.c"
    break;

  case 313: /* cnf_disjunction: cnf_literal  */
#line 852 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("cnf_disjunction", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4757 "y.tab.c"
    break;

  case 314: /* cnf_disjunction: cnf_disjunction VLINE cnf_literal  */
#line 853 "SyntaxBNF.y"
                                                        {(yyval.pval) = P_BUILD("cnf_disjunction", (yyvsp[-2].pval), P_TOKEN("VLINE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4763 "y.tab.c"
    break;

  case 315: /* cnf_literal: fof_atomic_formula  */
#line 856 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("cnf_literal", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4769 "y.tab.c"
    break;

  case 316: /* cnf_literal: TILDE fof_atomic_formula  */
#line 857 "SyntaxBNF.y"
                                               {(yyval.pval) = P_BUILD("cnf_literal", P_TOKEN("TILDE ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4775 "y.tab.c"
    break;

  case 317: /* cnf_literal: TILDE LPAREN fof_atomic_formula RPAREN  */
#line 858 "SyntaxBNF.y"
                                                             {(yyval.pval) = P_BUILD("cnf_literal", P_TOKEN("TILDE ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4781 "y.tab.c"
    break;

  case 318: /* cnf_literal: fof_infix_unary  */
#line 859 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("cnf_literal", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4787 "y.tab.c"
    break;

  case 319: /* thf_quantifier: tff_quantifier  */
#line 862 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("thf_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4793 "y.tab.c"
    break;

  case 320: /* thf_quantifier: th0_quantifier  */
#line 863 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("thf_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4799 "y.tab.c"
    break;

  case 321: /* thf_quantifier: type_quantifier  */
#line 864 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("thf_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4805 "y.tab.c"
    break;

  case 322: /* thf_unary_connective: unary_connective  */
#line 867 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("thf_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4811 "y.tab.c"
    break;

  case 323: /* thf_unary_connective: ntf_short_connective  */
#line 868 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("thf_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4817 "y.tab.c"
    break;

  case 324: /* th0_quantifier: CARET  */
#line 871 "SyntaxBNF.y"
                       {(yyval.pval) = P_BUILD("th0_quantifier", P_TOKEN("CARET ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4823 "y.tab.c"
    break;

  case 325: /* th0_quantifier: AT_SIGN_PLUS  */
#line 872 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("th0_quantifier", P_TOKEN("AT_SIGN_PLUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4829 "y.tab.c"
    break;

  case 326: /* th0_quantifier: AT_SIGN_MINUS  */
#line 873 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("th0_quantifier", P_TOKEN("AT_SIGN_MINUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4835 "y.tab.c"
    break;

  case 327: /* type_quantifier: EXCLAMATION_GREATER  */
#line 876 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("type_quantifier", P_TOKEN("EXCLAMATION_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4841 "y.tab.c"
    break;

  case 328: /* type_quantifier: QUESTION_STAR  */
#line 877 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("type_quantifier", P_TOKEN("QUESTION_STAR ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4847 "y.tab.c"
    break;

  case 329: /* subtype_sign: LESS_LESS  */
#line 880 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("subtype_sign", P_TOKEN("LESS_LESS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4853 "y.tab.c"
    break;

  case 330: /* tff_unary_connective: unary_connective  */
#line 883 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("tff_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4859 "y.tab.c"
    break;

  case 331: /* tff_unary_connective: ntf_short_connective  */
#line 884 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("tff_unary_connective", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4865 "y.tab.c"
    break;

  case 332: /* tff_quantifier: fof_quantifier  */
#line 887 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("tff_quantifier", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4871 "y.tab.c"
    break;

  case 333: /* tff_quantifier: hash  */
#line 888 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("tff_quantifier", P_TOKEN("hash ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4877 "y.tab.c"
    break;

  case 334: /* fof_quantifier: EXCLAMATION  */
#line 891 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("fof_quantifier", P_TOKEN("EXCLAMATION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4883 "y.tab.c"
    break;

  case 335: /* fof_quantifier: QUESTION  */
#line 892 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("fof_quantifier", P_TOKEN("QUESTION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4889 "y.tab.c"
    break;

  case 336: /* nonassoc_connective: LESS_EQUALS_GREATER  */
#line 895 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("LESS_EQUALS_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4895 "y.tab.c"
    break;

  case 337: /* nonassoc_connective: EQUALS_GREATER  */
#line 896 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("EQUALS_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4901 "y.tab.c"
    break;

  case 338: /* nonassoc_connective: LESS_EQUALS  */
#line 897 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("LESS_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4907 "y.tab.c"
    break;

  case 339: /* nonassoc_connective: LESS_TILDE_GREATER  */
#line 898 "SyntaxBNF.y"
                                         {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("LESS_TILDE_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4913 "y.tab.c"
    break;

  case 340: /* nonassoc_connective: TILDE_VLINE  */
#line 899 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("TILDE_VLINE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4919 "y.tab.c"
    break;

  case 341: /* nonassoc_connective: TILDE_AMPERSAND  */
#line 900 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("nonassoc_connective", P_TOKEN("TILDE_AMPERSAND ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4925 "y.tab.c"
    break;

  case 342: /* assoc_connective: VLINE  */
#line 903 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("assoc_connective", P_TOKEN("VLINE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4931 "y.tab.c"
    break;

  case 343: /* assoc_connective: AMPERSAND  */
#line 904 "SyntaxBNF.y"
                                {(yyval.pval) = P_BUILD("assoc_connective", P_TOKEN("AMPERSAND ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4937 "y.tab.c"
    break;

  case 344: /* unary_connective: TILDE  */
#line 907 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("unary_connective", P_TOKEN("TILDE ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4943 "y.tab.c"
    break;

  case 345: /* gentzen_arrow: MINUS_MINUS_GREATER  */
#line 910 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("gentzen_arrow", P_TOKEN("MINUS_MINUS_GREATER ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4949 "y.tab.c"
    break;

  case 346: /* assignment: COLON_EQUALS  */
#line 913 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("assignment", P_TOKEN("COLON_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4955 "y.tab.c"
    break;

  case 347: /* identical: EQUALS_EQUALS  */
#line 916 "SyntaxBNF.y"
                          {(yyval.pval) = P_BUILD("identical", P_TOKEN("EQUALS_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4961 "y.tab.c"
    break;

  case 348: /* typeable_atom: constant  */
#line 919 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("typeable_atom", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4967 "y.tab.c"
    break;

  case 349: /* typeable_atom: distinct_object  */
#line 920 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("typeable_atom", P_TOKEN("distinct_object ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4973 "y.tab.c"
    break;

  case 350: /* atomic_type: typeable_atom  */
#line 923 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4979 "y.tab.c"
    break;

  case 351: /* atomic_type: defined_constant  */
#line 924 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4985 "y.tab.c"
    break;

  case 352: /* atomic_type: system_type  */
#line 925 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("atomic_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4991 "y.tab.c"
    break;

  case 353: /* type_constant: type_functor  */
#line 928 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("type_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 4997 "y.tab.c"
    break;

  case 354: /* type_functor: atomic_word  */
#line 931 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("type_functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5003 "y.tab.c"
    break;

  case 355: /* defined_type: atomic_defined_word  */
#line 934 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("defined_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5009 "y.tab.c"
    break;

  case 356: /* system_type: atomic_system_word  */
#line 937 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("system_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5015 "y.tab.c"
    break;

  case 357: /* defined_infix_pred: infix_equality  */
#line 940 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("defined_infix_pred", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5021 "y.tab.c"
    break;

  case 358: /* infix_equality: EQUALS  */
#line 943 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("infix_equality", P_TOKEN("EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5027 "y.tab.c"
    break;

  case 359: /* infix_inequality: EXCLAMATION_EQUALS  */
#line 946 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("infix_inequality", P_TOKEN("EXCLAMATION_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5033 "y.tab.c"
    break;

  case 360: /* constant: functor  */
#line 949 "SyntaxBNF.y"
                   {(yyval.pval) = P_BUILD("constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5039 "y.tab.c"
    break;

  case 361: /* functor: atomic_word  */
#line 952 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5045 "y.tab.c"
    break;

  case 362: /* defined_constant: defined_functor  */
#line 955 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("defined_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5051 "y.tab.c"
    break;

  case 363: /* defined_functor: atomic_defined_word  */
#line 958 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("defined_functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5057 "y.tab.c"
    break;

  case 364: /* system_constant: system_functor  */
#line 961 "SyntaxBNF.y"
                                 {(yyval.pval) = P_BUILD("system_constant", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5063 "y.tab.c"
    break;

  case 365: /* system_functor: atomic_system_word  */
#line 964 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("system_functor", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5069 "y.tab.c"
    break;

  case 366: /* th1_defined_term: EXCLAMATION_EXCLAMATION  */
#line 967 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("EXCLAMATION_EXCLAMATION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5075 "y.tab.c"
    break;

  case 367: /* th1_defined_term: QUESTION_QUESTION  */
#line 968 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("QUESTION_QUESTION ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5081 "y.tab.c"
    break;

  case 368: /* th1_defined_term: AT_AT_SIGN_PLUS  */
#line 969 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("AT_AT_SIGN_PLUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5087 "y.tab.c"
    break;

  case 369: /* th1_defined_term: AT_AT_SIGN_MINUS  */
#line 970 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("AT_AT_SIGN_MINUS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5093 "y.tab.c"
    break;

  case 370: /* th1_defined_term: AT_SIGN_EQUALS  */
#line 971 "SyntaxBNF.y"
                                     {(yyval.pval) = P_BUILD("th1_defined_term", P_TOKEN("AT_SIGN_EQUALS ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5099 "y.tab.c"
    break;

  case 371: /* defined_term: number  */
#line 974 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("defined_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5105 "y.tab.c"
    break;

  case 372: /* defined_term: distinct_object  */
#line 975 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("defined_term", P_TOKEN("distinct_object ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5111 "y.tab.c"
    break;

  case 373: /* variable: upper_word  */
#line 978 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("variable", P_TOKEN("upper_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5117 "y.tab.c"
    break;

  case 374: /* source: dag_source  */
#line 981 "SyntaxBNF.y"
                    {(yyval.pval) = P_BUILD("source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5123 "y.tab.c"
    break;

  case 375: /* source: internal_source  */
#line 982 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5129 "y.tab.c"
    break;

  case 376: /* source: external_source  */
#line 983 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5135 "y.tab.c"
    break;

  case 377: /* source: _LIT_unknown  */
#line 984 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("source", P_TOKEN("_LIT_unknown ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5141 "y.tab.c"
    break;

  case 378: /* source: LBRKT sources RBRKT  */
#line 985 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("source", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5147 "y.tab.c"
    break;

  case 379: /* sources: source  */
#line 988 "SyntaxBNF.y"
                 {(yyval.pval) = P_BUILD("sources", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5153 "y.tab.c"
    break;

  case 380: /* sources: source COMMA sources  */
#line 989 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("sources", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5159 "y.tab.c"
    break;

  case 381: /* dag_source: name  */
#line 992 "SyntaxBNF.y"
                  {(yyval.pval) = P_BUILD("dag_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5165 "y.tab.c"
    break;

  case 382: /* dag_source: inference_record  */
#line 993 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("dag_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5171 "y.tab.c"
    break;

  case 383: /* inference_record: _LIT_inference LPAREN inference_rule COMMA useful_info COMMA parents RPAREN  */
#line 996 "SyntaxBNF.y"
                                                                                               {(yyval.pval) = P_BUILD("inference_record", P_TOKEN("_LIT_inference ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 5177 "y.tab.c"
    break;

  case 384: /* inference_rule: atomic_word  */
#line 999 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("inference_rule", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5183 "y.tab.c"
    break;

  case 385: /* internal_source: _LIT_introduced LPAREN intro_type COMMA useful_info COMMA parents RPAREN  */
#line 1002 "SyntaxBNF.y"
                                                                                           {(yyval.pval) = P_BUILD("internal_source", P_TOKEN("_LIT_introduced ", (yyvsp[-7].ival)), P_TOKEN("LPAREN ", (yyvsp[-6].ival)), (yyvsp[-5].pval), P_TOKEN("COMMA ", (yyvsp[-4].ival)), (yyvsp[-3].pval), P_TOKEN("COMMA ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL);}
#line 5189 "y.tab.c"
    break;

  case 386: /* intro_type: atomic_word  */
#line 1005 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("intro_type", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5195 "y.tab.c"
    break;

  case 387: /* external_source: file_source  */
#line 1008 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("external_source", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5201 "y.tab.c"
    break;

  case 388: /* file_source: _LIT_file LPAREN file_name file_info RPAREN  */
#line 1011 "SyntaxBNF.y"
                                                          {(yyval.pval) = P_BUILD("file_source", P_TOKEN("_LIT_file ", (yyvsp[-4].ival)), P_TOKEN("LPAREN ", (yyvsp[-3].ival)), (yyvsp[-2].pval), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL);}
#line 5207 "y.tab.c"
    break;

  case 389: /* file_info: COMMA name  */
#line 1014 "SyntaxBNF.y"
                       {(yyval.pval) = P_BUILD("file_info", P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5213 "y.tab.c"
    break;

  case 390: /* file_info: nothing  */
#line 1015 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("file_info", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5219 "y.tab.c"
    break;

  case 391: /* parents: LBRKT RBRKT  */
#line 1018 "SyntaxBNF.y"
                      {(yyval.pval) = P_BUILD("parents", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5225 "y.tab.c"
    break;

  case 392: /* parents: LBRKT parent_list RBRKT  */
#line 1019 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("parents", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5231 "y.tab.c"
    break;

  case 393: /* parent_list: parent_info  */
#line 1022 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("parent_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5237 "y.tab.c"
    break;

  case 394: /* parent_list: parent_info COMMA parent_list  */
#line 1023 "SyntaxBNF.y"
                                                    {(yyval.pval) = P_BUILD("parent_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5243 "y.tab.c"
    break;

  case 395: /* parent_info: source parent_details  */
#line 1026 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("parent_info", (yyvsp[-1].pval), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5249 "y.tab.c"
    break;

  case 396: /* parent_details: COLON general_term  */
#line 1029 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("parent_details", P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5255 "y.tab.c"
    break;

  case 397: /* parent_details: nothing  */
#line 1030 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("parent_details", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5261 "y.tab.c"
    break;

  case 398: /* optional_info: COMMA useful_info  */
#line 1033 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("optional_info", P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5267 "y.tab.c"
    break;

  case 399: /* optional_info: nothing  */
#line 1034 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("optional_info", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5273 "y.tab.c"
    break;

  case 400: /* useful_info: general_list  */
#line 1037 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("useful_info", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5279 "y.tab.c"
    break;

  case 401: /* include: _LIT_include LPAREN file_name include_optionals RPAREN PERIOD  */
#line 1040 "SyntaxBNF.y"
                                                                        {(yyval.pval) = P_BUILD("include", P_TOKEN("_LIT_include ", (yyvsp[-5].ival)), P_TOKEN("LPAREN ", (yyvsp[-4].ival)), (yyvsp[-3].pval), (yyvsp[-2].pval), P_TOKEN("RPAREN ", (yyvsp[-1].ival)), P_TOKEN("PERIOD ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL);}
#line 5285 "y.tab.c"
    break;

  case 402: /* include_optionals: nothing  */
#line 1043 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("include_optionals", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5291 "y.tab.c"
    break;

  case 403: /* include_optionals: COMMA formula_selection  */
#line 1044 "SyntaxBNF.y"
                                              {(yyval.pval) = P_BUILD("include_optionals", P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5297 "y.tab.c"
    break;

  case 404: /* include_optionals: COMMA formula_selection COMMA space_name  */
#line 1045 "SyntaxBNF.y"
                                                               {(yyval.pval) = P_BUILD("include_optionals", P_TOKEN("COMMA ", (yyvsp[-3].ival)), (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5303 "y.tab.c"
    break;

  case 405: /* formula_selection: LBRKT name_list RBRKT  */
#line 1048 "SyntaxBNF.y"
                                          {(yyval.pval) = P_BUILD("formula_selection", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5309 "y.tab.c"
    break;

  case 406: /* formula_selection: STAR  */
#line 1049 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("formula_selection", P_TOKEN("STAR ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5315 "y.tab.c"
    break;

  case 407: /* name_list: name  */
#line 1052 "SyntaxBNF.y"
                 {(yyval.pval) = P_BUILD("name_list", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5321 "y.tab.c"
    break;

  case 408: /* name_list: name COMMA name_list  */
#line 1053 "SyntaxBNF.y"
                                           {(yyval.pval) = P_BUILD("name_list", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5327 "y.tab.c"
    break;

  case 409: /* space_name: name  */
#line 1056 "SyntaxBNF.y"
                  {(yyval.pval) = P_BUILD("space_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5333 "y.tab.c"
    break;

  case 410: /* general_term: general_data  */
#line 1059 "SyntaxBNF.y"
                            {(yyval.pval) = P_BUILD("general_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5339 "y.tab.c"
    break;

  case 411: /* general_term: general_data COLON general_term  */
#line 1060 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("general_term", (yyvsp[-2].pval), P_TOKEN("COLON ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5345 "y.tab.c"
    break;

  case 412: /* general_term: general_list  */
#line 1061 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_term", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5351 "y.tab.c"
    break;

  case 413: /* general_data: atomic_word  */
#line 1064 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5357 "y.tab.c"
    break;

  case 414: /* general_data: general_function  */
#line 1065 "SyntaxBNF.y"
                                       {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5363 "y.tab.c"
    break;

  case 415: /* general_data: variable  */
#line 1066 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5369 "y.tab.c"
    break;

  case 416: /* general_data: number  */
#line 1067 "SyntaxBNF.y"
                             {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5375 "y.tab.c"
    break;

  case 417: /* general_data: distinct_object  */
#line 1068 "SyntaxBNF.y"
                                      {(yyval.pval) = P_BUILD("general_data", P_TOKEN("distinct_object ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5381 "y.tab.c"
    break;

  case 418: /* general_data: formula_data  */
#line 1069 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_data", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5387 "y.tab.c"
    break;

  case 419: /* general_function: atomic_word LPAREN general_terms RPAREN  */
#line 1072 "SyntaxBNF.y"
                                                           {(yyval.pval) = P_BUILD("general_function", (yyvsp[-3].pval), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5393 "y.tab.c"
    break;

  case 420: /* formula_data: _DLR_thf LPAREN thf_formula RPAREN  */
#line 1075 "SyntaxBNF.y"
                                                  {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_thf ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5399 "y.tab.c"
    break;

  case 421: /* formula_data: _DLR_tff LPAREN tff_formula RPAREN  */
#line 1076 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_tff ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5405 "y.tab.c"
    break;

  case 422: /* formula_data: _DLR_fof LPAREN fof_formula RPAREN  */
#line 1077 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_fof ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5411 "y.tab.c"
    break;

  case 423: /* formula_data: _DLR_cnf LPAREN cnf_formula RPAREN  */
#line 1078 "SyntaxBNF.y"
                                                         {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_cnf ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5417 "y.tab.c"
    break;

  case 424: /* formula_data: _DLR_fot LPAREN fof_term RPAREN  */
#line 1079 "SyntaxBNF.y"
                                                      {(yyval.pval) = P_BUILD("formula_data", P_TOKEN("_DLR_fot ", (yyvsp[-3].ival)), P_TOKEN("LPAREN ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RPAREN ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5423 "y.tab.c"
    break;

  case 425: /* general_list: LBRKT RBRKT  */
#line 1082 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("general_list", P_TOKEN("LBRKT ", (yyvsp[-1].ival)), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5429 "y.tab.c"
    break;

  case 426: /* general_list: LBRKT general_terms RBRKT  */
#line 1083 "SyntaxBNF.y"
                                                {(yyval.pval) = P_BUILD("general_list", P_TOKEN("LBRKT ", (yyvsp[-2].ival)), (yyvsp[-1].pval), P_TOKEN("RBRKT ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5435 "y.tab.c"
    break;

  case 427: /* general_terms: general_term  */
#line 1086 "SyntaxBNF.y"
                                   {(yyval.pval) = P_BUILD("general_terms", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5441 "y.tab.c"
    break;

  case 428: /* general_terms: general_term COMMA general_terms  */
#line 1087 "SyntaxBNF.y"
                                                       {(yyval.pval) = P_BUILD("general_terms", (yyvsp[-2].pval), P_TOKEN("COMMA ", (yyvsp[-1].ival)), (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5447 "y.tab.c"
    break;

  case 429: /* name: atomic_word  */
#line 1090 "SyntaxBNF.y"
                   {(yyval.pval) = P_BUILD("name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5453 "y.tab.c"
    break;

  case 430: /* name: integer  */
#line 1091 "SyntaxBNF.y"
                              {(yyval.pval) = P_BUILD("name", P_TOKEN("integer ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5459 "y.tab.c"
    break;

  case 431: /* atomic_word: lower_word  */
#line 1094 "SyntaxBNF.y"
                         {(yyval.pval) = P_BUILD("atomic_word", P_TOKEN("lower_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5465 "y.tab.c"
    break;

  case 432: /* atomic_word: single_quoted  */
#line 1095 "SyntaxBNF.y"
                                    {(yyval.pval) = P_BUILD("atomic_word", P_TOKEN("single_quoted ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5471 "y.tab.c"
    break;

  case 433: /* atomic_word: back_quoted  */
#line 1096 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("atomic_word", P_TOKEN("back_quoted ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5477 "y.tab.c"
    break;

  case 434: /* atomic_defined_word: dollar_word  */
#line 1099 "SyntaxBNF.y"
                                  {(yyval.pval) = P_BUILD("atomic_defined_word", P_TOKEN("dollar_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5483 "y.tab.c"
    break;

  case 435: /* atomic_system_word: dollar_dollar_word  */
#line 1102 "SyntaxBNF.y"
                                        {(yyval.pval) = P_BUILD("atomic_system_word", P_TOKEN("dollar_dollar_word ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5489 "y.tab.c"
    break;

  case 436: /* number: integer  */
#line 1105 "SyntaxBNF.y"
                 {(yyval.pval) = P_BUILD("number", P_TOKEN("integer ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5495 "y.tab.c"
    break;

  case 437: /* number: rational  */
#line 1106 "SyntaxBNF.y"
                               {(yyval.pval) = P_BUILD("number", P_TOKEN("rational ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5501 "y.tab.c"
    break;

  case 438: /* number: real  */
#line 1107 "SyntaxBNF.y"
                           {(yyval.pval) = P_BUILD("number", P_TOKEN("real ", (yyvsp[0].ival)),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5507 "y.tab.c"
    break;

  case 439: /* file_name: atomic_word  */
#line 1110 "SyntaxBNF.y"
                        {(yyval.pval) = P_BUILD("file_name", (yyvsp[0].pval),NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5513 "y.tab.c"
    break;

  case 440: /* nothing: %empty  */
#line 1113 "SyntaxBNF.y"
          {(yyval.pval) = P_BUILD("nothing",NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
#line 5519 "y.tab.c"
    break;


#line 5523 "y.tab.c"

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

