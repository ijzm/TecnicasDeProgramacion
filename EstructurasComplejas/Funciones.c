#include <stdio.h>
#include <stdlib.h>

#include "Funciones.h"

void crear(Lista *L) {

	Nodo *a, *b, *c, *p;

	a = (Nodo *)malloc(sizeof(Nodo));
	b = (Nodo *)malloc(sizeof(Nodo));
	c = (Nodo *)malloc(sizeof(Nodo));

	a -> dato = 25;
	b -> dato = 17;
	c -> dato = 14;

	a -> siguiente = b;
	b -> siguiente = c;
	c -> siguiente = NULL;

	L -> lista = a;
}

void imprimir(Lista *L) {
	Nodo *p = L -> lista;
	while(p != NULL) {
		printf("%d\n", p->dato);
		p = p-> siguiente;
	}
}