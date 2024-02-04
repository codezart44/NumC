//tensor_operations.c

#include "tensor.h"
#include "tensor_operations.h"
#include "tensor_utils.h"
#include "tensor_factory.h"


/**
 * @brief Elementwise addition of two tensors. 
 * 
 * Supports broadcasting. Inner shapes must align (from right) and the one of lower 
 * dimensionality will be broadcasted across the axes of the higher dim tensor.
 * 
 * @param pT_1 A pointer to an initialised instance of type `Tensor`
 * @param pT_2 A pointer to an initialised instance of type `Tensor` (may be same as pT_1)
 * @param pT_res A pointer to a declared instance of type `Tensor` (NOT SAME AS pT_1 OR pT_2!)
 * 
 * @return void
*/
void tensor_add(Tensor *pT_1, Tensor *pT_2, Tensor *pT_res) {
    // broadcasting operation

    Tensor *pT_high_dim = (pT_1->dimensionality >= pT_2->dimensionality) ? pT_1 : pT_2;
    Tensor *pT_low_dim = (pT_1->dimensionality < pT_2->dimensionality) ? pT_1 : pT_2;

    // Uint min_dimensionality = (pT_1->dimensionality<pT_2->dimensionality) ? pT_1->dimensionality : pT_2->dimensionality;
    Uint max_dimensionality = pT_high_dim->dimensionality;
    Uint padding = max_dimensionality - pT_low_dim->dimensionality;
    Uint padded_shape[max_dimensionality];

    // if (max_dimensionality == 0) {
    //     // pT_res->values[0] = pT_1->values[0] + pT_2->values[0];   // need .tensor_xxx depending on dtype ==> switch case
    // }

    // setting up broadcasted shapes
    for (Uint axis = 0; axis < max_dimensionality; axis++) {
        // {1, 2, 3, 4, 5} 5
        // (1)(1)(1){4, 5} 2
        padded_shape[axis] = (axis >= padding) ? pT_low_dim->shape[axis-padding] : 1;
    }

    // DEBUG PRINTS
    // print_1darray(pT_high_dim->shape, max_dimensionality);
    // print_1darray(padded_shape, max_dimensionality);


    // Check if shapes are compatible
    for (Uint axis = 0; axis < max_dimensionality; axis++) {
        if (padded_shape[axis] != pT_high_dim->shape[axis] && padded_shape[axis] != 1 ) {
            // raise error incompatile shapes
            printf("INCOMPATIBLE SHAPES!\n");
        }
    }

    // addition operation
    Uint multiplicity = pT_high_dim->size / pT_low_dim->size;

    define_tensor(pT_res, max_dimensionality, pT_high_dim->shape, pT_high_dim->dtype);

    for (Uint m = 0; m < multiplicity; m++) {
        for (Uint i = 0; i < pT_low_dim->size; i++) {
            switch (pT_high_dim->dtype)
            {
            case TENSOR_SHORT:
                pT_res->values[m*pT_low_dim->size+i].tensor_short = pT_high_dim->values[m*pT_low_dim->size+i].tensor_short + pT_low_dim->values[i].tensor_short;
                break;
            case TENSOR_USHORT:
                pT_res->values[m*pT_low_dim->size+i].tensor_ushort = pT_high_dim->values[m*pT_low_dim->size+i].tensor_ushort + pT_low_dim->values[i].tensor_ushort;
                break;
            case TENSOR_INT:
                pT_res->values[m*pT_low_dim->size+i].tensor_int = pT_high_dim->values[m*pT_low_dim->size+i].tensor_int + pT_low_dim->values[i].tensor_int;
                break;
            case TENSOR_UINT:
                pT_res->values[m*pT_low_dim->size+i].tensor_uint = pT_high_dim->values[m*pT_low_dim->size+i].tensor_uint + pT_low_dim->values[i].tensor_uint;
                break;
            case TENSOR_LONG:
                pT_res->values[m*pT_low_dim->size+i].tensor_long = pT_high_dim->values[m*pT_low_dim->size+i].tensor_long + pT_low_dim->values[i].tensor_long;
                break;
            case TENSOR_ULONG:
                pT_res->values[m*pT_low_dim->size+i].tensor_ulong = pT_high_dim->values[m*pT_low_dim->size+i].tensor_ulong + pT_low_dim->values[i].tensor_ulong;
                break;
            case TENSOR_FLOAT:
                pT_res->values[m*pT_low_dim->size+i].tensor_float = pT_high_dim->values[m*pT_low_dim->size+i].tensor_float + pT_low_dim->values[i].tensor_float;
                break;
            case TENSOR_DOUBLE:
                pT_res->values[m*pT_low_dim->size+i].tensor_double = pT_high_dim->values[m*pT_low_dim->size+i].tensor_double + pT_low_dim->values[i].tensor_double;
                break;
            default:
                // raise error invalid dtype
                break;
            }
        }
    }
}




/**
 * BROADCASTING ACCORDING TO NUMPY STANDARDS
 * 
 * align shapes from right 
 * broadcasting possible if:
 * - same shape
 * - one shape is 1
 * - missing shapes du to lower dim can be padded with 1
 * e.g.
 * Possible:
 * {2, 3, 1, 4}
 * (1){1, 1, 4}
 * Not Possible:
 * {2, 3, 1, 4}
 * (1){2, 1, 4}
*/