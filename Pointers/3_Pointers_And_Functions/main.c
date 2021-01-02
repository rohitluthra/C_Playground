//
// Created by Rohit Luthra on 1/1/21.
//

#include "stdio.h"
#include "stdlib.h"


int* allocate_array(int size, int value);

int main (int argc, char * argv[])
{
    /*
     * several potential problems can occur when returning a pointer from a function, including:
     *
     * • Returning an uninitialized pointer
     * • Returning a pointer to an invalid address
     * • Returning a pointer to a local variable
     * • Returning a pointer but failing to free it
     * */
    int* vector = allocate_array(5,0);

    for(int i=0; i<5; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");

    /*
     * - Returning dynamically allocated memory from the function means the function’s caller is responsible for deal‐ locating it.
     * - So we need to free(vector)
     * */

    free(vector);
    return 0;
}

int* allocate_array(int size, int value) {

    int *array = (int *) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = value;
    }
    /*
     * While the arr variable went away when the function terminated, the memory referenced by the pointer does not go away.
     * This memory will eventually need to be freed.
     * */
    return array;
}

