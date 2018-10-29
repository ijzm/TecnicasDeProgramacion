#include <stdio.h>
#include <stdlib.h>

#include "Ordenar.h"

int LeerDatos(int *arr) {
	int numDatos = 0, dato;
	FILE *Dato = fopen("Datos.txt", "r");
	if(Dato == NULL) {
		printf("ERROR: No se pudo abrir Datos.txt");
	}

	while(1) {
		fscanf(Dato, "%d", &dato);
		if(feof(Dato)) {
			break;
		}
		arr[numDatos] = dato;
		numDatos++;
	}
	return numDatos;
}

//Metodo de Intercambio
void Ordenar(int *arr, int max) {
	for (int i = 0; i < max - 1; ++i) {
		for (int j = i + 1; j < max; ++j) {
			if(arr[i] > arr[j]) {
				Swap(&arr[j], &arr[i]);
			}
		}
	}
}

void Swap(int *menor, int *mayor) {
	int t = *menor;
	*menor = *mayor;
	*mayor = t;
}

void ImprimirArreglo(int *arr, int max) {
	for (int i = 0; i < max; ++i) {
		printf("%3d ", arr[i]);
	}

	printf("\n");
}