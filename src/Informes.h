/*
 * Informes.h
 *
 *  Created on: 26 oct. 2022
 *      Author: Luna, Sonia
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "Bicicletas.h"
#include "Color.h"
#include "Marca.h"
#include "Tipo.h"
#include "Fecha.h"
#include "Trabajo.h"

int menuInformes();

void informar( eBici vec[], int tam, eColor color[], eMarca marca[], int tamColor, int tamMarca, eTipo tipos[], int tamTipos, eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServicio);

/// @brief Pide al usuario elegir un color(se le muestra el listo de colores) y muestra todos las bicicletas de ese color
///
/// @param lista Es el array de Bicis
/// @param tam
/// @param marcas
/// @param colores
/// @param tam_colores
/// @param tam_marca
/// @param tipos
/// @param tam_tipo
/// @return Retorna el valor de una variable utilizada para la verificacion de los datos usados en la funcion
int mostrarBiciColorSeleccionado(eBici lista[],int tam,eMarca marcas[], eColor colores[], int tam_colores,int tam_marca, eTipo tipos[], int tam_tipo);

/// @brief Pide al usuario elegir un tipo(se le muestra el listo de tipos) y muestra todos las bicicletas de ese tipo
///
/// @param lista
/// @param tam
/// @param marcas
/// @param colores
/// @param tam_colores
/// @param tam_marca
/// @param tipos
/// @param tam_tipo
/// @return Retorna el valor de una variable utilizada para la verificacion de los datos usados en la funcion
int mostrarBiciTipoSeleccionado(eBici lista[],int tam,eMarca marcas[], eColor colores[], int tam_colores,int tam_marca, eTipo tipos[], int tam_tipo);

/// @brief Informa si hay más bicicletas de carbono o de aluminio y muestrar la cantidad de bicis de cada material.
///
/// @param vec Es el array de Bicis
/// @param tam Es el tamaño del array de Bicis
/// @return Retorna el valor de una variable utilizada para la verificacion de los datos usados en la funcion
int informarMaterialMayorCant(eBici vec[], int tam);

/// @brief Muestrar un listado de las bicicletas separadas por tipo.
///
/// @param vec
/// @param tam
/// @param tipos
/// @param tam_tipos
/// @return Retorna el valor de una variable utilizada para la verificacion de los datos usados en la funcion
int ordenarBicisXTipo(eBici vec[], int tam, eTipo tipos[], int tam_tipos);

/// @brief Informa cuantas bicicletas hay un color y un tipo en específico.
///
/// @param vec
/// @param tam
/// @param colores
/// @param tam_colores
/// @param tipos
/// @param tam_tipos
/// @return Retorna el valor de una variable utilizada para la verificacion de los datos usados en la funcion
int informarCantXColorYTipo(eBici vec[], int tam, eColor colores[], int tam_colores,eTipo tipos[], int tam_tipos);

/// @brief Lista los colores más elegidos por los clientes.
///
/// @param vec
/// @param tam
/// @param colores
/// @param tamColor
/// @return Retorna el valor de una variable utilizada para la verificacion de los datos usados en la funcion
int informarColorMasElegido(eBici vec[], int tam, eColor colores[], int tamColor);

/// @brief Lista todos los trabajos de una bicicleta.
///
/// @param vec
/// @param color
/// @param marca
/// @param tam
/// @param tamColor
/// @param tamMarca
/// @param tipos
/// @param tamTipos
/// @param trabajos
/// @param tamTrabajo
/// @param servicios
/// @param tamServicio
/// @return Retorna el valor de una variable utilizada para la verificacion de los datos usados en la funcion
int mostrarTrabajosXBici(eBici vec[], eColor color[],eMarca marca[],int tam,int tamColor,int tamMarca, eTipo tipos[], int tamTipos, eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServicio);

/// @brief Informa la suma de los importes de los servicios de una bicicleta.
///
/// @param vec
/// @param color
/// @param marca
/// @param tam
/// @param tamColor
/// @param tamMarca
/// @param tipos
/// @param tamTipos
/// @param trabajos
/// @param tamTrabajo
/// @param servicios
/// @param tamServicio
/// @return Retorna el valor de una variable utilizada para la verificacion de los datos usados en la funcion
int mostrarSumaServiciosXBici(eBici vec[], eColor color[],eMarca marca[],int tam,int tamColor,int tamMarca, eTipo tipos[], int tamTipos, eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServicio);

/// @brief
///
/// @param vec
/// @param tam
/// @param id
/// @param pIndex
/// @return Retorna el valor de una variable utilizada para la verificacion de los datos usados en la funcion
int buscarServicioId(eServicio vec[], int tam, int id, int* pIndex);

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
/// @param trabajos
/// @param tamTrabajo
/// @param servicios
/// @param tamServicio
/// @return Retorna el valor de una variable utilizada para la verificacion de los datos usados en la funcion
int mostrarBiciYFechaXServicio(eBici vec[], eColor color[],eMarca marca[],int tam,int tamColor,int tamMarca, eTipo tipos[], int tamTipos, eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServicio);

int mostrarServiciosXFecha(eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServicio);

#endif /* INFORMES_H_ */
