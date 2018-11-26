#ifndef LISTA_LIGADA_H
#define LISTA_LIGADA_H

typedef struct Nodo {
	int dato;
	struct Nodo *siguiente;
} Nodo;

typedef struct ListaLigada {
	Nodo *inicio;	
} ListaLigada;

#endif