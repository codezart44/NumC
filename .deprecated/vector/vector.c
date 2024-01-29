#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
#include "../errors.h"


int main() {

    // CREATING VECTOR OF SPECIFIED LENGTH
    double values1[5] = {1, 2, 0, 0, 1};
    Vector v1 = create_vector_from_array(values1, 5);
    print_vector(&v1);

    // CREATING VECTOR FROM SENTINEL VALUE
    double values2[7] = {1, 0, 0, 3, 4, 2, SENTINEL_VALUE};
    Vector v2 = create_vector_from_sentinel(values2, SENTINEL_VALUE);
    print_vector(&v2);

    // CREATE ZERO VECTOR FROM SIZE
    Vector v3 = create_vector_from_size(3);
    print_vector(&v3);


    // VECTOR DOT PRODUCT
    const int size = 7;     // must be constant for array segment allocation
    double values_u[size] = {0, 3, 1, 2, 2, 0, 1};
    double values_v[size] = {5, 4, 3, 0, 1, 0, 2};
    Vector u = create_vector_from_array(values_u, size);
    Vector v = create_vector_from_array(values_v, size);

    printf("Vector u is given by: ");
    print_vector(&u);

    printf("Vector v is given by: ");
    print_vector(&v);

    double dot_uv = dot_product(&u, &v);
    printf("u • v = %i  (dot product)\n", (int)dot_uv);


    // GET VECTOR STRING REPRESENTATIONS FOR FLEXIBLE USE
    char* string_u = vector_to_string(&u);  // REMEMBER TO FREE DYNAMICALLY ALLOCATED SPACE
    printf("The vector u: %s\n", string_u);
    free(string_u);     // free dynamically allocated space for string representation
    string_u = NULL;    // set var to NULL to avoid double-free

    char* string_v = vector_to_string(&v);  // REMEMBER TO FREE DYNAMICALLY ALLOCATED SPACE
    printf("The vector v: %s\n", string_v);
    free(string_v);
    string_v = NULL;



    // ELEMENT WISE OPERATIONS
    Vector add_uv = element_wise_add(&u, &v);
    printf("u + v = ");
    print_vector(&add_uv);

    Vector sub_uv = element_wise_sub(&u, &v);
    printf("u - v = ");
    print_vector(&sub_uv);
    Vector sub_vu = element_wise_sub(&v, &u);
    printf("v - u = ");
    print_vector(&sub_vu);
    
    // add multiplication and division...


    
    // REVERSE VECTOR ELEMENTS
    reverse_vector(&u);
    printf("Vector u reversed: ");
    print_vector(&u);

}


/********************** UTILS **********************/

/**
 * ...
*/
void print_vector(Vector* pV) {
    printf("[ ");
    for (int i = 0; i < pV->size; i++) {
        printf("%i ", (int)pV->values[i]);
    }
    printf("]\n");
}


/**
 * @brief Create string representation of vector
 * 
 * ...
 * 
 * @param pV A pointer to an instance of a vector
 * 
 * @return A string representation of the vector
 * 
 * @note REMEMBER TO FREE ALLICATED SPACE `free(pointer_returned)`
*/
char* vector_to_string(Vector* pV) {
    const int string_length = 2 * (pV->size) + 4;       // need extra characters for spaces, brackets and terminal token \0

    // localc varaibles are stored on the stack and deallocated once the function exits.
    char* pString = (char*)malloc(string_length * sizeof(char));    // dynamic memory allocation needed since local varaibles will be discarded outside fo the local function call

    if (pString == NULL) {
        return NULL;        // null pointer
    }

    pString[0] = '[';
    for (int i = 1; i < string_length; i++) {
        if (i%2 == 1) {
            pString[i] = ' ';
        } else if (i%2 == 0) {
            pString[i] = (char)(pV->values[i/2-1] + '0');     // '0' has ASCII value 48, converts integer to its corresponding ASCII character form
        }
    } 

    pString[string_length-2] = ']';
    pString[string_length-1] = '\0';

    return pString;     // NOTE typedef a string of length xxx and return pointer to (may be able to return directly then)
}




/********************** FACTORY FUNCTIONS **********************/

/**
 * @brief Instantiate a vector from an array of values.
 * 
 * ...
 * 
 * @param array An array of values of type `double`
 * @param size An integer denoting the length of the vector
 * 
 * @return An instance of type `Vector` 
*/
Vector create_vector_from_array(double* array , int size) {        // array parameters decay to pointers when passed to functions
    if (size > MAXIMUM_LENGTH) {
        raise_error_max_length_exceeded(__LINE__, __func__, __FILE__, "", size);
    }

    Vector v;
    v.dimensions = 1;
    v.size = size;
    v.shape[0] = size;
    for (int i = 0; i < size; i++) {
        v.values[i] = array[i];
    }

    return v;
}


/**
 * @brief Instantiate a vector from an array with a sentinel value (end token).
 * 
 * ...
 * 
 * @param array An array of values of type `double`
 * @param sentinel_value A double also present in the array denoting the end of the vector values
 * 
 * @return An instance of type `Vector`
*/
Vector create_vector_from_sentinel(double* array, double sentinel_value) {
    int size = 0;

    while (array[size] != sentinel_value) {
        size++;
        if (size > MAXIMUM_LENGTH) {
            raise_error_max_length_exceeded(__LINE__, __func__, __FILE__, "", size);
        };
    }

    Vector v;
    v.dimensions = 1;
    v.size = size;
    v.shape[0] = size;
    for (int i = 0; i < size; i++) {
        v.values[i] = array[i];
    }

    // if returning a vector pointer (&v) malloc would be needed since local vector will be deallocated
    return v;   // returning a vector will result in it being copied, thus malloc not needed
}


