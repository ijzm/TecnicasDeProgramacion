#include <stdio.h>
#include "Funciones.h"

#define MAXCHAR 60

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

		imprimirLinea(Reporte, '=', MAXCHAR);

		fprintf(Reporte, "\n");
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

float buscarProductos(FILE *Productos, int codigo) {
	int productoActual;
	float precio;
	rewind(Productos);
	while (1) {
		fscanf(Productos, "%d %f", &productoActual, &precio);
		if(productoActual == codigo) {
			break;
		}

		if(feof(Productos)) {
			precio = -1;
			printf("ERROR: Producto no encontrado\n");
			break;
		}
	}

	return precio;
}


void imprimirEncabezado(FILE *Reporte, int numeroFactura, int dia, int mes, int ano, int dni, int ciudad, int telefono) {
	imprimirLinea(Reporte, '=', MAXCHAR);
	fprintf(Reporte, "Numero de Factura: %d                   Fecha: %02d/%02d/%d \n", numeroFactura, dia, mes, ano);
	fprintf(Reporte, "DNI: %8d         Ciudad: %03d           Telefono: %d\n", dni, ciudad, telefono);
	fprintf(Reporte, "CODIGO          PRECIO           CANTIDAD           SUBTOTAL\n");
	imprimirLinea(Reporte, '-', MAXCHAR);
}

void imprimirProductos(FILE *Productos, FILE *Facturas,FILE *Reporte) {
	int producto, cantidad;
	float precio, total = 0;

	while (1) {
		fscanf(Facturas, "%d %d", &producto, &cantidad);
		

		precio = buscarProductos(Productos, producto);
		fprintf(Reporte, "%6d         %7.2f             %3d              %8.2f\n", producto, precio, cantidad, precio * cantidad);
		total += precio * cantidad;

		if(fgetc(Facturas) == '\n') {
			break;
		}
	}

	imprimirLinea(Reporte, '-', MAXCHAR);
	fprintf(Reporte, "TOTAL:                                            %10.2f\n", total);

}

void imprimirLinea(FILE *Reporte, char c, int width) {
	for (int i = 0; i < width; ++i)	{
		fprintf(Reporte, "%c", c);
	}
	fprintf(Reporte, "\n");
}


void cerrarArchivos(FILE *Productos, FILE *Clientes, FILE *Facturas, FILE *Reporte) {
	fclose(Productos);
	fclose(Clientes);
	fclose(Facturas);
	fclose(Reporte);
}