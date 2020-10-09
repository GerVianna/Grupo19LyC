%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
FILE *yyin;
int yylval;
char *yyltext;

int yyerror(void);
%}

%option noyywrap
%option yylineno



%%



"\n"
"\t"
"\n\t"
"\r\t"
" "
.       yyerror();
%%

int main(int argc, char *argv[]) {
    if ((yyin = fopen(argv[1], "rt")) == NULL) {
        printf("\n No se puede abrir el archivo");
    } else {
        yylex();
    }
    fclose(yyin);
    return 0;
}

int yyerror(void) {
    printf("Error léxico: Caracter invalido: %s", yytext);
    exit(1);
}