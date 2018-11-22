#ifndef FUNCIONES_PILA_H
#define FUNCIONES_PILA_H
#include "Pila.h"

void inicializarPila(Pila *);
void pushPila(Pila *, int);
int isEmptyPila(Pila);
void popPila(Pila *, int *);

#endif