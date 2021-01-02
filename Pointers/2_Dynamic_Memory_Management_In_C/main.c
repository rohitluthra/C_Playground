/**********************************************************************************************************************
 * Description:
 *      - This file contains methods for understanding dynamic memory allocation.
 *      - It aims to explain malloc, realloc, calloc and free functions.
 *      - Dynamic Memory Allocation:
 *          - The basic steps used for dynamic memory allocation in C are:
 *              1. Use a malloc type function to allocate memory
 *              2. Use this memory to support the application
 *              3. Deallocate the memory using the free function
 * Creator:
 *      - Rohit Luthra
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Include Files
 **********************************************************************************************************************/
#include "stdio.h"
#include "stdlib.h"
#include <string.h>

/**********************************************************************************************************************
 * Function Declaration Starts
 **********************************************************************************************************************/
int allocate_memory();

void memory_leak();

void loosing_pointer();

void using_the_right_size_for_malloc_function();

void using_malloc_with_static_and_global_pointers();

void calloc_function();

void realloc_function();

void deallocating_memory_using_the_free_function();

void dangling_pointer();

/**********************************************************************************************************************
 * Function Declaration Ends
 **********************************************************************************************************************/


int main (int argc, char* argv [])
{
    allocate_memory();

    memory_leak();

    loosing_pointer();

    using_the_right_size_for_malloc_function();

    using_malloc_with_static_and_global_pointers();

    calloc_function();

    realloc_function();

    deallocating_memory_using_the_free_function();

    dangling_pointer();

    return 0;

}

void dangling_pointer() {
    int *pi = (int *) malloc(sizeof(int));
    *pi =5;
    printf("*pi: %d \n", *pi);

    free(pi);

    *pi = 10; // Shouldn't be done

    /* Two pointer referring to one address and one of them is freed*/
    int *p1 = (int*) malloc(sizeof(int)); *p1 = 5;

    int *p2;
    p2 = p1;

    free(p1);

    *p2 = 10; // Dangling Pointer

    /*
     * How to deal with dangling pointers
     *
     * Setting a pointer to NULL after freeing it.
     * */

}

int allocate_memory() {
    int *pi = (int *)malloc(sizeof(int));

    // Good Practice to Check for NULL
    if(pi == NULL){
        return 1; // Not Successful return
    }

    *pi = 5;
    printf ("Values of pi is: %d \n", *pi);

    free(pi);

    return 0;

}

void memory_leak() {
    /*
     * A memory leak occurs when allocated memory is never used again but is not freed. This can happen when:
     *      The memory’s address is lost
     *      The free function is never invoked though it should be (sometimes called a hidden leak)
     *
     * A problem with memory leaks is that the memory cannot be reclaimed and used later.
     * The amount of memory available to the heap manager is decreased. If memory is repeatedly allocated and then lost,
     * then the program may terminate when more memory is needed but malloc cannot allocate it because it ran out of memory.
     *
     * In extreme cases, the operating system may crash.
     * */
    char *chunk;
    chunk = (char*) malloc(1000000);
    printf("Allocating\n");
}

void loosing_pointer() {
    /*
     * Loosing a Pointer
     * */
    int *pi = (int*) malloc(sizeof(int)); *pi = 5;

    pi = (int*) malloc(sizeof(int));

    printf("Address of pi: %d", *pi);
}

void using_the_right_size_for_malloc_function() {
    const int NUMBER_OF_DOUBLES = 10;

    double *pd = (double *) malloc((NUMBER_OF_DOUBLES)* sizeof(double));

    printf("Address of double: %f", *pd);

}

void using_malloc_with_static_and_global_pointers() {
    /*
     * Following is not possible.
     *
     * You cannot use a function call when initializing a static or global variable.
     * */


    // static int *pi = (int *) malloc(sizeof(int));

}

void calloc_function() {
    /*
     * The calloc function will allocate and clear memory at the same time.
     *
     * To clear memory means its contents are set to all binary zeros.
     *
     *
     * */
    // void *calloc (size_t num_elements, size_t element_size)

    /*
     * The function will allocate memory determined by the product of the numElements and elementSize parameters.
     * A pointer is returned to the first byte of memory. If the function is unable to allocate memory, NULL is returned.
     *
     * If calloc is unable to allocate memory, a null pointer is returned and the global variable, errno, is set to ENOMEM (out of memory).
     * This is a POSIX error code and may not be available on all systems.
    */

    int *pi = calloc(5,sizeof(int));
    printf("value: %d", *pi);


    /*
     *
     * The memset function will fill a block with a value.
     * The first argument is a pointer to the buffer to fill. The second is the value used to fill the buffer,
     * and the last argument is the number of bytes to be set.
     * */
    int *pi_1 = malloc(5 * sizeof(int));
    memset(pi_1, 0, 5* sizeof(int));
}

void realloc_function() {
    /*
     * The function realloc returns a pointer to a block of memory. The function takes two arguments.
     * The first is a pointer to the original block, and the second is the requested size.
     * The reallocated block’s size will be different from the size of the block referenced by the first argument.
     * The return value is a pointer to the reallocated memory.
     *
     * the pointer returned is a null pointer and the errno is set to ENOMEM.
     * */

    // void *realloc(void *ptr, size_t size);

}

void deallocating_memory_using_the_free_function() {
    /*
     * void free(void *ptr);
     * The pointer argument should contain the address of memory allocated by a malloc type function.
     * This memory is returned to the heap. While the pointer may still point to the region, always assume it points to garbage.
     * This region may be reallocated later and populated with different data.
     * */
    int *pi = (int*) malloc(sizeof(int));

    free(pi);

    /*
     * Undefined Behavior
     *
     * If the free function is passed a null pointer, then it normally does nothing.
     * If the pointer passed has been allocated by other than a malloc type function, then the function’s behavior is undefined.
     * In the following example, pi is allocated the address of num. However, this is not a valid heap address:
     * */
    int num;
    int *pi_1 = &num;
    free(pi_1); // Undefined behavior


}