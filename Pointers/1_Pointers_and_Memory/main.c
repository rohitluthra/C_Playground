#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void display_nth_character();
void declare_a_pointer();
void read_a_declaration();
void address_of_pointer();
void dereference_a_Pointer_Using_the_Indirection_Operator();
void concept_of_null();


int main(int argc, char* argv[]) {

    display_nth_character();

    declare_a_pointer();

    read_a_declaration();

    address_of_pointer();

    dereference_a_Pointer_Using_the_Indirection_Operator();

    concept_of_null();

    return 0;
}

void display_nth_character()
{
    /***********************************************************************************************************************
   * - Displaying nth Character
   * ***********************************************************************************************************************/
    char *names[] = {"Rohit", "Jones", "Alex"};
    printf ("%c \n ", *(*(names + 1)+2));
    printf ("%c \n ", names[1][2]);
}

void declare_a_pointer()
{
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
    int *pi;
    int* pi_1;
    int * pi_2;
    int*pi_3;
}

void read_a_declaration()
{
    /***********************************************************************************************************************
     * - How to Read a Declaration
     * - Always read it backwards
     *    1. pci is a variables (pci)
     *    2. pci is pointer variable (*pci)
     *    3. pci is a pointer variable to an integer (int *pci)
     *    4. pci is pointer variable ti a constant integer (const int *pci)
     ***********************************************************************************************************************/
    const  int *pci;
}

void address_of_pointer(){
    int num;
    int *pi = &num;
}

void dereference_a_Pointer_Using_the_Indirection_Operator()
{
    /*
     * The indirection operator, *, returns the value pointed to by a pointer variable.
     * */

    int num = 5;
    int *numP = &num;

    printf("%p\n",*numP); // Displays 5

    *numP = 200;
    printf("%d\n",num); // Displays 200

}

void concept_of_null()
{

}