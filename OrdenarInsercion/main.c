#include <stdio.h>
#include <stdlib.h>

#include "Funciones.h"

#define MAX 100

int main(int argc, char const *argv[]) { 
	int arr[MAX], numDatos;

	numDatos = LeerDatos(arr);

	ImprimirArreglo(arr, numDatos);
	Ordenar(arr, numDatos);
	printf("\n");
	ImprimirArreglo(arr, numDatos);

	/*
	//Crear datos aleatorios para el archivo Datos.txt
	for (int i = 0; i < MAX; ++i) {
	printf("%.2f \n", rand() % 100);		
	}
	*/


	return 0;
}