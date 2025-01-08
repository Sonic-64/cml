#ifndef MATRIX_H
#include <stdlib.h>
typedef struct matrix {
    int rows;
    int columns;
    int *data;
}matrix;

matrix *startmatrix(int n_row, int n_col);
void matrix_free(matrix *mat);
int *matrix_cell (matrix *mat ,int column ,int row  );
#define MATRIX_H
#endif