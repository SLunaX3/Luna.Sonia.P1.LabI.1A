/*
 * Trabajo.h
 *
 *  Created on: 19 oct. 2022
 *      Author: Luna, Sonia
 */

#ifndef TRABAJO_H_
#define TRABAJO_H_

#include "Bicicletas.h"
#include "Marca.h"
#include "Color.h"
#include "Servicio.h"

#include "Fecha.h"




typedef struct
{
    int id;//autoincremental
    int idBicicleta; // (debe existir) Validar
    int idServicio;//(debe existir) Valida
    eFecha fecha; //Validar día, mes y anio
    int isEmpty;
}eTrabajo;

int inicializarTrabajo(eTrabajo vec[], int tam);

int buscarFreeTrabajo(eTrabajo vec[], int tam, int* pIndex);

int altaTrabajo(eTrabajo vec[],  int tam_t, eBici lista[],int tam, eServicio servicios[],eMarca marca[],int tamMarca, eColor color[],int tamColor, int tamServicio, int* pNextId, eTipo tipos[], int tamTipos);

void mostrarTrabajo(eTrabajo unTrabajo, eServicio servicios[], int tamServicio);

int listarTrabajos(eTrabajo trabajos[],int tam, eServicio servicios[],int tamServicios);



#endif /* TRABAJO_H_ */
