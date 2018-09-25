/* 
 * File:   main.c
 * Author: Ignacio Javier Zevallos Morales
 *
 * Created on 4 de septiembre de 2018, 09:01 AM
 * 
 * ******************************************************
 * Resumen: Hallar el Area y el Perimetro de un poligono.
 * ******************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv) {
    //Declaracion de variables a utilizar
    int x, y, x0, y0, xAnt, yAnt;
    int s1 = 0, s2 = 0, numLados = 0;
    float longLado;
    float area, perimetro = 0;
    
    printf("Ingrese las coordenadas del poligono: \n");    
    while(1) {
        //Recoleccion de datos del usuario
        scanf("%d %d", &x, &y);
        //Condicion para romper la iteracion principal
        if(x == 0 && y == 0) {
            break;
        }
        
        if(numLados == 0) {
            //Si es la primera iteracion, guardar los valores primeros valores
            //de x, y en x0, y0
            x0 = x;
            y0 = y;
        } else {
            //En las siguientes iteraciones acumular s1 y s2 segun la formula
            s1 += x * yAnt;
            s2 += y * xAnt;
            
            //Hallar la longitud del lado actual utilizando pitagoras
            //Acumular su resultado el la variable perimetro
            longLado = sqrt(pow(xAnt - x, 2) + pow(yAnt - y, 2));
            perimetro += longLado;
        }
        //Aumentar la variable para poder hallar el numero de lados
        numLados++;
        //Asignar las coordenadas anteriores para los calculos de la siguiente
        //iteracion.
        xAnt = x;
        yAnt = y;
    }
    
    //Acumulacion de s1 y s2, utilizando las primeras y ultimas coordenadas
    s1 += x0 * yAnt;
    s2 += y0 * xAnt;
    //Calculo del area
    area = (float)(s1 - s2)/2.0f;
    
    //Calculo de la longitud del lado actual. Utilizando las primeras y ultimas
    //coordenadas.
    //Terminar la acumulacion del perimetro
    longLado = sqrt(pow(xAnt - x0, 2) + pow(yAnt - y0, 2));
    perimetro += longLado;
    
    //Impresion de resultados
    printf("Resultados: \n");
    switch(numLados) {
        case 0:
        case 1:
            printf("El poligono tiene 0 lados \n");
            printf("No tiene area ni perimetro \n");
            break;
        case 2:
            printf("El poligono tiene 1 lados \n");
            printf("El poligono no tiene area \n");
            printf("Su perimetro es: %.2f \n", perimetro);
            break;
        default:
            printf("El poligono tiene %d lados \n", numLados);
            printf("Su area es: %.2f \n", area);
            printf("Su perimetro es: %.2f \n", perimetro);
            break;
    }    
    return (EXIT_SUCCESS);
}

