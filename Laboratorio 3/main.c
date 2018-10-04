/* 
 * File:   main.c
 * Author: Ignacio Javier Zevallos Morales
 *
 * *****************************************************************************
 * Descripcion: Dado los archivos Especialdades, Cursos, Alumnos y Notas, se 
 *              elabora un reporte de cada alumno segun sus creditos y notas.
 *              Finalmente se elabora un resumen con el total de alumnos y las
 *              mejores y peores notas
 * *****************************************************************************
 * 
 * Created on 2 de octubre de 2018, 08:02 AM
 */

#include <stdio.h>
#include <stdlib.h>

#include "Funciones.h"

/* 
 * Funcion Principal. Abre los archivos a utilizar, revisa que se puedan abrir
 * correctamente. Llama la funcion para imprimir el reporte. Despues cierra los
 * archivos y concluye la ejecucion del programa
 */
int main(int argc, char** argv) {
    //Declaracion de archivos a utilizar
    FILE *Especialidades, *Cursos, *Alumnos, *Notas, *Reporte;
    
    //Abrir los archivos
    Especialidades = fopen("Especialidades.txt", "r");
    Cursos = fopen("Cursos.txt", "r");
    Alumnos = fopen("Alumnos.txt", "r");
    Notas = fopen("Notas.txt", "r");
    Reporte = fopen("Reporte.txt", "w");
    
    //Asegurarse de que hayan sido correctamente abiertos
    if(Especialidades == NULL) {
        printf("ERROR: No se pudo abrir el archivo Especialidades.txt");
        exit(1);
    }
    if(Cursos == NULL) {
        printf("ERROR: No se pudo abrir el archivo Cursos.txt");
        exit(1);
    }
    if(Alumnos == NULL) {
        printf("ERROR: No se pudo abrir el archivo Alumnos.txt");
        exit(1);
    }
    if(Notas == NULL) {
        printf("ERROR: No se pudo abrir el archivo Notas.txt");
        exit(1);
    }
    if(Reporte == NULL) {
        printf("ERROR: No se pudo abrir el archivo Reporte.txt");
        exit(1);
    }
    
    //Imprime el Reporte
    imprimirReporte(Especialidades, Cursos, Alumnos, Notas, Reporte);
    
    //Cierra los archivos
    cerrarArchivos(Especialidades, Cursos, Alumnos, Notas, Reporte);

    //Concluye la ejecucion del programa
    return (EXIT_SUCCESS);
}

