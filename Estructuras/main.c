#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Funciones.h"
#include "Estructuras.h"

int main(int argc, char const *argv[]) {
	Persona personas[50];
	int numPersonas;

	numPersonas = leerDatos(personas);
	
	ordenarPorDNI(personas, numPersonas);

	imprimirDatos(personas, numPersonas);

	return 0;
}