//vector.h

// header guard (if not defined)
#ifndef VECTOR_H    
#define VECTOR_H

#include "../config.h"

typedef struct Vector {
    int dimensions;                     //!< The dimension of this arraylike.
    int size;                           //!< The number of elements in arraylike.
    int shape[1];                       //!< The leangth this arraylike stretches in each dimension.
    double values[MAXIMUM_LENGTH];      //!< The stored values of this arraylike.
} Vector;

typedef enum {False=0, True} BooleanT;



extern void print_vector(Vector *pV);
extern char* vector_to_string(Vector *pV);

extern Vector create_vector_from_array(double* array, int size);
extern Vector create_vector_from_sentinel(double* array, double sentinel_value);
extern Vector create_vector_from_size(int size);

extern double dot_product(Vector* pU, Vector* pV);

extern Vector element_wise_add(Vector* pU, Vector* pV);
extern Vector element_wise_sub(Vector* pU, Vector* pV);
extern Vector element_wise_mult(Vector* pU, Vector* pV);
extern Vector element_wise_div(Vector* pU, Vector* pV);


extern void reverse_vector(Vector* pV);
extern void negate_vector(Vector* pV);

extern Vector concatenate_vectors(Vector *pU, Vector *pV);
extern Vector slice_vector(Vector *pV); 

extern Vector sort_vector_values(Vector *pV, BooleanT ascending);


#endif
