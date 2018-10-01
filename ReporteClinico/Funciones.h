#include <stdio.h>

#ifndef FUNCIONES_H
#define FUNCIONES_H value

void imprimirReporte(FILE *, FILE *, FILE *, FILE *, FILE *);
void determinarGastosPorEspecialidad(FILE *, FILE *, FILE *, FILE *, FILE *);
void imprimirGastosPaciente(int, FILE *, FILE *, FILE *, FILE *, FILE *);
float determinarGastosParaEspecialidad(int, int, FILE *, FILE *);
int buscarDniDoctor(FILE *, int);
float buscarPrecio(int, int, FILE *Medicos);

void cerrarArchivos(FILE *, FILE *, FILE *, FILE *, FILE *);
void imprimirLinea(FILE *, char, int);
#endif