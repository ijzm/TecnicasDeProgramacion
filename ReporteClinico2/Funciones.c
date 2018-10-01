#include "Funciones.h"

#define MAXWIDTH 64


void imprimirReporte(FILE *Consultas, FILE *Especialidades, FILE *Medicos, FILE *Pacientes, FILE *Reporte) {
	int distritoElegido = 11, especialidad, num = 1;
	//printf("Seleccionar Distrito: ");
	//scanf("%d", &distrito);

	fprintf(Reporte, "DISTRITO ELEGIDO: %d \n", distritoElegido);
	imprimirLinea(Reporte, '=', MAXWIDTH);


	while(1) {
		fscanf(Especialidades, "%d", &especialidad);
		if(feof(Especialidades)) {
			break;
		}
		printf("Especialidad: %d \n", especialidad);
		fprintf(Reporte, "%4d) Especialidad: %d \n", num, especialidad);
		buscarDoctores(distritoElegido, especialidad, Consultas, Pacientes, Medicos, Reporte);
		imprimirLinea(Reporte, '-', MAXWIDTH);
		num++;
		printf("\n");
	}
	return;
}

void buscarDoctores(int distritoElegido, int especialidad, FILE *Consultas, FILE *Pacientes, FILE *Medicos, FILE *Reporte) {
	int dniDoctor, especialidadActual;
	float precio, gananciaTotal = 0;

	float mayorGanancia = 0, menorGanancia = 9999999;
	int mayorDoctor, menorDoctor;

	rewind(Medicos);
	while(1) {
		fscanf(Medicos, "%d %d %f", &dniDoctor, &especialidadActual, &precio);
		if(feof(Medicos)) {
			break;
		}
		if(especialidadActual == especialidad) {
			printf("	Medico: %d \n", dniDoctor);
			gananciaTotal = buscarGanancias(precio, dniDoctor, distritoElegido, Consultas, Pacientes);
			if(gananciaTotal > mayorGanancia) {
				mayorGanancia = gananciaTotal;
				mayorDoctor = dniDoctor;
			}
			if(gananciaTotal != 0) {
				if(gananciaTotal < menorGanancia) {
					menorGanancia = gananciaTotal;
					menorDoctor = dniDoctor;
				}
			}
			printf("		Ganancia Total: %f", gananciaTotal);
			printf("\n");
		}
	}

	if(gananciaTotal != 0) {
		fprintf(Reporte, "Medico que mas gano:   %8d        Monto Ganado: %10.2f \n",
		mayorDoctor, mayorGanancia);
		fprintf(Reporte, "Medico que menos gano: %8d        Monto Ganado: %10.2f \n",
		menorDoctor, menorGanancia);
	}

}

float buscarGanancias(float precio, int dniDoctor, int distritoElegido, FILE *Consultas, FILE *Pacientes) {
	float gananciaTotal = 0;
	int dniPaciente, distritoActual, telefono;
	rewind(Pacientes);
	while(1) {
		fscanf(Pacientes, "%d %d %d", &dniPaciente, &distritoActual, &telefono);
		if(feof(Pacientes)) {
			break;
		}
		if(distritoActual == distritoElegido){
			gananciaTotal += buscarConsultas(precio, dniPaciente, dniDoctor, Consultas);
		}
	}
	return gananciaTotal;
}

float buscarConsultas(float precio, int dniPaciente, int dniDoctor, FILE *Consultas) {
	float gananciaTotal = 0;
	int dniP, dniD;
	rewind(Consultas);
	while(1) {
		fscanf(Consultas, "%d %d", &dniP, &dniD);
		if(feof(Consultas)) {
			break;
		}
		if(dniP == dniPaciente && dniD == dniDoctor) {
			gananciaTotal += precio;
		}
	}
	return gananciaTotal;
}

void cerrarArchivos(FILE *Consultas, FILE *Especialidades, FILE *Medicos, FILE *Pacientes, FILE *Reporte) {
	fclose(Consultas);
	fclose(Especialidades);
	fclose(Medicos);
	fclose(Pacientes);
	fclose(Reporte);
}

void imprimirLinea(FILE *Archivo, char c, int width){
	for (int i = 0; i < width; ++i) {
		fprintf(Archivo, "%c", c);
	}
	fprintf(Archivo, "\n");
}