/*
 * Tipo.c
 *
 *  Created on: 19 oct. 2022
 *      Author: Luna, Sonia
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Tipo.h"

void mostrarTipo(eTipo unTipo)
{

    printf("  %d    %8s\n",
           unTipo.id,
           unTipo.descripcion);
}

int mostrarTipos(eTipo tipos[], int tam)
{
    int todoOk = 0;

	if(tipos != NULL && tam > 0)
	{
		printf("\n  ***   Tipos   ***\n");
		printf("----------------------\n");
		printf("   Id        Tipo\n");
		printf("----------------------\n");
		for(int i = 0; i < tam; i++)
		{
			mostrarTipo(tipos[i]);

		}
		printf("\n");
		todoOk = 1;
	}
	return todoOk;
}


int cargarTipo(eTipo tipos[], int tam, int idTipo , char elTipo[])
{
	int todoOk = 0;
	if(tipos != NULL && tam > 0 && elTipo != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			if(tipos[i].id == idTipo)
			{
				strcpy(elTipo, tipos[i].descripcion);
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}
