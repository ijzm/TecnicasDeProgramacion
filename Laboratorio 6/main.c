/* 
 * File:   main.c
 * Author: Ignacio Javier Zevallos Morales
 * Codigo: 20171160
 *
 * Created on 27 de noviembre de 2018, 08:01 AM
 */

#include <stdio.h>
#include <stdlib.h>

#include "Cliente.h"
#include "Funciones.h"


int main(int argc, char** argv) {
    Cliente clientes[300];
    int numClientes;
    
    numClientes = leerClientes(clientes);
    imprimirClientes(clientes, numClientes);
    
    reescribirClientes(clientes, numClientes);
    
    printf("\n\n");
    
    leerMovimientos(clientes, numClientes);
    imprimirSaldos(clientes, numClientes);
    

    return (EXIT_SUCCESS);
}

