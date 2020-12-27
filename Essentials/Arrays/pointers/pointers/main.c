//
//  main.c
//  pointers
//
//  Created by Rohit Luthra on 9/10/19.
//  Copyright © 2019 Rohit Luthra. All rights reserved.
//

#include <stdio.h>
#define MAX 100

int main(int argc, const char * argv[]) {
    
    /*
     Always initialise variable otherwise, dereferecing an uninitialised variable causes program to crash.ß
     If no value is available, initialize variable to NULL;
     */
    /*
     int i;      // random integer
     int* ip;    // pointer
     
     ip = &i;    // address of i is stored at ip;
     i = 3;    // value of i changes
     
     printf("%d", *ip);
     */
    
    
    
    /*
     Pointer pointing to itself*/
    /*
     int* self;
     self = &self;
     print("%d", self);
     */
    
    /*
    int* a;
    int b = (int)&a;
    double* c;
    a = b;
    printf("address of a = %d\n", &a);
    printf("    value of a = %d\n", a);
    printf ("Size of pointer = %d\n", sizeof(*c));
    */
    //int a1 [MAX];
   // int n = sizeof(a) / sizeof(a[0]); //(100/4) number of bytes to store this array.
    
    int a = 10;
    int *b = &a;
    printf("%p      using p wo * \n",b);
    printf("%d      using d wo * \n",b);

    printf("%p      using p w *\n",*b);
    printf("%d      using d \n",*b);

    printf("%x\n",b);
    printf("%x\n",*b);
    return 0;
    
}

