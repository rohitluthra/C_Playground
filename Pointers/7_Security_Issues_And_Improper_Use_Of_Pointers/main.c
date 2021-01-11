/*********************************************************************************************************************
* Description:
*      - This file contains methods for understanding relationship between pointers and structures.
*
* Creator:
*      - Rohit Luthra
**********************************************************************************************************************/

/**********************************************************************************************************************
 * Include Files
 **********************************************************************************************************************/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "assert.h"
#define SIZE 32

/**********************************************************************************************************************
 * Function Declaration Starts
 **********************************************************************************************************************/

void dealing_with_uninitialized_pointers();

void buffer_overflow_issue();

void misuse_of_dereference_operator();

void memory_out_of_bound_of_an_array();

void calculating_the_array_size_correctly(char buffer[], char replacement, size_t size);

void misuse_of_sizeof_operator();

void always_match_pointer_types();

void bounded_pointers();

int valid(void *ptr);

void memory_deallocation_issues();

/**********************************************************************************************************************
 * Function Declaration Ends
 **********************************************************************************************************************/


int main(int argc, char *argv[]) {

    // ---------------------------------------------------------------------------------------------------------------
    printf("dealing_with_uninitialized_pointers: \n");
    dealing_with_uninitialized_pointers();
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------------
    printf("buffer_overflow_issue: \n");
    buffer_overflow_issue();
    printf("\n");


    // ---------------------------------------------------------------------------------------------------------------
    printf("misuse_of_dereference_operator: \n");
    misuse_of_dereference_operator();
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------------
    printf("memory_out_of_bound_of_an_array: \n");
    memory_out_of_bound_of_an_array();
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------------
    printf("calculating_the_array_size_correctly: \n");
    char buffer[6] = "Rohit";
    char replacement = 'L';
    size_t size = 5;

    /*
     * While the strcpy function permitted buffer overflow, the replace function did not.

     * ex: strcpy(name,"Alexander");
     *  - this code is executed, we get the following output:
          Output:  ++++++++r

     * This assumes that the size passed is valid. Functions like strcpy that do not pass the buffer’s size should be
     * used with caution.
     *
     * Passing the buffer’s size provides an additional layer of protection.
     *

    */

    calculating_the_array_size_correctly(buffer, replacement, size);
    printf("buffer: %s \n", buffer);

    if (buffer[5] == '\0') {
        printf("buffer: %c", buffer[5]);
    }

    printf("\n");


    // ---------------------------------------------------------------------------------------------------------------
    printf("misuse_of_sizeof_operator: \n");
    misuse_of_sizeof_operator();
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------------
    printf("always_match_pointer_types: \n");
    always_match_pointer_types();
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------------
    printf("bounded_pointers: \n");
    bounded_pointers();
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------------
    printf("memory_deallocation_issues: \n");
    memory_deallocation_issues();
    printf("\n");

    return 0;
}

void memory_deallocation_issues() {
    /* - This situation involves freeing same memory twice
     *   Best way to deal with this is to always set a pointer to NULL after you free it.
     *
     * - Always clear the memory before deallocating it.
     * */


}

void bounded_pointers() {

    char name[SIZE];
    char *p = name;

    if (valid((void *)p)) {
        if (p >= name && p < name + SIZE) {
            // Valid pointer - continue
        } else {
            // Invalid pointer - error condition
        }
    }


}

int valid(void *ptr) {
    return (ptr != NULL);
}

void always_match_pointer_types() {

    int num = 2147483647;
    int *pi = &num;
    short *ps = (short *) pi;

    printf("pi: %p Value(16): %x Value(10): %d\n", pi, *pi, *pi);
    printf("ps: %p Value(16): %hx Value(10): %hd\n", ps, (unsigned short) *ps, (unsigned short) *ps);

}

void misuse_of_sizeof_operator() {

    // int buffer[20];
    // int *pbuffer = buffer;


    /*
     *  However, the sizeof(buffer) expression returns 80 since the size of the buffer in bytes is 80 (20 multiplied by 4 byte elements).
     *
     *  The for loop is executed 80 times instead of 20 and will frequently result in a memory access exception terminating the application.
     *
     *  Avoid this by using the expression sizeof(buffer)/sizeof(int) in the test condition of the for statement.

     for (int i = 0; i < sizeof(buffer); i++) { // instead of sizeof, use -> sizeof(buffer)/sizeof(int)
        *(pbuffer++) = 0;
    }

     */



    // vs

    /*

    for (int i = 0; i < sizeof(buffer)/sizeof(int) ; i++) { // This will run 20 times.
        *(pbuffer++) = 0;
    }

     */


}

void calculating_the_array_size_correctly(char buffer[], char replacement, size_t size) {
    /*
     * When passing an array to a function, always pass the size of the array at the same time.
     * This information will help the function avoid exceeding the bounds of the array.
     * */

    size_t siz = 0;
    while (*buffer != '\0' && siz++ < size) {
        *buffer = replacement;
        buffer++;
    }
}

void memory_out_of_bound_of_an_array() {

    char firstName[8] = "1234567";
    char middleName[8] = "12345";
    char lastName[8] = "123";

    // middleName[-2] = 'X';
    // middleName[0] = 'X';
    // middleName[10] = 'X';

    printf("%p %s\n", firstName, firstName);

    printf("%p %s\n", middleName, middleName);

    printf("%p %s\n", lastName, lastName);

}

void misuse_of_dereference_operator() {

    int num;
    int *pi = &num;
    printf("address of num: %p \n", pi);
    // vs

    /*
        - We are attempting to assign the address of num not to pi but rather to the memory location specified by the
          contents of pi.

        - The pointer, pi, has not been initialized yet.

        - We have made a simple mistake of misusing the dereference operator.
    */
    // int num_1;
    // int * pi_1;
    // *pi_1 = &num_1;

    // Correct way is:

    int num_2;
    int *pi_2;
    pi_2 = &num_2; // not using * dereference operator, Since we cannot access pi address as it is uninitialized

}

void buffer_overflow_issue() {

    /*
        - Buffer overflow occurs when memory outside the object’s bounds is overwritten. This memory may be part of the program’s
        address space or another process.
        - When the memory is outside of the program address space, most operating systems will issue a segmentation fault and terminate the program.

        - Buffer overflow can happen by:
            • Not checking the index values used when accessing an array’s elements
            • Not being careful when performing pointer arithmetic with array pointers
            • Using functions such as gets to read in a string from standard input
            • Using functions such as strcpy and strcat improperly
    */
}

void dealing_with_uninitialized_pointers() {
    /*
     *   • Always initialize a pointer with NULL
         • Use the assert function
         • Use third-party tools
     */
    int *pi = NULL;
    if (pi == NULL) {
        printf("Pointer is NULL. \n");
        // pi should not be de-referenced
    } else {
        // pi can be used
        printf("Pointer is not NULL. \n");

    }

    assert(pi == NULL);

}
