/*
 * Bicicletas.h
 *
 *  Created on: 19 oct. 2022
 *      Author: Luna, Sonia
 */

#ifndef BICICLETAS_H_
#define BICICLETAS_H_


#include "Marca.h"
#include "Tipo.h"
#include "Color.h"
#include "Servicio.h"

typedef struct
{
    int id;
    int idMarca;//validar
    int idTipo; //validar
    int idColor;//validar
    char material; //“c” carbono, “a” aluminio
    int isEmpty; // 1 si esta vacio, 0 si no esta disponible
} eBici;

int inicializarBici(eBici vec[], int tam);

int buscarFree(eBici vec[], int tam, int* pIndex);

int altaBici(eBici vec[], int tam, eTipo tipo[], eMarca marca[], eColor color[], eServicio lavados[], int tamTipo, int tamMarca, int tamColor, int tamServicio, int* pNextBici);

int mostrarBici(eBici unaBici, eMarca marcas[], eColor colores[], int tamColor,int tamMarca, eTipo tipos[], int tamTipos);

int listarBicis(eBici vec[], int tam, eMarca marca[], eColor color[], int tamMarca, int tamColores, eTipo tipos[], int tamTipos);

int hardcodearBicis(eBici vec[], int tam, int* pNextId);

int buscarBiciId(eBici vec[], int tam, int id, int* pIndex);

int modificarBici(eBici vec[], int tam, eColor color[], eMarca marca[], int tamColor, int tamMarca, eTipo tipos[], int tamTipos);

int bajaBici(eBici vec[], eColor color[],eMarca marca[],int tam,int tamColor,int tamMarca, eTipo tipos[], int tamTipos);



#endif /* BICICLETAS_H_ */
