/*
 * Color.h
 *
 *  Created on: 19 oct. 2022
 *      Author: Luna, Sonia
 */

#ifndef COLOR_H_
#define COLOR_H_



typedef struct
{
    int id;//comienza en 5000
    char nombreColor[20];
}eColor;

void mostrarColor(eColor unColor);

int mostrarColores(eColor colores[], int tam);


/// @brief
/// Recorre el array de colores, si el id del color coincide con algún id dentro del array
/// copia la descrpcion en la variable "nombreColor"
///
/// @param colores Es el array a recorrer
/// @param tam Es el tamaño a recorrer
/// @param idColor Es el valor a buscar dentro del campo idColor del array
/// @param nombreColor Es la variable donde se va a copiar la descripcion traida del array
/// @return
int cargarNombreColor(eColor colores[], int tam, int idColor , char nombreColor[]);

#endif /* COLOR_H_ */
