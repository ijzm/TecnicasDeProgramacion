#ifndef FUNCIONES_H
#define FUNCIONES_H 

void imprimirFacturas(FILE *, FILE *, FILE *, FILE *);
void buscarCliente(FILE *, int, int *, int *);
float buscarProductos(FILE *, int);
void imprimirEncabezado(FILE *, int, int, int, int, int, int, int);
void imprimirProductos(FILE *, FILE *,FILE *);
void imprimirLinea(FILE *, char, int);


void cerrarArchivos(FILE *, FILE *, FILE *, FILE *);

#endif