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

%token PUT
%token PYC
%token GET
%token ID
%token STRING CTE CTE_HEXA CTE_REAL
%token OP_ASIG OP_SUM OP_RES OP_MUL OP_DIV P_A P_C

%%

programa			:			program {printf("Compilacion OK\n");}
program				:			sentencia | program sentencia;
sentencia			: 		    put | get | asignacion;

put                 :           PUT factor PYC { printf("\n retorne put -> PUT STRING PYC\n\n");};
get                 :           GET ID PYC { printf("\n retorne get ->GET STRING PYC\n\n");};
asignacion          :           ID OP_ASIG exp PYC { printf("\n retorne get ->GET STRING PYC\n\n");};

exp:
	term {printf("regla exp es termino\n "); }
	|exp OP_SUM term { printf("regla exp es suma\n ");}
	| exp OP_RES term

	;
term:
	term OP_MUL factor
	|term OP_DIV factor
	| factor { printf("regla termino es factor\n ");}
	;

factor: CTE | ID | STRING | CTE_HEXA | CTE_REAL { printf("\n retorne get ->GET STRING PYC\n\n");};

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