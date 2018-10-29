#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX 20

int main(int argc, char const *argv[]) {
	srand(time(NULL));
	printf("Seed:\n%ld:\n", time(NULL));
	for (int i = 0; i < 10; ++i) {
		printf("%d ", rand() % 100);
	}
	printf("\n\n\n\n");

	int arr[MAX], pos, aux;
	for (int i = 0; i < MAX; ++i) {
		arr[i] = i;
	}
	//Desordenamos
	for (int j = MAX; j; j--) {
		pos = rand() % MAX;
		aux = arr[j - 1];
		arr[j - 1] = arr[pos];
		arr[pos] = aux;
	}

	for (int k = 0; k < MAX; ++k) {
		printf("%d ", arr[k]);
	}
	printf("\n");

	return 0;
}