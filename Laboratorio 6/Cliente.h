/* 
 * File:   Cliente.h
 * Author: Ignacio Javier Zevallos Morales
 * Codigo: 20171160
 *
 * Created on 27 de noviembre de 2018, 08:05 AM
 */

#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct Cliente {
    int Codigo;
    char *Nombre;
    double Saldo;
    double Sobregiro;
    char *Estado;
} Cliente;

#endif /* CLIENTE_H */

