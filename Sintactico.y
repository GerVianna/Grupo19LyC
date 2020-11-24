%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "y.tab.h"
#include "lib/tercetos.c"
#include "lib/pila.c"
#include "lib/tsimbolos.c"
#include "lib/assembler.c"

// #include "tablasimbolos.c"
int yystopparser = 0;
int variablesDIM = 0;
int tiposDIM = 0;
char vecId [50][32];
char vecTipos [50][32];
int cantExpr = -1;

FILE *yyin;

int yyerror();
int yylex();
void guardarAsignacion(const char*);
int yyerrorAsig(const char*);

void crearPilas();
bool verificarAsignacion(const char*);
bool esCompatible(const char*, const char*);


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

//Validar asignaciones
int esAsig = 0;
char vecAsignacion[30][50];

char auxString[10];
char maxString[10];
char despLista[10];

//Operacion
char oper[4];
int isOR = 0;

//Auxiliar para ASM
char auxASM[10] = "@aux";
char indiceString[10];

//Aux cantMaximos
int cantMaximo = 0;
char maxIndice[5];
char maximoString[10] = "@max";

//Pila
Pila pilaExpresion;
Pila pilaTermino;
Pila pilaFactor;
Pila pilaIf;
Pila pilaWhile;
Pila pilaLista;

%}

%union {
    int tipo_int;
    double tipo_double;
    char *tipo_string;
}

%token PUT GET MAXIMO DIM AS
%token<tipo_string> ID
%token<tipo_string> INTEGER
%token<tipo_string> FLOAT
%token<tipo_string> STRING
%token<tipo_string> CTE_STRING
%token<tipo_int> CTE
%token<tipo_string> CTE_HEXA
%token<tipo_double> CTE_REAL
%token<tipo_string> CTE_BIN
%token OP_ASIG OP_SUM OP_RES OP_MUL OP_DIV OP_IGUAL OP_DIST P_A P_C L_A L_C MENOR MAYOR MAYOR_I MENOR_I PYC COMA
%token WHILE IF ELSE
%token SEP_AND SEP_NOT SEP_OR

%right OP_IGUAL
%left OP_SUM OP_RES
%left OP_MUL OP_DIV

%type<tipo_string> tipo


%%

programa			:			program { printf("Compilacion OK\n");};

program				:			sentencia { printf("\n Regla 0\n\n");}
                                | program sentencia { printf("\n Regla 1\n\n");};

sentencia			: 		    put { printf("\n Regla 2\n\n");} 
                                | get { printf("\n Regla 3\n\n");}
                                | asignacion { printf("\n Regla 4\n\n");}
                                | maximo PYC { printf("\n Regla 5 \n\n");} 
                                | declaracion{ printf("\n Regla 6\n\n");}
                                | while{printf("\n Regla 7\n\n");}
                                | if { printf("\n Regla 8\n\n");};

declaracion         :           DIM MENOR lista_id MAYOR AS MENOR lista_tipos MAYOR { 
                                    int i = 0;
                                    for(i = 0; i < variablesDIM; i++) {
                                        insertarEnTablaDeSimbolos(vecId[i], vecTipos[i], "CTE_STRING", 0, 0 );
                                    }
                                    printf("\n Regla 9\n\n");
                                };

put                 :           PUT CTE  			    {itoa($2,varItoa,10);
                                                         strcpy(varString,"_");
                                                         strcat(varString, varItoa);
                                                         crear_terceto("PUT",varString,"_");} PYC { printf("\n Regla 10 \n\n");}

                                | PUT ID                {strcpy(varString,"_");
                                                         strcat(varString, $2);
                                                         crear_terceto("PUT",varString,"_");} PYC { printf("\n Regla 11 \n\n");}

                                | PUT CTE_STRING        {strcpy(varString,"_");
                                                         strcat(varString, $2);
                                                         crear_terceto("PUT",varString,"_");} PYC { printf("\n Regla 12\n\n");} 

                                | PUT CTE_HEXA          {strcpy(varString,"_");
                                                         strcat(varString, $2);
                                                         crear_terceto("PUT",varString,"_");} PYC { printf("\n Regla 13\n\n");}
                                | PUT CTE_REAL          {sprintf(varString,"%.2f",$2);
                                                         strcpy(varReal,"_");
                                                         strcat(varReal, varString);
                                                         crear_terceto("PUT",varReal,"_");} PYC { printf("\n Regla 14\n\n");}

                                | PUT CTE_BIN           {strcpy(varString,"_");
                                                         strcat(varString, $2);
                                                         crear_terceto("PUT",varString,"_");} PYC { printf("\n Regla 15\n\n");}
