#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"

int main(int argc, char const *argv[]) {
	int notas[100], numDatos;
	float promedio, desviacion;

	leerNotas(notas, &numDatos);
	promedio = calcularPromedio(notas, numDatos);
	desviacion = calcularDesviacion(notas, numDatos, promedio);

	printf("Numero de Datos: %8d\n", numDatos);
	printf("Promedio:        %8.2f\n", promedio);
	printf("Desviacion:      %8.2f\n", desviacion);

	/*
	for (int i = 0; i < numDatos; ++i)	{
		printf("%d \n", notas[i]);
	}
	*/

	return 0;
}