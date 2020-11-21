
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "Sintactico.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
#include "lib/tercetos.c"
#include "lib/pila.c"
#include "lib/tsimbolos.c"

// #include "tablasimbolos.c"
int yystopparser = 0;
int variablesDIM = 0;
int tiposDIM = 0;
char vecId [50][32];
char vecTipos [50][32];

FILE *yyin;

int yyerror();
int yylex();

//Indices para tercetos
int Find = 0;
int Tind = 0;
int Eind = 0;

//Indices en string
char FindString[3];
char TindString[3];
char EindString[3];

//Variable String para los itoa
char varItoa[30];
char varString[30];
char varID[30];
char varReal[30];

//Auxiliar para maximo
int aux = 0;
int max = 0;
int xind = 0;

char auxString[10];
char maxString[10];
char despLista[10];

//Pila

Pila pilaExpresion;
Pila pilaTermino;
Pila pilaFactor;
Pila pilaIf;
Pila pilaWhile;
Pila pilaLista;



/* Line 189 of yacc.c  */
#line 131 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PUT = 258,
     GET = 259,
     MAXIMO = 260,
     DIM = 261,
     AS = 262,
     ID = 263,
     INTEGER = 264,
     FLOAT = 265,
     STRING = 266,
     CTE_STRING = 267,
     CTE = 268,
     CTE_HEXA = 269,
     CTE_REAL = 270,
     CTE_BIN = 271,
     OP_ASIG = 272,
     OP_SUM = 273,
     OP_RES = 274,
     OP_MUL = 275,
     OP_DIV = 276,
     OP_IGUAL = 277,
     OP_DIST = 278,
     P_A = 279,
     P_C = 280,
     L_A = 281,
     L_C = 282,
     MENOR = 283,
     MAYOR = 284,
     MAYOR_I = 285,
     MENOR_I = 286,
     PYC = 287,
     COMA = 288,
     WHILE = 289,
     IF = 290,
     ELSE = 291,
     SEP_AND = 292,
     SEP_NOT = 293,
     SEP_OR = 294
   };
#endif
/* Tokens.  */
#define PUT 258
#define GET 259
#define MAXIMO 260
#define DIM 261
#define AS 262
#define ID 263
#define INTEGER 264
#define FLOAT 265
#define STRING 266
#define CTE_STRING 267
#define CTE 268
#define CTE_HEXA 269
#define CTE_REAL 270
#define CTE_BIN 271
#define OP_ASIG 272
#define OP_SUM 273
#define OP_RES 274
#define OP_MUL 275
#define OP_DIV 276
#define OP_IGUAL 277
#define OP_DIST 278
#define P_A 279
#define P_C 280
#define L_A 281
#define L_C 282
#define MENOR 283
#define MAYOR 284
#define MAYOR_I 285
#define MENOR_I 286
#define PYC 287
#define COMA 288
#define WHILE 289
#define IF 290
#define ELSE 291
#define SEP_AND 292
#define SEP_NOT 293
#define SEP_OR 294




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 58 "Sintactico.y"

    int tipo_int;
    double tipo_double;
    char *tipo_string;