;
get                 :           GET ID  {crear_terceto("GET",$2,"_");} PYC { printf("\n Regla 16\n\n");} ;

maximo              :           MAXIMO P_A lista P_C { 
                                    insertarEnTablaDeSimbolos(maximoString,"auxCode","",0,0);
                                    printf("\n Regla 17\n\n");
                                };
                                //| MAXIMO P_A lista P_C PYC { printf("\n Regla 17\n\n");};

asignacion          :           ID {strcpy(varID,$1);} OP_ASIG {esAsig = 1;} exp { 
                                    printf("\n Regla 18\n\n");
                                    if(!verificarAsignacion(varID)) {
                                        yyerrorAsig(varID);
                                    }
                                    int auxEind= desapilar(&pilaExpresion);
                                    itoa(auxEind,EindString,10);
                                    crear_terceto(":",varID,EindString);

                                    cantExpr = -1;
                                    esAsig = 0;
                                } PYC; 

while:
    WHILE {
            apilar(&pilaWhile,obtenerIndiceTercetos());
            crear_terceto("ET","_","_");
        }
        P_A condicion_simple P_C L_A program L_C { 
            int biInd = crear_terceto("JMP","_","_");
            char valorActual[4];
            int pivote=desapilar(&pilaIf);
            itoa(obtenerIndiceTercetos(),valorActual,10);
            strcpy(vector_tercetos[pivote].atr2,valorActual);
            
            pivote=desapilar(&pilaWhile);
            itoa(pivote,valorActual,10);
            strcpy(vector_tercetos[biInd].atr2,valorActual);
            
            printf("\n Regla 19\n\n");
        }
    | WHILE {
            apilar(&pilaWhile,obtenerIndiceTercetos());
            crear_terceto("ET","_","_");
        } P_A condicion_simple P_C sentencia { 
            int biInd = crear_terceto("JMP","_","_");
            char valorActual[4];
            int pivote=desapilar(&pilaIf);
            itoa(obtenerIndiceTercetos(),valorActual,10);
            strcpy(vector_tercetos[pivote].atr2,valorActual);
            
            pivote=desapilar(&pilaWhile);
            itoa(pivote,valorActual,10);
            strcpy(vector_tercetos[biInd].atr2,valorActual);

            printf("\n Regla 20\n\n");
        };
    /*| WHILE {
            apilar(&pilaWhile,obtenerIndiceTercetos());
            crear_terceto("ET","_","_");
        } P_A condicion P_C L_A program L_C { 
            int biInd = crear_terceto("JMP","_","_");
            char valorActual[4];
            int pivote=desapilar(&pilaIf);
            itoa(obtenerIndiceTercetos(),valorActual,10);
            strcpy(vector_tercetos[pivote].atr2,valorActual);
            
            pivote=desapilar(&pilaWhile);
            itoa(pivote,valorActual,10);
            strcpy(vector_tercetos[biInd].atr2,valorActual);

            printf("\n Regla 64\n\n");
        }
    | WHILE {
            apilar(&pilaWhile,obtenerIndiceTercetos());
            crear_terceto("ET","_","_");
        } P_A condicion P_C sentencia { 
            int biInd = crear_terceto("JMP","_","_");
            char valorActual[4];
            int pivote=desapilar(&pilaIf);
            itoa(obtenerIndiceTercetos(),valorActual,10);
            strcpy(vector_tercetos[pivote].atr2,valorActual);
            
            pivote=desapilar(&pilaWhile);
            itoa(pivote,valorActual,10);
            strcpy(vector_tercetos[biInd].atr2,valorActual);

            printf("\n Regla 65\n\n");
        };*/

