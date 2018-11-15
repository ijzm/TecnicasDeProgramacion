/* 
 * File:   main.c
 * Author: Ignacio Javier Zevallos Morales
 * Codigo: 20171160
 *
 * Created on 13 de noviembre de 2018, 08:01 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Funciones.h"

#define MAX_EMPLEADOS 500
#define MAX_BONOS 20

int main(int argc, char** argv) {
    srand(time(NULL));
    int empleados[MAX_EMPLEADOS], numEmpleados;
    float bonos[MAX_BONOS], numBonos;
    
    numBonos = leerBonos(bonos);
    numEmpleados = leerEmpleados(empleados);
    
    determinarBonos(bonos, numBonos, empleados, numEmpleados);

    return (EXIT_SUCCESS);
}

