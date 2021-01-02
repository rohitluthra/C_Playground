//
// Created by Rohit Luthra on 1/1/21.
//

#include "stdio.h"
#include "stdlib.h"


int* allocate_array(int size, int value);

int* pointer_to_localData(int i, int i1);

int* passing_null_pointer(int *arr, int size, int value);

void pointer_to_pointer(int **pInt, int i, int i1);

void personalized_free_function(void **i);

void declaring_function_pointer();

int main (int argc, char * argv[])
{
    /*
     * pointer_to_localData ->
     * several potential problems can occur when returning a pointer from a function, including:
     *
     * • Returning an uninitialized pointer
     * • Returning a pointer to an invalid address
     * • Returning a pointer to a local variable
     * • Returning a pointer but failing to free it
     *
     * - Returning dynamically allocated memory from the function means the function’s caller is responsible for deal‐ locating it.
     * - So we need to free(vector)
     * */
    int* vector = allocate_array(5,0); //Dynamically created address space
    for(int i=0; i<5; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
    free(vector);

    pointer_to_localData(5,0); // local data space created
    // -----------------------------------------------------------------------------------------------------------------------------------//

    // passing_null_pointer
    int* vector_1 = (int*)malloc(5 * sizeof(int));
    passing_null_pointer(vector_1,5,45);

    // -----------------------------------------------------------------------------------------------------------------------------------//
    // pointer_to_pointer
    int *arr = NULL;
    pointer_to_pointer(&arr, 5, 0);

    // -----------------------------------------------------------------------------------------------------------------------------------//
    // Its parameter is declared as a pointer to a pointer to void. Using a pointer to a pointer allows us to modify the pointer passed.
    // personalized_free_function(vector_1);

    // -----------------------------------------------------------------------------------------------------------------------------------//
    declaring_function_pointer();


    return 0;
}

void declaring_function_pointer() {
    /*
     * void (*foo)();
     *      void -> Return Type
     *      *foo -> Function pointer's variable name
     *      () -> parameters
     *
     * When function pointers are used, the programmer must be careful to ensure it is used properly because C
     * does not check to see whether the correct parameters are passed.
     *
     *
     * */

}

void personalized_free_function(void **i) {

    if (*i != NULL && i != NULL)
    {
        free(*i);
        *i = NULL; // good practice
    }

}

void pointer_to_pointer(int **pInt, int i, int i1) {

    *pInt = (int *)malloc(i * sizeof(int));

    if (*pInt != NULL)
    {
        for (int j=0; j< i; j++)
        {
            *(*pInt+i) = i1;
        }
    }
}

int* passing_null_pointer(int *arr, int size, int value) {


        if (arr != NULL) {
            for (int i = 0; i < size; i++) {
                arr[i] = value;
            }
        }
        return arr;

    }

int *pointer_to_localData(int j, int j1) {

        int *array = NULL;
        for (int i = 0; i < j; i++) {
            // printf("%d \n", array[i]);
        }

        /*
         * Unfortunately, the address of the array returned is no longer valid once the function returns because the function’s
         * stack frame is popped off the stack.
         *
         * While each array element may still contain a 0, these values may be overwritten if another function is called.
         * */
        return array;
    }

int *allocate_array(int size, int value) {

        int *array = (int *) malloc(size * sizeof(int));
        for (int i = 0; i < size; i++) {
            array[i] = value;
        }
        /*
         * While the arr variable went away when the function terminated, the memory referenced by the pointer does not go away.
         * This memory will eventually need to be freed.
         * */

        /*
         * An alternative approach is ->
         *  - to declare the arr variable as static. This will restrict the variable’s scope to the
         *    function but allocate it outside of the stack frame, eliminating the possibility of another function overwriting
         *    the variable’s value:
         *
         *  - However, this will not always work. Every time the rray function is called, it will reuse the array.
         *    This effectively invalidates any previous calls to the function. In addition, the static array must be declared
         *    with a fixed size. This will limit the function’s ability to handle various array sizes.
         * */

        // static int arr[5];
        return array;

}
