/*
 * Bicicletas.c
 *
 *  Created on: 19 oct. 2022
 *      Author: Luna, Sonia
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



int inicializarBici(eBici vec[], int tam)
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

int buscarFree(eBici vec[], int tam, int* pIndex)
{

    int todoOk = 0;
    int indice = -1; // no hay lugar libre

    if( vec != NULL && tam > 0 && pIndex != NULL)
    {

        for(int i=0; i < tam; i++)
        {
            if(vec[i].isEmpty == 1) // ==1 hay estructura vacía
            {
                indice = i;
                break;
            }
        }
        *pIndex = indice; // recien aca pisa e imprime el valor

        todoOk = 1;
    }
    return todoOk;
}



int altaBici(eBici vec[], int tam, eTipo tipo[], eMarca marca[], eColor color[], int tamTipo, int tamMarca, int tamColor, int* pNextBici)
{
    int todoOk = 0;
    int indice;
    eBici nuevaBici;


    if( vec != NULL && pNextBici != NULL && tam > 0 && tipo != NULL && marca != NULL && tamTipo > 0 && tamMarca > 0 && color != NULL && tamColor > 0)
    {
        printf("\n-------------- Alta Bici ---------------\n");
        printf("----------------------------------------\n");
        buscarFree(vec, tam, &indice);

        if(indice == -1) //si no hay lugar
        {
            printf("*** No hay lugar en el sistema!!! ****\n");
        }
        else
        {
            nuevaBici.id = *pNextBici;


            mostrarTipos(tipo, tamTipo);
            printf("Ingrese Id del Tipo de bici: ");
            fflush(stdin);
            scanf("%d", &nuevaBici.idTipo);
            while(nuevaBici.idTipo<1000||nuevaBici.idTipo>1004)
            {
                printf("ERROR. Ingrese un tipo que este listado: ");
                fflush(stdin);
                scanf("%d", &nuevaBici.idTipo);
            }

            printf("\n");


            listarMarcas(marca, tamMarca);
            printf("Ingrese Id de la Marca de la bici: ");
            fflush(stdin);
            scanf("%d", &nuevaBici.idMarca);
            while(nuevaBici.idMarca<1000||nuevaBici.idMarca>1004)
            {
                printf("ERROR. Ingrese una marca que este listada: ");
                fflush(stdin);
                scanf("%d", &nuevaBici.idMarca);
            }
            printf("\n");


            mostrarColores(color, tamColor);
            printf("Ingrese Id del Color de la bici: ");
            fflush(stdin);
            scanf("%d", &nuevaBici.idColor);
            while(nuevaBici.idColor<5000||nuevaBici.idColor>5004)
            {
                printf("ERROR. Ingrese un color que este listado:");
                fflush(stdin);
                scanf("%d", &nuevaBici.idColor);
            }
            printf("\n");


            printf("Ingrese tipo de material de la bici( “c” carbono, “a” aluminio): ");
            fflush(stdin);
            scanf("%c", &nuevaBici.material);
            nuevaBici.material = tolower(nuevaBici.material);
            if(nuevaBici.material!='c' && nuevaBici.material!='a')
            {
                printf("ERROR. Ingrese tipo de material válido ('c' carbono, 'a' aluminio): ");
                fflush(stdin);
                scanf("%c", &nuevaBici.material);
            }


            nuevaBici.isEmpty = 0;

            vec[indice] = nuevaBici;

            (*pNextBici)++;

            todoOk = 1;
        }
    }
    return todoOk;
}


int mostrarBici(eBici unaBici, eMarca marcas[], eColor colores[], int tamColor,int tamMarca, eTipo tipos[], int tamTipos)
{
    int todoOk = 0;
    char elTipo[21];
    char laMarca[21];
    char elColor[21];
	char material[20];
    char aluminio[20]= "Aluminio";
    char carbono[20]= "Carbono";

    if(tipos!=NULL && marcas!=NULL && colores!=NULL && tamMarca>0 && tamColor>0 && tamTipos>0)
    {
    	cargarTipo(tipos, tamTipos, unaBici.idTipo, elTipo);
		cargarMarca(marcas, tamMarca, unaBici.idMarca, laMarca);
		cargarNombreColor(colores, tamColor, unaBici.idColor, elColor);


		if(unaBici.material =='a')
		{
			strcpy(material, aluminio);
		}
		else
		{
			strcpy(material, carbono);
		}

		printf(" %d   %10s   %6s   %8s   %12s \n",
			   unaBici.id,
			   elTipo,
			   laMarca,
			   elColor,
			   material);
    }

    return todoOk;
}


int listarBicis(eBici vec[], int tam, eMarca marca[], eColor color[], int tamMarca, int tamColores, eTipo tipos[], int tamTipos)
{
    int todoOk = 0;
    int flag = 1;
    if( vec != NULL && tam > 0)
    {
        printf("\n                  *** Listado de Bicis ***\n");
        printf("--------------------------------------------------------------\n");
        printf(" Id         Tipo       Marca     Color    Tipo de Material \n");
        printf("--------------------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty==0) // si algo rompe, ver esto
            {
                mostrarBici(vec[i], marca, color, tamColores, tamMarca, tipos, tamTipos);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("    ***No hay Bicis en el sistema*** \n");
        }
        todoOk = 1;
    }
    return todoOk;
}



int hardcodearBicis(eBici vec[], int tam, int* pNextId, int cant)
{
    int todoOk = 0;
    eBici bici[] =
    {
        {0, 1004, 1000, 5004, 'c', 0},
        {0, 1003, 1001, 5004, 'a', 0},
        {0, 1002, 1002, 5002, 'c', 0},
        {0, 1001, 1003, 5003, 'a', 0},
        {0, 1000, 1000, 5004, 'c', 0},
        {0, 1001, 1003, 5001, 'a', 0},
        {0, 1002, 1002, 5003, 'c', 0},
        {0, 1003, 1001, 5003, 'a', 0}
    };

    if( vec != NULL && pNextId != NULL && tam > 0)
    {
        for(int i=0; i < cant; i++)
        {
            vec[i] = bici[i];
            vec[i].id = *pNextId;
            (*pNextId)++;
        }
        todoOk = 1;
    }
    return todoOk;
}



int buscarBiciId(eBici vec[], int tam, int id, int* pIndex)
{
    int todoOk = 0;
    if( vec != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {

            if( vec[i].isEmpty==0  && vec[i].id == id)
            {
                *pIndex = i;
                todoOk = 1;
                break;
            }
        }

    }
    return todoOk;
}



int modificarBici(eBici vec[], int tam, eColor color[], eMarca marca[], int tamColor, int tamMarca, eTipo tipos[], int tamTipos)
{
    int modificado = 0;
    int id = -1;
    int indice;
    int auxTipo;
    char auxMaterial;


    if(vec != NULL && marca != NULL && color != NULL && tam > 0 && tamMarca > 0 && tamColor > 0 && tipos != NULL && tamTipos > 0 )
    {
        printf("\n----------------------- Modificar Bici ------------------------\n");
        printf("---------------------------------------------------------------");

        do
        {
        	listarBicis(vec, tam, marca, color, tamMarca, tamColor, tipos, tamTipos);

        	//id = -1;
			printf("\nIngrese Id de la Bici que desea modificar, o 0 para salir: ");
			fflush(stdin);
			scanf("%d", &id);


			if(id!=-1)
			{
				buscarBiciId(vec, tam, id, &indice);

				if(indice == -1)
				{
					printf("No existe una Bici con ese id: %d\n", id);
				}
				else
				{
					printf("\n");
					mostrarBici(vec[indice], marca, color, tamColor, tamMarca, tipos, tamTipos);

						switch(subMenu())
						{
						case 1:

							mostrarTipos(tipos, tamTipos);
							printf("Ingrese el Id del Nuevo Tipo: \n");
							fflush(stdin);
							scanf("%d", &auxTipo);

							while(auxTipo<1000||auxTipo>1004)
							{
								printf("ERROR. Id no válido.\n");
								printf("Ingrese el Id del Nuevo Tipo: \n");
								fflush(stdin);
								scanf("%d", &auxTipo);
							}

							vec[indice].idTipo = auxTipo;
							modificado = 1;
							break;


						case 2:

				            printf("Ingrese tipo de material de la Bici( “c” carbono, “a” aluminio): ");
				            fflush(stdin);
				            scanf("%s", &auxMaterial);
				            auxMaterial = tolower(auxMaterial);
				            while(auxMaterial!='c' && auxMaterial!='a')
				            {
				                printf("ERROR. Ingrese tipo de material válido ('c' carbono, 'a' aluminio): ");
				                fflush(stdin);
				                scanf("%c", &auxMaterial);
				            }

							vec[indice].material = auxMaterial;
							modificado = 1;
							break;



						}

				}
			}
			else
			{
				printf("En ese paso se permiten sólo números. \n");
			}
    	}while(id!=0);
    }
    return modificado;
}


int bajaBici(eBici vec[], eColor color[],eMarca marca[],int tam,int tamColor,int tamMarca, eTipo tipos[], int tamTipos)
{
    int borrado = 0;
    int indice;
    int id = -1;
    char confirma;
    if( vec != NULL && color != NULL && marca != NULL && tam > 0 && tamColor > 0 && tamMarca > 0 && tipos != NULL && tamTipos > 0 )
    {
        printf("------------------------- Baja Bici --------------------------\n");
        printf("--------------------------------------------------------------");

        do{

        	listarBicis(vec, tam, marca, color, tamMarca, tamColor, tipos, tamTipos);
			printf("\nIngrese Id de la Bici que desea dar de baja, o 0 para salir: ");
			fflush(stdin);
			scanf("%d", &id);
			printf("\n");

			if(id!=-1)
			{
				if(buscarBiciId(vec, tam, id, &indice))
				{
					if(indice == -1)
					{
						printf("No existe una Bici con el Id > %d < en el sistema\n", id);
					}
					else
					{
						mostrarBici(vec[indice], marca, color, tamColor, tamMarca, tipos, tamTipos);
						printf("Confirma baja?('s' para confirmar): ");
						fflush(stdin);
						scanf("%c", &confirma);

						if(confirma == 's' || confirma == 'S')
						{
							vec[indice].isEmpty = 2;
							printf("\n\n ***  Baja exitosa!!!  ***\n\n");
							borrado = 1;
						}
						else
						{
							printf("\nBaja cancelada por el usuario...\n");
						}

					}

				}
			}
			else
			{
				printf("En ese paso se permiten sólo números...: \n");
			}
        }while(id!=0);
    }
    return borrado;
}

