#include "gauss.h"
#include <stdio.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    /*
  	Tutaj nalezy umiescic wlasciwa implemntacje.
	*/

	for(int i=0; i<mat->r; i++){
		if(mat->data[i][i]==0.0){
			fprintf(stderr,"!!! Blad: macierz osobliwa - dzielenie przez 0.\n");
			return 1;
		}
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