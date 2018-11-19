#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Estructuras.h"
#include "FuncionesDeCadenas.h"
#include "Funciones.h"

void asignarDatos(Persona *p, int dni, char *nombre, float sueldo) {
	p -> dni = dni;
	strcpy(p -> nombre, nombre);
	p -> sueldo = sueldo;
}

int leerDatos(Persona *personas) {
	FILE *Arch = leerArchivo("Datos.csv", "r");
	int num = 0;
	Persona personaActual;

	while(1) {
		leerPersona(Arch, &personaActual);
		if(feof(Arch)) {
			break;
		}

		personas[num] = personaActual;
		num++;
	}

	fclose(Arch);
	return num;
}

void leerPersona(FILE *Arch, Persona *persona) {
	char *Cadena, *Datos[3];
	int numDatos;

	Cadena = leerCadenaExacta(Arch);
	if(feof(Arch)) {
		return;
	}
	numDatos = sacaPalabrasCSV(Cadena, Datos);

	persona -> dni = atoi(Datos[0]);
	strcpy(persona -> nombre, Datos[1]);
	persona -> sueldo = atof(Datos[2]);

	free(Cadena);
	for (int i = 0; i < numDatos; ++i) {
		free(Datos[i]);
	}
}

void ordenarPorDNI(Persona *personas, int max) {
	for (int i = 0; i < max; ++i) {
		for (int j = 0; j < max; ++j) {
			if(personas[i].dni < personas[j].dni) {
				swapPersona(personas, i, j);
			}
		}
	}
}

void swapPersona(Persona *p, int i, int j) {
	Persona t = p[i];
	p[i] = p[j];
	p[j] = t;
}

void imprimirDatos(Persona *personas, int num) {
	for (int i = 0; i < num; ++i) {
		printf("%3d) %06d %-30s %10.2f\n",
		i, personas[i].dni, personas[i].nombre, personas[i].sueldo);
	}
}