/*
 * Menu.c
 *
 *  Created on: 19 oct. 2022
 *      Author: Luna, Sonia
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "Menu.h"

int menu()
{

    int opcion;

    printf("\n\n----------------ABM---------------\n");
    printf("---Elija la operación a realizar---\n\n");
    printf("1. Alta Bicicleta\n");
    printf("2. Modificar Bicicleta \n");
    printf("3. Baja Bicicleta\n");
    printf("4. Listar Bicicletas\n");
    printf("5. Listar Tipos\n");
    printf("6. Listar Colores \n");
    printf("7. Listar Servicios \n");
    printf("8. Alta Trabajo\n");
    printf("9. Listar Trabajos\n");
    printf("10. INFORMES\n");
    printf("11. Salir\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}




int subMenu()
{

    int opcion = -1;

	do{
		printf("\n-----Elija la modificacion a realizar-----\n\n");
		printf("   1. Tipo\n");
		printf("   2. Material \n");
		printf("   3. Salir de la modificación.\n\n");

		printf("Ingrese opcion: ");
		fflush(stdin);
		scanf("%d", &opcion);


	}while(opcion<1 || opcion>3);

    return opcion;
}



