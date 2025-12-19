#include "backsubst.h"
#include <stdlib.h>
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int backsubst(Matrix *x, Matrix *mat, Matrix *b) {
    int i, j;

    // Podstawowa walidacja czy wskaźniki i rozmiary są OK
    if (x == NULL || mat == NULL || b == NULL) return 2;

    // mat musi być kwadratowa, a b oraz x wektorami o zgodnych rozmiarach
    if (mat->r <= 0) return 2;
    if (mat->r != mat->c) return 2;
    if (b->c != 1 || x->c != 1) return 2;
    if (b->r != mat->r || x->r != mat->r) return 2;

    // Wsteczne podstawienie dla macierzy górnotrójkątnej
    for (i = mat->r - 1; i >= 0; --i) {
        double sum = b->data[i][0];

        for (j = i + 1; j < mat->c; ++j) {
            sum -= mat->data[i][j] * x->data[j][0];
        }

        if (mat->data[i][i] == 0.0) return 1;

        x->data[i][0] = sum / mat->data[i][i];
    }

    return 0;
}