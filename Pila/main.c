#include <stdio.h>
#include <stdlib.h>

#include "FuncionesPila.h"
#include "Pila.h"

int main(int argc, char const *argv[]) {
	Pila p;
	inicializarPila(&p);

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
		pushPila(&p, d);
	}

	while(!isEmptyPila(p)) {
		popPila(&p, &d);
		printf("%d\n", d);
	}

	return 0;
}