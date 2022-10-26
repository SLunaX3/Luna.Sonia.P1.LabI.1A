/*
 * Trabajo.c
 *
 *  Created on: 19 oct. 2022
 *      Author: Luna, Sonia
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Trabajo.h"
#include "Bicicletas.h"

int inicializarTrabajo(eTrabajo vec[], int tam)
{
    int todoOk = 0;
    if( vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarFreeTrabajo(eTrabajo vec[], int tam, int* pIndex)
{

    int todoOk = 0;
    int indice = -1;

    if( vec != NULL && tam > 0 && pIndex != NULL)
    {
        for(int i=0; i < tam; i++)
        {
            if(vec[i].isEmpty == 1)
            {
                indice = i;
                break;
            }
        }
        *pIndex = indice;

        todoOk = 1;
    }
    return todoOk;
}


int altaTrabajo(eTrabajo vec[],  int tam_t, eBici lista[],int tam, eServicio servicios[],eMarca marca[],int tamMarca, eColor color[],int tamColor, int tamServicio, int* pNextId, eTipo tipos[], int tamTipos)
{
    int todoOk = 0;
    int indice;
    int indiceBici;
    eTrabajo nuevoT;
    eFecha fecha;
    int idBici;

    if( vec != NULL && pNextId != NULL && tam > 0 && marca != NULL && tamMarca > 0 && color != NULL && tamColor > 0 && servicios != NULL && tamServicio > 0 && tipos != NULL && tamTipos > 0)
    {
        printf("---------------------- Alta Trabajo ---------------------------\n");
        printf("---------------------------------------------------------------");
        buscarFreeTrabajo(vec, tam_t, &indice);

        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            nuevoT.id = *pNextId;
            (*pNextId)++;

            listarBicis(lista, tam, marca, color, tamMarca, tamColor, tipos, tamTipos);
            printf("\nIngrese Id de la Bici: ");
            fflush(stdin);
            scanf("%d", &idBici);
            while(!buscarBiciId(lista,tam,idBici, &indiceBici))
             {
                 printf("ERROR. Ingrese una Bici que este en la lista: \n");
                 fflush(stdin);
                 scanf("%d", &idBici);
             }
            nuevoT.idBicicleta = idBici;

             mostrarServicios(servicios,tamServicio);
             printf("Ingrese el Id del servicio: ");
             fflush(stdin);
             scanf("%d", &nuevoT.idServicio);

             while(nuevoT.idServicio<20000||nuevoT.idServicio>20003)
             {
                 printf("ERROR. Ingrese Id válido del servicio que desea: \n");
                 fflush(stdin);
                 scanf("%d", &nuevoT.idServicio);
             }

             printf("Ingrese la fecha (dd/mm/aaaa): \n");
             fflush(stdin);
             scanf("%d/%d/%d",
            		 &fecha.dia,
            		 &fecha.mes,
					 &fecha.anio);
             while(!validarFecha(fecha.dia,fecha.mes,fecha.anio))
             {
                 printf("ERROR. Ingrese una fecha válida (dd/mm/aaaa): \n");
                 fflush(stdin);
                 scanf("%d/%d/%d", &fecha.dia,&fecha.mes,&fecha.anio);
             }

            nuevoT.fecha = fecha;

             nuevoT.isEmpty = 0;

            vec[indice] = nuevoT;



            todoOk = 1;
        }
    }
    return todoOk;
}


void mostrarTrabajo(eTrabajo unTrabajo, eServicio servicios[], int tamServicio)
{
    char descServicio[26];

    cargarServicio(servicios, tamServicio, unTrabajo.idServicio, descServicio);

    printf("  %d       %d       %6s   %02d/%02d/%4d    \n",
           unTrabajo.id,
           unTrabajo.idBicicleta,
            descServicio,
           unTrabajo.fecha.dia,
           unTrabajo.fecha.mes,
           unTrabajo.fecha.anio);
}

int listarTrabajos(eTrabajo trabajos[],int tam, eServicio servicios[],int tamServicios)
{
    int todoOk = 0;
    int flag = 1;

    if(trabajos != NULL && tam > 0)
    {
        printf("\n        *** Listado de Trabajos ***      \n");
        printf("----------------------------------------------\n");
        printf("IdTrabajo   idBici    Servicio   Fecha\n");
        printf("----------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if(trabajos[i].isEmpty == 0)
            {
                mostrarTrabajo(trabajos[i],servicios,tamServicios);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("No hay Trabajos para mostrar\n");

        }
        todoOk = 1;
    }
    return todoOk;
}


