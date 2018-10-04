/* 
 * File:   Funciones.h
 * Author: Ignacio Javier Zevallos Morales
 * 
 * *****************************************************************************
 * Descripcion: Archivo cabezera para la declaracion de funciones a utilizar en 
 *              el programa
 * *****************************************************************************
 *
 * Created on 2 de octubre de 2018, 08:03 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void imprimirReporte(FILE *, FILE *, FILE *, FILE *, FILE *);
void imprimirNotas(FILE *, FILE *, FILE *, FILE *, FILE *);
float buscarMinimoCreditosRequeridos(FILE *, int);
void buscarCreditos(FILE *, FILE *, int, float *, float *, float *);
float buscarNumeroCreditosEnCurso(FILE *, int);

void cerrarArchivos(FILE *, FILE *, FILE *, FILE *, FILE *);
void imprimirLinea(FILE *, char, int);

#endif /* FUNCIONES_H */

