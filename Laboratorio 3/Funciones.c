/* 
 * File:   main.c
 * Author: Ignacio Javier Zevallos Morales
 *
 * *****************************************************************************
 * Descripcion: Funciones de ayuda para la elaboracion del reporte de alumnos
 * *****************************************************************************
 * 
 * Created on 2 de octubre de 2018, 08:02 AM
 */

#include <stdio.h>
#include <stdlib.h>

#include "Funciones.h"

#define MAXWIDTH 92
#define NOTA_APROBATORIA 10.5

/*
 * Imprime el encabezado y llama la funcion imprimirNotas
 */
void imprimirReporte(FILE *Especialidades, FILE *Cursos, FILE *Alumnos, FILE *Notas, FILE *Reporte) {
    fprintf(Reporte, "                                  INSTITUTO DE EDUCACION SUPERIOR \n");
    fprintf(Reporte, "                            SITUACION DE LOS ALUMNOS DE LA INSTITUCION \n");
    imprimirLinea(Reporte, '=', MAXWIDTH);
    fprintf(Reporte, "No.   ALUMNO   ESPECIALIDAD   CREDITOS APROBADOS   PROMEDIO   %% CRED.AP/CRED.MAT   SITUACION \n");
    imprimirLinea(Reporte, '-', MAXWIDTH);
    
    imprimirNotas(Especialidades, Cursos, Alumnos, Notas, Reporte);
    imprimirLinea(Reporte, '=', MAXWIDTH);
}

/*
 * Llama a diferentes funciones para el calculo de variables necesarias. Despues
 * imprime el reporte
 */
void imprimirNotas(FILE *Especialidades, FILE *Cursos, FILE *Alumnos, FILE *Notas, FILE *Reporte) {
    
    //Declaracion de variables a utilizar
    int num = 1, codigoAlumno, codigoEspecialidad, totalAprobados = 0;
    float creditosAprobados, creditosTotales, acumulacionPromedioPonderado, promedio, porcentajeAprobado, minimoCreditos;
    
    int alumnoMayorPromedio, alumnoMenorPromedio;
    float notaMayorPromedio = 0, notaMenorPromedio = 21, porcentajeMayorPromedio, porcentajeMenorPromedio;
    
    //Iteracion Principal
    while(1) {
        //Lectura del arichov Alumnos
        fscanf(Alumnos, "%d %d", &codigoAlumno, &codigoEspecialidad);
        //Condicion de salida
        if(feof(Alumnos)) {
            break;
        }
        //Regresa los valores acumulados a 0, para la buena ejecucion de la siguiente iteracion
        creditosAprobados = creditosTotales = acumulacionPromedioPonderado = 0;
        
        //Hallar el minimo de creditos necesarios para aprobar
        minimoCreditos = buscarMinimoCreditosRequeridos(Especialidades, codigoEspecialidad);
        //Hallar el numero de creditos totales y aprobados que el alumno ha llevado
        buscarCreditos(Notas, Cursos, codigoAlumno, &creditosAprobados, &creditosTotales, &acumulacionPromedioPonderado);
        //Calculo del porcentaje de creditos aprobados
        porcentajeAprobado = (creditosAprobados/creditosTotales) * 100.0f;
        //Calculo del Promedio Ponderado
        promedio = acumulacionPromedioPonderado / creditosTotales;

        //Impresion del archivo Reporte segun cada alumno
        fprintf(Reporte, "%3d) %8d     %7d           %6.2f           %05.2f           %5.1f%%      ", num, codigoAlumno, codigoEspecialidad, creditosAprobados, promedio, porcentajeAprobado);
        if(creditosAprobados >= minimoCreditos) {
            totalAprobados++;
            fprintf(Reporte, "   EGRESADO");
        } else {
            fprintf(Reporte, "NO EGRESADO");
        }
        
        fprintf(Reporte, "\n");
        
        //Calculo del mayor promedio        
        if(promedio > notaMayorPromedio) {
            alumnoMayorPromedio = codigoAlumno;
            notaMayorPromedio = promedio;
            porcentajeMayorPromedio = porcentajeAprobado;
        }
        
        //Calculo del menor promedio
        if(promedio < notaMenorPromedio) {
            alumnoMenorPromedio = codigoAlumno;
            notaMenorPromedio = promedio;
            porcentajeMenorPromedio = porcentajeAprobado;
        }
        
        //Aumenta la acumulacion de alumnos
        num++;        
    }
    
    //Impresion del resumen
    imprimirLinea(Reporte, '-', MAXWIDTH);
    
    fprintf(Reporte, "RESUMEN: \n");
    
    //En el total de alumnos se utiliza "num - 1", ya que la variable num es
    //inicializada con el valor de 1
    fprintf(Reporte, "Total de alumnos:          %5d \n", num - 1);
    fprintf(Reporte, "Total de egresados:        %5d \n", totalAprobados);
    
    fprintf(Reporte, "\n");
    
    fprintf(Reporte, "Alumno con mayor promedio: %d con %05.2f de promedio ponderado. \n", alumnoMayorPromedio, notaMayorPromedio);
    fprintf(Reporte, "                           El alumno tiene el %6.2f%% de creditos/creditos matriculados. \n", porcentajeMayorPromedio);
    
    fprintf(Reporte, "Alumno con menor promedio: %d con %05.2f de promedio ponderado. \n", alumnoMenorPromedio, notaMenorPromedio);
    fprintf(Reporte, "                           El alumno tiene el %6.2f%% de creditos/creditos matriculados. \n", porcentajeMenorPromedio);
    
}

