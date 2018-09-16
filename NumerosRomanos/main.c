#include <stdio.h>
#include <stdlib.h>

int getNum(char c);

int main(int argc, char const *argv[]) {
	FILE *Datos;
	char NumActual, NumAnterior;
	int Numero, Total=0;

	Datos = fopen("Datos.txt", "r");

	while (1) {
		Numero = 0;
		NumActual = fgetc(Datos);
		NumAnterior = 0;
		if(NumActual == -1) {
			break;
		}
		while (1) {
			NumAnterior = NumActual;
			NumActual = fgetc(Datos);

			if(NumActual == 10 || NumActual == -1) {
				Numero += getNum(NumAnterior);
				//fgetc(Datos);
				//printf("BREAK 1\n");
				break;
			}
			

			if(getNum(NumAnterior) < getNum(NumActual)){
				Numero -= getNum(NumAnterior);
			} else {
				Numero += getNum(NumAnterior);
			}
			//printf("%d %d\n", getNum(NumAnterior), getNum(NumActual));
			//printf("%c %c\n", NumAnterior, NumActual);
			//printf("%d \n", Numero);
		}

		printf("%d \n", Numero);
		Total += Numero;
	
	}

	printf("%d", Total);



	return 0;
}

int getNum(char c) {
	switch(c) {
		case 'I':
		return 1;
		break;
		case 'V':
		return 5;
		break;
		case 'X':
		return 10;
		break;
		case 'L':
		return 50;
		break;
		case 'C':
		return 100;
		break;
		case 'D':
		return 500;
		break;
		case 'M':
		return 1000;
		break;
		default:
		return 0;
		break;
	}
}