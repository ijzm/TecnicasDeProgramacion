#include <stdio.h>
#include <stdlib.h>

#define LINEWIDTH 80

void printSeparator(FILE *Archivo, char c);

int main(int argc, char const *argv[]) {
	FILE *ArchivoDatos, *ArchivoReporte;
	int CodigoEmpresa, Telefono, Pais, Ciudad;
	float Tiempo, Costo, GastoTotal = 0;
	int c;	
	ArchivoDatos = fopen("LlamadasTelefonicas.txt", "r");
	if(ArchivoDatos == NULL) {
		printf("Error: No se pudo abrir LlamadasTelefonicas.txt");
		exit(1);
	}
	ArchivoReporte = fopen("Reporte.txt", "w");
	if(ArchivoReporte == NULL) {
		printf("Error: No se pudo abrir Reporte.txt");
		exit(1);
	}

	fprintf(ArchivoReporte, "Registro de llamadas de la corporación por empresa \n");


	while(1) {
		GastoTotal = 0;
		printSeparator(ArchivoReporte, '=');

		fscanf(ArchivoDatos, "%d", &CodigoEmpresa);
		fprintf(ArchivoReporte, "Código de la empresa: %d \n", CodigoEmpresa);
		printSeparator(ArchivoReporte, '-');
		fprintf(ArchivoReporte, "LLAMADAS REALIZADAS: \n");
		fprintf(ArchivoReporte, "TELÉFONO    TIEMPO DE LLAMADA (seg)    PAÍS    COSTO \n");
		printSeparator(ArchivoReporte, '-');

		while(1) {	
			fscanf(ArchivoDatos, "%8d%3d%3d %f", &Telefono, &Pais, &Ciudad, &Tiempo);

			fprintf(ArchivoReporte, "%d     ", Telefono);
			fprintf(ArchivoReporte, "%5.1f     ", Tiempo);
			fprintf(ArchivoReporte, "%3d     ", Pais);

			if(Pais == 51) {
				Costo = 0.9f * Tiempo;
			} else if(Pais >= 1 && Pais <= 99) {
				Costo = 5.25 * Tiempo;
			} else if(Pais > 99) {
				Costo = 10.75 * Tiempo;
			}
			GastoTotal += Costo;

			fprintf(ArchivoReporte, "%7.2f \n", Costo);
			c = fgetc(ArchivoDatos);
			if(c == 13) {
				fgetc(ArchivoDatos);
				break;
			}
		}

		printSeparator(ArchivoReporte, '-');
		fprintf(ArchivoReporte, "Gasto total: %.2f \n", GastoTotal);
		printSeparator(ArchivoReporte, '=');
		fprintf(ArchivoReporte, "\n");

		c = fgetc(ArchivoDatos);

		if( feof(ArchivoDatos)) {
			break;
		}
	}

	fclose(ArchivoReporte);
	fclose(ArchivoDatos);

	return 0;
}

void printSeparator(FILE *Archivo, char c) {
	for (int i = 0; i < LINEWIDTH; ++i)	{
		fprintf(Archivo, "%c", c);
	}
	fprintf(Archivo, "\n");
}