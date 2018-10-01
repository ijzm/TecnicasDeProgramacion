#include <stdio.h>
#include <stdlib.h>

#include "Funciones.h"

int main(int argc, char const *argv[]) {
	FILE *Consultas, *Especialidades, *Medicos, *Pacientes, *Reporte;

	Consultas = fopen("Consultas.txt", "r");
	Especialidades = fopen("Especialidades.txt", "r");
	Medicos = fopen("Medicos.txt", "r");
	Pacientes = fopen("Pacientes.txt", "r");
	Reporte = fopen("Reporte.txt", "w");

	if(Consultas == NULL) {
		printf("ERROR: Consultas.txt no se pudo abrir");
	}

	if(Especialidades == NULL) {
		printf("ERROR: Especialidades.txt no se pudo abrir");
	}

	if(Medicos == NULL) {
		printf("ERROR: Medicos.txt no se pudo abrir");
	}

	if(Pacientes == NULL) {
		printf("ERROR: Pacientes.txt no se pudo abrir");
	}

	if(Reporte == NULL) {
		printf("ERROR: Reporte.txt no se pudo abrir");
	}


	imprimirReporte(Consultas, Especialidades, Medicos, Pacientes, Reporte);
	cerrarArchivos(Consultas, Especialidades, Medicos, Pacientes, Reporte);


	return 0;
}