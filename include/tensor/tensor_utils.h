//tensor_utils.h

#ifndef TENSOR_UTILS_H
#define TENSOR_UTILS_H

#include "tensor.h"


//math functions

extern double scalar_pdf_gaussian(double mu, double sigmoid, double x);

extern double scalar_cos(double x);
extern double scalar_sin(double x);

extern double scalar_ln(double x);
extern double scalar_exp(double x);
extern double scalar_abs(double x);
extern double scalar_power_n(double x, int n);


//convert integer value to type Number

extern Number cast_int_to_number(int integer_value, NumberType dtype);


//printing tensor in terminal

extern void print_tensor_shape(Tensor *pT);
extern void print_tensor_dtype(Tensor *pT);
extern void print_tensor_metadata(Tensor *pT);
extern void print_tensor_values_1d(Number values[], Uint size);
extern void print_tensor(Tensor *pT);

extern void print_1d_array(Uint* array, Uint size);

//saving and loading tensors (serializing)

extern void save_tensor(char* path, Tensor *pT);
extern void load_tensor(char* path, Tensor *pT);

#endif //TENSOR_UTILS_H
