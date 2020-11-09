#ifndef TERCETOS_H
#define TERCETOS_H

typedef struct terceto {
    int nroTerceto;
    char atr1[50];
    char atr2[50];
    char atr3[50];
} terceto;

terceto vector_tercetos[1000];

int crear_terceto(char*, char*, char*);
void escribir_tercetos();
int obtenerIndiceTercetos();
void setIndiceTercetos(int);

static int indice_terceto = 0;

#endif