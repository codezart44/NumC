//matrix.c


#include <stdio.h>
#include <math.h>
#include "matrix.h"
#include "../errors.h"


int main() {

    // Matrix A = create_matrix(3, 4);

    // print_matrix(&A);

    double values_B[3*3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    Matrix B = create_matrix_from_array(values_B, 3, 3);

    print_matrix(&B);

    transpose_matrix(&B);

    print_matrix(&B);



}


/********************** UTILS **********************/

/**
 * ...
*/
double maximum_matrix_value(Matrix *pA) {
    double maximum = pA->values[0][0];

    for (int i = 1; i < pA->shape[0]; i++) {
        for (int j = 0; j < pA->shape[1]; j++) {

            if (pA->values[i][j] > maximum) {
                maximum = pA->values[i][j];
            }

        }
    }
    return maximum;
}



/**
 * @brief Print a representation of the matrix `Matrix`.
 * 
 * ...
 * 
 * @param pA A pointer to a matrix `Matrix`
 * 
 * @return `Void`
*/
void print_matrix(Matrix *pA) {
    double maximum_value = maximum_matrix_value(pA);
    int max_num_digits = (int) log10(maximum_value);            // num spaces occupied by longest number in matrix
    int num_digits;

    int rows = pA->shape[0];
    int cols = pA->shape[1];

    for (int i = 0; i < rows; i++) {
        if (i == 0) printf("[[ ");
        else printf(" [ ");

        for (int j = 0; j < cols; j++) {

            num_digits = (int)log10(pA->values[i][j]);      // num digits of current value
            int spaces = max_num_digits-num_digits+1;           // num spaces needed to align next column
            char print_spacing[spaces+1];                       // string of spaces, `+1` for terminal token `\0`

            for (int s = 0; s < spaces; s++) {
                print_spacing[s] = ' ';
            }
            print_spacing[spaces] = '\0';                       // add terminal token last

            printf("%i%s", (int)pA->values[i][j], print_spacing);
        }
        
        if (i == rows-1) printf("]]\n");
        else printf("]\n");
    }
}



/********************** FACTORY FUNCTIONS **********************/

/**
 * @brief Create an instance of a matrix `Matrix` initialised to zero values.
 * 
 * ...
 * 
 * @param rows The number of rows `int` in the matrix.
 * @param cols The number of cols `int` in the matrix.
 * 
 * @return An instance of type `Matrix` with zero values in specified shape.
*/
Matrix create_matrix(int rows, int cols) {
    if (rows * cols > MAXIMUM_LENGTH) {
        raise_error_max_length_exceeded(__LINE__, __func__, __FILE__, "", rows * cols);
    }

    Matrix A;
    A.dimensions = 2;
    A.size = rows * cols;
    A.shape[0] = rows;
    A.shape[1] = cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            A.values[i][j] = 0;
        }
    }

    return A;
}

/**
 * @brief Create an instance of a matrix `Matrix` initialised to zero values.
 * 
 * ...
 * 
 * @param values A single array values matrix A should be initialised to have. Must have length = rows * cols. 
 * @param rows The number of rows `int` in the matrix.
 * @param cols The number of cols `int` in the matrix.
 * 
 * @return An instance of type `Matrix` with zero values in specified shape.
*/
Matrix create_matrix_from_array(double* values, int rows, int cols) {
    if (rows*cols > MAXIMUM_LENGTH) {
        raise_error_max_length_exceeded(__LINE__, __func__, __FILE__, "", rows*cols);
    }

    Matrix A;
    A.dimensions = 2;
    A.size = rows*cols;
    A.shape[0] = rows;
    A.shape[1] = cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            A.values[i][j] = values[i*cols+j];
        }
    }

    return A;
}



/********************** VECTOR OPERATIONS **********************/

/**
 * ...
*/
void transpose_matrix(Matrix *pA) {
    int rows = pA->shape[0];
    int cols = pA->shape[1];
    double temp[rows][cols];

    // flip shape
    pA->shape[0] = cols;        // only perform these to reform matrix
    pA->shape[1] = rows;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            temp[i][j] = pA->values[i][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // printf("%i, %i, %i \n", j*rows+i, i*cols+j, (int)temp[i*cols+j]);
            // building up column by column
            pA->values[j][i] = temp[i][j];      //due to the order of the values in the values array
        }
    }
}





