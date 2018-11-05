#include <stdio.h>
#include <stdlib.h>

#include "Funciones.h"

int main(int argc, char const *argv[]) {
	char cadena1[100], cadena2[100], nuevaCadena[100], pruebaConcat[100] = "i";
	int comp;
	scanf("%s", cadena1);

	printf("%s tiene %d caracteres\n", cadena1, length(cadena1));

	copiar(nuevaCadena, cadena1);
	strToUppercase(nuevaCadena);
	printf("%s\n", nuevaCadena);

	scanf("%s", cadena2);

	comp = comparar(cadena1, cadena2);
	printf("Comparar = %d\n", comp);

	concat(pruebaConcat, cadena1);
	concat(pruebaConcat, " ");
	concat(pruebaConcat, cadena2);
	concat(pruebaConcat, " ");
	concat(pruebaConcat, nuevaCadena);
	concat(pruebaConcat, "\n");

	printf("%s", pruebaConcat);

}