/**
 * @brief Instanciate a zero vector of desired length.
 * 
 * ...
 * 
 * @param size An integer denoting the legth of the vector
 * 
 * @return An instance of type `Vector`
*/  
Vector create_vector_from_size(int size) {
    if (size > MAXIMUM_LENGTH) {
        raise_error_max_length_exceeded(__LINE__, __func__, __FILE__, "", size);
    }
    Vector v;
    v.dimensions = 1;
    v.size = size;
    v.shape[0] = size;
    for (int i = 0; i < size; i++) {
        v.values[i] = 0;
    }

    return v;
}


/********************** VECTOR OPERATIONS **********************/


/**
 * @brief Dot product of two vectors of same length.
 * 
 * ...
 * 
 * @param pU A pointer to an instance of type `Vector`
 * @param pV A pointer to an instance of type `Vector`
 * 
 * @return The dot product `double` of u and v 
 * 
*/
double dot_product(Vector* pU, Vector* pV) {
    if (pU->size != pV->size) {
        raise_error_incompatible_shape(__LINE__, __func__, __FILE__, "", pU->shape, pV->shape);
    }

    double dot_product = 0;
    for (int i = 0; i < pU->size; i++) {
        dot_product += pU->values[i] * pV->values[i];
    }

    return dot_product;
}


/**
 * @brief Element wise summation of two vectors u & v.
 * 
 * ...
 * 
 * @param pU A pointer to an instance of type `Vector`
 * @param pV A pointer to an instance of type `Vector`
 * 
 * @return An instance of a vector `Vector` representing the sum of u & v
*/
Vector element_wise_add(Vector* pU, Vector* pV) {
    if (pU->shape[0] != pV->shape[0]) {
        raise_error_incompatible_shape(__LINE__, __func__, __FILE__, "", pU->shape, pV->shape);
    }

    Vector w;
    w.dimensions = 1;
    w.size = pU->size;
    w.shape[0] = pU->size;

    for (int i = 0; i < pU->size; i++) {
        w.values[i] = pU->values[i] + pV->values[i];
    }

    return w;
}


/**
 * @brief Element wise subtraction of two vectors u & v.
 * 
 * Calculated as u - v.
 * 
 * @param pU A pointer to an instance of type `Vector`
 * @param pV A pointer to an instance of type `Vector`
 * 
 * @return An instance of a vector `Vector` representing the sum of u & v
*/
Vector element_wise_sub(Vector* pU, Vector* pV) {
    if (pU->shape[0] != pV->shape[0]) {
        raise_error_incompatible_shape(__LINE__, __func__, __FILE__, "", pU->shape, pV->shape);
    }

    Vector w;
    w.dimensions = 1;
    w.size = pU->size;
    w.shape[0] = pU->size;

    for (int i = 0; i < pU->size; i++) {
        w.values[i] = pU->values[i] - pV->values[i];
    }

    return w;
}

/**
 * @brief Element wise multiplication of two vectors u & v.
 * 
 * Calculated as u * v (not dot product which is element wise multiplication and sum).
 * 
 * @param pU A pointer to an instance of type `Vector`
 * @param pV A pointer to an instance of type `Vector`
 * 
 * @return An instance of a vector `Vector` representing the product of u & v
*/
Vector element_wise_mult(Vector *pU, Vector *pV) {
    if (pU->shape[0] != pV->shape[0]) {
        raise_error_incompatible_shape(__LINE__, __func__, __FILE__, "", pU->shape, pV->shape);
    }

    Vector w;
    w.dimensions = 1;
    w.size = pU->size;
    w.shape[0] = pU->size;
    for (int i = 0; i < pU->size; i++) {
        w.values[i] = pU->values[i] * pV->values[i];
    }

    return w;
}

/**
 * @brief Element wise division of two vectors u & v.
 * 
 * Calculated as u / v.
 * 
 * @param pU A pointer to an instance of type `Vector`
 * @param pV A pointer to an instance of type `Vector`
 * 
 * @return An instance of a vector `Vector` representing the quotient of u & v
*/
Vector element_wise_div(Vector *pU, Vector *pV) {
    if (pU->shape[0] != pV->shape[0]) {
        raise_error_incompatible_shape(__LINE__, __func__, __FILE__, "", pU->shape, pV->shape);
    }

    Vector w;
    w.dimensions = 1;
    w.size = pU->size;
    w.shape[0] = pU->size;
    for (int i = 0; i < pU->size; i++) {
        if (pV->values[i] == 0) {
            raise_error_div_by_zero(__LINE__, __func__, __FILE__, "");
        }
        w.values[i] = pU->values[i] / pV->values[i];
    }

    return w;
}


/**
 * @brief Inplace reverse the order of the vector values.
 * 
 * ...
 * 
 * @param pV A pointer to an instance of type `Vector`
 * 
 * @return No return value as it modifies the vector in place.
 * 
*/
void reverse_vector(Vector *pV) {
    double temp;
    int half_size = pV->size/2;
    for (int i = 0; i < half_size; i++) {
        temp = pV->values[i];                       // store a in temp
        pV->values[i] = pV->values[pV->size-1-i];   // set a to b
        pV->values[pV->size-1-i] = temp;            // set b to a (temp)
    }
}


/**
 * @brief Inplace negate the values of the vector.
 * 
 * ...
 * 
 * @param pV A pointer to an instance of type `Vector`
 * 
 * @return No return value as it modifies the vector in place.
 * 
*/
void negate_vector(Vector *pV) {
    for (int i = 0; i<pV->size; i++) {
        pV->values[i] = pV->values[i];
    }
}



