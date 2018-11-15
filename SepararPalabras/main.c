#include <stdio.h>
#include <stdlib.h>

#include "Funciones.h"
#include "FuncionesDeCadenas.h"

int main(int argc, char const *argv[]) {
/*
	char frase[500];
	char *palabras[30];
	int numPal;


	leerCadena(frase, 500, stdin);
	numPal = sacaPalabras(frase, palabras);
	for (int i = 0; i < numPal; ++i) {
		printf("%s\n", palabras[i]);
	}
	liberarEspacios(palabras, numPal);
*/

	int codigo[100], numDatos;
	float sueldo[100];
	char *nombre[100];

	numDatos = leerDatos(codigo, nombre, sueldo);
	imprimirDatos(codigo, nombre, sueldo, numDatos);

	return 0;
	
}