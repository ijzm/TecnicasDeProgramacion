/* 
 * File:   main.c
 * Author: Ignacio Javier Zevallos Morales
 * Codigo: 20171160
 * Created on 30 de octubre de 2018, 08:01 AM
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_COMP 500
#define MAX_ART 50
int main(int argc, char** argv) {
    int dni[MAX_COMP], codigoProducto[MAX_ART] = {0}, almacen[MAX_ART], stock[MAX_ART];
    float costoTotal[MAX_COMP], costo[MAX_ART], costo12[MAX_ART];
    double fechas[MAX_COMP];
    int numCompras, numArticulos;
    
    numArticulos = leerArticulos(codigoProducto, almacen, costo, costo12, stock);
    ordenarArticulos(numArticulos, codigoProducto, almacen, costo, costo12, stock);
    reescribirArticulos(numArticulos, codigoProducto, almacen, costo, costo12, stock);
        
    numCompras = leerCompras(fechas, dni, costoTotal, codigoProducto, costo, costo12, stock);
    
    ordenarCompras(numCompras, fechas, dni, costoTotal);
    imprimirTotales(numCompras, fechas, dni, costoTotal);
    
    imprimirResumen(numCompras, costoTotal);
    return (EXIT_SUCCESS);
}

