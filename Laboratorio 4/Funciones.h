/* 
 * File:   Funciones.h
 * Author: Ignacio Javier Zevallos Morales
 * Codigo: 20171160
 * Created on 30 de octubre de 2018, 08:02 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

int leerArticulos(int *, int *, float *, float *, int *);
void ordenarArticulos(int, int *, int *, float *, float *, int *);
void reescribirArticulos(int, int *, int *, float *, float *, int *);

int leerCompras(double *, int *, float *, int *, float *, float *, int *);
int conseguirCosto(int , FILE *, float *, int *, float *, float *, int *);
int buscarCosto(int, int *);
double convertirFecha(int, int, int, int, int, int);

void ordenarCompras(int, double *, int *, float *);
void imprimirTotales(int, double *, int *, float *);

void imprimirResumen(int, float *);

void swapI(int *, int, int);
void swapF(float *, int, int);
void swapD(double *, int, int);


#endif /* FUNCIONES_H */

