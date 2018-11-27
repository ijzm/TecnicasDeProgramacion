/* 
 * File:   Funciones.c
 * Author: Ignacio Javier Zevallos Morales
 * Codigo: 20171160
 *
 * Created on 27 de noviembre de 2018, 08:03 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cliente.h"
#include "Funciones.h"

int leerClientes(Cliente *clientes) {
    int num = 0;
    char *linea[3];
    
    FILE *ArchClientes = abrirArchivo("Clientes.csv", "r");
    char buffer[300];
    while(1){
        leerCadena(buffer, 300, ArchClientes);
        if(feof(ArchClientes)) {
            break;
        }
        separarCadena(linea, buffer, ',');

        clientes[num].Codigo = atoi(linea[0]);
        clientes[num].Nombre = linea[1];
        
        double tmp = atof(linea[2]);
        if(tmp >= 0) {
             clientes[num].Saldo = tmp;
             clientes[num].Estado = "";
        } else {
            clientes[num].Sobregiro = -tmp;
            clientes[num].Estado = "SOBREGIRO";
        }       
        free(linea[0]);
        free(linea[2]);
        
        num++;
    }
    fclose(ArchClientes);
    return num;
}

void imprimirClientes(Cliente *clientes, int max) {
    int i;
    for(i = 0; i < max; i++) {
        printf("%d %s\n", clientes[i].Codigo, clientes[i].Nombre);
    }
}

void leerMovimientos(Cliente *clientes, int max) {
    FILE *ArchMovimientos = abrirArchivo("MovimientosDecuenta.csv", "r");
    char buffer[300];
    char *linea[30];
    int numLineas;
    while(1){
        leerCadena(buffer, 300, ArchMovimientos);
        if(feof(ArchMovimientos)) {
            break;
        }
        numLineas = separarCadena(linea, buffer, ',');
        int i;
        for(i = 0; i < max; i++) {
            int clienteActual = atoi(linea[0]);
            if(clienteActual == clientes[i].Codigo) {
                int j;
                for(j = 1; j < numLineas; j += 2) {
                    
                    double valor = atof(linea[j + 1]);
                    
                    //RETIRO
                    if(strcmp(linea[j], "R") == 0) {
                        if(clientes[i].Saldo > 0) {
                            if(clientes[i].Saldo - valor >= 0) {
                                clientes[i].Saldo -= valor;
                            } else {
                                valor -= clientes[i].Saldo;
                                clientes[i].Saldo = 0;
                                clientes[i].Sobregiro += valor;
                            }
                        } else {
                            clientes[i].Sobregiro += valor;
                        }
                    }
                    //DEPOSITO
                    else {
                        if(clientes[i].Saldo >= 0) {
                            clientes[i].Saldo += valor;
                        } else {
                            if(clientes[i].Sobregiro - valor > 0) {
                                clientes[i].Sobregiro -= valor;
                            } else {
                                valor -= clientes[i].Sobregiro;
                                clientes[i].Sobregiro = 0;
                                clientes[i].Saldo += valor;
                            }
                        }
                    }
                }
                //free(linea[j]);
                //free(linea[j+1]);
            }
        }
    }
    
    determinarSobregiro(clientes, max);
    
    fclose(ArchMovimientos);
}

void determinarSobregiro(Cliente *clientes, int max) {
    int i;
    for(i = 0; i < max; i++) {
        if(clientes[i].Sobregiro > 0) {
            clientes[i].Estado = "SOBREGIRO";
        } else {
            clientes[i].Estado = "";
        }
    }
}

void imprimirSaldos(Cliente *clientes, int max) {
    int i;
    for(i = 0; i < max; i++) {
        if(clientes[i].Sobregiro > 0) {
            printf("%10d %40s %10.2f %s\n", clientes[i].Codigo, clientes[i].Nombre, clientes[i].Sobregiro, "SOBREGIRO");
        } else {
            printf("%10d %40s %10.2f\n", clientes[i].Codigo, clientes[i].Nombre, clientes[i].Saldo);
        }
    }
}

int separarCadena(char **linea, char *cadena, char separador) {
    char buffer[100];
    char c;
    int posicion = 0;
    int longitud = 0;
    int num = 0;
    while(1) {
        c = cadena[posicion];
        if(c == separador || c == '\0') {
            buffer[longitud] = '\0';
            linea[num] = malloc(sizeof(char) * (strlen(buffer) + 1));
            strcpy(linea[num], buffer);
            longitud = 0;
            num++;
            posicion++;
            if(c == '\0') {
                break;
            }
            continue;
        }
        buffer[longitud] = c;
        posicion++;
        longitud++;
    }
    return num;
}

FILE *abrirArchivo(char *path, char *args) {
    FILE *Arch = fopen(path, args);
    if(Arch == NULL) {
        printf("ERROR al abrir %s\n", path);
        exit(1);
    }
    return Arch;
}

void leerCadena(char *cadena, int max, FILE *Arch) {
    int longitud;
    fgets(cadena, max, Arch);
    longitud = strlen(cadena);
    if(cadena > 0) {
        cadena[longitud - 1] = '\0';
    }
}

void reescribirClientes(Cliente *clientes, int max) {
    printf("%lf\n",clientes[3].Saldo );
    FILE *Arch = abrirArchivo("ClientesNuevo.csv", "w");
    char *nuevoNombre[4];
    int i;
    for(i = 0; i < max; i++) {
        fprintf(Arch, "%d,", clientes[i].Codigo);
        separarCadena(nuevoNombre, clientes[i].Nombre, '/');
        fprintf(Arch, "%s/", nuevoNombre[1]);
        fprintf(Arch, "%s/", nuevoNombre[2]);
        fprintf(Arch, "%s,", nuevoNombre[0]);
        if(clientes[i].Saldo > 0) {
            fprintf(Arch, "%.2lf\n", clientes[i].Saldo);
        } else {
            fprintf(Arch, "-%.2lf\n", clientes[i].Sobregiro);
        }        
                
    }
}
