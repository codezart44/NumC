
## REPOSITORY STRUCTURE

```
NumC
|
|-- include/                            # header files .h
|   |-- tensor/
|   |   |-- tensor_factory.h
|   |   |-- tensor_operations.h
|   |   |-- tensor_utils.h
|   |
|   |-- config.h
|   |-- errors.h
|
|-- src/                                # source files .c
|   |-- tensor/
|   |   |-- tensor_factory.c
|   |   |-- tensor_operations.c
|   |   |-- tensor_utils.c
|   |
|   |-- errors.c
|   |-- main.c
|
|-- tests/                              # test files .c
|   |--tensor/
|   |   |-- test_tensor_factory.c
|   |   |-- test_tensor_operations.c
|   |   |-- test_tensor_utils.c
|   |
|   |-- Makefile                        # Makefile for tests
|   |-- test_main.c
|
|-- .gitignore
|-- Makefile                            # Makefile for compiling
|-- README.md

```

## MAKE SHORT COMMANDS
```
> make                  # compile files specified in makefile to executable
> make clean            # remove files used to create executable
> ./NumC                # execute program (main.c)
```







## TENSOR OPERATIONS TO BE IMPLEMENTED

1. Basic Element-wise Operations:
- Addition, Subtraction, Multiplication, Division: Perform these operations element-wise between tensors or between a tensor and a scalar.
- Unary operations: Functions like abs, sin, cos, exp, log, etc., applied element-wise.

2. Broadcasting:
- Implementing broadcasting rules allows element-wise operations to be performed on tensors of different shapes, automatically expanding them to compatible dimensions.

3. Reduction Operations:
- Sum, Mean, Min, Max: Calculate these across the entire tensor or along specific axes.
- Standard Deviation and Variance.

4. Matrix Operations:
- Matrix Multiplication: Both element-wise multiplication and dot product.
- Transpose: Swap axes of the tensor.
- Determinant and Inverse (for 2D matrices).

5. Tensor Reshaping:
- Reshape: Change the shape of a tensor without changing its data.
- Squeeze and Unsqueeze: Add or remove dimensions of size 1.
- Flatten: Collapse a tensor into a 1D array.

6. Indexing and Slicing:
- Advanced indexing and slicing capabilities to extract sub-tensors.

7. Tensor Concatenation and Splitting:
- Concatenate: Join a sequence of tensors along an existing axis.
- Split: Divide a tensor into multiple sub-tensors.

8. Linear Algebra Functions:
- Eigenvalues and Eigenvectors.
- Singular Value Decomposition (SVD).
- QR Decomposition.

9. Convolution Operations (useful in deep learning):
- Convolutional operations over tensors, typically used for image and signal processing.

10. Gradient Computation (for advanced machine learning applications):
- Ability to compute gradients, which is essential for optimization in machine learning.

11. Random Tensor Generation:
- Generate tensors with random values following specific distributions.

12. Saving and Loading Tensors:
- Functions to serialize tensors to disk and load them back.