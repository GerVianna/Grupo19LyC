#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tercetos.h"

int crear_terceto(char* atr1, char* atr2, char* atr3) {
    terceto ter;
    ter.nroTerceto = indice_terceto;
    strcpy(ter.atr1, atr1);
    strcpy(ter.atr2, atr2);
    strcpy(ter.atr3, atr3);
    vector_tercetos[indice_terceto] = ter;
    indice_terceto++;
    return indice_terceto-1;
}

void escribir_tercetos()
{
	FILE* arch;
	int i;
	terceto aux;
	arch = fopen("intermedia.txt", "w+");
   
	for(i = 0; i < indice_terceto; i++)
	{	
		aux =  vector_tercetos[i];
		fprintf(arch, "[%d] (%s,%s,%s)\n", aux.nroTerceto, aux.atr1,aux.atr2, aux.atr3);
		
	}
	fclose(arch);
}