#include <stdio.h>
#include <stdlib.h>

#include "Funciones.h"

#define MAX_CHAR 60

void leerCandidatos(int *candidatos, int *numCandidatos) {
	FILE *ArchCandidatos;
	ArchCandidatos = fopen("Candidatos.txt", "r");
	if(ArchCandidatos == NULL) {
		printf("ERROR: No se pudo abir Candidatos.txt");
		exit(1);
	}

	*numCandidatos = 0;
	while(1) {
		fscanf(ArchCandidatos, "%d", &candidatos[*numCandidatos]);
		if(feof(ArchCandidatos)) {
			break;
		}
		(*numCandidatos)++;
	}

	fclose(ArchCandidatos);
}

void contarVotos(int *votos, int numCandidatos, int *numVotos) {
	FILE *ArchVotos;
	ArchVotos = fopen("Votos.txt", "r");
	if(ArchVotos == NULL) {
		printf("ERROR: No se pudo abir Votos.txt");
		exit(1);
	}

	for (int i = 0; i < numCandidatos; ++i)	{
		votos[i] = 0;
	}

	int votoActual;
	*numVotos = 0;
	while(1) {
		fscanf(ArchVotos, "%d", &votoActual);
		if(feof(ArchVotos)) {
			break;
		}
		if(votoActual >= 1 && votoActual <= numCandidatos) {
			votos[votoActual - 1]++;
		}
		(*numVotos)++;
	}

	fclose(ArchVotos);
}

void calculcarPorcentajes(int *votos, int numCandidatos, int numVotos, float *porcentajes) {
	for (int i = 0; i < numCandidatos; ++i)	{
		porcentajes[i] = ((float)votos[i] / numVotos) * 100;
	}
}

void imprimirResultados(int *candidatos, int *votos, float *porcentajes, int numCandidatos, int numVotos) {
	int maxVotos, numChar;
	
	maxVotos = calcularMaximo(votos, numCandidatos);

	printf("Numero Candidatos: %3d   Numero de Votos: %3d \n", numCandidatos, numVotos);
	for (int i = 0; i < numCandidatos; ++i)	{
		printf("%6d:   %4d    %5.2f%%   ", candidatos[i], votos[i], porcentajes[i]);

		printf("|");
		numChar = votos[i] * MAX_CHAR / maxVotos;
		for (int j = 0; j < numChar; ++j) {
			printf("*");
		}
		printf("\n");

	}
}

int calcularMaximo(int *votos, int numCandidatos) {
	int max = 0;
	for (int i = 0; i < numCandidatos; ++i)	{
		if(votos[i] > max) {
			max = votos[i];
		}
	}

	return max;
}