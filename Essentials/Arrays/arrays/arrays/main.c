//
//  main.c
//  arrays
//
//  Created by Rohit Luthra on 9/7/19.
//  Copyright © 2019 Rohit Luthra. All rights reserved.
// Important Notes:
//      Size of the array is decided at compile time not runtime.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int length[] = {1,2,3,4,5};
    int length_1 [5] = {1,2,3,4,5};
    int length_2 [5] = {1,2};
    int length_3 [5] = {0};
    
    int i=0;
    for( i=0; i<5;i++)
    {
    printf("%d \n", length_1[i] );
    }

}

/*
 Base Array Example which prints address of each element.
 
 int length[] = {1,2,3,4,5};
 int length_1 [5] = {1,2,3,4,5};
 int length_2 [5] = {1,2};
 int length_3 [5] = {0};
 
 int i=0;
 for( i=0; i<5;i++)
 {
 printf("%u \n", &length_1[i] );
 }

 
 */
/*Dynamic Array Example
 
 //In a nutshell pointer acts as a name of the array.
 int *pointer;
 
 //Before the address of array in heap is allocated to pointer, *pointer must be initialised.
 
 
 // 1. Initially, malloc will return a void type of pointer. Hence it must be type casted before use.
 //2. type caste it to (int*);
 
 pointer = (int *)malloc(5*sizeof(int));
 
 // HERE POINTER REFERS TO FIRST ELEMENT, WHICH IS 30.
 
 pointer[0] = 30;
 pointer[1] = 40;
 pointer[2] = 50;
 pointer[3] = 60;
 pointer[4] = 70;
 
 int i=0;
 for(;i< 5;i++)
 {
 printf("%d ", pointer[i]);
 }
 
 */

//-----------------------------------------------------------------------------------

/*
 // Demo for increasing Size of dynamic Array.
 int a[] = {1,2,3,4,5};
 int i=0;
 int *pointer,*q;
 
 pointer = (int *) malloc(5*sizeof(int));
 
 pointer[0] = 30;
 pointer[1] = 40;
 pointer[2] = 50;
 pointer[3] = 60;
 pointer[4] = 70;
 
 //double of "pointer" array
 q = (int *) malloc(10*sizeof(int));
 
 for(i=0; i<10;i++){
 q[i] = pointer[i];
 }
 
 free(pointer);
 // Here pointer's size has increased.
 pointer = q;
 q = NULL;
 
 */
