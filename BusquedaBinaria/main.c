#include <stdio.h>
#include <stdlib.h>

#include "Ordenar.h"
#include "Funciones.h"

#define MAXDATOS 100
int main(int argc, char const *argv[]) {
	int Datos[MAXDATOS], numDatos;
	int buscar, indiceEncontrado;
	numDatos = LeerDatos(Datos);
	Ordenar(Datos, numDatos);
	
	printf("Ingrese un dato a buscar: ");
	scanf("%d", &buscar);

	indiceEncontrado = BusquedaBinaria(Datos, buscar, numDatos);

	if(indiceEncontrado == -1) {
		printf("No se pudo encontrar el dato %d \n", buscar);
	} else {
		printf("El dato %d esta en el lugar %d \n", buscar, indiceEncontrado);
	}
	return 0;
}