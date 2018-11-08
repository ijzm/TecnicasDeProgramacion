#include <stdio.h>
#include <stdlib.h>

#include "Funciones.h"
#include "FuncionesDeCadenas.h"

int main(int argc, char const *argv[]) {
	char *cadena;
	cadena = leerCadenaExacta(stdin);
	printf("%s\n", cadena);
	free(cadena);

	return 0;
}