/*********************************************************************************************************************
* Description:
*      - This file contains methods for understanding relationship between pointers and Strings.
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

void string_fundamentals();

void string_declaration();

void string_initialization();

/**********************************************************************************************************************
 * Function Declaration Ends
 **********************************************************************************************************************/

int main(int argc, char* argv[])
{

    // ---------------------------------------------------------------------------------------------------------------
    printf("string_fundamentals: \n");
    string_fundamentals();
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------------
    printf("string_fundamentals: \n");
    string_declaration();
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------------
    printf("string_initialization: \n");
    string_initialization();
    printf("\n");
    return 0;
}

void string_initialization() {
    /*
     *
     * */

}

void string_declaration() {

    /*
     * String declarations are supported in one of three ways:
     *      1. A literal:
     *              - The string literal is a sequence of characters enclosed in double quotes.
     *                String literals are frequently used for initialization purposes. They are located in a string literal pool
     *
     *      2. As an array of characters:
     *
     *      3. Using a pointer to a character
     *
     * String literals are not to be confused with characters enclosed in single quotes—these are character literals.
     * */

    // 1. GCC allows following but in many compilers, string literals are treated as constant hence it is immutable.
    // usually, it is not recommended.

    char *tabHeader = "Sound"; // This is string literal
    *tabHeader = 'L';
    printf("%s\n",tabHeader); // Displays "Lound"

    const char *tab_header = "Sound";

    //2.
    char header[32];

    //3.
    char *header_1;

}

void string_fundamentals() {
    /* sizeof is of unsigned integral type which is usually denoted by size_t */
    printf("size of \"char\": %lu  \n", sizeof(char));
    printf("size of \"a\": %lu  \n", sizeof('a'));

}
