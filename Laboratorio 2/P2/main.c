/* 
 * File:    main.c
 * Author:  Ignacio Javier Zevallos Morales
 * Codigo:  20171160
 * Horario: 431
 * Aula:    V207
 *
 * *****************************************************************************
 * Descricion: Dado un archivo de texto (Texto.txt), se crea un nuevo archivo
 *             (TextoModificado.txt) donde la primera y ultima letra de cada 
 *             palabra sea mayuscula, y se eliminen multiples espacios
 * *****************************************************************************
 * 
 * Created on 18 de septiembre de 2018, 09:21 AM
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    //Declaracion de variables a utilizar
    FILE *Input, *Output;
    char cAnt, cAct, cSig, conv = 'A' - 'a';
    
    //Se abren los archivos a utilizar
    Input = fopen("Texto.txt", "r");
    Output = fopen("TextoModificado.txt", "w");
    
    //Se asegura que se hayan abierto los archivos correctamente
    //En caso contrario, arrojar un error y salir del programa;
    if(Input == NULL) {
        printf("ERROR: No se pudo abrir el archivo Texto.txt");
        return -1;
    }
    if(Output == NULL) {
        printf("ERROR: No se pudo abrir el archivo TextoModificado.txt");
        return -1;
    }
    
    //Se inician los valores a utilizar
    cAnt = ' ';
    cAct = fgetc(Input);
    cSig = fgetc(Input);
    
    //Iteracion Principal
    while (cSig != EOF) {
        
        //Se averigua si el caracter anterior es espacio, nueva linea o tabulacion
        //De ser asi, se prueba si el caracter es minuscula
        //De ser asi, imprimir el caracter en mayusculas, de no ser asi, imprimir
        //el caracter
        if(cAnt == ' ' || cAnt == '\n' || cAnt == '\t' ||
           cSig == ' ' || cSig == '\n' || cSig == '\t') {
            
            if(cAct >= 'a' && cAct <= 'z') {
                fputc(cAct + conv, Output);
            } else if(cAct == ' ' && (cAnt == ' ' || cAnt == '\n' || cAnt == '\t')) {
                //Si el caracter anterior es espacio, nueva linea o tabulacion
                //Y el caracter actual es un espacio, no se imprime
            } else {
                fputc(cAct, Output);
            }
        } else {
            fputc(cAct, Output);
        }     
        
        //Se hayan los nuevos valores
        cAnt = cAct;
        cAct = cSig;
        cSig = fgetc(Input);
    }   
    
    //Se cierran los archivos correctamente
    fclose(Input);
    fclose(Output);

    return (EXIT_SUCCESS);
}
