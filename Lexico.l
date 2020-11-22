%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "y.tab.h"
FILE *yyin;
char *yyltext;

int yyerrorl(void);
int yyerrorm(char*);
void validarString(char*);
void validarFloat(double);
void validarInt(int);
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
STRING  String
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
CTE_REAL {DIGITO}*[.]{DIGITO}+|{DIGITO}+[.]{DIGITO}*
ID          {LETRA}({LETRA}|{DIGITO})*
CTE_STRING  \"(\\.|[^"\\])*\"
COMENTARIO \*-.*-\*

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
{INTEGER}   {
                yylval.tipo_string = yytext;
                return INTEGER;
            }	
{FLOAT}     {
                yylval.tipo_string = yytext;
                return FLOAT;
            }	
{STRING}    {
                yylval.tipo_string = yytext;
                return STRING;
            }	
{DIM}       {return DIM;}
{AS}        {return AS;}
{IF}        {return IF;}
{ELSE}      {return ELSE;}
{WHILE}     {return WHILE;}
{MAXIMO}    {return MAXIMO;} 
{PUT}       {return PUT;}
{GET}       {return GET;}
{CTE}       { 
            yylval.tipo_int = atoi(yytext);
            validarInt(yylval.tipo_int);
            insertarEnTablaDeSimbolos(yytext, "CTE", "", yylval.tipo_int, 0);
            return CTE;
            }
{CTE_HEXA}  {
            yylval.tipo_string = yytext;
            validarString(yylval.tipo_string);
            insertarEnTablaDeSimbolos(yylval.tipo_string, "CTE_HEXA", yylval.tipo_string, 0, 0);
            return CTE_HEXA;
            }
{CTE_BIN}   {
            yylval.tipo_string = yytext;
            validarString(yylval.tipo_string);
            insertarEnTablaDeSimbolos(yylval.tipo_string, "CTE_BIN", yylval.tipo_string, 0, 0);
            return CTE_BIN;
            }
{CTE_REAL}  {
            yylval.tipo_double = atof(yytext);
            validarFloat(yylval.tipo_double);
            insertarEnTablaDeSimbolos(yytext, "CTE_REAL", "", 0, yylval.tipo_double);
            return CTE_REAL;
            }
{CTE_STRING} {
            yylval.tipo_string = yytext;
            validarString(yylval.tipo_string);
            insertarEnTablaDeSimbolos(yylval.tipo_string, "CTE_STRING", yylval.tipo_string, 0, 0);
            return CTE_STRING;
            }
{SEP_AND}   {return SEP_AND;}
{SEP_OR}    {return SEP_OR; }
{SEP_NOT}   {return SEP_NOT;}
{ID}        {
                yylval.tipo_string = yytext;
                return ID;
            }	
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
{COMENTARIO}


"\n"
"\t"
"\n\t"
"\r\t"
" "
.       yyerrorl();
%%

int yyerrorl(void) {
    printf("Error léxico: Caracter invalido: %s", yytext);
    exit(1);
}

int yyerrorm(char* mensaje) {
    printf("\n%s\n", mensaje);
    exit(1);
}

void validarString(char *cadena)
{
    int largo = strlen(cadena);
    if(largo > 31)
    {
        yyerrorm("Error: Rango de String excedido. Se permite un maximo de 30 caracteres");
    }
}

void validarFloat(double numero)
{   
    double max = 3.402823 * pow(10, 38);
    double min = 1.175494 * pow(10, -38);
    if(numero > max || (numero > 0 && numero < min))
    {
        yyerrorm("Error: Rango de Float excedido. Se permite entre [1.175494*10^-38; 3.402823*10^38] o cero.\n");
    }
}

void validarInt(int numero)
{
    if(numero > 65535)
    {
        yyerrorm("Error: Valor de Integer excedido, el mayor posible es 65535");
    }
}
