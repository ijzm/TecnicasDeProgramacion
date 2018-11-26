#include <stdio.h>
#include <stdlib.h>

#include "Cola.h"
#include "FuncionesCola.h"

void inicializarCola(Cola *c) {
	c -> inicio = NULL;
	c -> fin = NULL;
}

void llegadaCola(Cola *c, int d) {
	Nodo *nuevo;
	nuevo = (Nodo *)malloc(sizeof(Nodo));
	nuevo -> dato = d;
	nuevo -> siguiente = NULL;
	if(isEmptyCola(*c)){
		c -> inicio = nuevo;
	} 
	else {
		c -> fin -> siguiente = nuevo;
	}
	c -> fin = nuevo;
}

int isEmptyCola(Cola c) {
	if(c.inicio == NULL) {
		return 1;
	} else {
		return 0;
	}
}

void atencionCola(Cola *c, int *d) {
	Nodo *tmp = c -> inicio;
	c -> inicio = tmp -> siguiente;

	*d = tmp -> dato;
	if(c -> inicio == NULL) {
		c -> fin = NULL;
	}
	free(tmp);
}