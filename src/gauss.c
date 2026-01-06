#include "gauss.h"
#include <stdio.h>
#include <math.h> // korzystanie z funk. fabs()

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	
	for(int i=0; i<mat->r; i++){
		
		// Wybor najwiekszego elementu z kolumny
		int maxi= i;
		for(int j=i+1; j<mat->r; j++){
			if(fabs(mat->data[j][i]) > fabs(mat->data[maxi][i])){
				maxi = j;
			}
		}
		if(mat->data[maxi][i]==0.0){ // jesli wszystkie elementy w kolumnie to 0, pomin te kolumne
			continue;
		}
		// Zamiana wierszy
		double * copy = mat->data[i];
		double * copyb = b->data[i];
		mat->data[i] = mat->data[maxi];
		b->data[i] = b->data[maxi];
		mat->data[maxi] = copy;
		b->data[maxi] = copyb;
		// Eliminacja Gaussa
		// ...
		for(int j=i+1; j<mat->r; j++){
			double w = mat->data[j][i]/mat->data[i][i];
			for(int k=i; k<=mat->c; k++){
				if (k==mat->c){
					b->data[j][0] = b->data[j][0] - w*b->data[i][0];
				} else {
					mat->data[j][k] = mat->data[j][k] - w*mat->data[i][k];
				}
				
			}
		}
	}


	return 0;
}

