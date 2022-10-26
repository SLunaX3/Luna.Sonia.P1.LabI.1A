/*
 * Servicio.c
 *
 *  Created on: 19 oct. 2022
 *      Author: Luna, Sonia
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Servicio.h"
//#include "Autos.h"
//#include "Marca.h"
//#include "Color.h"
//
//#include "Trabajo.h"
//#include "otrasFunciones.h"

void mostrarServicio(eServicio unServicio)
{

    printf("  %d    %10s      %5.2f\n",
           unServicio.id,
           unServicio.descripcion,
		   unServicio.precio);
}

int mostrarServicios(eServicio servicios[], int tamServicio)
{

    int todoOk = 0;

	if(servicios != NULL && tamServicio > 0)
	{
		printf("\n         *** Servicios ***\n");
		printf("------------------------------------\n");
		printf(" Id        Descripcion     Precio\n");
		printf("------------------------------------\n");
		for(int i = 0; i < tamServicio; i++)
		{
			mostrarServicio(servicios[i]);
		}
		printf("\n");
		todoOk = 1;
	}
	return todoOk;
}

int cargarServicio(eServicio lavados[], int tam, int idServicio , char descServicio[])
{
	int todoOk = 0;
	if(lavados != NULL && tam > 0 && descServicio != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			if(lavados[i].id == idServicio)
			{
				strcpy(descServicio, lavados[i].descripcion);
				todoOk = 1;
				break;
			}
		}
	}
	return todoOk;
}

int cargarPrecio(eServicio lavados[],int tam, int idServicio, int* precio)
{
    int todoOk = 0;

	if(lavados != NULL && tam > 0 && precio != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			if(lavados[i].id == idServicio)
			{
				*precio = lavados[i].precio;
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}
