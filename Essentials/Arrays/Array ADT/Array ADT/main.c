//
//  main.c
//  Array ADT
//
//  Created by Rohit Luthra on 9/7/19.
//  Copyright © 2019 Rohit Luthra. All rights reserved.
//  Following progr

#include <stdio.h>
#include <stdlib.h>

struct Array{
    // This is pointer to first element of the array (which will be dynamically formed).
    int *array;
    // This is the size of the array.
    int size;
    // Number of elements currently present in the array.
    int length;
};

void display_elements(struct Array incoming)
{
    int j = 0;
    printf("\nAll Elements are: \n");
    
    for(j=0; j<incoming.length;j++)
    {
        printf("%d", incoming.array[j]);
    }
}

/*
 Append function basically adds something at the end of the array. (If there is space available.)
 
 */
// call by address type.

void append(struct Array *arr, int x)
{
    if(arr->length < arr->size)
    {
        arr->array[arr->length++]=x;
    }
    
}

/*
 Insert Function:
 */

int insert (struct Array *arr, int index, int element)
{
    int i=0;
    if(index>=0 && index<=arr->length)
    {
        for(i=arr->length; i > index;i--)
            arr->array[i] = arr->array[i-1];
        
        
        arr->array[index] = element;
        return 1;
    }
    return 0;
}

int delete (struct Array *arr, int index)
{
    int i=0;
    
    if(index>=0 && index <= arr->length){
        for(i=index; i<=arr->length;i++)
        {
            arr->array[i] =arr->array[i+1];
        }
        arr->length--;
        return 1;
    }
    
    return 0;
    
}


/*
 Main Function to test all other funciton incldued in htis project.
 
 
 
 */
int main(int argc, const char * argv[])
{
    
    // This array will be created in the heap as we are dependent on user input of the size and the input.
    
    struct Array arr;
    int number, i=0;
    char permission;
    
    //Once the user puts the size input, the array will be created in the heap.
    // Initial length of arrat is zero as there are no other elements present.
    
    printf("Enter Size of the array: ");
    scanf("%d", &arr.size);
    arr.array = (int *) malloc(arr.size * sizeof(int));
    arr.length = 0;
    
    /*
     If for some reason we were not dealing with dynamic array then, initialisation of the struct would be in such format:
     
     struct Array arr = {{1,2,3,4,5,6},25,5};
     
     */
    
    printf("Enter number of elements to be added: ");
    scanf("%d", &number);
    printf("Enter all Elements: ");
    
    for(i=0;i<number;i++)
    {
        scanf("%d", &arr.array[i]);
    }
    // Updating length in struct.
    arr.length = number;
    
    //Displaying all the elements entered.
    display_elements(arr);
    
    /*
     Following is the code to append.
     Commented out to test other functions.
     */
    /*
     askagain:
     printf("Would you like to append any elements (Y or N)? ");
     scanf("%s", &permission);
     
     if(permission == 'Y'){
     int n;
     printf("Type number to append: ");
     scanf ("%d", &n);
     append(&arr, n);
     display_elements(arr);
     printf("\nAppend Succesfull");
     // break;
     }
     else if (permission == 'X')
     {
     printf("Nothing added.");
     
     }
     else {
     printf ("character didn't recognised, Please select between Y or N\n");
     goto askagain;
     }
     */
    /*
askagain_1:
    printf("\nWould you like to add any elements (Y or N)? ");
    scanf("%s", &permission);
    
    if(permission == 'Y'){
        int n,i;
        printf("Type number to append: ");
        scanf ("%d", &n);
        
        printf("What index? ");
        scanf ("%d", &i);
        
        int rr = insert(&arr, i, n);
        if(rr == 1){
            display_elements(arr);
            printf("\nAdditon Succesfull");
            
        }
        else{
            printf("Addition denied");
        }
        
        // break;
    }
    else if (permission == 'X')
    {
        printf("Nothing added.");
        
    }
    else {
        printf ("character didn't recognised, Please select between Y or N\n");
        goto askagain_1;
    }
    
    return 0;
    */
    
    
askagain_1:
    printf("\nWould you like to delete any elements (Y or N)? ");
    scanf("%s", &permission);
    
    if(permission == 'Y'){
        int i;

        printf("What index to delete? ");
        scanf ("%d", &i);
        
        int rr = delete(&arr, i);
        if(rr == 1){
            display_elements(arr);
            printf("\nDeletion Succesfull");
            
        }
        else{
            printf("\nDeletion denied");
        }
        
        // break;
    }
    else if (permission == 'X')
    {
        printf("Nothing added.");
        
    }
    else {
        printf ("character didn't recognised, Please select between Y or N\n");
        goto askagain_1;
    }
    
    return 0;
}
