
#ifndef TENSOR_H
#define TENSOR_H

#include "../config.h"


// enum for types of values allowed in Tensors
/**
 * 
*/
typedef enum 
{   
    SHORT,
    USHORT,
    INT,
    UINT,
    LONG,
    ULONG,
    FLOAT,
    DOUBLE,
} NumberType;


// union of the datatypes allowed in Tensors
/**
 * @brief Allowed datatypes of values stored in a tensor.
 * 
 * The size of `NumberValue` values will be arg max(union members) 
 * plus any padding according to the systems alignment requirements.
 * 
 * @param short
 * @param Ushort (unsigned short)
 * @param int
 * @param Uint (unsigned int)
 * @param long
 * @param Ulong (unsigned long)
 * @param float
 * @param double
*/
typedef union 
{   
    short s;
    Ushort us;
    int i;
    Uint ui;
    long l;
    Ulong ul;
    float f;
    double d;
} NumberValue;      




/**
 * @brief A generalisation of dimensional array objects.
 * 
 * Can store up to `MAXIMUM_DIMENSION` dimensional arrays with meta data for shape,
 * size, datatype and dimension of the tensor.
 * 
 * @param dimension The dimension `Uint` of the tensor
 * @param size The number of values `Uint` stored in the tensor
 * @param shape An array of dimensional lengths `Uint [MAXIMUM_DIMENSIONS]` for the values
 * @param dtype The datatype `NumberType` of the numeric values stored in the tensor
 * @param values An array of values `NumberValue [MAXIMUM_LENGTH]` stored in the tensor
*/
typedef struct Tensor 
{   
    Uint dimension;                         // The number of dimensions the tensor spans
    Uint size;                              // The number of values `NumberValues` stored in the `.values` member
    Uint shape[MAXIMUM_DIMENSION];          // An array of the length the tensor values stretch in each dimension
    NumberType dtype;                       // The datatype of the numeric values stored in the `.values` member
    NumberValue values[MAXIMUM_LENGTH];     // The values contained by the tensor
} Tensor;



#endif //TENSOR_H



