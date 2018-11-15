/* 
 * File:   FuncionesDeCadena.c
 * Author: Ignacio Javier Zevallos Morales
 * Codigo: 20171160
 *
 * Created on 13 de noviembre de 2018, 08:25 AM
 */

#include <stdlib.h>
#include <stdio.h>

#include "FuncionesDeCadena.h"

char *leerFrase(char *cadena, FILE *arch) {
    char Buffer[500];
    int longitudTotal = 0, longBuffer;
    if(feof(arch)) {
        return NULL;
    }
    
    while(1) {
        fscanf(arch, "%s", Buffer);
        longBuffer = hallarLongitud(Buffer);
        
        cadena = concatenar(cadena, Buffer, &longitudTotal, longBuffer);
        if(feof(arch)) {
            break;
        }
        if(fgetc(arch) == ' ') {
            cadena = concatenar(cadena, " ", &longitudTotal, 1);
        }
    }
    
    return cadena;
}

void nombrePropio(char *cadena) {
    int longitud = hallarLongitud(cadena);
    int i;
    char c;
    for(i = 0; i < longitud; i++) {
        c = cadena[i];
        if(i < 1) {
            if(cadena[i] >= 'a' && cadena[i] <= 'z') {
                cadena[i] = c - ('a' - 'A');
            }
        } else {
            if(cadena[i - 1] == ' ') {
                if(cadena[i] >= 'a' && cadena[i] <= 'z') {
                    cadena[i] = c - ('a' - 'A');
                }
            } else if(cadena[i] >= 'A' && cadena[i] <= 'Z') {
                cadena[i] = c + ('a' - 'A');
            }
        }
    }
}

int subConjunto(char *cadena1, char* cadena2) {
    int longitud = hallarLongitud(cadena1);
    int longitud2 = hallarLongitud(cadena2);
    int r = 1;
    
    char *tmp = copiarCadena(cadena2);
    
    int i, j;
    for(i = 0; i < longitud; i++) {
        for(j = 0; j < longitud2; j++) {
            if(cadena1[i] == tmp[j]) {
                tmp[j] = 0;
            }
        }       
    }
    
    int k;
    for(k = 0; k < longitud2; k++) {
        if(tmp[j] != 0) {
            r = 0;
            break;
        }
    }
    
    free(tmp);
    
    return r;
}

int encontrar(char *cadena1, char *cadena2) {
    int i, j;
    int longitud1 = hallarLongitud(cadena1), longitud2 = hallarLongitud(cadena2);
    
    for(i = 0; i < longitud1 - longitud2; i++) {
        for(j = 0; j < longitud2; j++) {
            if(cadena1[i + j] == cadena2[j]) {
                if(j == longitud2 - 1) {
                    return i;
                }
            } else {
                break;
            }
        }
    }
    
    return -1;    
}

void codigoAleatorio(char *codigo, char *cadena) {
    codigo[0] = rand() % ('Z' - 'A') + 'A';
    codigo[1] = rand() % ('Z' - 'A') + 'A';
    
    codigo[2] = rand() % ('z' - 'a') + 'a';
    codigo[3] = rand() % ('z' - 'a') + 'a';
    
    int i;
    for(i = 0; i < 4; i++) {
        codigo[4 + i] = rand() % 10 + '0';
    }
    
    codigo[8] = cadena[rand() % hallarLongitud(cadena)];
    codigo[9] = cadena[rand() % hallarLongitud(cadena)];
    
    codigo[10] = '\0';    
}

int hallarLongitud(char *c) {
    int num = 0;
    while(1) {
        if(c[num] == '\0') {
            break;
        }
        num++;
    }
    return num;
}

char *copiarCadena(char *src) {
    int longitud = hallarLongitud(src);
    char *tmp = (char*) malloc(sizeof(char) * (longitud + 1));
    
    int i;
    for(i = 0; i < longitud; i++) {
        tmp[i] = src[i];
    }
    tmp[longitud] = '\0';
    return tmp;
}

char *concatenar(char *dst, char *src, int *longtotal, int lb) {
    char *tmp = malloc(sizeof(char) * (*longtotal + lb + 1));
    
    if(*longtotal > 0) {
        int i;
        for(i = 0; i < *longtotal; i++) {
            tmp[i] = dst[i];
        }
        free(dst);
    }
    
    int j;
    for(j = 0; j < lb; j++) {
        tmp[*longtotal + j] = src[j];
    }
    
    *longtotal = *longtotal + lb;
    
    tmp[*longtotal] = '\0';
    
    
    
    return tmp;
}