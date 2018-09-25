/* 
 * File:    main.c
 * Author:  Ignacio Javier Zevallos Morales
 * Codigo:  20171160
 * Horario: 431
 * Aula:    V207
 *
 * *****************************************************************************
 * Descripcion: Elabora un Reporte bancario, con los datos ingresados en los
 *              archivos MovimientosEnCuenta.txt y DatosIniciales.txt
 * *****************************************************************************
 * 
 * Created on 18 de septiembre de 2018, 08:17 AM
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    //Declaracion de variables a utilizar en el programa:    
    FILE *Movimientos, *DatosIniciales, *Reporte;
    int numCuenta, dia, mes, ano, hora, minuto, segundo;
    int horaAnt, minutoAnt, segundoAnt, horaTemp, minutoTemp, segundoTemp;
    int tiempoAct, tiempoAnt, tiempoTrans, tipoMov, tipoMon;
    float saldoInicial, monto, saldoActual, tipoDeCambio, montoMinimo;
    
    //Abrir los archivos a utilizar
    Movimientos = fopen("MovimientosEnCuenta.txt", "r");
    DatosIniciales = fopen("DatosIniciales.txt", "r");
    Reporte = fopen("Reporte.txt", "w");
    
    //Se asegura que los archivos se hayan abierto correctamente, de caso contrario
    //se arroja un error al usuario
    if(Movimientos == NULL) {
        printf("ERROR: No se pudo abrir el archivo MovimientosEnCuenta.txt");
        return -1;
    }
    if(DatosIniciales == NULL) {
        printf("ERROR: No se pudo abrir el archivo DatosIniciales.txt");
        return -1;
    }
    if(Reporte == NULL) {
        printf("ERROR: No se pudo abrir el archivo Reporte.txt");
        return -1;
    }
    
    //Se leen los datos iniciales
    fscanf(DatosIniciales, "%f %f", &tipoDeCambio, &montoMinimo);
    //Se leen el Numero de Cuenta y el Saldo Inicial
    fscanf(Movimientos, "%d %f", &numCuenta, &saldoInicial);
    
    //Se imprime el encabezado del Reporte
    fprintf(Reporte, "Banco ABC \n");
    fprintf(Reporte, "Estado de cuenta numero: %d \n", numCuenta);
    fprintf(Reporte, "Tipo de cambio: $==S/. %.2f \n", tipoDeCambio);
    fprintf(Reporte, "\n");
    fprintf(Reporte, "Movimientos Realizados: \n");
    fprintf(Reporte, "Saldo Inicial:           S/. %10.2f\n", saldoInicial);
    fprintf(Reporte, "\n");
    
    //Se inicializa la variable saldoInicial
    saldoActual = saldoInicial;
    
    //Iteracion Principal
    while (1) {
        //Se leen y guarda el dia, mes y año segun su variable correspondiente
        fscanf(Movimientos, "%d/%d/%d", &dia, &mes, &ano);
        
        //Condicion para romper la iteracion
        if(feof(Movimientos)) {
            break;
        }
        
        //Se imprime la fecha y el encabezado de las columnas
        fprintf(Reporte, "Fecha: %d/%d/%d \n", dia, mes, ano);
        fprintf(Reporte, "TIEMPO TRANSCURRIDO     MONTO DE OPERACION     SALDO S/.     OBSERVACION \n");
        
        //Se inicializan las variables anteriores
        horaAnt = minutoAnt = segundoAnt = 0;
        
        //Segunda Iteracion
        while(1) {
            //Se leen y guardan las horas, minutos y segundos de la transaccion
            fscanf(Movimientos, "%d:%d:%d", &hora, &minuto, &segundo);
            
            //Condicion para romper la iteracion
            if(hora == -1 || minuto == -1 || segundo == -1) {
                break;
            }
            
            //Se Imprime el espaciado
            fprintf(Reporte, "     ");
            
            //Se calcula el tiempo transcurrido entre la ultima transaccion
            tiempoAnt = horaAnt * 60 * 60 + minutoAnt * 60 + segundoAnt;
            tiempoAct = hora * 60 * 60 + minuto * 60 + segundo;
            
            tiempoTrans = tiempoAct - tiempoAnt;
            
            //Se pone el Tiempo Transcurrido en el formato correspondiente
            horaTemp = tiempoTrans / 3600;
            tiempoTrans -= horaTemp * 3600;
            minutoTemp = tiempoTrans / 60;
            tiempoTrans -= minutoTemp * 60;
            segundoTemp = tiempoTrans;
            
            //Se imprimen los valores calculados anteriormente
            fprintf(Reporte, "%02d:%02d:%02d", horaTemp, minutoTemp, segundoTemp);
            
            //Se Imprime el espaciado
            fprintf(Reporte, "             ");
            
            //Se leen y guardan el Tipo de Movimiento, Tipo de Moneda y Monto
            fscanf(Movimientos, "%d %d %f", &tipoMov, &tipoMon, &monto);
            //Logica para Imprimir los valores al archivo de Reporte:
            if(tipoMon) {
                fprintf(Reporte, "$  ");                
            } else {
                fprintf(Reporte, "S/.");
            }
            
            if(tipoMov) {
                fprintf(Reporte, "(%10.2f)", monto);
                //Si es un retiro, el monto se pone negativo despues de ser impreso
                monto *= -1; 
            } else {
                fprintf(Reporte, " %10.2f ", monto);
            }
            
            //Se Imprime el espaciado
            fprintf(Reporte, "     ");
            
            //Si el Tipo de Moneda es dolares, se haya el nuevo valor del monto,
            //Convertido a dolares
            if(tipoMon) {
                monto *= tipoDeCambio;
            }
            
            //Se calcula el nuevo saldo actual y se imprime con el formato correspondiente
            saldoActual += monto;
            
            if(saldoActual >= 0) {
                fprintf(Reporte, " %10.2f ", saldoActual);
            } else {
                fprintf(Reporte, "(%10.2f)", -saldoActual);
            }
            
            //Se Imprime el espaciado
            fprintf(Reporte, "    ");
            
            //Logica para imprimir las Observaciones
            if(saldoActual < 0) {
                fprintf(Reporte, "SOBREGIRO");
            } else if(saldoActual < montoMinimo) {
                fprintf(Reporte, "MENOR AL MINIMO");
            }
            
            fprintf(Reporte, "\n");
            
            //Se guardan los valores anteriores
            horaAnt = hora;
            minutoAnt = minuto;
            segundoAnt = segundo;
        }
        
        fprintf(Reporte, "\n");
    }
    
    //Se cierran los archivos correctamente
    fclose(Movimientos);
    fclose(DatosIniciales);
    fclose(Reporte);
    
    //Se sale del programa
    return (EXIT_SUCCESS);
}

