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


int mostrarBiciColorSeleccionado(eBici lista[],int tam,eMarca marcas[], eColor colores[], int tam_colores,int tam_marca, eTipo tipos[], int tam_tipo);

int mostrarBiciTipoSeleccionado(eBici lista[],int tam,eMarca marcas[], eColor colores[], int tam_colores,int tam_marca, eTipo tipos[], int tam_tipo);

int informarMaterialMayorCant(eBici vec[], int tam);

int ordenarBicisXTipo(eBici vec[], int tam, eTipo tipos[], int tam_tipos);

int informarCantXColorYTipo(eBici vec[], int tam, eColor colores[], int tam_colores,eTipo tipos[], int tam_tipos);

int informarColorMasElegido(eBici vec[], int tam, eColor colores[], int tamColor);

int mostrarTrabajosXBici(eBici vec[], eColor color[],eMarca marca[],int tam,int tamColor,int tamMarca, eTipo tipos[], int tamTipos, eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServicio);

int mostrarSumaServiciosXBici(eBici vec[], eColor color[],eMarca marca[],int tam,int tamColor,int tamMarca, eTipo tipos[], int tamTipos, eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServicio);


int buscarServicioId(eServicio vec[], int tam, int id, int* pIndex);
int mostrarBiciYFechaXServicio(eBici vec[], eColor color[],eMarca marca[],int tam,int tamColor,int tamMarca, eTipo tipos[], int tamTipos, eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServicio);

int mostrarServiciosXFecha(eTrabajo trabajos[], int tamTrabajo, eServicio servicios[], int tamServicio);

#endif /* INFORMES_H_ */