/*
 * Dado el archivo de especialidades y el codigo de especialidad,
 * devuelve el numero minimo de creditos de ese curso
 */
float buscarMinimoCreditosRequeridos(FILE *Especialidades, int codigoEspecialidad) {
    //Declaracion de variables a utilizar en la funcion
    int especialidadActual;
    float minimoCreditos;
        
    //Se regresa al comienzo del archivo Especialidades
    rewind(Especialidades);
    //Iteracion Principal
    while(1) {
        //Lectura de datos del archivo
        fscanf(Especialidades, "%d %f", &especialidadActual, &minimoCreditos);
        //Condicion para salir de la iteracion
        if(feof(Especialidades)) {
            minimoCreditos = -1;
            break;
        }
        //Revisar si la especialidad leida es la que estamos buscando
        if(especialidadActual == codigoEspecialidad) {
            break;
        }
    }
    //Regresa el minimo de creditos de la especialidad
    return minimoCreditos;
}

/*
 * Dado los archivos de Notas y Cursos, ademas de la variable codigo de alumno,
 * devuelve los valores del total de Creditos Aprobados, total de Creditos y la
 * acumulacion del promedio ponderado para ese alumno
 */
void buscarCreditos(FILE *Notas, FILE *Cursos, int codigoAlumno, float *creditosAprobados, float *creditosTotales, float *acumulacionPromedioPonderado) {
    //Declaracion de variables a utilizar en la funcion
    int alumnoActual, codigoCurso;
    float notaObtenida;
    
    //Se regreza al comienzo del archivo notas
    rewind(Notas);
    //Iteracion Principal
    while(1) {
        //Lectura del archivo
        fscanf(Notas, "%d %d %f", &alumnoActual, &codigoCurso, &notaObtenida);
        //Condicion para salir de la iteracion
        if(feof(Notas)) {
            break;
        }
        //Revisar si el codigo leido es el que estamos buscando
        if(alumnoActual == codigoAlumno) {
            //Halla el numero de creditos que vale el curso
            float numCreditos = buscarNumeroCreditosEnCurso(Cursos, codigoCurso);
            
            //Acumula el numero de creditos
            *creditosTotales += numCreditos;
            if(notaObtenida >= NOTA_APROBATORIA) {
                //Acumula el numero de creditos si el curso fue aprobado
                *creditosAprobados += numCreditos;  
            }
            
            //Acumula el promedio ponderado del alumno
            *acumulacionPromedioPonderado += notaObtenida * numCreditos;
        }
    }
}
/*
 * Dado el archivo Cursos y el codigo de un curso,
 * devuelve el Numero de Creditos que vale ese curso
 */
float buscarNumeroCreditosEnCurso(FILE *Cursos, int codigoCurso) {
    //Declaracion de variables a utilizar en la funcion
    int cursoActual;
    float numeroCreditos;
    
    //Regresar al comienzo del archivo Cursos
    rewind(Cursos);
    while(1) {
        //Lectura del archivo
        fscanf(Cursos, "%d %f", &cursoActual, &numeroCreditos);
        //Condicion para salir de la iteracion
        if(feof(Cursos)) {
            return -1;
        }
        //Si el curso leido es el curso que buscabamos, retornar el numero de creditos
        if(cursoActual == codigoCurso) {
            return numeroCreditos;
        }        
    }
}

/*
 * Cierra los archivos
 */
void cerrarArchivos(FILE *Especialidades, FILE *Cursos, FILE *Alumnos, FILE *Notas, FILE *Reporte) {
    fclose(Especialidades);
    fclose(Cursos);
    fclose(Alumnos);
    fclose(Notas);
    fclose(Reporte);
}

/*
 * Dado una variable archivo, un caracter c, y un numero n,
 * escribe una linea de n caracteres, utlizando el caracter c
 */
void imprimirLinea(FILE *Archivo, char c, int width) {
    int i;
    for(i = 0; i < width; i++) {
        fprintf(Archivo, "%c", c);
    }
    fprintf(Archivo, "\n");
}

