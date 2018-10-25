#include <stdio.h>
#include <stdlib.h>

#include "Funciones.h"

int LeerDatos(int *dni, int *region, int *ciudad, float *sueldo) {
	int numDatos = 0, d, r, c;
	float s;
	FILE *Dato = fopen("Datos.txt", "r");
	if(Dato == NULL) {
		printf("ERROR: No se pudo abrir Datos.txt");
	}

	while(1) {
		fscanf(Dato, "%d %d %d %f", &d, &r, &c, &s);
		if(feof(Dato)) {
			break;
		}
		dni[numDatos] = d;
		region[numDatos] = r;
		ciudad[numDatos] = c;
		sueldo[numDatos] = s;
		numDatos++;
	}

	fclose(Dato);
	return numDatos;
}

//Metodo de Intercambio
void Ordenar(int *dni, int *region, int *ciudad, float *sueldo, int max) {
	for (int i = 0; i < max - 1; ++i) {
		for (int j = i + 1; j < max; ++j) {
			if(
				(ciudad[i] > ciudad[j]) ||
				(ciudad[i] == ciudad[j] && region[i] > region [j]) ||
				(ciudad[i] == ciudad[j] && region[i] == region[j] && dni[i] > dni[j])
			) {
				Swap(dni,      i, j);
				Swap(region,   i, j);
				Swap(ciudad,   i, j);
				SwapF(sueldo,  i, j);
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

void ImprimirReporte(int *dni, int *region, int *ciudad, float *sueldo, int numDatos) {
	FILE *Reporte = fopen("Reporte.txt", "w");

	fprintf(Reporte, "DNI          SUELDO   REGION CIUDAD \n");

	for (int i = 0; i < numDatos; ++i) {
		fprintf(Reporte, "%08d    %7.2f     %1d      %1d\n", dni[i], sueldo[i], region[i], ciudad[i]);
	}

	fclose(Reporte);
}