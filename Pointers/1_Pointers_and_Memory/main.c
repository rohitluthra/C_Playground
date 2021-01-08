/**********************************************************************************************************************
 * Description:
 *      - This file contains methods for understanding relationship between memory and pointers.
 *      - Secrets of printf:
 *          \   escape the next character
 *          \\  print a backslash
 *          "   start or end of string
 *          \"  print a double quote
 *          ’   start or end a character constant
 *          \’  print a single quote
 *          %   start a format specification
 *          \%  print a percent sign
 *          %c  print a single character
 *          %d  print a decimal (base 10) number
 *          %e  print an exponential floating-point number
 *          %f  print a floating-point number
 *          %g  print a general-format floating-point number
 *          %i  print an integer in base 10
 *          %o  print a number in octal (base 8)
 *          %s  print a string of characters
 *          %u  print an unsigned decimal (base 10) number
 *          %x  print a number in hexi-decimal (base 16)
 *          %%  print a percent sign (\% also works)
 *
 * Creator:
 *      - Rohit Luthra
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Include Files
 **********************************************************************************************************************/
#include <stdio.h>
#include <string.h>


/**********************************************************************************************************************
 * Function Declaration Starts
 **********************************************************************************************************************/
void display_nth_character();

void declare_a_pointer();

void read_a_declaration();

void address_of_pointer();

void dereference_a_Pointer_Using_the_Indirection_Operator();

void concept_of_null();

void pointer_to_void();

void predefined_pointer_related_types();

void pointer_operators();

/**********************************************************************************************************************
 * Function Declaration Ends
 **********************************************************************************************************************/

int main(int argc, char *argv[]) {
    // ---------------------------------------------------------------------------------------------------------------
    printf("pointer_operators: \n");
    pointer_operators();
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------------
    printf(" display_nth_character: \n");
    display_nth_character();
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------------
    printf(" declare_a_pointer: \n");
    declare_a_pointer();
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------------
    printf("read_a_declaration:  \n");
    read_a_declaration();
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------------
    printf("address_of_pointer: \n");
    address_of_pointer();
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------------
    printf("dereference_a_Pointer_Using_the_Indirection_Operator:  \n");
    dereference_a_Pointer_Using_the_Indirection_Operator();
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------------
    printf("concept_of_null:  \n");
    concept_of_null();
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------------
    printf("pointer_to_void: \n");
    pointer_to_void();
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------------
    printf("predefined_pointer_related_types: \n");
    predefined_pointer_related_types();
    printf("\n");

    return 0;
}

void display_nth_character() {
    /***********************************************************************************************************************
   * - Displaying nth Character
   * ***********************************************************************************************************************/
    char *names[] = {"Rohit", "Jones", "Alex"};
    printf("%c \n ", *(*(names + 1) + 2));
    printf("%c \n ", names[1][2]);
}

void declare_a_pointer() {
    /***********************************************************************************************************************
     * * - Declaring a Pointer
     * * - The use of white space is a matter of user preference.
     * * - There are several points to remember:
     * *    The content of pi should eventually be assigned the address of an integer variable.
     * *    These variables have not been initialized and thus contain garbage.
     * *    There is nothing inherent to a pointer’s implementation that suggests what type of data it is referencing or whether
     * *        its contents are valid.
     * *   However, the pointer type has been specified and the compiler will frequently complain when the pointer is not used correctly.
     * ***********************************************************************************************************************/
    int *pi = NULL; // Initial value is NULL
    int *pi_1 = NULL;;
    int *pi_2 = NULL;;
    int *pi_3 = NULL;;

    /* Following are same thing */
    const int *pci = NULL;;
    int const *pci_1 = NULL;;

    /* Constant pointer to a constant integer  */
    const int limit = 100;
    const int *const cpci = &limit;

    printf("*pi: %p\n,*pi_1: %p\n,*pi_2: %p\n,*pi_3: %p\n,*pci: %p\n,*pci_1: %p\n, limit: %d\n, cpci: %p \n",pi,pi_1,pi_2,pi_3,pci,pci_1, limit, cpci);

}

