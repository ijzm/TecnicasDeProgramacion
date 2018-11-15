/* 
 * File:   FuncionesDeCadena.h
 * Author: Ignacio Javier Zevallos Morales
 * Codigo: 20171160
 *
 * Created on 13 de noviembre de 2018, 08:25 AM
 */

#ifndef FUNCIONESDECADENA_H
#define FUNCIONESDECADENA_H

char *leerFrase(char *, FILE *);
void nombrePropio(char *);
int subConjunto(char *, char *);
int encontrar(char *, char *);
void codigoAleatorio(char *, char *);

int hallarLongitud(char *);
char *copiarCadena(char *);
char *concatenar(char *, char *, int *, int);

#endif /* FUNCIONESDECADENA_H */