/* Line 214 of yacc.c  */
#line 253 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 265 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  31
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   192

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNRULES -- Number of states.  */
#define YYNSTATES  142

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    16,    19,
      21,    23,    25,    34,    35,    40,    41,    46,    47,    52,
      53,    58,    59,    64,    65,    70,    71,    76,    81,    82,
      83,    90,    91,   100,   101,   108,   109,   119,   120,   128,
     136,   142,   143,   153,   154,   162,   170,   176,   181,   184,
     188,   192,   196,   200,   204,   208,   212,   216,   220,   222,
     226,   230,   232,   234,   236,   238,   240,   242,   244,   248,
     250,   252,   256,   260,   262,   266,   268,   270,   272
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    42,    -1,    43,    -1,    42,    43,    -1,
      45,    -1,    52,    -1,    55,    -1,    54,    32,    -1,    44,
      -1,    58,    -1,    61,    -1,     6,    28,    74,    29,     7,
      28,    73,    29,    -1,    -1,     3,    13,    46,    32,    -1,
      -1,     3,     8,    47,    32,    -1,    -1,     3,    12,    48,
      32,    -1,    -1,     3,    14,    49,    32,    -1,    -1,     3,
      15,    50,    32,    -1,    -1,     3,    16,    51,    32,    -1,
      -1,     4,     8,    53,    32,    -1,     5,    24,    72,    25,
      -1,    -1,    -1,     8,    56,    17,    69,    57,    32,    -1,
      -1,    34,    59,    24,    67,    25,    26,    42,    27,    -1,
      -1,    34,    60,    24,    67,    25,    43,    -1,    -1,    35,
      24,    67,    25,    26,    42,    27,    62,    66,    -1,    -1,
      35,    24,    67,    25,    43,    63,    66,    -1,    35,    24,
      67,    25,    26,    42,    27,    -1,    35,    24,    67,    25,
      43,    -1,    -1,    35,    24,    68,    25,    26,    42,    27,
      64,    66,    -1,    -1,    35,    24,    68,    25,    43,    65,
      66,    -1,    35,    24,    68,    25,    26,    42,    27,    -1,
      35,    24,    68,    25,    43,    -1,    36,    26,    42,    27,
      -1,    36,    43,    -1,    69,    28,    69,    -1,    69,    29,
      69,    -1,    69,    31,    69,    -1,    69,    30,    69,    -1,
      69,    22,    69,    -1,    69,    23,    69,    -1,    67,    37,
      67,    -1,    69,    18,    70,    -1,    69,    19,    70,    -1,
      70,    -1,    70,    20,    71,    -1,    70,    21,    71,    -1,
      71,    -1,    13,    -1,     8,    -1,    12,    -1,    14,    -1,
      15,    -1,    16,    -1,    24,    69,    25,    -1,    54,    -1,
      69,    -1,    72,    33,    69,    -1,    73,    33,    75,    -1,
      75,    -1,    74,    33,     8,    -1,     8,    -1,     9,    -1,
      10,    -1,    11,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    87,    87,    89,    90,    92,    93,    94,    95,    96,
      97,    98,   100,   102,   102,   107,   107,   111,   111,   115,
     115,   118,   118,   123,   123,   127,   127,   129,   134,   134,
     134,   142,   142,   159,   159,   209,   209,   219,   219,   228,
     235,   244,   244,   257,   257,   269,   279,   293,   298,   309,
     321,   331,   342,   353,   364,   378,   401,   408,   415,   423,
     430,   437,   444,   452,   457,   463,   468,   476,   482,   488,
     494,   501,   518,   523,   531,   535,   543,   545,   547
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PUT", "GET", "MAXIMO", "DIM", "AS",
  "ID", "INTEGER", "FLOAT", "STRING", "CTE_STRING", "CTE", "CTE_HEXA",
  "CTE_REAL", "CTE_BIN", "OP_ASIG", "OP_SUM", "OP_RES", "OP_MUL", "OP_DIV",
  "OP_IGUAL", "OP_DIST", "P_A", "P_C", "L_A", "L_C", "MENOR", "MAYOR",
  "MAYOR_I", "MENOR_I", "PYC", "COMA", "WHILE", "IF", "ELSE", "SEP_AND",
  "SEP_NOT", "SEP_OR", "$accept", "programa", "program", "sentencia",
  "declaracion", "put", "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "get",
  "$@7", "maximo", "asignacion", "$@8", "$@9", "while", "$@10", "$@11",
  "if", "$@12", "$@13", "$@14", "$@15", "else", "condicion_simple",
  "condicion", "exp", "term", "factor", "lista", "lista_tipos", "lista_id",
  "tipo", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    43,    43,    43,
      43,    43,    44,    46,    45,    47,    45,    48,    45,    49,
      45,    50,    45,    51,    45,    53,    52,    54,    56,    57,
      55,    59,    58,    60,    58,    62,    61,    63,    61,    61,
      61,    64,    61,    65,    61,    61,    61,    66,    66,    67,
      67,    67,    67,    67,    67,    68,    69,    69,    69,    70,
      70,    70,    71,    71,    71,    71,    71,    71,    71,    71,
      72,    72,    73,    73,    74,    74,    75,    75,    75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     2,     1,
       1,     1,     8,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     4,     0,     0,
       6,     0,     8,     0,     6,     0,     9,     0,     7,     7,
       5,     0,     9,     0,     7,     7,     5,     4,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     3,     3,     1,     3,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,    28,    31,     0,     0,     2,
       3,     9,     5,     6,     0,     7,    10,    11,    15,    17,
      13,    19,    21,    23,    25,     0,     0,     0,     0,     0,
       0,     1,     4,     8,     0,     0,     0,     0,     0,     0,
       0,    63,    64,    62,    65,    66,    67,     0,    69,    70,
      58,    61,     0,    75,     0,     0,     0,     0,     0,     0,
       0,    16,    18,    14,    20,    22,    24,    26,     0,     0,
       0,     0,     0,    27,     0,     0,     0,    29,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    68,
      56,    57,    59,    60,    71,     0,    74,     0,     0,     0,
       0,    40,    55,     0,    46,    53,    54,    49,    50,    52,
      51,     0,    30,     0,    34,     0,     0,     0,     0,    76,
      77,    78,     0,    73,     0,    39,     0,    38,    45,    44,
      12,     0,    32,     0,     0,    48,     0,    72,    36,     0,
      42,    47
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     8,     9,    10,    11,    12,    36,    34,    35,    37,
      38,    39,    13,    40,    48,    15,    27,    97,    16,    28,
      29,    17,   133,   116,   136,   118,   127,    58,    59,    60,
      50,    51,    52,   122,    54,   123
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -98
static const yytype_int16 yypact[] =
{
     157,   141,    13,    -1,    -3,   -98,   -98,     6,    52,   157,
     -98,   -98,   -98,   -98,    22,   -98,   -98,   -98,   -98,   -98,
     -98,   -98,   -98,   -98,   -98,    31,    73,    69,    68,    78,
      31,   -98,   -98,   -98,    57,    74,    76,    82,    87,   105,
     106,   -98,   -98,   -98,   -98,   -98,   -98,    31,   -98,   -14,
      56,   -98,    45,   -98,    46,    31,    31,    31,    48,    79,
      65,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -11,    31,
      31,    31,    31,   -98,    31,   126,   140,   -14,   142,   143,
       7,    31,    14,    31,    31,    31,    31,    31,    31,   -98,
      56,    56,   -98,   -98,   -14,   138,   -98,   144,   147,   157,
     157,   133,   -98,   157,   134,   -14,   -14,   -14,   -14,   -14,
     -14,   101,   -98,   157,   -98,    23,   139,    63,   139,   -98,
     -98,   -98,    72,   -98,   117,   145,   124,   -98,   146,   -98,
     -98,   101,   -98,   139,   157,   -98,   139,   -98,   -98,   137,
     -98,   -98
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -98,   -98,   -97,    -8,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,   -98,   -98,   -98,     0,   -98,   -98,   -98,   -98,   -98,
     -98,   -98,   -98,   -98,   -98,   -98,   -80,   -22,   -98,   -23,
      66,    75,   -98,   -98,   -98,    43
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -44
static const yytype_int16 yytable[] =
{
      14,    32,    49,   115,    69,    70,   117,    69,    70,    14,
       1,     2,     3,     4,    89,     5,   124,     1,     2,     3,
       4,    24,     5,    25,    68,    26,     1,     2,     3,     4,
      30,     5,    77,   100,    78,    79,     3,   139,   129,    41,
     103,     6,     7,    42,    43,    44,    45,    46,     6,     7,
     125,    94,    31,   138,    33,    47,   140,     6,     7,   102,
     105,   106,   107,   108,   109,   110,     1,     2,     3,     4,
      73,     5,   101,    80,   104,    75,    71,    72,    74,    76,
      14,    53,    14,    69,    70,    81,    55,    83,    84,    61,
     128,   114,    56,    85,    86,    87,    88,     6,     7,    14,
      14,   130,    57,    14,    82,   131,    62,    32,    63,    32,
     119,   120,   121,    14,    64,    14,    32,    14,   135,    65,
       1,     2,     3,     4,    14,     5,    14,     1,     2,     3,
       4,    32,     5,    95,    14,    90,    91,    66,    67,    14,
       1,     2,     3,     4,   132,     5,    92,    93,    96,    18,
     134,     6,     7,    19,    20,    21,    22,    23,     6,     7,
       1,     2,     3,     4,   141,     5,   111,    98,    99,   -37,
     -43,     6,     7,   113,   137,   126,   112,     0,     0,     0,
       0,   -35,   -41,     0,     0,     0,     0,     0,     0,     0,
       0,     6,     7
};

static const yytype_int16 yycheck[] =
{
       0,     9,    25,   100,    18,    19,   103,    18,    19,     9,
       3,     4,     5,     6,    25,     8,   113,     3,     4,     5,
       6,     8,     8,    24,    47,    28,     3,     4,     5,     6,
      24,     8,    55,    26,    56,    57,     5,   134,   118,     8,
      26,    34,    35,    12,    13,    14,    15,    16,    34,    35,
      27,    74,     0,   133,    32,    24,   136,    34,    35,    81,
      83,    84,    85,    86,    87,    88,     3,     4,     5,     6,
      25,     8,    80,    25,    82,    29,    20,    21,    33,    33,
      80,     8,    82,    18,    19,    37,    17,    22,    23,    32,
      27,    99,    24,    28,    29,    30,    31,    34,    35,    99,
     100,    29,    24,   103,    25,    33,    32,   115,    32,   117,
       9,    10,    11,   113,    32,   115,   124,   117,   126,    32,
       3,     4,     5,     6,   124,     8,   126,     3,     4,     5,
       6,   139,     8,     7,   134,    69,    70,    32,    32,   139,
       3,     4,     5,     6,    27,     8,    71,    72,     8,     8,
      26,    34,    35,    12,    13,    14,    15,    16,    34,    35,
       3,     4,     5,     6,    27,     8,    28,    25,    25,    36,
      36,    34,    35,    26,   131,    36,    32,    -1,    -1,    -1,
      -1,    36,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     8,    34,    35,    41,    42,
      43,    44,    45,    52,    54,    55,    58,    61,     8,    12,
      13,    14,    15,    16,     8,    24,    28,    56,    59,    60,
      24,     0,    43,    32,    47,    48,    46,    49,    50,    51,
      53,     8,    12,    13,    14,    15,    16,    24,    54,    69,
      70,    71,    72,     8,    74,    17,    24,    24,    67,    68,
      69,    32,    32,    32,    32,    32,    32,    32,    69,    18,
      19,    20,    21,    25,    33,    29,    33,    69,    67,    67,
      25,    37,    25,    22,    23,    28,    29,    30,    31,    25,
      70,    70,    71,    71,    69,     7,     8,    57,    25,    25,
      26,    43,    67,    26,    43,    69,    69,    69,    69,    69,
      69,    28,    32,    26,    43,    42,    63,    42,    65,     9,
      10,    11,    73,    75,    42,    27,    36,    66,    27,    66,
      29,    33,    27,    62,    26,    43,    64,    75,    66,    42,
      66,    27
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 87 "Sintactico.y"
    { printf("Compilacion OK\n");}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 89 "Sintactico.y"
    { printf("\n Regla 0\n\n");}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 90 "Sintactico.y"
    { printf("\n Regla 1\n\n");}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 92 "Sintactico.y"
    { printf("\n Regla 2\n\n");}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 93 "Sintactico.y"
    { printf("\n Regla 3\n\n");}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 94 "Sintactico.y"
    { printf("\n Regla 4\n\n");}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 95 "Sintactico.y"
    { printf("\n Regla 5 \n\n");}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 96 "Sintactico.y"
    { printf("\n Regla 6\n\n");}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 97 "Sintactico.y"
    {printf("\n Regla 7\n\n");}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 98 "Sintactico.y"
    { printf("\n Regla 8\n\n");}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 100 "Sintactico.y"
    { printf("\n Regla 9\n\n");}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 102 "Sintactico.y"
    {itoa((yyvsp[(2) - (2)].tipo_int),varItoa,10);
                                                         strcpy(varString,"_");
                                                         strcat(varString, varItoa);
                                                         crear_terceto("PUT",varString,"_");}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 105 "Sintactico.y"
    { printf("\n Regla 10 \n\n");}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 107 "Sintactico.y"
    {strcpy(varString,"_");
                                                         strcat(varString, (yyvsp[(2) - (2)].tipo_string));
                                                         crear_terceto("PUT",varString,"_");}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 109 "Sintactico.y"
    { printf("\n Regla 11 \n\n");}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 111 "Sintactico.y"
    {strcpy(varString,"_");
                                                         strcat(varString, (yyvsp[(2) - (2)].tipo_string));
                                                         crear_terceto("PUT",varString,"_");}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 113 "Sintactico.y"
    { printf("\n Regla 12\n\n");}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 115 "Sintactico.y"
    {strcpy(varString,"_");
                                                         strcat(varString, (yyvsp[(2) - (2)].tipo_string));
                                                         crear_terceto("PUT",varString,"_");}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 117 "Sintactico.y"
    { printf("\n Regla 13\n\n");}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 118 "Sintactico.y"
    {sprintf(varString,"%.2f",(yyvsp[(2) - (2)].tipo_double));
                                                         strcpy(varReal,"_");
                                                         strcat(varReal, varString);
                                                         crear_terceto("PUT",varReal,"_");}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 121 "Sintactico.y"
    { printf("\n Regla 14\n\n");}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 123 "Sintactico.y"
    {strcpy(varString,"_");
                                                         strcat(varString, (yyvsp[(2) - (2)].tipo_string));
                                                         crear_terceto("PUT",varString,"_");}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 125 "Sintactico.y"
    { printf("\n Regla 15\n\n");}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 127 "Sintactico.y"
    {crear_terceto("GET",(yyvsp[(2) - (2)].tipo_string),"_");}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 127 "Sintactico.y"
    { printf("\n Regla 16\n\n");}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 129 "Sintactico.y"
    { 
                                    printf("\n Regla 17\n\n");
                                }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 134 "Sintactico.y"
    {strcpy(varID,(yyvsp[(1) - (1)].tipo_string));}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 134 "Sintactico.y"
    { 
                                    int auxEind= desapilar(&pilaExpresion);
                                    itoa(auxEind,EindString,10);
                                    crear_terceto(":",varID,EindString);
                                    printf("\n Regla 18\n\n");
                                }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 142 "Sintactico.y"
    {
            apilar(&pilaWhile,obtenerIndiceTercetos());
            crear_terceto("ET","_","_");
        }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 146 "Sintactico.y"
    { 
            int biInd = crear_terceto("BI","_","_");
            char valorActual[4];
            int pivote=desapilar(&pilaIf);
            itoa(obtenerIndiceTercetos(),valorActual,10);
            strcpy(vector_tercetos[pivote].atr2,valorActual);
            
            pivote=desapilar(&pilaWhile);
            itoa(pivote,valorActual,10);
            strcpy(vector_tercetos[biInd].atr2,valorActual);
            
            printf("\n Regla 19\n\n");
        }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 159 "Sintactico.y"
    {
            apilar(&pilaWhile,obtenerIndiceTercetos());
            crear_terceto("ET","_","_");
        }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 162 "Sintactico.y"
    { 
            int biInd = crear_terceto("BI","_","_");
            char valorActual[4];
            int pivote=desapilar(&pilaIf);
            itoa(obtenerIndiceTercetos(),valorActual,10);
            strcpy(vector_tercetos[pivote].atr2,valorActual);
            
            pivote=desapilar(&pilaWhile);
            itoa(pivote,valorActual,10);
            strcpy(vector_tercetos[biInd].atr2,valorActual);

            printf("\n Regla 20\n\n");
        }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 209 "Sintactico.y"
    {
                                        int bi=crear_terceto("BI","_","_");
                                        char valorActual[4];
                                        int pivote=desapilar(&pilaIf);
                                        itoa(obtenerIndiceTercetos(),valorActual,10);
                                        strcpy(vector_tercetos[pivote].atr2,valorActual);
                                        apilar(&pilaIf,bi);
                                        }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 216 "Sintactico.y"
    { printf("\n Regla 21 \n\n");}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 219 "Sintactico.y"
    {
                                        int bi=crear_terceto("BI","_","_");
                                        char valorActual[4];
                                        int pivote=desapilar(&pilaIf);
                                        itoa(obtenerIndiceTercetos(),valorActual,10);
                                        strcpy(vector_tercetos[pivote].atr2,valorActual);
                                        apilar(&pilaIf,bi);
                                        }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 226 "Sintactico.y"
    { printf("\n Regla 22\n\n");}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 228 "Sintactico.y"
    {
                        char valorActual[4];
                        int pivote = desapilar(&pilaIf);
                           itoa(obtenerIndiceTercetos(),valorActual,10);
                            strcpy(vector_tercetos[pivote].atr2,valorActual);
                            printf("\n Regla 23\n\n");}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 235 "Sintactico.y"
    {
                        char valorActual[4];
                        int pivote = desapilar(&pilaIf);
                           itoa(obtenerIndiceTercetos(),valorActual,10);
                            strcpy(vector_tercetos[pivote].atr2,valorActual);
                             printf("\n Regla 24\n\n");}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 244 "Sintactico.y"
    {
                                        int bi=crear_terceto("BI","_","_");
                                        char valorActual[4];
                                        int pivote=desapilar(&pilaIf);
                                        int tercetoActual=obtenerIndiceTercetos();
                                        itoa(tercetoActual,valorActual,10);
                                        strcpy(vector_tercetos[pivote].atr2,valorActual);
                                         pivote=desapilar(&pilaIf);
                                        strcpy(vector_tercetos[pivote].atr2,valorActual);
                                         apilar(&pilaIf,bi);
                                        }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 254 "Sintactico.y"
    { printf("\n Regla 25\n\n");}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 257 "Sintactico.y"
    {
                                        int bi=crear_terceto("BI","_","_");
                                        char valorActual[4];
                                        int pivote=desapilar(&pilaIf);
                                        int tercetoActual=obtenerIndiceTercetos();
                                        itoa(tercetoActual,valorActual,10);
                                        strcpy(vector_tercetos[pivote].atr2,valorActual);
                                         pivote=desapilar(&pilaIf);
                                        strcpy(vector_tercetos[pivote].atr2,valorActual);
                                         apilar(&pilaIf,bi);
                                        }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 267 "Sintactico.y"
    { printf("\n Regla 26\n\n");}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 269 "Sintactico.y"
    {
                        char valorActual[4];
                        int pivote = desapilar(&pilaIf);
                           int tercetoActual=obtenerIndiceTercetos();
                                        itoa(tercetoActual,valorActual,10);
                                        strcpy(vector_tercetos[pivote].atr2,valorActual);
                                         pivote=desapilar(&pilaIf);
                                        strcpy(vector_tercetos[pivote].atr2,valorActual);
                                         printf("\n Regla 27\n\n");}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 279 "Sintactico.y"
    {
                        char valorActual[4];
                        int pivote = desapilar(&pilaIf);
                          int tercetoActual=obtenerIndiceTercetos();
                                        itoa(tercetoActual,valorActual,10);
                                        strcpy(vector_tercetos[pivote].atr2,valorActual);
                                         pivote=desapilar(&pilaIf);
                                        strcpy(vector_tercetos[pivote].atr2,valorActual);
                                         printf("\n Regla 28\n\n");}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 293 "Sintactico.y"
    {int pivote=desapilar(&pilaIf);
                            char valorActual[4];
                                        itoa(obtenerIndiceTercetos(),valorActual,10);
                                        strcpy(vector_tercetos[pivote].atr2,valorActual);
                                         printf("\n Regla 29 \n\n");}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 298 "Sintactico.y"
    {int pivote=desapilar(&pilaIf);
                            char valorActual[4];
                                        itoa(obtenerIndiceTercetos(),valorActual,10);
                                        strcpy(vector_tercetos[pivote].atr2,valorActual);
                                         printf("\n Regla 30\n\n");}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 309 "Sintactico.y"
    {
                    char auxEind1[4];

                    itoa(desapilar(&pilaExpresion),auxEind1,10);
                    char auxEind2[4];
                    itoa(desapilar(&pilaExpresion),auxEind2,10);
                    crear_terceto("CMP",auxEind2,auxEind1);
                    int numTerceto=crear_terceto("BGE","_","_");
                    apilar(&pilaIf,numTerceto);
                    printf("\n Regla 31\n\n");}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 321 "Sintactico.y"
    {
                    char auxEind1[4];
                    itoa(desapilar(&pilaExpresion),auxEind1,10);
                    char auxEind2[4];
                    itoa(desapilar(&pilaExpresion),auxEind2,10);
                    crear_terceto("CMP",auxEind2,auxEind1);
                    int numTerceto=crear_terceto("BLE","_","_");
                    apilar(&pilaIf,numTerceto);
                    printf("\n Regla 32\n\n");}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 331 "Sintactico.y"
    {
                    char auxEind1[4];
                    itoa(desapilar(&pilaExpresion),auxEind1,10);
                    char auxEind2[4];
                    itoa(desapilar(&pilaExpresion),auxEind2,10);
                    crear_terceto("CMP",auxEind2,auxEind1);
                    int numTerceto=crear_terceto("BGT","_","_");
                    apilar(&pilaIf,numTerceto);
                    printf("\n Regla 33\n\n");
        }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 342 "Sintactico.y"
    {
                    char auxEind1[4];
                    itoa(desapilar(&pilaExpresion),auxEind1,10);
                    char auxEind2[4];
                    itoa(desapilar(&pilaExpresion),auxEind2,10);
                    crear_terceto("CMP",auxEind2,auxEind1);
                    int numTerceto=crear_terceto("BLT","_","_");
                    apilar(&pilaIf,numTerceto);
                    printf("\n Regla 34\n\n");
        }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 353 "Sintactico.y"
    {
                    char auxEind1[4];
                    itoa(desapilar(&pilaExpresion),auxEind1,10);
                    char auxEind2[4];
                    itoa(desapilar(&pilaExpresion),auxEind2,10);
                    crear_terceto("CMP",auxEind2,auxEind1);
                    int numTerceto=crear_terceto("BNE","_","_");
                    apilar(&pilaIf,numTerceto);
                    printf("\n Regla 35\n\n");
        }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 364 "Sintactico.y"
    {
                    char auxEind1[4];
                    itoa(desapilar(&pilaExpresion),auxEind1,10);
                    char auxEind2[4];
                    itoa(desapilar(&pilaExpresion),auxEind2,10);
                    crear_terceto("CMP",auxEind2,auxEind1);
                    int numTerceto=crear_terceto("BEQ","_","_");
                    apilar(&pilaIf,numTerceto);
                    printf("\n Regla 36\n\n");
                          
        }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 378 "Sintactico.y"
    { printf("\n Regla 37\n\n");}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 401 "Sintactico.y"
    { 
        itoa(desapilar(&pilaExpresion),EindString,10);
        itoa(desapilar(&pilaTermino),TindString,10);
        Eind=crear_terceto("+",EindString,TindString); 
        apilar(&pilaExpresion,Eind);
        printf("\n Regla 40\n\n");
    }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 408 "Sintactico.y"
    { 
        itoa(desapilar(&pilaExpresion),EindString,10);
        itoa(desapilar(&pilaTermino),TindString,10);
        Eind=crear_terceto("-",EindString,TindString);
        apilar(&pilaExpresion,Eind) ;
        printf("\n Regla 41\n\n");
    }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 415 "Sintactico.y"
    { 
        Eind=desapilar(&pilaTermino); 
        apilar(&pilaExpresion,Eind) ;
        printf("\n Regla 42\n\n");
    }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 423 "Sintactico.y"
    { 
        itoa(desapilar(&pilaTermino),TindString,10);
        itoa(desapilar(&pilaFactor),FindString,10);
        Tind=crear_terceto("*",TindString,FindString);
        apilar(&pilaTermino,Tind) ;
        printf("\n Regla 43\n\n");
    }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 430 "Sintactico.y"
    { 
        itoa(desapilar(&pilaTermino),TindString,10);
        itoa(desapilar(&pilaFactor),FindString,10);
        Tind=crear_terceto("/",TindString,FindString);
        apilar(&pilaTermino,Tind) ;
        printf("\n Regla 44\n\n");
    }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 437 "Sintactico.y"
    {  
        Tind = desapilar(&pilaFactor);
        apilar(&pilaTermino,Tind) ;
        printf("\n Regla 45\n\n");
    }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 444 "Sintactico.y"
    {  
            itoa((yyvsp[(1) - (1)].tipo_int),varItoa,10);
            strcpy(varString,"_");
            strcat(varString, varItoa);
            Find = crear_terceto(varString,"_","_");
            apilar(&pilaFactor,Find);
            printf("\n Regla 46\n\n");
        }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 452 "Sintactico.y"
    { 
            Find = crear_terceto((yyvsp[(1) - (1)].tipo_string),"_","_");
            apilar(&pilaFactor,Find);
            printf("\n Regla 47\n\n");
        }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 457 "Sintactico.y"
    {
            Find = crear_terceto((yyvsp[(1) - (1)].tipo_string),"_","_");
            apilar(&pilaFactor,Find);
            printf("\n Regla 48\n\n");
        }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 463 "Sintactico.y"
    { 
            Find = crear_terceto((yyvsp[(1) - (1)].tipo_string),"_","_");
            apilar(&pilaFactor,Find);
            printf("\n Regla 49\n\n");
        }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 468 "Sintactico.y"
    { 
            sprintf(varString,"%.3f",(yyvsp[(1) - (1)].tipo_double));
            strcpy(varReal,"_");
            strcat(varReal, varString);
            Find = crear_terceto(varReal,"_","_");
            apilar(&pilaFactor,Find);
            printf("\n Regla 50\n\n");
        }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 476 "Sintactico.y"
    { 
            Find = crear_terceto((yyvsp[(1) - (1)].tipo_string),"_","_");
            apilar(&pilaFactor,Find);
            printf("\n Regla 51\n\n");
        }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 482 "Sintactico.y"
    { 
            Find = desapilar(&pilaExpresion);
            apilar(&pilaFactor,Find);
            printf("\n Regla 52\n\n");
        }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 488 "Sintactico.y"
    { 
            Find = crear_terceto("@max","_","_");
            apilar(&pilaFactor,Find);
            printf("\n Regla 53\n\n");}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 495 "Sintactico.y"
    {  int d = desapilar(&pilaExpresion);
        itoa(d,despLista,10);
        crear_terceto(":", "@max", despLista);
        printf("\n Regla 55\n\n");
    }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 502 "Sintactico.y"
    { 
        int d = desapilar(&pilaExpresion);
        itoa(d,despLista,10);
        crear_terceto(":","@aux",despLista);
        crear_terceto("CMP","@aux","@max");
        xind = crear_terceto("BLE","_","_");
        apilar(&pilaLista,xind);
        crear_terceto(":","@max","@aux");
        xind = desapilar(&pilaLista);
        char valorActual[4];
        itoa(obtenerIndiceTercetos(),valorActual,10);
        strcpy(vector_tercetos[xind].atr2,valorActual);
        printf("\n Regla 54\n\n");
    }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 518 "Sintactico.y"
    { 
            strcpy(vecTipos[tiposDIM], (yyvsp[(3) - (3)].tipo_string));
            tiposDIM++; 
            printf("\n Regla 56\n\n");
            }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 523 "Sintactico.y"
    { 
            strcpy(vecTipos[tiposDIM], (yyvsp[(1) - (1)].tipo_string));
            tiposDIM++; 
            printf("\n Regla 57\n\n");
            }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 531 "Sintactico.y"
    { 
            strcpy(vecId[variablesDIM], (yyvsp[(3) - (3)].tipo_string));
            variablesDIM++; 
            printf("\n Regla 58\n\n");}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 535 "Sintactico.y"
    { 
            strcpy(vecId[variablesDIM], (yyvsp[(1) - (1)].tipo_string));
            variablesDIM++;
            printf("\n Regla 59\n\n");
         }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 543 "Sintactico.y"
    {(yyval.tipo_string) = (yyvsp[(1) - (1)].tipo_string); 
            printf("\n Regla 60\n\n");}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 545 "Sintactico.y"
    {(yyval.tipo_string) = (yyvsp[(1) - (1)].tipo_string);
            printf("\n Regla 61\n\n");}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 547 "Sintactico.y"
    {(yyval.tipo_string) = (yyvsp[(1) - (1)].tipo_string);
            printf("\n Regla 62\n\n");}
    break;



/* Line 1455 of yacc.c  */
#line 2408 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 550 "Sintactico.y"


int main(int argc, char *argv[]) {
    if((yyin = fopen(argv[1], "rt")) == NULL)
    {
        printf("\nNo se puede abrir el archivo de prueba: %s\n", argv[1]);
    }
    else {
        pilaExpresion = crearPila();
        pilaIf = crearPila();
        pilaTermino = crearPila();
        crearTablaSimbolos();
        yyparse();
		int i = 0;
        for(i = 0; i < variablesDIM; i++) {
            insertarEnTablaDeSimbolos(vecId[i], vecTipos[i], "CTE_STRING", 0, 0 );
        }
        guardarTablaDeSimbolos();
        escribir_tercetos();
        if (tiposDIM != variablesDIM) {
            printf("Parse failed: error en la declaracion de dim no coinciden la cantidad de VARIABLES con la cantidad de TIPOS\n");
        };
    }
    fclose(yyin);
    return 0;
}

int yyerror(void) {
    printf("Error sintactico \n");
    exit(1);
}

