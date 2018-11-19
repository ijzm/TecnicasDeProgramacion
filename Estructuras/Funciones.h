#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "Estructuras.h"

void asignarDatos(Persona *, int, char *, float);
int leerDatos(Persona *);
void leerPersona(FILE *, Persona *);

void ordenarPorDNI(Persona *, int);

void imprimirDatos(Persona *, int);



void swapPersona(Persona *, int, int);

#endif