#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Funciones.h"

int generarInt(int Longitud) {
	return rand() % (int)pow(10, Longitud);
}

float generarFloat(int Longitud) {
	return generarInt(Longitud - 2) + (float)generarInt(2)/100;
}

char generarChar() {
	char c = rand() % 26 + 'A';
	c += ('a' - 'A') * (rand() % 2)	; 
	return c;
}

char *generarString(int Max) {
	char *Cadena;
	int Longitud = rand() % Max  + 1;

	Cadena = malloc(sizeof(char) * (Longitud + 1));

	for (int i = 0; i < Longitud; ++i) {
		Cadena[i] = generarChar();
	}

	Cadena[Longitud] = '\0';
	return Cadena;
}
