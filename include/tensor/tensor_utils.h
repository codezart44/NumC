//tensor_utils.h

#ifndef TENSOR_UTILS_H
#define TENSOR_UTILS_H

#include "tensor.h"

//printing tensor in temrinal
extern void print_tensor(Tensor *pT);

//saving and loading tensors (serializing)
extern void save_tensor(char* path, Tensor *pT);
extern void load_tensor(char* path, Tensor *pT);

#endif //TENSOR_UTILS_H
