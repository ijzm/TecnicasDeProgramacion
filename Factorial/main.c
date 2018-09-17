#include <stdio.h>
#include <stdlib.h>

#include "FuncionesEstadisticas.h"

int main(int argc, char const *argv[]) {
	
	printf("Factoriales: \n");
	int fact;
	while(1) {
		scanf("%d", &	fact);
		if(fact == 0) {
			break;
		}
		printf("%d! = %d \n", fact, factorial(fact));
	}
	
	printf("Combinaciones: \n");
	int n, p;
	scanf("%d %d", &n, &p);
	printf("Combinacion(%d,%d) = %d \n", n, p, combinacion(n,p));
	return 0;
}