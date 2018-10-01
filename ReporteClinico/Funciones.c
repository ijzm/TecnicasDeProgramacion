#include "Funciones.h"

#define MAXWIDTH 60

void imprimirReporte(FILE *Consultas, FILE *Especialidades, FILE *Medicos, FILE *Pacientes, FILE *Reporte) {
	fprintf(Reporte, "GASTOS POR PACIENTE: \n");
	imprimirLinea(Reporte, '=', MAXWIDTH);

	determinarGastosPorEspecialidad(Consultas, Especialidades, Medicos, Pacientes, Reporte);
}

void determinarGastosPorEspecialidad(FILE *Consultas, FILE *Especialidades, FILE *Medicos, FILE *Pacientes, FILE *Reporte) {
	int num = 1, dni, distrito, telefono;

	while(1) {
		fscanf(Pacientes, "%d %d %d", &dni, &distrito, &telefono);

		printf("%d: \n", num);

		if(feof(Pacientes)) {
			printf("BREAK: determinarGastosPorEspecialidad \n");
			break;
		}

		fprintf(Reporte, "%3d) Paciente: %d \n", num, dni);
		fprintf(Reporte, "     Distrito: %d \n", distrito);
		fprintf(Reporte, "     Telefono: %d \n", telefono);

		imprimirLinea(Reporte, '-', MAXWIDTH);
		fprintf(Reporte,    "ESPECIALIDAD   GASTO TOTAL \n");
		imprimirLinea(Reporte, '-', MAXWIDTH);


		imprimirGastosPaciente(dni, Consultas, Especialidades, Medicos, Pacientes, Reporte);


		num++;
	}
}

void imprimirGastosPaciente(int dni, FILE *Consultas, FILE *Especialidades, FILE *Medicos, FILE *Pacientes, FILE *Reporte) {
	int especialidad;
	char letra = 'a';
	float gasto;
	
	printf(" imprimirGastosPaciente \n");

	rewind(Especialidades);
	while(1) {
		fscanf(Especialidades, "%d", &especialidad);
		if(feof(Especialidades)) {
			printf("BREAK : imprimirGastosPaciente \n");
			break;
		}

		gasto = determinarGastosParaEspecialidad(dni, especialidad, Medicos, Consultas);
		printf("DNI: %d, Especialidad %d, Gasto: %f \n", dni, especialidad, gasto);
		if(gasto > 0) {
			fprintf(Reporte, "     %c)  %d    %f \n", letra, especialidad, gasto);
			letra++;
		}

	}
}

float determinarGastosParaEspecialidad(int dni, int especialidad, FILE *Medicos, FILE *Consultas) {
	rewind(Consultas);

	int dniActual, dniMedico;
	float gasto = 0;
	while(1) {
		fscanf(Consultas, "%d %d", &dniActual, &dniMedico);
		if(feof(Consultas)) {
			
			break;
		}
		if(dniActual == dni) {
			gasto += buscarPrecio(dniMedico, especialidad, Medicos);
		}

	}

	return gasto;
}

int buscarDniDoctor(FILE *Consultas, int dni) {
	int dniActual, dniDoctor;

	while(1) {
		fscanf(Consultas, "%d %d", &dniActual, &dniDoctor);
		if(feof(Consultas)){
			return -1;
		}

		if(dniActual == dni) {
			return dniDoctor;
		}
	}
}

float buscarPrecio(int dniMedico, int especialidad, FILE *Medicos) {
	float precio;
	int dniActual, especialidadActual;

	rewind(Medicos);

	while(1) {
		fscanf(Medicos, "%d %d %f", &dniActual, &especialidadActual, &precio);
		if(feof(Medicos)) {
			return -1;
		}

		if(especialidadActual == especialidad && dniActual == dniMedico) {
			return precio;
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