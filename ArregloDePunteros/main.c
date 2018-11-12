#include <stdio.h>
#include <stdlib.h>

#include "Funciones.h"

int main(int argc, char const *argv[]) {
	char *nombres[100];
	int numDatos;
	
	numDatos = leerDatos(nombres);

	for (int i = 0; i < numDatos; ++i) {
		printf("%s\n", nombres[i]);
	}

	liberarMemoria(nombres, numDatos);

	return 0;
}