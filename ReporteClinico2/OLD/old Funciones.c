#include "Funciones.h"

#define MAXWIDTH 60

void imprimirReporte(FILE *Consultas, FILE *Especialidades, FILE *Medicos, FILE *Pacientes, FILE *Reporte) {
	int distritoElegido = 11, especialidad;
	//printf("Seleccionar Distrito: ");
	//scanf("%d", &distrito);

	fprintf(Reporte, "DISTRITO ELEGIDO: %d \n", distritoElegido);
	imprimirLinea(Reporte, '=', MAXWIDTH);


	while(1) {
		fscanf(Especialidades, "%d", &especialidad);
		if(feof(Especialidades)) {
			break;
		}
		buscarPacientes(distritoElegido, especialidad, Consultas, Pacientes, Medicos, Reporte);
	}
	return;
}

void buscarPacientes(int distritoElegido, int especialidad, FILE *Consultas, FILE *Pacientes, FILE *Medicos, FILE *Reporte) {
	int dni, distritoActual, telefono;

	int mayorDoctor;
	float mayorGanancia = 0;

	rewind(Pacientes);
	while(1) {
		fscanf(Pacientes, "%d %d %d", &dni, &distritoActual, &telefono);
		if(feof(Pacientes))  {
			break;
		}
		if(distritoActual == distritoElegido) {
			buscarMayorGanancia(&mayorDoctor, &mayorGanancia, dni, especialidad, Medicos, Consultas);
		}
	}
}

void buscarMayorGanancia(int *mayorDoctor,float *mayorGanancia, int dni, int especialidad,FILE *Medicos,FILE *Consultas) {
	int dniActual, dniDoctor;
	rewind(Consultas);
	while(1) {
		fscanf(Consultas, "%d %d", &dniActual, &dniDoctor);
		if(dniActual == dni) {
			
		}
	}
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