void read_a_declaration() {
    /***********************************************************************************************************************
     * - How to Read a Declaration
     * - Always read it backwards
     *    1. pci is a variables (pci)
     *    2. pci is pointer variable (*pci)
     *    3. pci is a pointer variable to an integer (int *pci)
     *    4. pci is pointer variable to a constant integer (const int *pci)
     ***********************************************************************************************************************/
    // const int *pci;
}

void address_of_pointer() {
    // int num;
    // int *pi = &num;
}

void dereference_a_Pointer_Using_the_Indirection_Operator() {
    /*
     * The indirection operator, *, returns the value pointed to by a pointer variable.
     * */

    int num = 5;
    int *numP = &num;

    printf("%d \n", *numP); // Displays 5

    *numP = 200;
    printf("%d\n", num); // Displays 200

}

void concept_of_null() {
    /*
     * 6 Types of Null
     *      The null concept
     *      The null pointer constant
     *      The NULL macro
     *      The ASCII NUL
     *      A null string
     *      The null statement
     *
     * A null pointer vs an uninitialized pointer:
     *      An uninitialized pointer can contain any value, whereas
     *      a pointer containing NULL does not reference any location in memory.
     *
     * Important:
     *      1. When NULL is assigned to a pointer, it means the pointer does not point to anything.
     *      2. The null concept refers to the idea that a pointer can hold a special value that is not equal to another pointer.
     *      3. It does not point to any area of memory. Two null pointers will always be equal to each other.
     *      4. The null concept is an abstraction supported by the null pointer constant. This constant may or may not be a constant zero.
     *      5. The NULL macro is a constant integer zero cast to a pointer to void. In many libraries, it is defined as follows:
     *          #define NULL    ((void *)0)
     *          This is what we typically think of as a null pointer.
     *      6. The ASCII NUL is defined as a byte containing all zeros. However, this is not the same as a null pointer.
     *      7. A string in C is represented as a sequence of characters terminated by a zero value. The null string is an empty string and does not contain any characters.
     *      8. Finally, the null statement consists of a statement with a single semicolon.
     * */

    int *temp = NULL;

    if (temp) {// Not NUll
    } else {//Null
    }

}

void pointer_to_void() {
    /*
     * A pointer to void is a general-purpose pointer used to hold references to any data type. An example of a pointer to void is shown below:
     *      void *pv;
     * It has two interesting properties:
     *      - A pointer to void will have the same representation and memory alignment as a pointer to char.
     *      - A pointer to void will never be equal to another pointer. However, two void pointers assigned a NULL value will be equal.
     */

    int num;
    int *pi = &num;
    printf("Value of pi: %p\n", pi);

    void *pv = pi;
    pi = (int *) pv;
    printf("Value of pi: %p\n", pi);

    // size_t size = sizeof(void *); // Legal

    // size_t size_1 = sizeof(void); // Illegal
}

void pointer_operators() {
    /*
     * "*"              -> Used to declare a pointer
     * "*"              -> Used to dereference a pointer
     * "->"             -> Used to access field of a structure referenced by a pointer
     * "+"              -> Used to increment a pointer
     * "-"              -> Used to decrement a pointer
     * "== !="          -> Equal or not equal
     * "(data type)"    -> pointer type conversion
     * */

    /*
     *  Type    Size
        byte    1
        char    1
        short   2
        int     4
        long    8
        float   4
        double  8
     * */

}

void predefined_pointer_related_types() {

    /* size_t

     * The type size_t represents the maximum size any object can be in C.
     * It is an unsigned integer since negative numbers do not make sense in this context.
     * Its purpose is to provide a portable means of declaring a size consistent with the addressable area of memory
     * available on a system.
     *
     * The size_t type is used as the return type for the sizeof operator and as the argument to many functions,
     * including malloc and strlen, among others.*/

    // typedef unsigned int size_t;

}