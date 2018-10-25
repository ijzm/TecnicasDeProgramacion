#include <stdio.h>
#include <stdlib.h>

#include "Funciones.h"

#define MAX 100

int main(int argc, char const *argv[]) { 
	int dni[MAX], region[MAX], ciudad[MAX], numDatos;
	float sueldo[MAX];

	numDatos = LeerDatos(dni, region, ciudad, sueldo);

	//ImprimirArreglo(dni, numDatos);
	Ordenar(dni, region, ciudad, sueldo, numDatos);
	//ImprimirArreglo(dni, numDatos);

	ImprimirReporte(dni, region, ciudad, sueldo, numDatos);


	/*
	//Crear datos aleatorios para el archivo Datos.txt
	for (int i = 0; i < MAX; ++i) {
	printf("%08d %3d %2d %.2f \n",
		rand() % 100000000,
		rand() % 10,
		rand() % 5,
		rand() % 1000 + ((float)(rand() % 100))/100
	);		
	}
	*/
	


	return 0;
}