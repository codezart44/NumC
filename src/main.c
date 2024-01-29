
#include <stdio.h>
#include "tensor_factory.h"
#include "tensor_operations.h"
#include "tensor_utils.h"



int main() {

    Tensor t = create_tensor(2, (int[2]){3, 4}, TENSOR_INT);

    Tensor s;
    define_tensor(&s, 2, (int[2]){5, 6}, TENSOR_UINT);

    Number values_p[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Tensor p = create_tensor_from_array(2, (int [2]){2, 5}, TENSOR_UINT, values_p);
    
    Tensor q;
    Number values_q[12] = {1, 0, 5, 4, 4, 0, 7, 2, 1, 1, 0, 7};
    define_tensor_from_array(&q, 3, (int [3]){2, 3, 2}, TENSOR_USHORT, values_q);


    return 0;
}