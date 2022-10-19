/*
 * Color.c
 *
 *  Created on: 19 oct. 2022
 *      Author: Luna, Sonia
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Color.h"

void mostrarColor(eColor unColor)
{

    printf("  %d    %6s \n",
           unColor.id,
           unColor.nombreColor);
}


int mostrarColores(eColor colores[], int tam)
{
    int todoOk = 0;

	if(colores != NULL && tam > 0)
	{
		printf(" ***   Colores   ***\n");
		printf("----------------------\n");
		printf("    Id      Color\n");
		printf("----------------------\n");
		for(int i = 0; i < tam; i++)
		{
			mostrarColor(colores[i]);
		}
		todoOk = 1;
		printf("\n");
	}
	return todoOk;
}


int cargarColor(eColor colores[], int tam, int idColor , char nombreColor[])
{
	int todoOk = 0;
	if(colores != NULL && tam > 0 && nombreColor != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			if(colores[i].id == idColor)
			{
				strcpy(nombreColor, colores[i].nombreColor);
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}

