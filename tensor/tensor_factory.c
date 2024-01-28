//tensor_factory.c

#include <stdio.h>
#include "tensor.h"
#include "tensor_factory.h"


int main() {
    //testing local functions
    int t_shape[2] = {3, 4};
    Tensor t = create_tensor(2, t_shape);
    for (int i = 0; i < t.size; i++) {
        printf("%i ", (int)t.values[i]);
    }

    return 0;
}


/**
 * ...
*/
Tensor create_tensor(int dimension, int* shape) {
    if (dimension > MAXIMUM_DIMENSION) {    //abstract to `assert_allowed_dimension(dimension);`
        // ...raise error maximum dimension exceeded
    }

    Tensor t;
    t.dimension = dimension;
    t.size = 1;
    for (int axis = 0; axis < dimension; axis++) {
        t.shape[axis] = shape[axis];
        t.size *= shape[axis];
    }
    for (int i = 0; i < t.size; i++) {
        t.values[i] = 0;
    }

    return t;
}


/**
 * ...
*/
void define_tensor(int dimension, int* shape, Tensor *pT) {
    if (dimension > MAXIMUM_DIMENSION) {
        // ...raise error maximum dimension exceeded
    }
}
