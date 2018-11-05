/* 
 * File:   Funciones.h
 * Author: Ignacio Javier Zevallos Morales
 * Codigo: 20171160
 * Created on 30 de octubre de 2018, 08:02 AM
 */

#include <stdio.h>
#include <stdlib.h>

#include "Funciones.h"

int leerArticulos(int *codigoProducto, int *almacen, float *costo, float *costo12, int *stock) {
    int num = 0;
    FILE *Articulos = fopen("Articulos.txt", "r");
    if(Articulos == NULL) {
        printf("ERROR: No se pudo abrir Articulos.txt");
        exit(1);
    }
    
    while(1) {
        fscanf(Articulos, "%d %d %f %f %d", &codigoProducto[num], &almacen[num], &costo[num], &costo12[num], &stock[num]);
        if(feof(Articulos)) {
            break;
        }
        num++;
    }
    
    fclose(Articulos);
   
    return num;
}

void ordenarArticulos(int num, int *codigoProducto, int *almacen, float *costo, float *costo12, int *stock) {
    int i, j;
    for(i = 0; i < num; i++) {
        for(j = i + 1; j < num; j++) {
            if(codigoProducto[i] > codigoProducto[j]) {
                swapI(codigoProducto, i, j);
                swapI(almacen, i, j);
                swapF(costo, i, j);
                swapF(costo12, i, j);
                swapI(stock, i, j);
            }
        }
    }
}

void reescribirArticulos(int num, int *codigoProducto, int *almacen, float *costo, float *costo12, int *stock) {
    FILE *ArticulosOrd = fopen("ArticulosOrdenados.txt", "w");
    if(ArticulosOrd == NULL) {
        printf("ERROR: No se pudo abrir ArticulosOrdenados.txt");
        exit(1);
    }
    int i;
    for(i = 0; i < num; i++) {
         fprintf(ArticulosOrd, "%d %d %.2f %.2f %d\n", codigoProducto[i], almacen[i], costo[i], costo12[i], stock[i]);
    }
    fclose(ArticulosOrd);
}

int leerCompras(double *fechas, int *dni, float *costoTotal, int *codigoProducto, float *costo, float *costo12, int *stock) {
    int num = 0;
    int dd, mm, aa, H, M, S;
    FILE *Compras = fopen("Compras.txt", "r");
    if(Compras == NULL) {
        printf("ERROR: No se pudo abrir Compras.txt");
        exit(1);
    }
    
    while(1) {
        fscanf(Compras, "%d/%d/%d %d:%d:%d %d", &dd, &mm, &aa, &H, &M, &S, &dni[num]);        
        if(conseguirCosto(num, Compras, costoTotal, codigoProducto, costo, costo12, stock)) {
            break;
        }
        
        fechas[num] = convertirFecha(dd, mm, aa, H, M, S);
        
        num++;
    }
    
    fclose(Compras);
    
    return num;
}

int conseguirCosto(int num, FILE *Compras, float *costoTotal, int *codigoProducto, float *costo, float *costo12, int *stock) {
    int codigoActual, cantidad, indice;
    char c;
    costoTotal[num] = 0;
    while(1) {
        
        
        fscanf(Compras, "%d %d", &codigoActual, &cantidad);
        c = fgetc(Compras);
        if(c == '\n' || c == EOF) {
            if(feof(Compras)) {
                return 1;
            }
            return 0;
        }
       
            
        indice = buscarCosto(codigoActual, codigoProducto);
        if(indice == -1) {
            printf("ERROR: No se pudo encontrar el producto actual: %d %d \n", codigoActual, cantidad);
            continue;
        }
        
        if(cantidad > stock[indice]) {
            if(stock[indice] % 12 == 0) {
                costoTotal[num] += costo12[indice] * stock[indice];
            } else {
                costoTotal[num] += costo[indice] * stock[indice];
            }
            stock[indice] = 0;
        } else {
            if(cantidad % 12 == 0) {
                costoTotal[num] += costo12[indice] * cantidad;
            } else {
                costoTotal[num] += costo[indice] * cantidad;
            }
            stock[indice] -= cantidad;
        }
    }
}

int buscarCosto(int codigo, int *codigoProducto) {
    int i;
    for(i = 0; i < 50; i++) {
        if(codigo == codigoProducto[i]) {
            return i;
        }
    }
    return -1;
}

double convertirFecha(int dd, int mm, int aa, int H, int M, int S) {
    double fecha = 0;
    fecha += dd + mm *100 + aa * 1000000;
    fecha += (float)H /100 + (float)M/10000 + (float)S/1000000;   
    return fecha;
}

void ordenarCompras(int num, double *fechas, int *dni, float *costoTotal) {
    int i, j;
    for(i = 0; i < num; i++) {
        for(j = i + 1; j < num; j++) {
            if(fechas[i] > fechas[j]) {
                swapI(dni, i, j);
                swapD(fechas, i, j);
                swapF(costoTotal, i, j);
            }
        }
    }
}

void imprimirTotales(int num, double *fechas, int *dni, float *costoTotal) {
    int i;
    FILE *Total = fopen("Totales.txt", "w");
    for(i = 0; i < num; i++) {
        fprintf(Total, "%lf %d %.2f\n", fechas[i], dni[i], costoTotal[i]);
    }
}

void imprimirResumen(int numCompras, float *costoTotal) {
    float promedio = 0, media;
    
    int i;
    for(i = 0; i < numCompras; i++) {
        promedio += costoTotal[i];
    }
    
    promedio /= numCompras;
    
    ordenarCostos(numCompras, costoTotal);
    media = costoTotal[numCompras/1];
    
    printf("Promedio: %.2f Media: %.2f\n", promedio, media);
}

void ordenarCostos(int num, float *costoTotal) {
    int i, j;
    for(i = 0; i < num; i++) {
        for(j = i + 1; j < num; j++) {
            if(costoTotal[i] > costoTotal[j]) {

                swapF(costoTotal, i, j);

            }
        }
    }
}



void swapI(int *arr, int i, int j) {
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

void swapF(float *arr, int i, int j) {
    float t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

void swapD(double *arr, int i, int j) {
    double t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}