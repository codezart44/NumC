

#include "tensor_utils.h"


/**
 * ...
 */
void print_tensor(Tensor *pT) {
    int dim = pT->dimensionality;

    /**
     * dim = 2
     * 
     * 1 2 3
     * 4 5 6
     * 
     * d1 = 2   (rows)
     * d2 = 3   (cols)
     * 
     * 01
     * 012
    */

    for (int d = 0; d < dim; d++) {
        for (Uint i = 0; i < pT->shape[d]; i++) {
            // looping through each dimension
        }
    } 
}