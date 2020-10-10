%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
// #include "tablasimbolos.c"
int yystopparser = 0;
FILE *yyin;

    int yyerror();
    int yylex();
%}

%token GET

%%

get:
    GET { printf("retorne alto GET\n");};

%%

int main(int argc, char *argv[]) {
    if((yyin = fopen(argv[1], "rt")) == NULL)
    {
        printf("\nNo se puede abrir el archivo de prueba: %s\n", argv[1]);
    }
    else {
        printf("pase por el parse");
        yyparse();
    }
    fclose(yyin);
    return 0;
}

int yyerror(void) {
    printf("Error sintactico \n");
    exit(1);
}