if:
    IF P_A condicion_simple P_C L_A program L_C {
                                        int bi=crear_terceto("JMP","_","_");
                                        char valorActual[4];
                                        int pivote=desapilar(&pilaIf);
                                        itoa(obtenerIndiceTercetos(),valorActual,10);
                                        strcpy(vector_tercetos[pivote].atr2,valorActual);
                                        apilar(&pilaIf,bi);
                                    } else { printf("\n Regla 21 \n\n");}


    | IF P_A condicion_simple P_C sentencia {
                                        int bi=crear_terceto("JMP","_","_");
                                        char valorActual[4];
                                        int pivote=desapilar(&pilaIf);
                                        itoa(obtenerIndiceTercetos(),valorActual,10);
                                        strcpy(vector_tercetos[pivote].atr2,valorActual);
                                        apilar(&pilaIf,bi);
                                    } else { printf("\n Regla 22\n\n");}

    | IF P_A condicion_simple P_C L_A program L_C{
                                        char valorActual[4];
                                        int pivote = desapilar(&pilaIf);
                                        itoa(obtenerIndiceTercetos(),valorActual,10);
                                        strcpy(vector_tercetos[pivote].atr2,valorActual);
                                        printf("\n Regla 23\n\n");
                                    }

    | IF P_A condicion_simple P_C sentencia{
                                        char valorActual[4];
                                        int pivote = desapilar(&pilaIf);
                                        itoa(obtenerIndiceTercetos(),valorActual,10);
                                        strcpy(vector_tercetos[pivote].atr2,valorActual);
                                        printf("\n Regla 24\n\n");
                                    }   
    |
    IF P_A condicion P_C L_A program L_C {
                                        int bi=crear_terceto("JMP","_","_");
                                        char valorActual[4];
                                        int pivote=desapilar(&pilaIf);
                                        int tercetoActual=obtenerIndiceTercetos();
                                        itoa(tercetoActual,valorActual,10);
                                        strcpy(vector_tercetos[pivote].atr2,valorActual);
                                        if(isOR == 1) {
                                            itoa(pivote+1,valorActual,10);
                                            isOR = 0;
                                        }
                                        pivote=desapilar(&pilaIf);
                                        strcpy(vector_tercetos[pivote].atr2,valorActual);
                                        apilar(&pilaIf,bi);
                                    } else { printf("\n Regla 25\n\n");}


    | IF P_A condicion P_C sentencia {
                                        int bi=crear_terceto("JMP","_","_");
                                        char valorActual[4];
                                        int pivote=desapilar(&pilaIf);
                                        int tercetoActual=obtenerIndiceTercetos();
                                        itoa(tercetoActual,valorActual,10);
                                        strcpy(vector_tercetos[pivote].atr2,valorActual);
                                        if(isOR == 1) {
                                            itoa(pivote+1,valorActual,10);
                                            isOR = 0;
                                        }
                                        pivote=desapilar(&pilaIf);
                                        strcpy(vector_tercetos[pivote].atr2,valorActual);
                                        apilar(&pilaIf,bi);
                                    } else { printf("\n Regla 26\n\n");}

    | IF P_A condicion P_C L_A program L_C{
                                        char valorActual[4];
                                        int pivote = desapilar(&pilaIf);
                                        int tercetoActual=obtenerIndiceTercetos();
                                        itoa(tercetoActual,valorActual,10);
                                        strcpy(vector_tercetos[pivote].atr2,valorActual);
                                        if(isOR == 1) {
                                            itoa(pivote+1,valorActual,10);
                                            isOR = 0;
                                        }
                                        pivote=desapilar(&pilaIf);
                                        strcpy(vector_tercetos[pivote].atr2,valorActual);
                                        printf("\n Regla 27\n\n");
                                    }
    | IF P_A condicion P_C sentencia{
                                        char valorActual[4];
                                        int pivote = desapilar(&pilaIf);
                                        int tercetoActual=obtenerIndiceTercetos();
                                        itoa(tercetoActual,valorActual,10);
                                        strcpy(vector_tercetos[pivote].atr2,valorActual);
                                        if(isOR == 1) {
                                            itoa(pivote+1,valorActual,10);
                                            isOR = 0;
                                        }
                                        pivote=desapilar(&pilaIf);
                                        strcpy(vector_tercetos[pivote].atr2,valorActual);
                                        printf("\n Regla 28\n\n");
                                    }


;

else:
    ELSE L_A program L_C{   int pivote=desapilar(&pilaIf);
                            char valorActual[4];
                            itoa(obtenerIndiceTercetos(),valorActual,10);
                            strcpy(vector_tercetos[pivote].atr2,valorActual);
                            printf("\n Regla 29 \n\n");
                        }
    | ELSE sentencia{       int pivote=desapilar(&pilaIf);
                            char valorActual[4];
                            itoa(obtenerIndiceTercetos(),valorActual,10);
                            strcpy(vector_tercetos[pivote].atr2,valorActual);
                            printf("\n Regla 30\n\n");
                    }
