//tensor_factory.c

#include "tensor.h"
#include "tensor_factory.h"


#define INITIALIZE_TENSOR_VALUE_I(pT, dtype, value, i)                  \
    switch ((dtype))                                                    \
        {                                                               \
        case TENSOR_SHORT:                                              \
            (pT)->values[(i)].tensor_short = (value).tensor_short;      \
            break;                                                      \
        case TENSOR_USHORT:                                             \
            (pT)->values[(i)].tensor_ushort = (value).tensor_ushort;    \
            break;                                                      \
        case TENSOR_INT:                                                \
            (pT)->values[(i)].tensor_int = (value).tensor_int;          \
            break;                                                      \
        case TENSOR_UINT:                                               \
            (pT)->values[(i)].tensor_uint = (value).tensor_uint;        \
            break;                                                      \
        case TENSOR_LONG:                                               \
            (pT)->values[(i)].tensor_long = (value).tensor_long;        \
            break;                                                      \
        case TENSOR_ULONG:                                              \
            (pT)->values[(i)].tensor_ulong = (value).tensor_ulong;      \
            break;                                                      \
        case TENSOR_FLOAT:                                              \
            (pT)->values[(i)].tensor_float = (value).tensor_float;      \
            break;                                                      \
        case TENSOR_DOUBLE:                                             \
            (pT)->values[(i)].tensor_double = (value).tensor_double;    \
            break;                                                      \
        default:                                                        \
            break;                                                      \
        }




/**
 * @brief Declare and initialize (create) tensor varaible.
 * 
 * ...
 * 
 * @param dimension
 * @param shape 
 * @param dtype
 * 
 * @return A tensor `Tensor` instance.
*/
Tensor create_tensor(Uint dimensionality, Uint* shape, NumberType dtype) {
    if (dimensionality > MAXIMUM_DIMENSION) {    // assert allowed dimension 
        // raise error maximum dimensionality exceeded
    }

    Tensor tensor;

    tensor.dimensionality = dimensionality;
    tensor.size = 1;
    tensor.dtype = dtype;

    // initialise tensor shape and size
    for (Uint axis = 0; axis < dimensionality; axis++) {
        if (shape[axis] <= 0) {
            // raise error non positive axis
        }
        tensor.shape[axis] = shape[axis];
        tensor.size *= shape[axis];
    }

    // initialise tensor values
    for (Uint i = 0; i < tensor.size; i++) {
        INITIALIZE_TENSOR_VALUE_I(&tensor, dtype, (Number) 0, i);
    }

    return tensor;
}


/**
 * @brief Initliaze (define) an already declared tensor variable.
 * 
 * Intialize the members of an already declared Tensor varaible. 
 * This method of initializing a tensor is more efficient, especially 
 * for large tensors, since it avoids copying and returning a complete 
 * tensor object.
 * 
 * @param dimension
 * @param shape
 * @param dtype
 * @param pT A pointer to a declared but not initialized tensor `Tensor`
 * 
 * @return Void
*/
void define_tensor(Tensor *pT, Uint dimensionality, Uint* shape, NumberType dtype) {
    if (dimensionality > MAXIMUM_DIMENSION) {
        // ...raise error maximum dimension exceeded
    }

    pT->dimensionality = dimensionality;
    pT->dtype = dtype;
    pT->size = 1;

    // initialise tensor shape and size
    for (Uint axis = 0; axis < dimensionality; axis++) {
        if (axis <= 0) {
            // raise error non positive axis
        }
        pT->shape[axis] = shape[axis];
        pT->size *= shape[axis];
    }

    // initialise tensor values
    for (Uint i = 0; i < pT->size; i++) {
        INITIALIZE_TENSOR_VALUE_I(pT, dtype, (Number) 0, i);
    }
}


/**
 * ...
*/
Tensor create_tensor_from_array(Uint dimensionality, Uint* shape, NumberType dtype, Number* values) {
    if (dimensionality > MAXIMUM_DIMENSION) {
        // ...raise error maximum dimension exceeded
    }

    Tensor tensor;
    tensor.dimensionality = dimensionality;
    tensor.dtype = dtype;
    tensor.size = 1;

    // intialise tensor shape and size
    for (Uint axis = 0; axis < dimensionality; axis++) {
        if (axis <= 0) {
            // raise error non positive axis
        }
        tensor.shape[axis] = shape[axis];
        tensor.size *= shape[axis];
    }

    // initialise tensor values
    for (Uint i = 0; i < tensor.size; i++) {
        INITIALIZE_TENSOR_VALUE_I(&tensor, dtype, values[i], i);
    }

    return tensor;
}


/**
 * ...
*/
void define_tensor_from_array(Tensor *pT, Uint dimensionality, Uint* shape, NumberType dtype, Number* values) {
    if (dimensionality > MAXIMUM_DIMENSION) {
        // ...raise error maximum dimension exceeded
    }

    pT->dimensionality = dimensionality;
    pT->dtype = dtype;
    pT->size = 1;

    // intialise tensor shape and size
    for (Uint axis = 0; axis < dimensionality; axis++) {
        if (axis <= 0) {
            // raise error non positive axis
        }
        pT->shape[axis] = shape[axis];
        pT->size *= shape[axis];
    }

    // initialise tensor values
    for (Uint i = 0; i < pT->size; i++) {
        INITIALIZE_TENSOR_VALUE_I(pT, dtype, values[i], i);
    }
}

