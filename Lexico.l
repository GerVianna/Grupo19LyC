%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
#include "tablasimbolos.c"
FILE *yyin;
int yylval;
char *yyltext;

int yyerrork(void);
%}

%option noyywrap
%option yylineno

PUT PUT
GET GET
DIM DIM
AS AS
IF  if
ELSE    else
WHILE   while
INTEGER Integer 
FLOAT Float
MAXIMO maximo 
SEP_AND and
SEP_OR  or
SEP_NOT  not



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
MENOR_I  "<""="
MAYOR_I  ">""="
COMA        ","
P_A     "("
P_C     ")"
L_A     "{"
L_C     "}"
PYC     ";"

%%
{INTEGER}   {return INTEGER;}
{FLOAT}     {return FLOAT;}
{DIM}       {return DIM;}
{AS}        {return AS;}
{IF}        {atoi(yytext); return IF;}
{ELSE}      {return ELSE;}
{WHILE}     {return WHILE;}
{MAXIMO}    {return MAXIMO;} 
{PUT}       {return PUT;}
{GET}       {return GET;}
{CTE}       {return CTE;}
{CTE_HEXA}  {return CTE_HEXA;}
{CTE_BIN}   {return CTE_BIN;}
{CTE_REAL}  {return CTE_REAL;}
{STRING}    {return STRING;}
{SEP_AND}   {return SEP_AND;}
{SEP_OR}    {return SEP_OR; }
{SEP_NOT}   {return SEP_NOT;}
{ID}        {return ID;}
{OP_ASIG}   {return OP_ASIG;}
{OP_SUM}    {return OP_SUM;}
{OP_DIV}    {return OP_DIV;}
{OP_MUL}    {return OP_MUL;}
{OP_RES}    {return OP_RES;}
{OP_DIST}   {return OP_DIST;}
{OP_IGUAL}  {return OP_IGUAL;}
{MENOR}     {return MENOR;}
{MAYOR}     {return MAYOR;}
{MENOR_I}   {return MENOR_I;}
{MAYOR_I}   {return MAYOR_I;}
{P_A}       {return P_A;}
{P_C}       {return P_C;}
{L_A}       {return L_A;}
{L_C}       {return L_C;}
{PYC}       {return PYC; }
{COMA}      {return COMA; }



"\n"
"\t"
"\n\t"
"\r\t"
" "
.       yyerrork();
%%

int yyerrork(void) {
    printf("Error léxico: Caracter invalido: %s", yytext);
    exit(1);
}

/*
%%
[0-9]+ {
 yylval.numero = atoi(yytext);
 return NUMERO;
}
":=" { return ASIG; }
[a-zA-Z][a-zA-Z0-9]*{
 yylval.ptr_simbolo = buscar(t,yytext);
 if (yylval.ptr_simbolo == NULL)
 {
yylval.ptr_simbolo=(simbolo *) malloc(sizeof(simbolo));
strcpy(yylval.ptr_simbolo->nombre, yytext);
yylval.ptr_simbolo->valor=0;
insertar(&t, yylval.ptr_simbolo);
 }
 return ID;
}
[ \t]+ {;}
.|\n {return yytext[0];}
*/