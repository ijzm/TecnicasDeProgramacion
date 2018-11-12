#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "FuncionesDeCadenas.h"

//Lee un archivo y devuelve la cadena SIN \n
char *leerCadena(char *cadena, int max, FILE *arch) {
	int longitud;
	char *c;
	c = fgets(cadena, max, arch);
	longitud = strlen(cadena);
	cadena[longitud - 1] = '\0';

	return c;	
}

//Abre y verifica un archivo
FILE *leerArchivo(const char *Path, const char *Arg) {
	FILE *Archivo;
	Archivo = fopen(Path, Arg);

	if(Archivo == NULL) {
		printf("ERROR: No se pudo abrir el archivo: %s\n", Path);
		exit(1);
		return NULL;
	}
	return Archivo;
}

char *leerCadenaExacta(FILE *Arch) {
	char buffer[500], *cadena;
	int longitud;
	leerCadena(buffer, 500, Arch);
	if(feof(Arch)) {
		return NULL;
	}
	longitud = strlen(buffer);

	cadena = (char *)malloc(sizeof(char) * (longitud + 1));
	strcpy(cadena, buffer);
	return cadena;
}