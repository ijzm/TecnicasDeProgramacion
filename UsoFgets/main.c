#include <stdio.h>
#include <stdlib.h>

#include "FuncionesDeCadenas.h"

int main(int argc, char const *argv[]) {
	char cadena[200];
	char *d;
	FILE *Arch;
	Arch = leerArchivo("Datos.txt", "r");
	fclose(Arch);
	d = leerCadena(cadena, 200, stdin);

	printf("%s\n", d);

	return 0;
}