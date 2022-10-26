/*
 * Marca.c
 *
 *  Created on: 19 oct. 2022
 *      Author: Luna, Sonia
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Marca.h"

void mostrarMarca(eMarca unaMarca)
{

    printf("  %d    %7s\n",
           unaMarca.id,
           unaMarca.descripcion);
}

int listarMarcas(eMarca marcas[], int tam)
{
    int todoOk = 0;

	if(marcas != NULL && tam > 0)
	{
		printf("\n ***   Marcas   ***\n");
		printf("----------------------\n");
		printf("   Id        Marca\n");
		printf("----------------------\n");
		for(int i = 0; i < tam; i++)
		{
			mostrarMarca(marcas[i]);

		}
		printf("\n");
		todoOk = 1;
	}
	return todoOk;
}


int cargarMarca(eMarca marcas[], int tam, int idMarca , char laMarca[])
{
	int todoOk = 0;
	if(marcas != NULL && tam > 0 && laMarca != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			if(marcas[i].id == idMarca)
			{
				strcpy(laMarca, marcas[i].descripcion);
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}
