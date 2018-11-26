#include <stdio.h>
#include <stdlib.h>

#include "FuncionesListaLigada.h"

void inicializarListaLigada(ListaLigada *l) {
	l -> inicio = NULL;
}

void insertarListaLigada(ListaLigada *l, int d) {
	Nodo *p, *anterior, *nuevo;
	p = l -> inicio;
	anterior = NULL;
	nuevo = (Nodo *)malloc(sizeof(Nodo));
	nuevo -> dato = d;

	while(p != NULL) {
		if(p -> dato > d) {
			break;
		}
		anterior = p;
		p = p -> siguiente;
	}
	nuevo -> siguiente = p;
	if(anterior == NULL) {
		l -> inicio = nuevo;
	} else {
		anterior -> siguiente = nuevo;
	}

}

void imprimirListaLigada(ListaLigada l) {
	Nodo *tmp;
	tmp = l.inicio;
	while(tmp != NULL) {
		printf("%d\n", tmp -> dato);
		tmp = tmp -> siguiente;
	}
}