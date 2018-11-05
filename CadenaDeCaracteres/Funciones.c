#include <stdio.h>
#include <stdlib.h>

#include "Funciones.h"

int length(const char *c) {
	//Version Facil:
	int n = 0;
	
	while(1) {
		if(c[n] == '\0') {
			break;
		}
		n++;
	}
	return n;
	
	/*
	//Version Guanira:
	int i;
	for(i = 0; c[i]; i++);
	return i;
	*/
}

void strToUppercase(char *c) {
	int longitud = length(c);
	for (int i = 0; i < longitud; ++i)	{
		if(c[i] >= 'a' && c[i] <= 'z') {
			c[i] = c[i] - 'a' + 'A'; 
		} else {
			c[i] = c[i];
		}
	}
}

void copiar(char *nueva, const char *cadena) {
	int longitud = length(cadena);
	for (int i = 0; i < longitud; ++i)	{
		nueva[i] = cadena[i];
	}
}

int comparar(const char *cadena1, const char *cadena2) {
	int c = 0;

	while(cadena1[c] == cadena2[c]) {
		if(cadena1[c] == 0) {
			return 0;
		}
		c++;
	}

	return cadena1[c] - cadena2[c];
}

void concat(char *destino, const char *fuente) {
	int lng = length(destino);

	copiar(&destino[lng], fuente);
}