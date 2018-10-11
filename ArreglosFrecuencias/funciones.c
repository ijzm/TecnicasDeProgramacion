#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void leerNotas(int *Notas, int *numDatos) {
	FILE *Datos;
	Datos = fopen("Datos.txt", "r");
	if(Datos == NULL) {
		printf("ERROR: No se pudo leer Datos.txt");
		exit(1);
	}

	*numDatos = 0;
	while(1) {
		fscanf(Datos, "%d", &Notas[*numDatos]);
		if(feof(Datos)) {
			break;
		}
		(*numDatos)++;
	}

	fclose(Datos);
}

float calcularPromedio(int *Notas, int numDatos) {
	int suma = 0;

	for (int i = 0; i < numDatos; ++i)	{
		suma += Notas[i];
	}

	return (float)suma/numDatos;
}

float calcularDesviacion(int *Notas, int numDatos, float promedio) {
	float suma = 0;
	for (int i = 0; i < numDatos; ++i) {
		suma += pow(Notas[i] - promedio, 2);
	}
	return sqrt((suma)/(numDatos-1));
}