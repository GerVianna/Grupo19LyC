%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
// #include "tablasimbolos.c"
int yystopparser = 0;
int variablesDIM = 0;
int tiposDIM = 0;
char vecId [50][32];
char vecTipos [50][32];


FILE *yyin;

    int yyerror();
    int yylex();

typedef struct
{
        char *nombre;
        char *tipo;
        union Valor{
                int valor_int;
                double valor_double;
                char *valor_string;
        }valor;
        int longitud;
}t_data;

typedef struct simbolo
{
        t_data data;
        struct simbolo *siguiente;
}t_nodo;


typedef struct
{
        t_nodo *primero;
}t_tabla;

t_tabla tablaSimbolos;

void crearTablaSimbolos();

t_data* crearDatos(const char *nombre, const char *tipo, const char* valString, int valInt, double valDouble);

int insertarEnTablaDeSimbolos(const char *nombre,const char *tipo, const char* valString, int valInt, double valDouble);

void guardarTablaDeSimbolos();

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
%token CTE_HEXA
%token<tipo_double> CTE_REAL
%token CTE_BIN
%token OP_ASIG OP_SUM OP_RES OP_MUL OP_DIV OP_IGUAL OP_DIST P_A P_C L_A L_C MENOR MAYOR MAYOR_I MENOR_I PYC COMA
%token WHILE IF ELSE
%token SEP_AND SEP_NOT SEP_OR

%right OP_IGUAL
%left OP_SUM OP_RES
%left OP_MUL OP_DIV

%type<tipo_string> tipo


%%

programa			:			program { printf("Compilacion OK\n");};
program				:			sentencia | program sentencia { printf("\n retorne program -> PROGRAM\n\n");};
sentencia			: 		    put | get | asignacion | maximo | declaracion | while | if { printf("\n retorne sentencia -> SENTENCIA\n\n");};
declaracion         :           DIM MENOR lista_id MAYOR AS MENOR lista_tipos MAYOR { printf("");};

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
        CTE_STRING | 
        CTE_HEXA | CTE_REAL | CTE_BIN | P_A exp P_C | maximo { printf("\n retorne factor ->regla factor\n\n");};
lista: 
     lista COMA exp
     |exp
     ;

lista_tipos:
    lista_tipos COMA tipo { 
            strcpy(vecTipos[tiposDIM], $3);
            tiposDIM++; 
            }
    | tipo { 
            strcpy(vecTipos[tiposDIM], $1);
            tiposDIM++; 
            } 
    ;

lista_id:
    lista_id COMA ID { 
            strcpy(vecId[variablesDIM], $3);
            variablesDIM++; } 
    | ID { 
            strcpy(vecId[variablesDIM], $1);
            variablesDIM++;
         } 
    ;

tipo:
    INTEGER {$<tipo_string>$ = $1;} | FLOAT {$<tipo_string>$ = $1;} | STRING {$<tipo_string>$ = $1;}
    ;
%%

