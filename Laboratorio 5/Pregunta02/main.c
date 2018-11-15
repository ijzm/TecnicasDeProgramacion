/* 
 * File:   main.c
 * Author: Ignacio Javier Zevallos Morales
 * Codigo: 20171160
 *
 * Created on 13 de noviembre de 2018, 08:25 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "FuncionesDeCadena.h"

int main(int argc, char** argv) {
    srand(time(NULL));
    
    char *cadenaLeerFrase;
    FILE *Arch = fopen("Frase.txt", "r");
    if(Arch == NULL) {
        printf("ERROR: Al abrir el archivo Frase.txt\n");
        exit(1);
    }
    cadenaLeerFrase = leerFrase(cadenaLeerFrase, Arch);
    
    printf("%s\n", cadenaLeerFrase);
            
    printf("\n");
    
    
    
    char cadenaNombrePropio[100] =  "su COrrEO erA juaN1244@pucp.edu.pe PERO lo CaNcElO";
    
    printf("Cadena Original: %s\n", cadenaNombrePropio);
    
    nombrePropio(cadenaNombrePropio);
    printf("Cadena Final   : %s\n", cadenaNombrePropio);
    
    printf("\n");


    char *cadena1SubConjunto = "Juan $#3 Perez", *cadena2SubConjunto = "3eJP#";
    int outputSubConjunto = subConjunto(cadena1SubConjunto, cadena2SubConjunto);
    
    printf("Cadena 1: %s\n", cadena1SubConjunto);
    printf("Cadena 2: %s\n", cadena2SubConjunto);
    printf("Retorno : %d\n", outputSubConjunto);
    
    printf("\n");
    
    char *cadena3SubConjunto = "aEJPx";
    outputSubConjunto = subConjunto(cadena1SubConjunto, cadena3SubConjunto);
    
    printf("Cadena 1: %s\n", cadena1SubConjunto);
    printf("Cadena 2: %s\n", cadena3SubConjunto);
    printf("Retorno : %d\n", outputSubConjunto);
    
    printf("\n");

    
    char *cadena1Encontrar = "Juan Carlos Lopez Perez", *cadena2Encontrar = "Lopez";
    int outputEncontrar = encontrar(cadena1Encontrar, cadena2Encontrar);
    
    printf("Cadena 1: %s\n", cadena1Encontrar);
    printf("Cadena 2: %s\n", cadena2Encontrar);
    printf("Retorno : %d\n", outputEncontrar);
    
    printf("\n");
    
    char *cadena3Encontrar = "Maria";
    outputEncontrar = encontrar(cadena1Encontrar, cadena3Encontrar);
    printf("Cadena 1: %s\n", cadena1Encontrar);
    printf("Cadena 2: %s\n", cadena3Encontrar);
    printf("Retorno : %d\n", outputEncontrar);
    
    printf("\n");
    
    char codigo[11], *cadenaCodigo = "#$%&!";   
    codigoAleatorio(codigo, cadenaCodigo);
    printf("Codigo: %s\n", codigo);

    return (EXIT_SUCCESS);
}

