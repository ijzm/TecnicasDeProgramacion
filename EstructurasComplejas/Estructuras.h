#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H value

typedef struct Fecha {
	int dd;
	int mm;
	int aa;	
} Fecha;

typedef struct Alumno{
	int codigo;
	char nombre[50];
	Fecha fechaNac;
	int notas[10];
} Alumno;

//Estructuras Auto Referenciadas
//Linked List?

typedef struct Nodo {
	int dato;
	struct Nodo *siguiente;
} Nodo;

typedef struct Lista {
	Nodo *lista;	
} Lista;

#endif