;




condicion_simple:
            exp MENOR exp {
                    char auxEind1[4];
                    itoa(desapilar(&pilaExpresion),auxEind1,10);
                    char auxEind2[4];
                    itoa(desapilar(&pilaExpresion),auxEind2,10);
                    crear_terceto("CMP",auxEind2,auxEind1);
                    int numTerceto=crear_terceto("JAE","_","_");
                    apilar(&pilaIf,numTerceto);
                    printf("\n Regla 31\n\n");}

        |
            exp MAYOR exp {
                    char auxEind1[4];
                    itoa(desapilar(&pilaExpresion),auxEind1,10);
                    char auxEind2[4];
                    itoa(desapilar(&pilaExpresion),auxEind2,10);
                    crear_terceto("CMP",auxEind2,auxEind1);
                    int numTerceto=crear_terceto("JNA","_","_");
                    apilar(&pilaIf,numTerceto);
                    printf("\n Regla 32\n\n");}
                    
        |   exp MENOR_I exp {
                    char auxEind1[4];
                    itoa(desapilar(&pilaExpresion),auxEind1,10);
                    char auxEind2[4];
                    itoa(desapilar(&pilaExpresion),auxEind2,10);
                    crear_terceto("CMP",auxEind2,auxEind1);
                    int numTerceto=crear_terceto("JA","_","_");
                    apilar(&pilaIf,numTerceto);
                    printf("\n Regla 33\n\n");
        } 

        |   exp MAYOR_I exp {
                    char auxEind1[4];
                    itoa(desapilar(&pilaExpresion),auxEind1,10);
                    char auxEind2[4];
                    itoa(desapilar(&pilaExpresion),auxEind2,10);
                    crear_terceto("CMP",auxEind2,auxEind1);
                    int numTerceto=crear_terceto("JNAE","_","_");
                    apilar(&pilaIf,numTerceto);
                    printf("\n Regla 34\n\n");
        }

        |   exp OP_IGUAL exp {
                    char auxEind1[4];
                    itoa(desapilar(&pilaExpresion),auxEind1,10);
                    char auxEind2[4];
                    itoa(desapilar(&pilaExpresion),auxEind2,10);
                    crear_terceto("CMP",auxEind2,auxEind1);
                    int numTerceto=crear_terceto("JNE","_","_");
                    apilar(&pilaIf,numTerceto);
                    printf("\n Regla 35\n\n");
        }

        |   exp OP_DIST exp {
                    char auxEind1[4];
                    itoa(desapilar(&pilaExpresion),auxEind1,10);
                    char auxEind2[4];
                    itoa(desapilar(&pilaExpresion),auxEind2,10);
                    crear_terceto("CMP",auxEind2,auxEind1);
                    int numTerceto=crear_terceto("JE","_","_");
                    apilar(&pilaIf,numTerceto);
                    printf("\n Regla 36\n\n");
                          
        }       
;

condicion:
    condicion_simple SEP_AND condicion_simple { printf("\n Regla 37\n\n");}
    | condicion_simple SEP_OR {
            int num = crear_terceto("JMP","_","_");
            char valorActual[4];
            int pivote = desapilar(&pilaIf);
            int tercetoActual=obtenerIndiceTercetos();
            itoa(tercetoActual,valorActual,10);
            strcpy(vector_tercetos[pivote].atr2,valorActual);
            isOR = 1;
            apilar(&pilaIf, num);
        } condicion_simple { printf("\n Regla 38\n\n");}
;

exp:
	exp OP_SUM term { 
        itoa(desapilar(&pilaExpresion),EindString,10);
        itoa(desapilar(&pilaTermino),TindString,10);
        Eind=crear_terceto("+",EindString,TindString);
        itoa(Eind,indiceString,10);
        strcat(auxASM,indiceString);
        strcpy(vector_tercetos[Eind].res_aux,auxASM);
        insertarEnTablaDeSimbolos(auxASM,"auxCode","",0,0);
        strcpy(auxASM,"@aux");
        apilar(&pilaExpresion,Eind);
        printf("\n Regla 40\n\n");
    }
	| exp OP_RES term { 
        itoa(desapilar(&pilaExpresion),EindString,10);
        itoa(desapilar(&pilaTermino),TindString,10);
        Eind=crear_terceto("-",EindString,TindString);
        itoa(Eind,indiceString,10);
        strcat(auxASM,indiceString);
        strcpy(vector_tercetos[Eind].res_aux,auxASM);
        insertarEnTablaDeSimbolos(auxASM,"auxCode","",0,0);
        strcpy(auxASM,"@aux");
        apilar(&pilaExpresion,Eind) ;
        printf("\n Regla 41\n\n");
    }
    | term { 
        Eind=desapilar(&pilaTermino); 
        apilar(&pilaExpresion,Eind) ;
        printf("\n Regla 42\n\n");
    }

	;
