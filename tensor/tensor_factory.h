//tensor_factory.h

#ifndef TENSOR_FACTORY_H
#define TENSOR_FACTORY_H

#include "tensor.h"

// specified tensor factory functions
extern Tensor create_tensor(int dimension, int* shape);                 //return Tensor object (declare and initialize)
extern void define_tensor(int dimensino, int* shape, Tensor *pT);       //initialise and define input Tensor varaible

extern Tensor create_tensor_from_array(int dimension, int* shape, double* values);
extern Tensor create_tensor_random_values(int dimension, int* shape);
extern Tensor create_tensor_single_value(int dimension, int*shape, double value);

// random tensor factory functions
extern Tensor create_tensor_gaussian(int dimensino, int* shape);
// extern void create_tensor_


#endif //TENSOR_FACTORY_H