//tensor_factory.h

#ifndef TENSOR_FACTORY_H
#define TENSOR_FACTORY_H

#include "tensor.h"

// deterministic tensor factory functions
extern Tensor create_tensor(Uint dimensionality, Uint* shape, NumberType dtype);                   //return Tensor object (declare and initialize)
extern Tensor create_tensor_single_value(Uint dimensionality, Uint* shape, NumberType dtype, Number value);
extern Tensor create_tensor_from_array(Uint dimensionality, Uint* shape, NumberType dtype, Number* values);

extern void define_tensor(Tensor *pT, Uint dimensionality, Uint* shape, NumberType dtype);         //initialise and define input Tensor varaible
extern void define_tensor_single_value(Tensor *pT, Uint dimensionality, Uint*shape, NumberType dtype, Number value);
extern void define_tensor_from_array(Tensor *pT, Uint dimensionality, Uint* shape, NumberType dtype, Number* values);


// random tensor factory functions
extern Tensor create_tensor_uniform(Uint dimensionality, Uint* shape);
extern Tensor create_tensor_gaussian(Uint dimensionality, Uint* shape);


#endif //TENSOR_FACTORY_H