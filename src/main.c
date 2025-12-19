#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {
	int res, fail = 0;
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x;

	if (A == NULL) return -1;
	if (b == NULL) return -2;
	printf("Macierz A:\n");
	printToScreen(A);
	printf("\nMacierz b:\n");
	printToScreen(b);

	res = eliminate(A,b);
	printf("\nSchodkowanie:\n");
	printToScreen(A);
	
	x = createMatrix(b->r, 1);
	if (x != NULL) {
		res = backsubst(x,A,b);
		if (res == 0) {
			printf("\nPodstawienie wsteczne:\n");
			printToScreen(x);
		} else if (res == 1) {
			fprintf(stderr,"\nBlad dzielenia przez 0! Nie moglem dokonac podstawienia wstecznego.\n");
			fail = 1;
		} else if (res == 2) {
			fprintf(stderr,"\nBlad nieprawidlowych rozmiarow macierzy! Nie moglem dokonac podstawienia wstecznego.\n");
			fail = 1;
		}
		freeMatrix(x);
	} else {
		fprintf(stderr,"\nBlad! Nie moglem utworzyc wektora wynikowego x.\n");
		fail = 1;
	}

	freeMatrix(A);
	freeMatrix(b);
	if (fail == 0) {
		return EXIT_SUCCESS;
	} else {
		return EXIT_FAILURE;
	}
}