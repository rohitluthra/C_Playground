//
//  main.c
//  recursion
//
//  Created by Rohit Luthra on 8/29/19.
//  Copyright © 2019 Rohit Luthra. All rights reserved.
//

#include <stdio.h>


int main(){
    
    recursive(3);
    printf("\n");
    recursive_1(3);
    return 0;
}


// Decending order

int recursive(int temp){
    
    if(temp>0)
    {
        printf("%d ", temp);
        recursive(temp-1);
    }
    return 0;
}

// Ascending Order

int recursive_1(int temp){
    
    if(temp>0)
    {
        recursive_1(temp-1);
        printf("%d ", temp);
    }
    return 0;
}
