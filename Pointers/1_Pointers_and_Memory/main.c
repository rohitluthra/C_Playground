#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])

{

/***********************************************************************************************************************
- Displaying nth Character
***********************************************************************************************************************/

    char *names[] = {"Rohit", "Jones", "Alex"};

  printf ("%c \n ", *(*(names + 1)+2));
  printf ("%c \n ", names[1][2]);

  /***********************************************************************************************************************
  - Declaring a Pointer

  - The use of white space is a matter of user preference.

  - There are several points to remember:
	• The content of pi should eventually be assigned the address of an integer variable.
	• These variables have not been initialized and thus contain garbage.
	• There is nothing inherent to a pointer’s implementation that suggests what type of data it is referencing or whether its contents are valid.
	• However, the pointer type has been specified and the compiler will frequently complain when the pointer is not used correctly.

  ***********************************************************************************************************************/
  int *pi;
  int* pi_1;
  int * pi_2;
  int*pi_3;



  /***********************************************************************************************************************
  - How to Read a Decalartion

  - Always read it backwards:
	1. pci is a variables (pci)
	2. pci is pointer variable (*pci)
	3. pci is a pointer variable to an integer (int *pci)
	4. pci is pointer variable ti a constant integer (const int *vpci)
  ***********************************************************************************************************************/
  const  int *pci;

return 0;
}
