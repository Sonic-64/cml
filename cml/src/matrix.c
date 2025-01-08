
#include "matrix.h" 

matrix *start_matrix(int n_row, int n_col){
    
    matrix *mat = calloc(1,sizeof(matrix));
    mat->rows=n_row;
    mat->columns=n_col;
    mat->data=calloc(n_row*n_col,sizeof(int)); 
    return mat; 
}
void matrix_free(matrix *mat){
    free(mat->data);
    free(mat);
}
int *matrix_cell (matrix *mat ,int column ,int row  ){
   
    return &mat->data[row*mat->columns + column];
}
/*matrix *matrix_multiply(matrix *mat1, matrix *mat2){
    
if(mat1->columns != mat2->rows){
    return NULL;
}
matrix *mat_multiply = start_matrix(mat1->rows,mat2->columns)
for(int i = 0 ; i< mat_multiply->rows; i++){
    for(int j = 0 ; j <mat.multiply->columns ; j++){
matrix_cell(mat_multiply,i,j) = dot_product()
    }

}
}
*/