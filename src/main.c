
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tensor_factory.h"
#include "tensor_operations.h"
#include "tensor_utils.h"



int main() {
    srand(time(NULL));      // seeding rand once and in beginning of program

    // Tensor t_uniform = create_tensor_uniform(3, (Uint [3]){2, 2, 3}, TENSOR_INT, 0, 10);
    // print_tensor(&t_uniform);
    

    // Tensor t1 = create_tensor(2, (Uint [2]){2, 3}, TENSOR_UINT);

    // Uint t2_arr[2*3] = {1, 2, 3, 1, 2, 3};
    // Tensor t2 = create_tensor_from_array(2, (Uint [2]){2, 3}, TENSOR_UINT, t2_arr);
    // Tensor t3;
    
    // tensor_add(&t2, &t2, &t3);

    // print_tensor(&t2);
    // print_tensor(&t2);
    // print_tensor(&t3);


    // Tensor t = create_tensor(2, (Uint [2]){3, 4}, TENSOR_INT);

    // Tensor s;
    // define_tensor(&s, 2, (Uint [2]){5, 6}, TENSOR_UINT);

    double values_p[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Tensor p = create_tensor_from_array(2, (Uint [2]){2, 5}, TENSOR_DOUBLE, values_p);
    
    Tensor q;
    Ushort values_q[12] = {1, 0, 5, 4, 4, 0, 7, 2, 1, 1, 0, 7};
    define_tensor_from_array(&q, 3, (Uint [3]){2, 3, 2}, TENSOR_USHORT, values_q);

    // print_tensor(&t);
    // print_tensor(&s);
    print_tensor(&p);
    print_tensor(&q);


    return 0;
}