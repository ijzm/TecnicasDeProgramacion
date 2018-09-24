#include <stdio.h>
#include <stdlib.h>

#include "Funciones.h"

int main(int argc, char const *argv[]) {
	//Definir y preparar archivos
	FILE *Productos, *Clientes, *Facturas, *Reporte;

	Productos = fopen("Productos.txt", "r");
	Clientes = fopen("Clientes.txt", "r");
	Facturas = fopen("Facturas.txt", "r");
	Reporte = fopen("Reporte.txt", "w");

	if(Productos == NULL) {
		printf("ERROR: Productos.txt no se pudo abrir \n");
		exit(1);
	}
	if(Clientes == NULL) {
		printf("ERROR: Clientes.txt no se pudo abrir \n");
		exit(1);
	}
	if(Facturas == NULL) {
		printf("ERROR: Facturas.txt no se pudo abrir \n");
		exit(1);
	}
	if(Reporte == NULL) {
		printf("ERROR: Reporte.txt no se pudo abrir \n");
		exit(1);
	}

	//Imprimir Facturas
	imprimirFacturas(Productos, Clientes, Facturas, Reporte);

	//Cerrrar Archivos
	cerrarArchivos(Productos, Clientes, Facturas, Reporte);

	return 0;
}