#ifndef COLA_H
#define COLA_H

typedef struct Nodo {
	int dato;
	struct Nodo *siguiente;
} Nodo;

typedef struct Cola {
	Nodo *inicio;
	Nodo *fin;
} Cola;

#endif