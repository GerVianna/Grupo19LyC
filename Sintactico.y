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



%token PUT GET MAXIMO DIM AS
%token ID
%token INTEGER FLOAT
%token STRING CTE CTE_HEXA CTE_REAL CTE_BIN
%token OP_ASIG OP_SUM OP_RES OP_MUL OP_DIV OP_IGUAL OP_DIST P_A P_C L_A L_C MENOR MAYOR MAYOR_I MENOR_I PYC COMA
%token WHILE IF ELSE
%token SEP_AND SEP_NOT SEP_OR

%right OP_IGUAL
%left OP_SUM OP_RES
%left OP_MUL OP_DIV

%%

programa			:			program {printf("Compilacion OK\n");};
program				:			sentencia | program sentencia { printf("\n retorne program -> PROGRAM\n\n");};
sentencia			: 		    put | get | asignacion | maximo | declaracion | while | if { printf("\n retorne sentencia -> SENTENCIA\n\n");};
declaracion         :           DIM MENOR lista_id MAYOR AS MENOR lista_tipos MAYOR { printf("\n retorne declaracion -> DIM LISTA AS LISTA\n\n");};

put                 :           PUT factor PYC { printf("\n retorne put -> PUT STRING PYC\n\n");};
get                 :           GET ID PYC { printf("\n retorne get ->GET STRING PYC\n\n");};
maximo              :           MAXIMO P_A lista P_C | MAXIMO P_A lista P_C PYC { printf("\n retorne maximo -> MAXIMO\n\n");};
asignacion          :           ID OP_ASIG exp PYC { printf("\n retorne asignacion ->ID OP_ASIG exp PYC\n\n");};

while:
    WHILE P_A condicion P_C L_A program L_C 
    | WHILE P_A condicion P_C sentencia
;

if:
    IF P_A condicion P_C L_A program L_C else
    | IF P_A condicion P_C sentencia else
    | IF P_A condicion P_C L_A program L_C
    | IF P_A condicion P_C sentencia
;

else:
    ELSE L_A program L_C
    | ELSE sentencia
;




condicion_simple:
    exp operador exp {printf("\nexp operador exp\n"); }
;

condicion:
    condicion_simple separador_logico condicion_simple {printf("\ncondicion_simple separador_logico condicion_simple\n"); }
    | condicion_simple {printf("\ncondicion_simple\n"); }
;
separador_logico:
    SEP_AND {printf("\nSEP_AND\n"); }
    | SEP_OR {printf("\n SEP_OR\n");}
    | SEP_NOT {printf("\n SEP_NOT\n");}
;

operador: 
    MAYOR {printf("\noperador mayor reconocido\n");}
    | MENOR {printf("\noperador menor reconocido\n");}
    | MAYOR_I | MENOR_I | OP_DIST | OP_IGUAL {printf("operador reconocido\n "); }
;

exp:
	term {printf("term\n "); }
	|exp OP_SUM term { printf("exp OP_SUM term\n ");}
	| exp OP_RES term { printf("exp OP_RES term\n ");}

	;
term:
	term OP_MUL factor { printf("regla multiplicacion es factor\n ");}
	|term OP_DIV factor { printf("regla division es factor\n ");}
	| factor { printf("regla termino es factor\n ");}
	;

factor: CTE |
        ID { printf("\nID\n ");} | 
        STRING | 
        CTE_HEXA | CTE_REAL | CTE_BIN | P_A exp P_C | maximo { printf("\n retorne factor ->regla factor\n\n");};
lista: 
     lista COMA exp
     |exp
     ;

lista_tipos:
    lista_tipos COMA tipo
    | tipo
    ;

lista_id:
    lista_id COMA ID
    | ID
    ;

tipo:
    INTEGER | FLOAT
    ;
%%

int main(int argc, char *argv[]) {
    if((yyin = fopen(argv[1], "rt")) == NULL)
    {
        printf("\nNo se puede abrir el archivo de prueba: %s\n", argv[1]);
    }
    else {
        yyparse();
    }
    fclose(yyin);
    return 0;
}

int yyerror(void) {
    printf("Error sintactico \n");
    exit(1);
}