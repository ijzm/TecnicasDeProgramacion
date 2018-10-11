#include <stdio.h>
#include <stdlib.h>

#include "Funciones.h"

#define MAX_CANDIDATOS 20

int main(int argc, char const *argv[]) {
	int candidatos[MAX_CANDIDATOS], votos[MAX_CANDIDATOS], numCandidatos, numVotos;
	float porcentajes[MAX_CANDIDATOS];

	leerCandidatos(candidatos, &numCandidatos);
	contarVotos(votos, numCandidatos, &numVotos);
	calculcarPorcentajes(votos, numCandidatos, numVotos, porcentajes);
	imprimirResultados(candidatos, votos, porcentajes, numCandidatos, numVotos);


	return 0;
}