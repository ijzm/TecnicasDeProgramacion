#include <stdio.h>
#include <stdlib.h>

#include "Pila.h"
#include "FuncionesPila.h"

void inicializarPila(Pila *p) {
	p -> pila = NULL;
}

void pushPila(Pila *p, int d) {
	Nodo *nuevo;
	nuevo = (Nodo *)malloc(sizeof(Nodo));
	nuevo -> dato = d;

	nuevo -> siguiente = p -> pila;
	p -> pila = nuevo;
}

int isEmptyPila(Pila p) {
	if(p.pila == NULL) {
		return 1;
	} else {
		return 0;
	}
}

void popPila(Pila *p, int *d) {
	Nodo *tmp = p -> pila;
	p -> pila = tmp -> siguiente;

	*d = tmp -> dato;
	free(tmp);
}