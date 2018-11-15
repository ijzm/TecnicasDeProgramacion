/* 
 * File:   Funciones.h
 * Author: Ignacio Javier Zevallos Morales
 * Codigo: 20171160
 *
 * Created on 13 de noviembre de 2018, 08:02 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

int leerBonos(float *);
int leerEmpleados(int *);

void determinarBonos(float *, int , int *, int);

void arrPop(int *, int, int);

FILE *AbrirArchivo(const char *, const char *);


#endif /* FUNCIONES_H */

