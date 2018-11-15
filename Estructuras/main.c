#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Funciones.h"
#include "Estructuras.h"

int main(int argc, char const *argv[]) {
	Persona p;
	p.dni = 1234;
	strcpy(p.nombre, "Juan Perez");
	p.sueldo = 123.42;

	printf("%d %s %f\n", p.dni, p.nombre, p.sueldo);
	return 0;
}