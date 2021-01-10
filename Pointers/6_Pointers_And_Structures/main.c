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

/**********************************************************************************************************************
 * Function Declaration Starts
 **********************************************************************************************************************/


void introduction();

void how_memory_is_allocated_for_structure();

void avoiding_malloc_free_overhead();

/**********************************************************************************************************************
 * Function Declaration Ends
 **********************************************************************************************************************/

int main(int argc, char *argv[]) {
    // ---------------------------------------------------------------------------------------------------------------
    printf("introduction: \n");
    introduction();
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------------
    printf("how_memory_is_allocated_for_structure: \n");
    how_memory_is_allocated_for_structure();
    printf("\n");

    // ---------------------------------------------------------------------------------------------------------------
    printf("avoiding_malloc_free_overhead: \n");
    avoiding_malloc_free_overhead();
    printf("\n");
    // ---------------------------------------------------------------------------------------------------------------
    printf(": \n");
    printf("\n");
    // ---------------------------------------------------------------------------------------------------------------
    printf(": \n");
    printf("\n");
    // ---------------------------------------------------------------------------------------------------------------
    printf(": \n");
    printf("\n");
    // ---------------------------------------------------------------------------------------------------------------
    printf(": \n");
    printf("\n");


}

void avoiding_malloc_free_overhead() {

    typedef struct {

        char *firstname;
        char *lastname;
        unsigned int age;

    } Person;

    Person *list[10];
    // Before Using this we need to initialize it.

    for (int i = 0; i < 10; i++) {
        list[i] == NULL;
    }

}


void how_memory_is_allocated_for_structure() {
    /*
     * When a structure is allocated memory, the amount allocated to the structure is at minimum the sum of the size of
     * its individual fields. However, the size is often larger than this sum because padding can occur between fields
     * of a structure.
     *
     * This padding can result from the need to align certain data types on specific boundaries.
     * For example ->
     *      a short is typically aligned on an address evenly divisible by two while
     *      an integer is aligned on an address even divisible by four.
     *
     * Several implications are related to this allocation of extra memory:
     *      • Pointer arithmetic must be used with care
     *      • Arrays of structures may have extra memory between their elements
     */

    typedef struct {

        char *firstname;
        char *lastname;
        unsigned int age;

    } Person;

    /*
     *         AlternatePerson people[30];
     *
     *         for this structure looks like this:
     *         people[0] takes 100, 104, 108, 112 (for 112, of which half is paddings its short)
     *         people[1] takes 116, 120, 124, 128 (for 128, of which half is paddings its short)
     *         .
     *         . and so forth
     * */
    typedef struct _alternatePerson {
        char *firstName;
        char *lastName;
        char *title;
        short age;
    } AlternatePerson;

    printf("size of char: %lu \n", sizeof(char));
    printf("size of short: %lu \n", sizeof(short));

    printf("Size of person: %lu \n ", sizeof(Person));
    printf("Size of alternatePerson: %lu \n", sizeof(AlternatePerson));
    AlternatePerson person = (AlternatePerson *) malloc(sizeof(AlternatePerson));

    /*  Deallocate_structure
     *      - You have to deeallocate individual memory not just the structure.
     */
    free(person.firstName);
    free(person.lastName);
    free(person.title);
    free(person.age);

}

void introduction() {

    typedef struct {

        char *firstname;
        char *lastname;
        unsigned int age;

    } Person;

    /* Creating Instance */
    // Person person;

    /*Alternately, we can declare a pointer to a Person and allocate memory for it, as shown
    below:*/

    Person *person_1;
    person_1 = (Person *) malloc(sizeof(Person));
    person_1->firstname = (char *) malloc(strlen("Rohit"));

    // or

    (*person_1).firstname = (char *) malloc(strlen("Rohit"));

    strcpy(person_1->firstname, "Rohit");

    free(person_1);
}
