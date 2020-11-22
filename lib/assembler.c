#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#include "assembler.h"
#include "tercetos.h"
#include "const.h"

char bufferaux1[20];
int yyerror();
int esOperacion(int);

void preparar_assembler()
{
	char etiqueta[20] = "etiqueta_";
	int entero_aux;
    int i;
    int j;
    int indice_terceto = obtenerIndiceTercetos();
	
	for(i=0;i<indice_terceto;i++)
	{

		if(strcmp(vector_tercetos[i].atr2,"_")==0 && strcmp(vector_tercetos[i].atr3,"_")==0 && vector_tercetos[i].esEtiqueta!=99 )
		{
			for(j=i+1;j< indice_terceto;j++)
			{
				itoa(i,bufferaux1,10);
				if(strcmp(vector_tercetos[j].atr2,bufferaux1)==0)
				{
					strcpy(vector_tercetos[j].atr2,vector_tercetos[i].atr1);
				}
				if(strcmp(vector_tercetos[j].atr3,bufferaux1)==0)
				{
					strcpy(vector_tercetos[j].atr3,vector_tercetos[i].atr1);
				}
			}
		}

		
		
		if(strcmp(vector_tercetos[i].atr2,"_")==0 && strcmp(vector_tercetos[i].atr3,"_")==0 && vector_tercetos[i].esEtiqueta==99 )
		{
			//printf("ETIQUETA + TERCETO _ _\n");
			j=i+1;
			itoa(i,bufferaux1,10);
			while(strcmp(vector_tercetos[j].atr2,bufferaux1)!=0 && strcmp(vector_tercetos[j].atr3,bufferaux1)!=0)
				j++;
			
			if(strcmp(vector_tercetos[j].atr2,bufferaux1)==0)
				strcpy(vector_tercetos[j].atr2,vector_tercetos[i].atr1);
			else
				strcpy(vector_tercetos[j].atr3,vector_tercetos[i].atr1);
			
		}
		
		if(esOperacion(i))
		{
			for(j=i+1;j< indice_terceto;j++)
			{	
				itoa(i,bufferaux1,10);
				if(strcmp(vector_tercetos[j].atr2,bufferaux1)==0)
				{
					strcpy(vector_tercetos[j].atr2,vector_tercetos[i].resultado_aux);
				}
				
				if(strcmp(vector_tercetos[j].atr3,bufferaux1)==0)
				{
					strcpy(vector_tercetos[j].atr3,vector_tercetos[i].resultado_aux);
				}
				
			}
			
		}
		
		if(esSalto(i))
		{	
			printf("\natr1: %s - atr2: %s - atr3: %s\n",vector_tercetos[i].atr1,vector_tercetos[i].atr2,vector_tercetos[i].atr3);
			entero_aux = atoi(vector_tercetos[i].atr2);
			printf("\nentero_aux: %d",entero_aux);
			vector_tercetos[entero_aux].esEtiqueta = 99;
			strcat(etiqueta,vector_tercetos[i].atr2);
			printf("\nETIQUETA: %s",etiqueta);
			strcpy(vector_tercetos[i].atr2,etiqueta);
			printf("\nvector_tercetos[%d].atr2: %s",i,vector_tercetos[i].atr2);
			strcpy(etiqueta,"etiqueta_");
		}
		
	}

}

int esOperacion(int indice)
{

	if(strcmp(vector_tercetos[indice].atr1,"+")==0)
	    return 1;	
	if(strcmp(vector_tercetos[indice].atr1,"-")==0)
	    return 1;
	if(strcmp(vector_tercetos[indice].atr1,"*")==0)
	    return 1;
	if(strcmp(vector_tercetos[indice].atr1,"/")==0)
	    return 1;
	if(strcmp(vector_tercetos[indice].atr1,":")==0){
		return 1;
	}
	if(strcmp(vector_tercetos[indice].atr1,"PUT")==0)
	{
		return 1;											
	}
	if(strcmp(vector_tercetos[indice].atr1,"GET")==0){
		return 1;
	}
	
	return 0;
}

int esSalto(int indice)
{	
	if(strcmp(vector_tercetos[indice].atr1,"JNA")==0)		// >
	return 1;
	
	if(strcmp(vector_tercetos[indice].atr1,"JAE")==0)		// <
	return 2;
	
	if(strcmp(vector_tercetos[indice].atr1,"JNAE")==0)		// >=
	return 3;
	
	if(strcmp(vector_tercetos[indice].atr1,"JA")==0)			// <=
	return 4;
	
	if(strcmp(vector_tercetos[indice].atr1,"JNE")==0)		// ==
	return 5;
	
	if(strcmp(vector_tercetos[indice].atr1,"JE")==0)			// !=
	return 6;
	
	if(strcmp(vector_tercetos[indice].atr1,"JMP")==0)		// salto incondicional
	return 7;
	
	return 0;
}

int get_aux_tiponumerico()
{
   return aux_tiponumerico;
}

void set_aux_tiponumerico(int value)
{
   aux_tiponumerico = value;
}