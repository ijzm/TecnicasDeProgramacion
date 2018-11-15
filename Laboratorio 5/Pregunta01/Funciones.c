/* 
 * File:   Funciones.c
 * Author: Ignacio Javier Zevallos Morales
 * Codigo: 20171160
 *
 * Created on 13 de noviembre de 2018, 08:02 AM
 */

#include <stdio.h>
#include <stdlib.h>

#include "Funciones.h"

int leerBonos(float *bonos) {
    int n = 0;
    FILE *ArchBonos = AbrirArchivo("bonos.txt", "r");
    
    while(1) {
        fscanf(ArchBonos, "%f", &bonos[n]);
        
        if(feof(ArchBonos)) {
            break;
        }
        
        n++;
    }
    
    return n;
}

int leerEmpleados(int *empleados) {
    int n = 0;
    FILE *ArchEmpleados = AbrirArchivo("empleados.txt", "r");
    
    while(1) {
        fscanf(ArchEmpleados, "%d", &empleados[n]);
        
        if(feof(ArchEmpleados)) {
            break;
        }
        
        n++;
    }
    return n;
}

void determinarBonos(float *bonos, int numBonos, int *empleados, int numEmpleados) {
    int i, indice;
    FILE *Reporte = AbrirArchivo("Reporte.txt", "w");
    fprintf(Reporte, "   DNI       BONO\n");
    for(i = numEmpleados - 1; i >= 0; i--) {
        indice = rand() % (numEmpleados + 1);
        if(i < numBonos) {
            fprintf(Reporte, "%9d %9.2f\n", empleados[indice], bonos[i]);
        }
        arrPop(empleados, indice, i);
    }
}

void arrPop(int *Arr, int indice, int max) {
    int i;
    for(i = indice; i < max; i++) {
        Arr[i] = Arr[i + 1];
    }
}

FILE *AbrirArchivo(const char *Path, const char *Args) {
    FILE *Arch = fopen(Path, Args);
    if(Arch == NULL) {
        printf("ERROR: No se pudo abrir el archivo %s\n", Path);
        exit(1);
    }
    return Arch;
}
