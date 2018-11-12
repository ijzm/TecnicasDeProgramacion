#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Funciones.h"

#define NUM_TIPOS 50

int main(int argc, char const *argv[]) {
	srand(time(NULL));
	char *s;
	int numeroDatos, numTipos = 0;
	struct dato Datos[NUM_TIPOS];

	printf("%d", rand() % 2);

	FILE *Salida = fopen("Datos.txt", "w");
	if(Salida == NULL) {
		printf("ERROR: No se pudo abrir Datos.txt\n");
	}

	printf("Escribe el numero de datos: ");
	scanf("%d", &numeroDatos);

	while(1) {
		char TempChar;
		int TempInt = 3;
		printf("Ingrese Tipo y Longitud: ");
		scanf(" %c", &TempChar);
		if(TempChar == '0') {
			break;
		}
		if(TempChar != 'c') {
			scanf(" %d", &TempInt);
		}
		Datos[numTipos].Tipo = TempChar;
		Datos[numTipos].Longitud = TempInt;

		numTipos++;
	}

	for (int i = 0; i < numeroDatos; ++i) {
		for (int j = 0; j < numTipos; ++j) {
			switch(Datos[j].Tipo) {
				case 'i':
				fprintf(Salida, "%d", generarInt(Datos[j].Longitud));
				break;
				case 'f':
				fprintf(Salida, "%.2f", generarFloat(Datos[j].Longitud));
				break;
				case 'c':
				fprintf(Salida, "%c", generarChar());
				break;
				case 's':
				s = generarString(Datos[j].Longitud);
				fprintf(Salida, "%s", s);
				free(s);
				break;

				default:
				break;
			}

			if(j + 1 < numTipos) {
				fprintf(Salida, " ");
			}
		}

		fprintf(Salida, "\n");
	}

	fclose(Salida);
	return 0;
}