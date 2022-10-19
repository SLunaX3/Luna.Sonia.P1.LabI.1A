/*
 * Fecha.c
 *
 *  Created on: 19 oct. 2022
 *      Author: Luna, Sonia
 */


#include <stdio.h>

#include "Fecha.h"

int validarFecha(int dia, int mes, int anio)
{
    int todoOk = 1;

    if(dia <1 || dia > 31)
    {
    	printf("No es una fecha correcta.\n");
    	todoOk = 0;
    }
    if(mes < 1 || mes > 12)
    {
    	printf("No es una fecha correcta.\n");
    	todoOk = 0;
    }
    if(anio < 1 || anio > 2022)
    {
    	printf("No es una fecha correcta.\n");
    	todoOk = 0;
    }


    return todoOk;
}