term:
	term OP_MUL factor { 
        itoa(desapilar(&pilaTermino),TindString,10);
        itoa(desapilar(&pilaFactor),FindString,10);
        Tind=crear_terceto("*",TindString,FindString);
        itoa(Tind,indiceString,10);
        strcat(auxASM,indiceString);
        strcpy(vector_tercetos[Tind].res_aux,auxASM);
        insertarEnTablaDeSimbolos(auxASM,"auxCode","",0,0);
        strcpy(auxASM,"@aux");
        apilar(&pilaTermino,Tind) ;
        printf("\n Regla 43\n\n");
    }
	|term OP_DIV factor { 
        itoa(desapilar(&pilaTermino),TindString,10);
        itoa(desapilar(&pilaFactor),FindString,10);
        Tind=crear_terceto("/",TindString,FindString);
        itoa(Tind,indiceString,10);
        strcat(auxASM,indiceString);
        strcpy(vector_tercetos[Tind].res_aux,auxASM);
        insertarEnTablaDeSimbolos(auxASM,"auxCode","",0,0);
        strcpy(auxASM,"@aux");
        apilar(&pilaTermino,Tind) ;
        printf("\n Regla 44\n\n");
    }
	| factor {  
        Tind = desapilar(&pilaFactor);
        apilar(&pilaTermino,Tind) ;
        printf("\n Regla 45\n\n");
    }
	;

factor: CTE {  
            itoa($1,varItoa,10);
            strcpy(varString,"_");
            strcat(varString, varItoa);
            Find = crear_terceto(varString,"_","_");
            apilar(&pilaFactor,Find);
            if(esAsig == 1) {
                guardarAsignacion(varString);
            }
            printf("\n Regla 46\n\n");
        }
        | ID { 
            Find = crear_terceto($1,"_","_");
            apilar(&pilaFactor,Find);
            if(esAsig == 1) {
                guardarAsignacion($1);
            }
            printf("\n Regla 47\n\n");
        }
        | CTE_STRING {
            Find = crear_terceto($1,"_","_");
            apilar(&pilaFactor,Find);
            strcpy(varString,"_");
            strcat(varString, $1);
            
            if(esAsig == 1) {
                guardarAsignacion(varString);
            }
            printf("\n Regla 48\n\n");
        } 

        | CTE_HEXA { 
            Find = crear_terceto($1,"_","_");
            apilar(&pilaFactor,Find);
            strcpy(varString,"_");
            strcat(varString, $1);
            
            if(esAsig == 1) {
                guardarAsignacion(varString);
            }
            printf("\n Regla 49\n\n");
        } 
        | CTE_REAL { 
            sprintf(varString,"%g",$1);
            strcpy(varReal,"_");
            strcat(varReal, varString);
            Find = crear_terceto(varReal,"_","_");
            apilar(&pilaFactor,Find);
            if(esAsig == 1) {
                guardarAsignacion(varReal);
            }
            printf("\n Regla 50\n\n");
        }
        | CTE_BIN { 
            Find = crear_terceto($1,"_","_");
            apilar(&pilaFactor,Find);
            strcpy(varString,"_");
            strcat(varString, $1);
            if(esAsig == 1) {
                guardarAsignacion(varString);
            }
            printf("\n Regla 51\n\n");
        }

        | P_A exp P_C  { 
            Find = desapilar(&pilaExpresion);
            apilar(&pilaFactor,Find);
            printf("\n Regla 52\n\n");
        }

        | maximo { 
            Find = crear_terceto(maximoString,"_","_");
            cantMaximo--;
            itoa(cantMaximo,maxIndice,10);
            strcpy(maximoString,"@max");
            strcat(maximoString,maxIndice);
            apilar(&pilaFactor,Find);
            printf("\n Regla 53\n\n");}
        ;
