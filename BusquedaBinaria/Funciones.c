#include <stdio.h>
#include <stdlib.h>

#include "Funciones.h"

int BusquedaBinaria(int *arr, int dato, int numDatos) {
	int limiteInf, limiteSup, puntoMedio;
	limiteInf = 0;
	limiteSup = numDatos - 1;

	while(1) {
		if(limiteInf > limiteSup) {
			return -1;
		}

		puntoMedio = (limiteInf + limiteSup)/2;

		if(arr[puntoMedio] == dato) {
			return puntoMedio;
		}

		if(arr[puntoMedio] > dato) {
			limiteSup = puntoMedio - 1;
		} else {
			limiteInf = puntoMedio + 1;
		}
	}
}