#include <stdio.h>
#include <stdlib.h>

#include "Funciones.h"

#define MAX 100

int main(int argc, char const *argv[]) { 
	int dni[MAX], telefono[MAX], numDatos;
	float sueldo[MAX];

	numDatos = LeerDatos(dni, telefono, sueldo);

	ImprimirArreglo(dni, numDatos);
	Ordenar(dni, telefono, sueldo, numDatos);
	printf("\n");
	ImprimirArreglo(dni, numDatos);

	/*
	//Crear datos aleatorios para el archivo Datos.txt
	for (int i = 0; i < MAX; ++i) {
	printf("%08d %07d %.2f \n", rand() % 100000000, rand() %1000000, rand() % 1000 + ((float)(rand() % 100))/100);		
	}
	*/


	return 0;
}