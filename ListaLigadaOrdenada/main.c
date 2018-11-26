#include <stdio.h>
#include <stdlib.h>

#include "FuncionesListaLigada.h"
#include "ListaLigada.h"

int main(int argc, char const *argv[]) {
	ListaLigada l;
	inicializarListaLigada(&l);

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
		insertarListaLigada(&l, d);
	}
	imprimirListaLigada(l);
	return 0;
}