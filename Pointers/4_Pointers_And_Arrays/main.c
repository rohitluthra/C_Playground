/**********************************************************************************************************************
 * Description:
 *      - This file contains methods for understanding relationship between pointers and arrays.
 *
 * Creator:
 *      - Rohit Luthra
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Include Files
 **********************************************************************************************************************/
#include "stdio.h"
#include "stdlib.h"

/**********************************************************************************************************************
 * Function Declaration Starts
 **********************************************************************************************************************/

void one_dimensional_array();

void two_dimensional_array();

void pointer_notation_arrays();

void difference_between_pointers_and_arrays();

void malloc_to_create_one_d_array();

char *realloc_to_resize_an_array();

void display_array(int arr[], int size);

void display_input(char* arr, int size);

void one_d_array_of_pointers();

void two_dimensional_array_notation();

/**********************************************************************************************************************
 * Function Declaration Ends
 **********************************************************************************************************************/


int main(int argc, char *argv[]) {
    // ---------------------------------------------------------------------------------------------------------------
    printf("One Dimensional Array: \n");
    one_dimensional_array();
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------------
    printf("Two Dimensional Array: \n");
    two_dimensional_array();
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------------
    printf("Pointer Notation and Arrays: \n");
    pointer_notation_arrays();
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------------
    printf("Difference between Pointer and Arrays: \n");
    difference_between_pointers_and_arrays();
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------------
    printf("Using malloc to Create a One-Dimensional Array: \n");
    malloc_to_create_one_d_array();
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------------
    printf("Using the realloc Function to Resize an Array: \n");
    char * input = realloc_to_resize_an_array();
    display_input(input, 17);
    printf("\n");


    // ---------------------------------------------------------------------------------------------------------------
    printf("Using a One-Dimensional Array of Pointers:  \n");
    one_d_array_of_pointers();
    display_input(input, 17);
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------------
    printf("Two-dimensional array notation:  \n");
    two_dimensional_array_notation();
    display_input(input, 17);
    printf("\n");


    return 0;
}

void two_dimensional_array_notation() {

    /*
     * The array is stored in row-column order. That is, the first row is stored sequentially in memory followed by the second row.
     *
     * arr[i][j]  =>   address of arr + (i * size of row) + (j * size of column);
     * */

    int matrix[2][5] = {{1,2,3,4,5},{6,7,8,9,10}};

    for(int i=0; i<2; i++) {
        for(int j=0; j<5; j++) {
            printf("matrix[%d][%d] Address: %p Value: %d\n", i, j, &matrix[i][j], matrix[i][j]);
        }
    }


    /*  The expression, (*pmatrix), declares a pointer to an array. Combined with the rest of the declaration,
     *  pmatrix is defined as a pointer to a two-dimensional array of integers with five elements per column.
     *
     *  If we had left the parentheses off, we would have declared a five-element array of pointers to integers.
     *  The size of the first dimension is 2 since we know the dimensions of the matrix.
     *
     *  If a different size is used to access the array, then the results are unpredictable.*/
    int (*pmatrix)[5] = matrix;

    printf("matrix: %p\n", matrix);
    printf("matrix + 1: %p\n", matrix + 1);

    printf("pmatrix: %p", pmatrix);

}

void one_d_array_of_pointers() {

    int *arr[5];

    /*
     * Since arr was declared as an array of pointers, arr[i] returns an address.
     * When we dereference a pointer such as *arr[i], we get the contents at that address.
     * */

    for (int i = 0; i< 5; i++){
        arr[i] = (int *) malloc(sizeof(int));
        *arr[i] = i;

        //or

    /*
        *(arr+i) = (int*)malloc(sizeof(int));

        **(arr+i) = i;

     * */
    }
}

