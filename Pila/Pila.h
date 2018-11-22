#ifndef PILA_H
#define PILA_H

typedef struct Nodo {
	int dato;
	struct Nodo *siguiente;
} Nodo;

typedef struct Pila {
	Nodo *pila;
} Pila;

#endif