int main(int argc, char *argv[]) {
    if((yyin = fopen(argv[1], "rt")) == NULL)
    {
        printf("\nNo se puede abrir el archivo de prueba: %s\n", argv[1]);
    }
    else {
        crearTablaSimbolos();
        yyparse();
		int i = 0;
        for(i = 0; i < variablesDIM; i++) {
            insertarEnTablaDeSimbolos(vecId[i], vecTipos[i], "CTE_STRING", 0, 0 );
        }
        guardarTablaDeSimbolos();
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

void crearTablaSimbolos() {
    tablaSimbolos.primero = NULL;
}

int insertarEnTablaDeSimbolos(const char *nombre,const char *tipo, const char* valString, int valInt, double valDouble)
{   
    t_nodo *tabla = tablaSimbolos.primero;
    char nombreCTE[32] = "_";
    strcat(nombreCTE, nombre);
    
    while(tabla)
    {
        if(strcmp(tabla->data.nombre, nombre) == 0 || strcmp(tabla->data.nombre, nombreCTE) == 0)
        {
            return 1;
        }
        
        if(tabla->siguiente == NULL)
        {
            break;
        }
        tabla = tabla->siguiente;
    }

    t_data *data = (t_data*)malloc(sizeof(t_data));
    data = crearDatos(nombre, tipo, valString, valInt, valDouble);

    if(data == NULL)
    {
        return 1;
    }

    t_nodo* nuevo = (t_nodo*)malloc(sizeof(t_nodo));

    if(nuevo == NULL)
    {
        return 2;
    }

    nuevo->data = *data;
    nuevo->siguiente = NULL;

    if(tablaSimbolos.primero == NULL)
    {
        tablaSimbolos.primero = nuevo;
    }
    else
    {
        tabla->siguiente = nuevo;
    }

    return 0;
}

t_data* crearDatos(const char *nombre, const char *tipo, const char* valString, int valInt, double valDouble)
{
    char full[32] = "_";
    char aux[20];

    t_data *data = (t_data*)calloc(1, sizeof(t_data));
    if(data == NULL)
    {
        return NULL;
    }

    data->tipo = (char*)malloc(sizeof(char) * (strlen(tipo) + 1));
    strcpy(data->tipo, tipo);


    //Es una variable
    if(strcmp(tipo, "String")==0 || strcmp(tipo, "Integer")==0 || strcmp(tipo, "Float")==0)
    {
        //al nombre lo dejo aca porque no lleva 
        data->nombre = (char*)malloc(sizeof(char) * (strlen(nombre) + 1));
        strcpy(data->nombre, nombre);
        return data;
    }
    else
    {      //Son constantes: tenemos que agregarlos a la tabla con "_" al comienzo del nombre, hay que agregarle el valor
        if(strcmp(tipo, "CTE_STRING") == 0)
        {
            data->valor.valor_string = (char*)malloc(sizeof(char) * strlen(valString) +1);
            data->nombre = (char*)malloc(sizeof(char) * (strlen(valString) + 1));
            strcat(full, valString);
            data->longitud = strlen(valString);
            strcpy(data->nombre, full);    
            strcpy(data->valor.valor_string, valString);
        }
        if(strcmp(tipo, "CTE_REAL") == 0)
        {
            sprintf(aux, "%g", valDouble);
            strcat(full, aux);
            data->nombre = (char*)malloc(sizeof(char) * strlen(full));

            strcpy(data->nombre, full);
            data->valor.valor_double = valDouble;
        }
        if(strcmp(tipo, "CTE") == 0)
        {
            sprintf(aux, "%d", valInt);
            strcat(full, aux);
            data->nombre = (char*)malloc(sizeof(char) * strlen(full));
            strcpy(data->nombre, full);
            data->valor.valor_int = valInt;
        }
        return data;
    }
    return NULL;
}

void guardarTablaDeSimbolos()
{
    FILE* archivo;
    if((archivo = fopen("ts.txt", "wt")) == NULL)
    {
            printf("\nNo se pudo crear la tabla de simbolos.\n\n");
            return;
    }
    else if(tablaSimbolos.primero == NULL)
            return;
    
    fprintf(archivo, "%-30s%-30s%-30s%-30s\n", "NOMBRE", "TIPO", "VALOR", "LONGITUD");

    t_nodo *aux;
    t_nodo *tabla = tablaSimbolos.primero;
    char linea[100];

    while(tabla)
    {
        aux = tabla;
        tabla = tabla->siguiente;
        
        if(strcmp(aux->data.tipo, "Integer") == 0) //variable int
        {
            sprintf(linea, "%-30s%-30s%-30s%lu\n", aux->data.nombre, aux->data.tipo, "--", strlen(aux->data.nombre));
        }
        else if(strcmp(aux->data.tipo, "CTE") == 0)
        {
            sprintf(linea, "%-30s%-30s%-30d%s\n", aux->data.nombre, aux->data.tipo, aux->data.valor.valor_int, "");
        } 
        else if(strcmp(aux->data.tipo, "Float") ==0)
        {
            sprintf(linea, "%-30s%-30s%-30s%lu\n", aux->data.nombre, aux->data.tipo, "--", strlen(aux->data.nombre));
        }
        else if(strcmp(aux->data.tipo, "CTE_REAL") == 0)
        {
            sprintf(linea, "%-30s%-30s%-30g%s\n", aux->data.nombre, aux->data.tipo, aux->data.valor.valor_double, "");
        }
        else if(strcmp(aux->data.tipo, "String") == 0)
        {
            sprintf(linea, "%-30s%-30s%-30s%lu\n", aux->data.nombre, aux->data.tipo, "--", strlen(aux->data.nombre));
        }
        else if(strcmp(aux->data.tipo, "CTE_STRING") == 0)
        {
            sprintf(linea, "%-30s%-30s%-30s%d\n", aux->data.nombre, "", aux->data.valor.valor_string, aux->data.longitud);
        }
        fprintf(archivo, "%s", linea);
        free(aux);
    }
    fclose(archivo); 
}