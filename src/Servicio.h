/*
 * Servicio.h
 *
 *  Created on: 19 oct. 2022
 *      Author: Luna, Sonia
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_


typedef struct
{
    int id;//comienza en 20000
    char descripcion[25];
    float precio;
}eServicio;

void mostrarServicio(eServicio unServicio);

int mostrarServicios(eServicio lavados[], int tamServicio);

int cargarServicio(eServicio lavados[], int tam, int idServicio , char descServicio[]);

int cargarPrecio(eServicio lavados[],int tam, int idServicio, int* precio);


#endif /* SERVICIO_H_ */
