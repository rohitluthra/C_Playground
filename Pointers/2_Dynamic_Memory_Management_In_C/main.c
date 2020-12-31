//
// Created by Rohit Luthra on 12/27/20.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int allocate_memory();

void memory_leak();

void loosing_pointer();

/*
 * Dynamic Memory Allocation
        The basic steps used for dynamic memory allocation in C are:
        1. Use a malloc type function to allocate memory
        2. Use this memory to support the application
        3. Deallocate the memory using the free function
 * */

int main (int argc, char* argv [])
{
    allocate_memory ();

    memory_leak();

    loosing_pointer();

    return 0;

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

    printf("Address of pi: %x", pi);
}
