#ifndef FUNCIONES_H
#define FUNCIONES_H

int LeerDatos(int *, int *, int *, float *);
void Ordenar(int *dni, int *region, int *ciudad, float *sueldo, int numDatos);
void Swap(int *, int, int);
void SwapF(float *, int, int);
void ImprimirArreglo(int *, int);

void ImprimirReporte(int *dni, int *region, int *ciudad, float *sueldo, int numDatos);


#endif