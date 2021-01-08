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
#include "string.h"

/**********************************************************************************************************************
 * Function Declaration Starts
 **********************************************************************************************************************/

void string_fundamentals();

void string_declaration();

void string_initialization();

void summary_of_string_placement();

void standard_string_operation();

void passing_arguments_to_application(int argc, char** argv);

void returning_string();

char* return_a_literal(int code);

/**********************************************************************************************************************
 * Function Declaration Ends
 **********************************************************************************************************************/

int main(int argc, char *argv[]) {

    // ---------------------------------------------------------------------------------------------------------------
    printf("string_fundamentals: \n");
    string_fundamentals();
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------------
    printf("string_declaration: \n");
    string_declaration();
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------------
    printf("string_initialization: \n");
    string_initialization();
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------------
    printf("summary_of_string_placement: \n");
    summary_of_string_placement();
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------------
    printf("standard_string_operation: \n");
    standard_string_operation();
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------------
    printf("passing_arguments_to_application: \n");
    char * arg[] = {"process.exe", "-f", "names.txt", "limit=12" , "-verbose"};
    passing_arguments_to_application(5, arg);
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------------
    printf("returning_string: \n");
    returning_string();
    printf("\n");



    return 0;
}

void returning_string() {

    /*
     * When a function returns a string, it returns the address of the string. The main concern is to return a valid string address.
     * To do this, we can return a reference to either:
     *      • A literal
     *      • Dynamically allocated memory
     *      • A local string variable
     * */

    return_a_literal(100);


}


char* return_a_literal(int code ) {
    switch(code) {
        case 100:
            return "Boston Processing Center";
        case 200:
            return "Denver Processing Center";
        case 300:
            return "Atlanta Processing Center";

    }
    return "Code not present";

}
void passing_arguments_to_application(int argc, char** argv) {

    for (int i = 0; i < argc; i++)
    {
        printf ("argv[%d] = %s\n", i, argv[i]);
    }

}

void standard_string_operation() {

    /* Comparing String
     *
     *     int strcmp(const char *s1, const char *s2);
     *
     * Negative
     *      If s1 precedes s2 lexicographically (alphabetically)
     * Zero
     *      If the two strings are equal
     * Positive
     *      If s1 follows s2 lexicographically
     */

    char command[16];

    printf("Enter a Command: ");
    scanf("%s", command);

    if (strcmp(command, "Quit") == 0) // if(command == "Quit") compares addresses, not value
    {
        printf("The command was Quit");
    }
    else {
        printf("The command was not Quit");
    }

    /* Copying String
     *
     * char* strcpy(char *s1, const char *s2);
     *      1. Read in the string using a large array of char
     *      2. Use malloc to allocate just the right amount of memory
     *      3. Use strcpy to copy the string into the dynamically allocated memory
     *
     *
    */

    char name[32];
    char* names[30];

    size_t count = 0;
    printf("\nPrint a name: ");
    scanf("%s", name);
    names[count] = (char *) malloc(strlen(name)+ 1 );
    strcpy(names[count], name);
    printf("Copied String: %s", names[count]);

    // free(names[count]);

    count++;

    // Two pointers can reference the same string. When two pointers reference the same location, this is called aliasing.
    // Here, page_header[12] and page_header[13] points to "Compound interest" in String Literal.
    char *page_header[300];
    page_header[12] = "Compound Interest";
    page_header[13] = page_header[12];

    /* Concatenating Strings
     *
     * char *strcat(char *s1, const char *s2);
     *
     * - The function does not allocate memory. This means the first string must be large enough to hold the concatenated
     *   results or it may write past the end of the string, resulting in unpredictable behavior.
     * */
    printf("\n");

    char * error = "Error: ";
    char * error_message = "Not Enough Memory";

    char * buffer = (char *) malloc(strlen(error) + strlen(error_message) + 1);
    strcpy(buffer, error);
    strcat(buffer, error_message);

    printf("%s\n", buffer);
    printf("%s\n", error);
    printf("%s\n", error_message);



}

