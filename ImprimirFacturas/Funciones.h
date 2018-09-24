#ifndef FUNCIONES_H
#define FUNCIONES_H 

void imprimirFacturas(FILE *, FILE *, FILE *, FILE *);
void buscarCliente(FILE *, int, int *, int *);
void imprimirEncabezado(FILE *, int, int, int, int, int, int, int);
void imprimirProductos(FILE *, FILE *,FILE *);


void cerrarArchivos(FILE *, FILE *, FILE *, FILE *);

#endif