/*
 * Fecha.h
 *
 *  Created on: 19 oct. 2022
 *      Author: Luna, Sonia
 */

#ifndef FECHA_H_
#define FECHA_H_


typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;


int validarFecha(int dia, int mes, int anio);

#endif /* FECHA_H_ */
