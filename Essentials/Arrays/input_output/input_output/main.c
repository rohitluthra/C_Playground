//
//  main.c
//  input_output
//
//  Created by Rohit Luthra on 9/14/19.
//  Copyright © 2019 Rohit Luthra. All rights reserved.
//

#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
int main(int argc, const char * argv[]) {
    
    
    /*
    Followinf program scans one directory.
     */
    // Directory Entry Pointer
    /*
    struct dirent *de;
    // open dir return pointer of DIR type.
    DIR *dr = opendir(".");
    
    // opendir return null if directory is not found.
    if(dr == NULL){
        printf ("Couldnot open directory.");
        return 0;
    }
    while( (de = readdir(dr)) != NULL)
        printf("%s\n", de->d_name);
    
    closedir(dr);
    return 0;
    */
    
    
    /*
     Following reads a file
     
     FILE *file1 ;
     char c;
     file1 =  fopen("/Users/rohitluthra/Documents/GitHub/C_implementation/Essentials/Arrays/input_output/temp.txt",  "r");
     
     while(1){
     c = fgetc(file1);
     if(c ==EOF){
     break;
     }
     else{
     printf("%c", c);
     }
     }
     */
    
    
     //Following copied the above file content to some other file
    FILE *file1 ;
    char c;
    file1 =  fopen("/Users/rohitluthra/Documents/GitHub/C_implementation/Essentials/Arrays/input_output/temp.txt",  "r");
    
     FILE *fpp;
     fpp = fopen("../test.txt", "w");
    
    //printf("Cwd %s: ", );
     
     while (1)
     {
     c = fgetc (file1);
     if(c == EOF){
     break;
     }
     fputc(c, fpp);
     }
     
     fclose(fpp);
     fclose(file1);
    

}
 
