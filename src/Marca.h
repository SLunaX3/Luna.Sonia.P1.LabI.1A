/*
 * Marca.h
 *
 *  Created on: 19 oct. 2022
 *      Author: Luna, Sonia
 */

#ifndef MARCA_H_
#define MARCA_H_

typedef struct
{
    int id; //comienza en 1000
    char descripcion[20];
} eMarca;


void mostrarMarca(eMarca unaMarca);

int listarMarcas(eMarca marcas[], int tam);

int cargarMarca(eMarca marcas[], int tam, int idMarca , char laMarca[]);

#endif /* MARCA_H_ */
