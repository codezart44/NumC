#include <stdio.h>




int main() {

    int array[5] = {};      // 5*4 20 bytes

    printf("%p\n", array);
    printf("%p\n", &array);

    printf("%p\n", array+1);
    printf("%p\n", &array+1);

    printf("Array size    :  %lu\n", sizeof(array));
    printf("Pointer size  :  %lu\n", sizeof(&array));

}

