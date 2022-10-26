/*
 * Informes.c
 *
 *  Created on: 26 oct. 2022
 *      Author: Luna, Sonia
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Informes.h"



int menuInformes()
{

    int opcion;

    printf("\n\n----------------INFORMES---------------\n");
    printf("---Elija la operación a realizar---\n\n");
    printf("1. Listar bicicletas por Color.\n");
    printf("2. Listar bicicletas por Tipo. \n");
    printf("3. Informar si hay más bicicletas de carbono o de aluminio y Listar la cantidad.\n");
    printf("4. Listar bicicletas separadas por Tipo.\n");
    printf("5. Informar cuantas bicicletas hay un color y un tipo en específico.\n");
    printf("6. Listar los colores más elegidos por los clientes. \n");
    printf("7. Listar todos los trabajos de una bicicleta. \n");
    printf("8. Informar la suma de los importes de los servicios de una bicicleta.\n");
    printf("9. Listar las bicicletas a las que se les realizo X servicio con la respectiva fecha del servicio.\n");
    printf("10. Listar todos los servicios realizados en X fecha.\n");
    printf("11. Salir\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


void informar( eBici vec[], int tam, eColor color[], eMarca marca[], int tamColor, int tamMarca, eTipo tipos[], int tamTipos, eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServicio)
{
	char salir = 'n';
	int opcion;
	do{

		opcion=menuInformes();
		switch (opcion) {
			case 1:
				mostrarBiciColorSeleccionado(vec, tam, marca, color, tamColor, tamMarca, tipos, tamTipos);

				break;

			case 2:
				mostrarBiciTipoSeleccionado(vec, tam, marca, color, tamColor, tamMarca, tipos, tamTipos);
				break;

			case 3:
				informarMaterialMayorCant(vec, tam);
				break;

			case 4:
				ordenarBicisXTipo(vec, tam, tipos, tamTipos);
				listarBicis(vec, tam, marca, color, tamMarca, tamColor, tipos, tamTipos);
				break;

			case 5:
				informarCantXColorYTipo(vec, tam, color, tamColor,tipos, tamTipos);
				break;

			case 6:
				informarColorMasElegido(vec, tam,color, tamColor);

				break;

			case 7:
				mostrarTrabajosXBici(vec, color, marca,tam,tamColor,tamMarca, tipos, tamTipos, trabajos, tamTrabajo, servicios, tamServicio);
				break;

			case 8:
				mostrarSumaServiciosXBici(vec, color, marca,tam,tamColor,tamMarca,tipos , tamTipos, trabajos, tamTrabajo, servicios, tamServicio);
				break;
			case 9:
				mostrarBiciYFechaXServicio(vec, color, marca,tam,tamColor,tamMarca,tipos, tamTipos, trabajos, tamTrabajo, servicios, tamServicio);
				break;

			case 10:
				mostrarServiciosXFecha(trabajos, tamTrabajo, servicios, tamServicio);
				break;

			case 11:
	            salir = 's';
	            break;
			default:
				printf("--- Ingrese alguna de las opciones:");
				break;
		}
	}while(salir!='s');
}



int mostrarBiciColorSeleccionado(eBici lista[],int tam,eMarca marcas[], eColor colores[], int tam_colores,int tam_marca, eTipo tipos[], int tam_tipo)
{
    int todoOk=0;
    int flag=1;

    if(lista != NULL && colores != NULL && marcas != NULL && tam > 0 && tam_colores > 0 && tam_marca > 0 && tipos != NULL && tam > 0 && tam_tipo > 0 )
    {
        int idColor;
        char nombreColor[20];

        mostrarColores(colores,tam_colores);
        printf("Ingrese id del color a buscar : ");
        scanf("%d", &idColor);
        while(idColor<5000 || idColor>5004)
        {
            printf("ERROR. Ingrese id válido: ");
            scanf("%d", &idColor);
        }

        cargarNombreColor(colores,tam_colores,idColor,nombreColor);

        printf("\n               *** Listado de Bicis de color %s ***      \n",nombreColor);
        printf("--------------------------------------------------------------\n");
        printf(" Id         Tipo       Marca     Color    Tipo de Material \n");
        printf("--------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0 && lista[i].idColor==idColor)
            {
                mostrarBici(lista[i], marcas, colores, tam_colores, tam_marca, tipos, tam_tipo);
                flag = 0;

            }
        }
        if(flag)
        {
            printf("No hay Bicis para mostrar de ese color.\n");

        }

        todoOk=1;
    }

    return todoOk;
}


int mostrarBiciTipoSeleccionado(eBici lista[],int tam,eMarca marcas[], eColor colores[], int tam_colores,int tam_marca, eTipo tipos[], int tam_tipo)
{
    int todoOk=0;
    int flag=1;

    if(lista != NULL && colores != NULL && marcas != NULL && tam > 0 && tam_colores > 0 && tam_marca > 0 && tipos != NULL && tam > 0 && tam_tipo > 0)
    {
        int idTipo;
        char descTipo[20];

        mostrarTipos(tipos,tam_tipo);
        printf("Ingrese el id del Tipo: ");
        fflush(stdin);
        scanf("%d", &idTipo);

        while(idTipo<1000||idTipo>1004)
        {
            printf("ERROR. Ingrese una marca que este en la lista:\n");
            fflush(stdin);
            scanf("%d", &idTipo);
        }

        cargarTipo(tipos,tam_tipo,idTipo,descTipo);

        printf("\n       *** Listado de Bicis de Tipo %s ***      \n",descTipo);
        printf("--------------------------------------------------------------\n");
        printf(" Id         Tipo       Marca     Color    Tipo de Material \n");
        printf("--------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0 && lista[i].idTipo==idTipo)
            {
            	mostrarBici(lista[i], marcas, colores, tam_colores, tam_marca, tipos, tam_tipo);
                flag = 0;

            }
        }
        if(flag)
        {
            printf("No hay Bicis para mostrar de ese Tipo.\n");

        }
        todoOk=1;
    }

    return todoOk;


}


int informarMaterialMayorCant(eBici vec[], int tam)
{
	int todoOk = 0;
	int contCarbono = 0;
	int contAluminio = 0;

    if(vec != NULL && tam > 0)
    {

        for(int i = 0; i < tam - 1; i++)
        {
			if(vec[i].isEmpty==0)
			{
        		if(vec[i].material=='c')
				{
					contCarbono++;
				}
				else
				{
					contAluminio++;
				}
			}

        }

        if(contCarbono>contAluminio)
        {
        	printf("\nHay más bicicletas de Carbono.\n");
        }
        else if(contCarbono<contAluminio)
        {
        	printf("\nHay más bicicletas de Aluminio.\n");
        }
        else
        {
        	printf("\nHay igual cantidad de Bicicletas de Carbono que de Aluminio.\n");
        }

        printf("\nCantidad de Bicis de Carbono: %d \n"
        		"Cantidad de Bicis de Aluminio: %d \n", contCarbono, contAluminio);

        todoOk = 1;
    }

	return todoOk;
}


int ordenarBicisXTipo(eBici vec[], int tam, eTipo tipos[], int tam_tipos)
{
    int todoOk = 0;
    eBici auxBici;
    char descTipoi[20];
    char descTipoj[20];

    if(vec != NULL && tam > 0 && tipos != NULL)
    {
        for(int i = 0; i < tam - 1; i++)
        {
            for(int j = i + 1; j < tam; j++)
            {
            	cargarTipo(tipos, tam_tipos, vec[i].idTipo, descTipoi);
            	cargarTipo(tipos, tam_tipos, vec[j].idTipo, descTipoj);
                if( strcmp(descTipoi, descTipoj)> 0)
                {
                    auxBici = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxBici;
                }
            }
        }

        todoOk = 1;
    }
    return todoOk;
}

//Elegir un color y un tipo y contar cuantas bicicletas hay de ese color y ese tipo.
int informarCantXColorYTipo(eBici vec[], int tam, eColor colores[], int tam_colores,eTipo tipos[], int tam_tipos)
{
	int todoOk = 0;
	int idColor;
	int idTipo;
	int contColorTipo = 0;
	char nombreColor[20];
	char elTipo[20];

	if(vec!=NULL && tam>0 && colores!= NULL && tam_colores > 0 && tipos != NULL && tam_tipos > 0)
	{
		mostrarColores(colores,tam_colores);
		printf("Ingrese id del color a buscar : ");
		scanf("%d", &idColor);
		while(idColor<5000 || idColor>5004)
		{
			printf("ERROR. Ingrese id válido: ");
			scanf("%d", &idColor);
		}


		mostrarTipos(tipos,tam_tipos);
		printf("Ingrese el id del Tipo: ");
		fflush(stdin);
		scanf("%d", &idTipo);

		while(idTipo<1000||idTipo>1004)
		{
			printf("ERROR. Ingrese una marca que este en la lista:\n");
			fflush(stdin);
			scanf("%d", &idTipo);
		}


			for(int i = 0; i < tam - 1; i++)
			{
				if(vec[i].isEmpty == 0 && vec[i].idColor==idColor && vec[i].idTipo==idTipo)
				{
					contColorTipo++;

				}
			}

			cargarNombreColor(colores, tam_colores, idColor, nombreColor);
			cargarTipo(tipos, tam_tipos, idTipo, elTipo);
			printf("\nLa cantidad de bicicletas de color %s y tipo %s son: %d \n", nombreColor, elTipo, contColorTipo);


			todoOk=1;
	}

	return todoOk;
}



int informarColorMasElegido(eBici vec[], int tam, eColor colores[], int tamColor)
{
	int todoOk = 0;
	int contColores[5]=
	{
		0, // id=5000
		0, // id=5001
		0, // id=5002
		0, // id=5003
		0  // id=5004
	};

	 int max = 0;

	 char nombreColor[20];

	if(vec!=NULL && tam>0)
	{
		for(int i = 0 ; i < tam -1 ; i++)
		{
			if(vec[i].isEmpty==0)
			{
				switch (vec[i].idColor)
				{
					case 5000:
						contColores[0]++;
						if(contColores[0]>max)
						{
							max = contColores[0];
						}
						break;
					case 5001:
						contColores[1]++;
						if(contColores[1]>max)
						{
							max = contColores[1];
						}
						break;
					case 5002:
						contColores[2]++;
						if(contColores[2]>max)
						{
							max = contColores[2];
						}
						break;
					case 5003:
						contColores[3]++;
						if(contColores[3]>max)
						{
							max = contColores[3];
						}
						break;
					case 5004:
						contColores[4]++;
						if(contColores[4]>max)
						{
							max = contColores[4];
						}
						break;

				}

			}
		}

        printf("\n***Colores más Elegidos***\n");
        printf("--------------------------\n");


		for(int i = 0; i < 5 ; i++)
		{
			if(contColores[i]==max)
			{
				cargarNombreColor(colores, tamColor, i+5000, nombreColor);
				printf("         %s   \n", nombreColor);
			}
		}
		printf("\nFue %d veces elegido.\n", max);

		todoOk = 1;
	}

	return todoOk;
}


//Pedir una bicicleta y mostrar todos los trabajos que se le hicieron a la misma.
int mostrarTrabajosXBici(eBici vec[], eColor color[],eMarca marca[],int tam,int tamColor,int tamMarca, eTipo tipos[], int tamTipos, eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServicio)
{
	int todoOk;
	int idBici = -1;
	int indice = -1;


	if(vec != NULL && marca != NULL && color != NULL && tam > 0 && tamMarca > 0 && tamColor > 0 && tipos != NULL && tamTipos > 0)
    {
		do
		{
			listarBicis(vec, tam, marca, color, tamMarca, tamColor, tipos, tamTipos);

			printf("\nIngrese Id de la Bici , o 0 para salir: ");
			fflush(stdin);
			scanf("%d", &idBici);


			if(idBici!=-1)
			{
				buscarBiciId(vec, tam, idBici, &indice);

				if(indice == -1)
				{
					printf("No existe una Bici con este id: %d\n", idBici);
				}
				else
				{
					printf("\n");
					mostrarBici(vec[indice], marca, color, tamColor, tamMarca, tipos, tamTipos);
				}

			}
			else
			{
				printf("En ese paso se permiten sólo números...: \n");
			}
		}while(indice==-1);// condicion para que repita si el id es erroneo

// Según la id selecciona, mostrar los trabajos relacionados a esa id

        printf("\n     *** Trabajos para la Bici %d ***      \n", idBici);
        printf("----------------------------------------------\n");
        printf(" IdTrabajo   idBici    Servicio   Fecha\n");
        printf("----------------------------------------------\n");
		for(int i=0; i<tamTrabajo; i++)
		{
			if(trabajos[i].isEmpty==0 && trabajos[i].idBicicleta == idBici)
			{
				mostrarTrabajo(trabajos[i], servicios, tamServicio);

			}
		}

		todoOk = 1;
	}
	return todoOk;
}


//Pedir una bicicleta e
//informar la suma de los importes de los servicios que se le hicieron a la
//misma.
int mostrarSumaServiciosXBici(eBici vec[], eColor color[],eMarca marca[],int tam,int tamColor,int tamMarca, eTipo tipos[], int tamTipos, eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServicio)
{
	int todoOk;
	int idBici = -1;
	int indice = -1;
	float importeTotal = 0;

	if(vec != NULL && marca != NULL && color != NULL && tam > 0 && tamMarca > 0 && tamColor > 0 && tipos != NULL && tamTipos > 0 )
    {
		do
		{
			listarBicis(vec, tam, marca, color, tamMarca, tamColor, tipos, tamTipos);

			printf("\nIngrese Id de la Bici , o 0 para salir: ");
			fflush(stdin);
			scanf("%d", &idBici);


			if(idBici!=-1)
			{
				buscarBiciId(vec, tam, idBici, &indice);

				if(indice == -1)
				{
					printf("No existe una Bici con este id: %d\n", idBici);
				}
				else
				{
					printf("\n");
					mostrarBici(vec[indice], marca, color, tamColor, tamMarca, tipos, tamTipos);
				}

			}
			else
			{
				printf("En ese paso se permiten sólo números...: \n");
			}
		}while(indice==-1);



		for(int i=0; i<tamTrabajo; i++)
		{
			if(trabajos[i].isEmpty==0 && trabajos[i].idBicicleta == idBici)
			{
                for(int j = 0; j < tamServicio; j++)
                {
                    if(servicios[j].id == trabajos[i].idServicio)
                    {
                        importeTotal += servicios[j].precio;
                    }
                }
			}
		}


        printf("----------------------------------------------\n");
        printf("Importe Total de Trabajos para la Bici %d : $ %.2f\n", idBici, importeTotal);
        printf("----------------------------------------------\n\n");

		todoOk = 1;
	}
	return todoOk;
}



// Pedir un servicio y mostrar las bicicletas a las que se les realizo ese servicio y la fecha.
int buscarServicioId(eServicio vec[], int tam, int id, int* pIndex)
{
    int todoOk = 0;
    if( vec != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {

            if(vec[i].id == id)
            {
                *pIndex = i;
                todoOk = 1;
                break;
            }
        }

    }
    return todoOk;
}


int mostrarBiciYFechaXServicio(eBici vec[], eColor color[],eMarca marca[],int tam,int tamColor,int tamMarca, eTipo tipos[], int tamTipos, eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServicio)
{
	int todoOk;
	int idServicio = -1;
	int indice = -1;
	char descServicio[25];
	int pIndex;

	if(vec != NULL && marca != NULL && color != NULL && tam > 0 && tamMarca > 0 && tamColor > 0 && tipos != NULL && tamTipos > 0 )
    {
		do
		{
			mostrarServicios(servicios, tamServicio);
			//listarTrabajos(trabajos, tamTrabajo, servicios, tamServicio);
			printf("\nIngrese Id del Trabajo , o 0 para salir: ");
			fflush(stdin);
			scanf("%d", &idServicio);


			if(idServicio!=-1)
			{
				buscarServicioId(servicios, tamServicio, idServicio, &indice);

				if(indice == -1)
				{
					printf("No existe un Trabajo con este id: %d\n", idServicio);
				}
				else
				{
					printf("\n");
					mostrarServicio(servicios[indice]);
					//mostrarTrabajo(trabajos[indice], servicios, tamServicio);
				}

			}
			else
			{
				printf("En ese paso se permiten sólo números...: \n");
			}
		}while(indice==-1);

//mostrar las bicicletas a las que se les realizo ese servicio y la fecha.

		cargarServicio(servicios, tamServicio, idServicio, descServicio);
        printf("\n                *** Bicis para el Servicio %s ***      \n", descServicio);
        printf("---------------------------------------------------------------\n");
        printf(" Id         Tipo       Marca     Color    Tipo de Material  \n");
        printf("---------------------------------------------------------------\n");
		for(int i=0; i<tamTrabajo; i++)
		{
			if(trabajos[i].idServicio == idServicio)
			{
				buscarBiciId(vec, tam, trabajos[i].idBicicleta, &pIndex);
				mostrarBici(vec[pIndex], marca, color, tamColor, tamMarca, tipos, tamTipos);

				printf("---> Fecha del Trabajo: %02d/%02d/%4d \n\n", trabajos[i].fecha.dia, trabajos[i].fecha.mes, trabajos[i].fecha.anio);

			}
		}

		todoOk = 1;
	}
	return todoOk;
}


// Pedir una fecha y mostrar todos los servicios realizados en la misma.
int mostrarServiciosXFecha(eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServicio)
{
	int todoOk;
	eFecha fechaIngresada ={-1,-1,-1};
	int fechaOk = -1;
	char descServicio[25];

	if(trabajos != NULL && tamTrabajo>0 && servicios != NULL && tamServicio>0)
    {
		do
		{
			printf("\nIngrese Fecha (dd/mm/aaaa), o Ingrese 's' para salir: ");
			fflush(stdin);
			scanf("%d/%d/%d", &fechaIngresada.dia, &fechaIngresada.mes, &fechaIngresada.anio );

			if(fechaIngresada.dia!=-1 && fechaIngresada.mes!=-1 && fechaIngresada.anio!=-1)
			{
				fechaOk = validarFecha(fechaIngresada.dia, fechaIngresada.mes, fechaIngresada.anio);
			}
			else
			{
				printf("\nVolviendo al menú anterior...\n");
				break;
			}

		}while(fechaOk==0);



		if(fechaOk==1)
		{

			printf("\n*** Servicios realizados en la fecha %02d/%02d/%4d *** \n", fechaIngresada.dia, fechaIngresada.mes, fechaIngresada.anio);
			printf("--------------------------------------------------------\n");
			for(int i=0; i<tamTrabajo; i++)
			{
				if(trabajos[i].fecha.dia==fechaIngresada.dia && trabajos[i].fecha.mes==fechaIngresada.mes && trabajos[i].fecha.anio==fechaIngresada.anio)
				{
					cargarServicio(servicios, tamServicio, trabajos[i].idServicio, descServicio);
					printf("         %s \n", descServicio);
				}
			}
		}
		todoOk = 1;
	}
	return todoOk;
}
