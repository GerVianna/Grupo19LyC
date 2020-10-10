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
PYC     ";"


%%
{DIM} printf("\nSentencia DIM: %s \n", yytext);
{AS} printf("\nSentencia AS: %s \n", yytext);
{IF}       printf ("\n Sentencia IF: %s\n",yytext);
{ELSE}     printf ("\n Sentencia ELSE: %s\n",yytext);
{WHILE}    printf ("\n Sentencia WHILE: %s\n",yytext);
{PUT} {printf("\n PUT: %s \n", yytext); return PUT;}
{GET} {printf("\n GET: %s \n", yytext);}
{CTE} printf("\n Constante: %s\n", yytext);
{CTE_HEXA} printf("\n Constante hexa: %s\n", yytext);
{CTE_BIN} printf("\n Constante binaria: %s\n", yytext);
{CTE_REAL} printf ("\n Constante real: %s\n",yytext);
{STRING} {printf("\n STRING: %s \n", yytext); return STRING;}
{ID} {printf("\n ID: %s \n", yytext); }
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
{PYC} {printf("\n PyC: %s \n", yytext); return PYC; }
{COMA} printf("\n Coma: %s \n", yytext);

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