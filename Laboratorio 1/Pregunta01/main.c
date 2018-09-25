/* 
 * File:   main.c
 * Author: Ignacio Javier Zevallos Morales
 *
 * Created on 4 de septiembre de 2018, 08:09 AM
 * 
 * **************************************************************
 * Resumen: Permite calcular el area bajo una curva y su longitud
 * **************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PRECISION 0.001

int main(int argc, char** argv) {
    double a, b, c, d, e, f;
    double limiteInf, limiteSup, h, x1, x2, y1, y2;
    int numIntervalos=0, intervalo;
    double area=0.0, areaAnt, longitud=0.0, longitudAnt;
    
    //Ingresamos los coeficientes de la ecuación:
    printf("Ingrese los coeficientes a, b, c, d, e, f: ");
    scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &e, &f);
    
    /* Ingresamos los limites entre los que queremos calcular
       el area y la longitud de la curva:
     */
    printf("Ingrese los limites: ");
    scanf("%lf %lf", &limiteInf, &limiteSup);
    /* Calculamos el área y longitud de la curva para diferentes
       números de franjas
     */
    
    do {
        areaAnt = area;
        longitudAnt = longitud;
        area = longitud = 0;
        numIntervalos++;
        h = (limiteSup - limiteInf)/numIntervalos;
        x1 = limiteInf;
        for(intervalo = 0; intervalo<numIntervalos; intervalo++) {
            x2 = x1 + h;
            y1 = a*pow(x1,5) + b*pow(x1,4) + c*pow(x1, 3) +
                 d*pow(x1,2) + e*x1 + f;
            
             y2 = a*pow(x2,5) + b*pow(x2,4) + c*pow(x2, 3) +
                  d*pow(x2,2) + e*x2 + f;
             area += (y1+y2)*h/2;
             longitud += sqrt(pow(y2-y1,2) + pow(h,2));
             x1 = x2;
        }
        /* Salimos del while cuando no hay diferencia entre el
         * cálculo de dos áreas seguidas y el calculo de dos
         * longitudes seguidas.
         */
    } while (fabs(area-areaAnt) >= PRECISION &&
             fabs(longitud-longitudAnt)>= PRECISION);
    
    //Mostramos los resultados:
    printf("Area bajo la curva   = %12.4lf\n", area);
    printf("Longitud de la curva = %12.4lf\n", longitud);    
    
    return (EXIT_SUCCESS);
}

