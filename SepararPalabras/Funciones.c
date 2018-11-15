#include <stdio.h>
#include <stdlib.h>

#include "Funciones.h"
#include "FuncionesDeCadenas.h"

int leerDatos(int *codigo, char **nombre, float *sueldo) {
	int num = 0;
	char cadenaDatos[200], *datos[20];
	FILE *Arch = leerArchivo("Datos.csv", "r");

	while(1) {
		leerCadena(cadenaDatos, 200, Arch);

		if(feof(Arch)) {
			break;
		}

		sacaPalabrasCSV(cadenaDatos, datos);
		codigo[num] = atoi(datos[0]);
		nombre[num] = datos[1];
		sueldo[num] = atof(datos[2]);
		num++;
		free(datos[0]);
		free(datos[2]);
	}

	fclose(Arch);
	return num;
}

void imprimirDatos(int *codigo, char **nombre, float *sueldo, int numDatos) {
	for (int i = 0; i < numDatos; ++i) {
		printf("%3d: %8d %-30s %10.2f\n", i, codigo[i], nombre[i], sueldo[i]);
	}
}
