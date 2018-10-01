#include <stdio.h>

#ifndef FUNCIONES_H
#define FUNCIONES_H value

void imprimirReporte(FILE *, FILE *, FILE *, FILE *, FILE *);
void buscarPacientes(int, int, FILE *, FILE *, FILE *, FILE *);
void buscarMayorGanancia(int *, float *, int, int, FILE *, FILE *);


void cerrarArchivos(FILE *, FILE *, FILE *, FILE *, FILE *);
void imprimirLinea(FILE *, char, int);
#endif