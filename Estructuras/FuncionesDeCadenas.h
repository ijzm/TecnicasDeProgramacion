#ifndef FUNCIONES_DE_CADENAS_H
#define FUNCIONES_DE_CADENAS_H

char *leerCadena(char *, int, FILE *);
char *leerCadenaExacta(FILE *);
FILE *leerArchivo(const char *, const char *);
int sacaPalabras(char *, char **);
int sacaPalabrasCSV(char *, char **);
void liberarEspacios(char **, int);

#endif