void summary_of_string_placement() {

    // IMPORTANT --------> "Header" is stored in String Literal Pool

    // char *globalHeader = "Header";                                           // Placed in Global Memory but points to string literal pool address
    // char global_header_array[] = "Global Header";                            // Placed in Global Memory

    // static char *static_header = "Header";                                  // Placed in Global Memory but pointers to header in String Literal Pool
    // static char static_array_header[] = "Static Char Array";                // Placed in Global Memory

    // char *local_header = "Header";                                          // Placed in Heap but points to string literal pool address
    // char local_array_header[] = "local array header";                       // Placed in Heap
    // char *heap_header = (char *) malloc(strlen("heap header" + 1));         // Placed in Heap and address given by malloc in also in heap.So it points to address in heap.

    // strcpy(heap_header, "heap header");

}

void string_initialization() {
    /*
     * - When a string is initialized, we can use a string literal or a series of characters, or obtain the characters
     *   from a different source such as standard input.
     *
     * - Total length is 22 but 23 bytes are required to represent the literal and hold the string.
     * - The initialization will copy these characters to the array terminated by the NUL character,
     * */
    char header[] = "This is String Literal";
    printf("String literal array: %s \n", header);
    header[0] = 'L'; // Ths is allowed
    printf("---------------- header[] = %s\n", header);

    // or

    char header_1[23];
    strcpy(header_1, "This is String Literal");
    header_1[0] = 'L'; // Ths is allowed
    printf("---------------- header[] = %s\n", header_1);
}

void string_declaration() {

    /*
     * String declarations are supported in one of three ways:
     *      1. A literal:
     *              - The string literal is a sequence of characters enclosed in double quotes.
     *
     *              - String literals are frequently used for initialization purposes. This string is stored at read-only
     *                memory and trying to modify this memory leads to undefined behavior. sThey are located in a string literal pool
     *
     *              - When literals are defined they are frequently assigned to a literal pool.
     *                This area of memory holds the character sequences making up a string.
     *                When a literal is used more than once, there is normally only a single copy of the string in the string literal pool.
     *                This will reduce the amount of space needed for the application.
     *
     *      2. As an array of characters:
     *              - Allocates memory and copies string "string2" into it, thus modifying it is valid.
     *
     *      3. Using a pointer to a character
     *              - A common way to initialize this string is to use the malloc and strcpy functions to allocate and copy a literal to the string,
     *
     * String literals are not to be confused with characters enclosed in single quotes—these are character literals.
     * */


    char *tabHeader = "Sound"; // This is string literal

    // Bus Error: 10 (also known as SIGBUS and is usually signal 10) occur when a process is trying to access memory that the CPU cannot physically address.
    //  *tabHeader = 'L'; // Not allowed, we can not modify string literals. This makes tabHeader to point to the read-only memory where your string literal is stored

    printf("%s\n", tabHeader);

    const char *tab_header = "Sound"; // Immutable
    printf("%s\n", tab_header);

    // 2.  Allocates memory and copies string  into it, thus modifying it is valid.
    char header[32] = "This is not string literal array";
    header[0] = 'L'; // Ths is allowed
    printf("header[32] = %s\n", header);

    //3.
    char *header_1 = (char *) malloc(strlen("Media Player") + 1);
    strcpy(header_1, "Media Player");
    printf("*header_1 = %s\n", header_1);
    free(header_1);


}

void string_fundamentals() {
    /* sizeof is of unsigned integral type which is usually denoted by size_t */
    printf("size of \"char\": %lu  \n", sizeof(char));
    printf("size of \"a\": %lu  \n", sizeof('a'));

    char character_literal = 'A';
    char *String_literal = "A";

    printf("character_literal: %c \n", character_literal);
    printf("String_literal: %s \n ", String_literal);

}
