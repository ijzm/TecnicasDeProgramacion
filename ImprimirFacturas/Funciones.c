#include <stdio.h>
#include "Funciones.h"

void imprimirFacturas(FILE *Productos, FILE *Clientes, FILE *Facturas, FILE *Reporte) {
	int numeroFactura, dia, mes, ano, dni, ciudad, telefono;
	while(1) {
		fscanf(Facturas, "%d %d/%d/%d %d", &numeroFactura, &dia, &mes, &ano, &dni);
		if(feof(Facturas)) {
			break;
		}

		buscarCliente(Clientes, dni, &ciudad, &telefono);

		imprimirEncabezado(Reporte, numeroFactura, dia, mes, ano, dni, ciudad, telefono);
	
		imprimirProductos(Productos, Facturas, Reporte);
	}
}

void buscarCliente(FILE *Clientes, int dni, int *ciudad, int *telefono) {
	int dniAct;
	rewind(Clientes);
	while(1) {
		fscanf(Clientes, "%d %d %d", &dniAct, ciudad, telefono);
		if(dniAct == dni) {
			return;
		}
		if(feof(Clientes)) {
			printf("ERROR: No se encontro cliente con dni: %d \n", dni);
			*ciudad = -1;
			*telefono = -1;
			return;
		}
	}
}

void imprimirEncabezado(FILE *Reporte, int numeroFactura, int dia, int mes, int ano, int dni, int ciudad, int telefono) {

}

void imprimirProductos(FILE *Productos, FILE *Facturas,FILE *Reporte) {
	//int producto, cantidad;
	//float precio;
}

void cerrarArchivos(FILE *Productos, FILE *Clientes, FILE *Facturas, FILE *Reporte) {
	fclose(Productos);
	fclose(Clientes);
	fclose(Facturas);
	fclose(Reporte);
}