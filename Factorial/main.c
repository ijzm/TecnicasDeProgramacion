#include <stdio.h>
#include <stdlib.h>

#include "FuncionesEstadisticas.h"

int main(int argc, char const *argv[]) {
	int fact;
	while(1) {
		scanf("%d", &	fact);
		if(fact == 0) {
			break;
		}
		printf("%d! = %d \n", fact, factorial(fact));
	}
	return 0;
}