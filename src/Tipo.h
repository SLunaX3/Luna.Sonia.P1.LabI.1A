/*
 * Tipo.h
 *
 *  Created on: 19 oct. 2022
 *      Author: Luna, Sonia
 */

#ifndef TIPO_H_
#define TIPO_H_

typedef struct
{
    int id;//comienza en 1000
    char descripcion[20];
}eTipo;

void mostrarTipo(eTipo unTipo);

int mostrarTipos(eTipo tipos[], int tam);

int cargarTipo(eTipo tipos[], int tam, int idTipo , char elTipo[]);



#endif /* TIPO_H_ */
