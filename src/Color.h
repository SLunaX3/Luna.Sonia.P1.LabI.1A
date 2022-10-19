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

int cargarColor(eColor colores[], int tam, int idColor , char nombreColor[]);

#endif /* COLOR_H_ */
