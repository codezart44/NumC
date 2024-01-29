//matrix.h

#ifndef MATRIX_H
#define MATRIX_H

#include "../config.h"


typedef struct Matrix {
    int dimensions;
    int size;
    int shape[2];
    double values[MAXIMUM_LENGTH][MAXIMUM_LENGTH];      //values stored contiguously
} Matrix;


extern void print_matrix(Matrix *pA);
double maximum_matrix_value(Matrix *pA);

extern Matrix create_matrix_from_array(double* values, int rows, int cols);
extern Matrix create_matrix(int rows, int cols);

extern Matrix matrix_multiplication(Matrix *pA, Matrix *pB);

extern void transpose_matrix(Matrix *pA);       //inplace op.


#endif

// NOTE: Create typedef Tensor generalizing both vector and matrix into one... (use shape!)