lista: 
    exp
     {  int d = desapilar(&pilaExpresion);
        itoa(d,despLista,10);
        strcpy(maximoString,"@max");
        cantMaximo++;
        itoa(cantMaximo,maxIndice,10);
        strcat(maximoString,maxIndice);
        crear_terceto(":", maximoString, despLista);
        printf("\n Regla 55\n\n");
    }
    |  
     lista COMA exp
     { 
        int d = desapilar(&pilaExpresion);
        itoa(d,despLista,10);
        crear_terceto(":","@aux",despLista);
        crear_terceto("CMP","@aux",maximoString);
        xind = crear_terceto("JNA","_","_");
        apilar(&pilaLista,xind);
        crear_terceto(":",maximoString,"@aux");
        xind = desapilar(&pilaLista);
        char valorActual[4];
        itoa(obtenerIndiceTercetos(),valorActual,10);
        strcpy(vector_tercetos[xind].atr2,valorActual);
        printf("\n Regla 54\n\n");
    };

lista_tipos:
    lista_tipos COMA tipo { 
            strcpy(vecTipos[tiposDIM], $3);
            tiposDIM++; 
            printf("\n Regla 56\n\n");
            }
    | tipo { 
            strcpy(vecTipos[tiposDIM], $1);
            tiposDIM++; 
            printf("\n Regla 57\n\n");
            } 
    ;

lista_id:
    lista_id COMA ID { 
            strcpy(vecId[variablesDIM], $3);
            variablesDIM++; 
            printf("\n Regla 58\n\n");} 
    | ID { 
            strcpy(vecId[variablesDIM], $1);
            variablesDIM++;
            printf("\n Regla 59\n\n");
         } 
    ;

tipo:
    INTEGER {$<tipo_string>$ = $1; 
            printf("\n Regla 60\n\n");}
    | FLOAT {$<tipo_string>$ = $1;
            printf("\n Regla 61\n\n");} 
    | STRING {$<tipo_string>$ = $1;
            printf("\n Regla 62\n\n");}
    ;
%%

int main(int argc, char *argv[]) {
    if((yyin = fopen(argv[1], "rt")) == NULL)
    {
        printf("\nNo se puede abrir el archivo de prueba: %s\n", argv[1]);
    }
    else {
        crearPilas();
        crearTablaSimbolos();
        yyparse();
        guardarTablaDeSimbolos();
        escribir_tercetos();
        generarAssembler();
        escribir_tercetosAssembler();
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

bool verificarAsignacion(const char* id) {
    t_nodo* lexi = getLexema(id);
    t_nodo* lexd;
    int i;
    for(i = 0; i<=cantExpr; i++){
        lexd = getLexema(vecAsignacion[i]);
        if(!esCompatible(lexi->data.tipo, lexd->data.tipo)) {
            return false;
        }
    }
    return true;
}


bool esCompatible(const char* tipo1, const char* tipo2)
{
    if(strcmp("Integer", tipo1) == 0){
        return (strcmp("Integer", tipo2) == 0 || strcmp("CTE", tipo2) == 0 
            || strcmp("CTE_HEXA", tipo2) == 0 || strcmp("CTE_BIN", tipo2) == 0);
    }
    else if(strcmp("Float", tipo1) == 0){
        return (strcmp("Float", tipo2) == 0 || strcmp("CTE", tipo2) == 0 || strcmp("CTE_REAL", tipo2) == 0 
            || strcmp("CTE_HEXA", tipo2) == 0 || strcmp("CTE_BIN", tipo2) == 0 || strcmp("Integer", tipo2) == 0);
    }
    else if(strcmp("String", tipo1) == 0){
        return (strcmp("String", tipo2) == 0 || strcmp("CTE_STRING", tipo2) == 0);
    }
}


void crearPilas() {
    pilaExpresion = crearPila();
    pilaTermino = crearPila();
    pilaFactor = crearPila();
    pilaIf = crearPila();
    pilaWhile = crearPila();
    pilaLista = crearPila();
}

int yyerrorAsig(const char* id) {
    printf("\nError: se hacen asignaciones de distinto tipo de datos para el id: %s", id);
    exit(1);
}

void guardarAsignacion(const char* id){
    cantExpr++;
    strcpy(vecAsignacion[cantExpr], id);
}
