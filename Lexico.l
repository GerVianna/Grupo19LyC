%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
FILE *yyin;
int yylval;
char *yyltext;

int yyerror(void);
%}

%option noyywrap
%option yylineno

PUT PUT
GET GET
IF  if
ELSE    else
WHILE   while


DIGITO [0-9]
LETRA [a-zA-Z]
CTE_HEXA 0x[0-9A-F]+
CTE_BIN 0b[0-1]+
CTE         {DIGITO}+
CTE_REAL {DIGITO}+"."{DIGITO}*
ID          {LETRA}({LETRA}|{DIGITO})*
STRING  \"(\\.|[^"\\])*\"

OP_ASIG     ":"
OP_SUM      "+"
OP_DIV      "/"
OP_MUL      "*"
OP_RES      "-"
OP_DIST     "<"">"
OP_IGUAL    "="
MENOR       "<"
MAYOR       ">"
MENORIGUAL  "<""="
MAYORIGUAL  ">""="
COMA        ","
P_A     "("
P_C     ")"
L_A     "{"
L_C     "}"
PyC     ";"


%%

{IF}       printf ("\n Sentencia IF: %s\n",yytext);
{ELSE}     printf ("\n Sentencia ELSE: %s\n",yytext);
{WHILE}    printf ("\n Sentencia WHILE: %s\n",yytext);
{PUT} printf("\n PUT: %s \n", yytext);
{GET} {printf("\n GET: %s \n", yytext); return GET;}
{CTE} printf("\n Constante: %s\n", yytext);
{CTE_HEXA} printf("\n Constante hexa: %s\n", yytext);
{CTE_BIN} printf("\n Constante binaria: %s\n", yytext);
{CTE_REAL} printf ("\n Constante real: %s\n",yytext);
{STRING} printf("\n String: %s\n", yytext);
{ID} printf("\n Identificador: %s\n", yytext);
{OP_ASIG} printf("\n Asignacion: %s\n", yytext);
{OP_SUM} printf("\n Suma: %s\n", yytext);
{OP_DIV} printf("\n Division: %s\n", yytext);
{OP_MUL} printf("\n Multiplicacion: %s\n", yytext);
{OP_RES}   printf ("\n Resta: %s\n",yytext);
{OP_DIST}  printf ("\n Distinto: %s\n",yytext);
{OP_IGUAL}    printf ("\n Igual: %s\n",yytext);
{MENOR} printf("\n Menor: %s\n", yytext);
{MAYOR} printf("\n Mayor: %s\n", yytext);
{MENORIGUAL} printf("\n Menor o igual: %s\n", yytext);
{MAYORIGUAL} printf("\n Mayor o igual: %s\n", yytext);
{P_A}      printf ("\nP_A: %s\n",yytext);
{P_C}      printf ("\nP_C: %s\n",yytext);
{L_A}      printf ("\nL_A: %s\n",yytext);
{L_C}      printf ("\nL_C: %s\n",yytext);
{PyC} printf("\n Semicolon: %s\n", yytext);
{COMA} printf("\n Coma: %s \n", yytext);

"\n"
"\t"
"\n\t"
"\r\t"
" "
.       yyerror();
%%

int yyerror(void) {
    printf("Error léxico: Caracter invalido: %s", yytext);
    exit(1);
}