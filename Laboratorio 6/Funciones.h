/* 
 * File:   Funciones.h
 * Author: Ignacio Javier Zevallos Morales
 * Codigo: 20171160
 *
 * Created on 27 de noviembre de 2018, 08:03 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Cliente.h"

int leerClientes(Cliente *);
void imprimirClientes(Cliente *, int);
void leerMovimientos(Cliente *, int);
void determinarSobregiro(Cliente *, int);
void imprimirSaldos(Cliente *, int);
int separarCadena(char **, char *, char);
FILE *abrirArchivo(char *, char *);
void leerCadena(char *, int, FILE *);
void reescribirClientes(Cliente *, int);

#endif /* FUNCIONES_H */

