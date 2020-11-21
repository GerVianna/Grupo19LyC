
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 58 "Sintactico.y"

    int tipo_int;
    double tipo_double;
    char *tipo_string;



/* Line 1676 of yacc.c  */
#line 138 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


