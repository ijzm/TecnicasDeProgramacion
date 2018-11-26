#include <stdio.h>
#include <stdlib.h>

#include "FuncionesCola.h"
#include "Cola.h"

int main(int argc, char const *argv[]) {
	Cola c;
	inicializarCola(&c);

	FILE *Arch = fopen("Datos.txt", "r");
	int d;
	if(Arch == NULL) {
		printf("ERROR: No se pudo abrir Datos.txt");
		exit(1);
	}

	while(1) {
		fscanf(Arch, "%d", &d);
		if(feof(Arch)) {
			break;
		}
		llegadaCola(&c, d);
	}

	while(!isEmptyCola(c)) {
		atencionCola(&c, &d);
		printf("%d\n", d);
	}

	return 0;
}