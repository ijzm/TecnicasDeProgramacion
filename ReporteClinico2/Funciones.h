#include <stdio.h>

#ifndef FUNCIONES_H
#define FUNCIONES_H value

void imprimirReporte(FILE *, FILE *, FILE *, FILE *, FILE *);
void buscarDoctores(int, int, FILE *, FILE *, FILE *, FILE *);
float buscarGanancias(float, int, int, FILE *, FILE *);
float buscarConsultas(float, int, int, FILE *);
void cerrarArchivos(FILE *, FILE *, FILE *, FILE *, FILE *);
void imprimirLinea(FILE *, char, int);
#endif