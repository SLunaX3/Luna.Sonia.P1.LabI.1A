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


/// @brief Inicializa los campos isEmpty del array de Bicis en 1
///
/// @param vec Es el array de Bicis
/// @param tam Es el tamaño del array de Bicis
/// @return Retorna el valor de una variable utilizada para la verificacion de los datos usados en la funcion
int inicializarBici(eBici vec[], int tam);

/// @brief Busca un lugar libre en el array, una estructura vacia
///
/// @param vec Es el array de Bicis
/// @param tam Es el tamaño del array de Bicis
/// @param pIndex Es el indice(en el array de Bicis) de la estructura vacia
/// @return Retorna el valor de una variable utilizada para la verificacion de los datos usados en la funcion
int buscarFree(eBici vec[], int tam, int* pIndex);

/// @brief Realiza el alta de una bicicleta cargando todos sus datos
///
/// @param vec Es el array de Bicis
/// @param tam Es el tamaño del array de Bicis
/// @param tipo Es el array de Tipos
/// @param marcaEs el array de Marcas
/// @param colorEs el array de Colores
/// @param tamTipo Es el tamaño del array de Tipos
/// @param tamMarca Es el tamaño del array de Marcas
/// @param tamColor Es el tamaño del array de Colores
/// @param pNextBici El indice(en el array de Bicis) de la estructura siguiente a esta Alta para la proxima carga
/// @return Retorna el valor de una variable utilizada para la verificacion de los datos usados en la funcion
int altaBici(eBici vec[], int tam, eTipo tipo[], eMarca marca[], eColor color[], int tamTipo, int tamMarca, int tamColor, int* pNextBici);

/// @brief Muestra los datos de una bici
///
/// @param unaBici Es el indice(en el array de Bicis) de la estructura a mostrar
/// @param marcas Es el array de Marcas
/// @param colores Es el array de Colores
/// @param tamColor Es el tamaño del array de Colores
/// @param tamMarca Es el tamaño del array de Marcas
/// @param tipos Es el array de Tipos
/// @param tamTipos Es el tamaño del array de Tipos
/// @return Retorna el valor de una variable utilizada para la verificacion de los datos usados en la funcion
int mostrarBici(eBici unaBici, eMarca marcas[], eColor colores[], int tamColor,int tamMarca, eTipo tipos[], int tamTipos);

/// @brief Lista todas las bicis con sus datos
///
/// @param vec Es el array de Bicis
/// @param tam Es el tamaño del array de Bicis
/// @param marca Es el array de Marcas
/// @param color Es el array de Colores
/// @param tamMarca Es el tamaño del array de Marcas
/// @param tamColores Es el tamaño del array de Colores
/// @param tipos Es el array de Tipos
/// @param tamTipos Es el tamaño del array de Tipos
/// @return Retorna el valor de una variable utilizada para la verificacion de los datos usados en la funcion
int listarBicis(eBici vec[], int tam, eMarca marca[], eColor color[], int tamMarca, int tamColores, eTipo tipos[], int tamTipos);

/// @brief Carga datos de bicicletas no cargadas por el usuario
///
/// @param vec Es el array de Bicis
/// @param tam Es el tamaño del array de Bicis
/// @param pNextId Es el proximo di a asignarse a la proxima carga
/// @param cant Es el valor de la cantidad de bicis a hardcodear
/// @return Retorna el valor de una variable utilizada para la verificacion de los datos usados en la funcion
int hardcodearBicis(eBici vec[], int tam, int* pNextId, int cant);

/// @brief Busca una bici por su id
///
/// @param vec Es el array de Bicis
/// @param tam Es ela tamaño del array de Bicis
/// @param id Es el id de la bici a buscar
/// @param pIndex Es el indice(en el array de Bicis) de la estructura que tiene ese id
/// @return Retorna el valor de una variable utilizada para la verificacion de los datos usados en la funcion
int buscarBiciId(eBici vec[], int tam, int id, int* pIndex);

/// @brief
///
/// @param vec
/// @param tam
/// @param color
/// @param marca
/// @param tamColor
/// @param tamMarca
/// @param tipos
/// @param tamTipos
/// @return Retorna el valor de una variable utilizada para la verificacion de los datos usados en la funcion
int modificarBici(eBici vec[], int tam, eColor color[], eMarca marca[], int tamColor, int tamMarca, eTipo tipos[], int tamTipos);

/// @brief
///
/// @param vec
/// @param color
/// @param marca
/// @param tam
/// @param tamColor
/// @param tamMarca
/// @param tipos
/// @param tamTipos
/// @return Retorna el valor de una variable utilizada para la verificacion de los datos usados en la funcion
int bajaBici(eBici vec[], eColor color[],eMarca marca[],int tam,int tamColor,int tamMarca, eTipo tipos[], int tamTipos);


#endif /* BICICLETAS_H_ */
