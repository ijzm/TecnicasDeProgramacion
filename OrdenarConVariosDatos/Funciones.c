#include <stdio.h>
#include <stdlib.h>

#include "Funciones.h"

int LeerDatos(int *dni, int *telefono, float *sueldo) {
	int numDatos = 0, d, t;
	float s;
	FILE *Dato = fopen("Datos.txt", "r");
	if(Dato == NULL) {
		printf("ERROR: No se pudo abrir Datos.txt");
	}

	while(1) {
		fscanf(Dato, "%d %d %f", &d, &t, &s);
		if(feof(Dato)) {
			break;
		}
		dni[numDatos] = d;
		telefono[numDatos] = t;
		sueldo[numDatos] = s;
		numDatos++;
	}
	return numDatos;
}

//Metodo de Intercambio
void Ordenar(int *dni, int *telefono, float *sueldo, int max) {
	for (int i = 0; i < max - 1; ++i) {
		for (int j = i + 1; j < max; ++j) {
			if(sueldo[i] > sueldo[j]) {
				Swap(dni,      i, j);
				Swap(telefono, i, j);
				SwapF(sueldo,   i, j);
			}
		}
	}
}

void Swap(int *arr, int i, int j) {
	int t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}

void SwapF(float *arr, int i, int j) {
	float t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}

void ImprimirArreglo(int *arr, int max) {
	for (int i = 0; i < max; ++i) {
		printf("%3d ", arr[i]);
	}

	printf("\n");
}