char *realloc_to_resize_an_array() {

    const size_t sizeIncrement = 10;        // The size of the initial buffer and the amount it will be incremented by when the buffer needs to be enlarged
    char *buffer = malloc(sizeIncrement);   // A pointer to the characters read in
    char *current_position = buffer;        // A pointer to the next free position in the buffer
    size_t maximum_length = sizeIncrement;  // The maximum number of characters that can be safely stored in the buffer
    size_t length = 0;                      // The number of characters read in
    int character;                          // The last character read in

    if (current_position == NULL) {
        return NULL;
    }
    while (1) {
        character = fgetc(stdin);
        if (character == '\n') {
            break;
        }
        if (++length >= maximum_length) {
            char *newBuffer = realloc(buffer, maximum_length += sizeIncrement);
            if (NULL == newBuffer) {
                free(buffer);
                return NULL;
            }

            current_position = newBuffer + (current_position - buffer);
            buffer = newBuffer;
        }
        *current_position++ = character;
    }
    *current_position = '\0';
    return buffer;
}

void malloc_to_create_one_d_array() {
    /* This technique creates a region of memory and treats it as an array. */

    int *pv = (int *) malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        pv[i] = i + 1;

        // or

        /*
         * [ *(pv+i) ] ---------- vs ---------- [ *pv + i ]
         * Dereference pointer has higher precedence over + operator. hence we have to use brackets in order to force increment.
         * */
        *(pv + i) = i + 1; // Same statement as above

    }
    printf("Display Array: \n");
    display_array(pv, 5);
    free(pv);

}

void difference_between_pointers_and_arrays() {
    /* The code generated by vector[i] is different from the code generated by vector+i.
     *
     *      - The notation vector[i] generates machine code that starts at location vector,
     *        moves i positions from this location, and uses its content.
     *
     *      - The notation vector+i generates machine code that starts at location vector, adds i to the address,
     *
     * Difference when the sizeof operator is applied to an array and to a pointer to the same array.
     *
     *      - Applying the sizeof operator to vector will return 20, the number of bytes allocated to the array.
     *
     *      - Applying the sizeof operator against pv will return 4, the pointer’s size.
     *
     * The pointer pv is an lvalue. An lvalue denotes the term used on the left hand side of an assignment operator.
     *      - An lvalue must be capable of being modified.
     *      - An array name such as vector is not an lvalue and cannot be modified.
     *      - The address assigned to an array cannot be changed .
     *      - A pointer can be assigned a new value and reference a different section of memory.
     * */

    int vector[5] = {1, 2, 3, 4, 5};
    int *pv = vector;

    pv = pv + 1; // Legal Statement
    // vector = vector + 1; // Syntax error and illegal


}

void pointer_notation_arrays() {

    /* pv[i] => *(pv + i) */

    int vector[5] = {1, 2, 3, 4, 5};
    /*
     * When an array name is used by itself, the array’s address is returned. We can assign this address to a pointer as
     * The variable pv is a pointer to the first element of the array and not the array itself.
     * */
    int *pv = vector;

    printf("Vector:  %p \n", vector);
    printf("&Vector[0]: %p \n", &vector[0]);
    printf("PV: %p \n", pv);
    printf("&PV: %p \n", &pv);
    printf("*PV: %d \n", *pv);

    pv = vector;
    int value = 3;
    for (int i = 0; i < 5; i++) {
        printf("Before: %d ", pv[i]);
        *pv++ *= value;
        printf("After %d ", pv[i]);
        printf("\n");

    }

}

void two_dimensional_array() {

    int matrix[2][3] = {{1, 2, 3},
                        {4, 5, 6}};

    for (int i = 0; i < 2; i++) {
        printf("&matrix[%d]: %p sizeof(matrix[%d]): %lu\n",
               i, &matrix[i], i, sizeof(matrix[i]));
    }

}

void one_dimensional_array() {

    /*
     * The array name simply references a block of memory.
     * Using the sizeof operator with an array will return the number of bytes allocated to the array.
     * To determine the number of elements, we divide the array’s size by its element’s size.
     *
     * */
    int vector[5] = {1, 2, 3, 4, 5};

    printf("%lu \n", sizeof(vector) / sizeof(int));


}

void display_array(int arr[], int size) {
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void display_input(char* arr, int size) {
    for (int i = 0; i < size; i++)
    {
        printf("%c", arr[i]);
    }
}