/*
 ============================================================================
 Name        : 1erParcial_Laboratorio.c
 Author      : Luna, Sonia
 Version     : Primera Parte

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Bicicletas.h"
#include "Menu.h"
#include "Marca.h"
#include "Tipo.h"
#include "Color.h"
#include "Servicio.h"
#include "Trabajo.h"
#include "Fecha.h"


#define TAM_B 10
#define TAM_TIPO 4
#define TAM_M 5
#define TAM_C 5
#define TAM_S 4
#define TAM_T 10

int main() {

	setbuf(stdout, NULL);
    char salir = 'n';

    int proxBici = 1000;
    int proxTrabajo = 3000;

    eBici lista[TAM_B];


    eTipo tipo[TAM_TIPO]=
    {
        {1000, "Rutera"},
        {1001, "Carrera"},
        {1002, "Mountain"},
        {1003, "BMX"}
    };


    eMarca marca[TAM_M]=
    {
        {1000, "AAA"},
        {1001, "BBB"},
        {1002, "CCC"},
        {1003, "DDD"},
        {1004, "EEE"}
    };


    eColor color[TAM_C]=
    {
        {5000, "Gris"},
        {5001, "Blanco"},
        {5002, "Azul"},
        {5003, "Negro"},
        {5004, "Rojo"}
    };

    eServicio lavados[TAM_S]=
    {
        {20000, "Limpieza", 30},
        {20001, "Parche", 400},
        {20002, "Centrado", 500},
        {20003, "Cadena", 450}
    };

    eTrabajo trabajos[TAM_T]={
        {3000,1001,20001,{01,02,2022},0},
        {3001,1001,20000,{02,02,2022},0},
        {3002,1002,20002,{03,02,2022},0},
        {3003,1003,20002,{04,02,2022},0},
        {3004,1003,20001,{05,02,2022},0},
        {3005,1002,20001,{06,02,2022},0},
        {3006,1000,20001,{10,02,2022},0}

    };


    inicializarBici(lista,TAM_B);

    hardcodearBicis(lista, TAM_B, &proxBici);

    inicializarTrabajo(trabajos, TAM_T);

    do
    {
        switch(menu())
        {
        case 1:
             if(altaBici(lista, TAM_B, tipo, marca, color, lavados, TAM_TIPO, TAM_M, TAM_C, TAM_S, &proxBici))
            {
                printf("Bici cargada con exito!!!\n");
            }
            else
            {
                printf("No se pudo cargar la Bici\n");
            }
            break;
        case 2:
            if(modificarBici(lista, TAM_B, color, marca, TAM_C, TAM_M, tipo, TAM_TIPO))
           {
               printf("Bici modifida con exito!!!\n");
           }
           else
           {
               printf("No se realizó la modificación...\n");

           }
            break;

        case 3:
            if(bajaBici(lista, color, marca, TAM_B, TAM_C, TAM_M, tipo, TAM_TIPO))
            {
                printf("Bici borrada con exito!!!\n");
            }
            else
            {
                printf("No se realizó la baja de Bici...\n");
            }

            break;

        case 4:
        	listarBicis(lista, TAM_B, marca, color, TAM_M, TAM_C, tipo, TAM_TIPO);
            break;

        case 5:
        	mostrarTipos(tipo, TAM_TIPO);
            break;

        case 6:
        	mostrarColores(color, TAM_C);
            break;

        case 7:
        	mostrarServicios(lavados, TAM_S);
            break;

        case 8:

        	if(altaTrabajo(trabajos, TAM_T, lista, TAM_B, lavados, marca, TAM_M, color, TAM_C, TAM_S, &proxTrabajo, tipo, TAM_TIPO))
            {
                printf("Trabajo cargado con exito!!!\n");
            }
            else
            {
                printf("No se pudo cargar el Trabajo\n");
            }

            break;
        case 9:
        	listarTrabajos(trabajos, TAM_T, lavados, TAM_S);
            break;

        case 10:
            salir = 's';
            break;
		default:
			printf("--- Ingrese alguna de las opciones:");
        }


    }
    while(salir != 's');


	return EXIT_SUCCESS;
}
