#include <stdio.h>
#include <stdlib.h>

#include "Funciones.h"
#include "FuncionesDeCadenas.h"

int leerDatos(char **nombres) {
	int num = 0;
	char *dato;

	FILE *Datos = leerArchivo("Datos.txt", "r");
	while(1) {
		dato = leerCadenaExacta(Datos);
		if(feof(Datos)) {
			break;
		}
		nombres[num] = dato;
		num++;
	}

	return num;
}

void liberarMemoria(char **nombres, int numDatos) {
	for (int i = 0; i < numDatos; ++i) {
		free(nombres[i]);
	}
}