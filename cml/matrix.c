#include <stdlib.h>
#include <assert.h>
#include "matrix.h" 
matrix startmatrix(int n_row, int n_col){
    assert(n_row>0 && n_col>0);
    matrix mat;
    mat.rows=n_row;
    mat.columns=n_col;
    mat.data=calloc(n_row*n_col,sizeof(int)); /* allocate memory and clear to zero */
    return mat; /* return copy of mat */
}

int *matrix_cell (matrix mat ,int column ,int row  ){
    assert(column < mat.columns && row < mat.rows);
    return &mat.data[row*mat.columns + column];
}
int matrix_multiply(matrix mat1, matrix mat2){



    
}