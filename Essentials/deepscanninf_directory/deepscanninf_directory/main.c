#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

/*
 Dirent.h is used to format directory Entries.
 Here, DIR is defined, which represents a directory stream.
 
 We have to make struct dirent in order to access it.
 This struct defines following member(which we require for this program):
 char d_name[] : Name of a entry
 Size is unspecified.
 
 We opendir(), by sending the pathname of the directory we want to deepscan.
 it takes char *input, (pointer) as argument.
 If opendir returns null then directroy was not found.
 
 We use readdir():
 
 int readdir_r(DIR *restrict dirp, struct dirent *restrict entry,struct dirent **restrict result);
 
 Function shall return a pointer to a structure representing the directory entry at the current position in the directory stream specified by the argument dirp, and position the directory stream at the next entry. It shall return a null pointer upon reaching the end of the directory stream. The structure dirent defined in the <dirent.h> header describes a directory entry.
 
 readdir() shall return a pointer to an object of type struct dirent
 
 Struct Stat:
 
 These functions return information about a file, in the buffer pointed to by statbuf.  No permissions are required on the file  itself, but—in the case of stat(), fstatat(), and lstat()—execute (search) permission is required on all of the directories in pathnamethat lead to the file.
 
 stat() and fstatat() retrieve information about the file pointed to by pathname; the differences for fstatat() are described below.
 
 lstat() is identical to stat(), except that if pathname is a symbolic link, then it returns information about the link itself, not the file that it refers to.
 
 st_mode
 This field contains the file type and mode.  See inode(7) for further information.
 
 Each file has an inode containing metadata about the file.  An application can retrieve this metadata using stat(2) (or related calls), which returns a stat structure.
 S_ISDIR:
 
 The file mode, stored in the st_mode field of the file attributes, contains two kinds of information: the file type code, and the access permission bits.There are two ways you can access the file type information in a file mode.
 
 This symbol is defined in the header file sys/stat.h.
 
 The following predicate macros test the type of a file, given the value m which is the st_mode field returned by stat on that file:
 
 Macro: int S_ISDIR (mode_t m)
 
 And then recursively calling ther directories.
 
 chdir: is defined by unistd.h file.
 return 0 on success, -1 on failure.
 
 */
void deepScan(char *directory, int depth)
{
    DIR *directoryP;
    struct dirent *entry;
    struct stat statbuf;
   // int dnum = 0;
    
    if((directoryP = opendir(directory)) == NULL) {
        fprintf(stderr,"cannot open directory: %s\n", directory);
        return;
    }
    
    chdir(directory);
    
    printf("\nNew Directory has been found \n");
    
    int i=0;
    
    while((entry = readdir(directoryP)) != NULL)
    {
        i+=1;
        //printf("\ncall to while loop: %d \n", i);
        //printf("\n\nentry name: %s\n\n", entry->d_name);
        stat(entry->d_name,&statbuf);
        
        
        if(S_ISDIR(statbuf.st_mode)) {
            
            /* Found a directory, but ignore . and .. */
            if(strcmp(".",entry->d_name) == 0 ||strcmp("..",entry->d_name) == 0)
            {
                printf(" Found hidden file \n");
                
                continue;
            }
            //dnum+=1;
            printf("\nFollowing is a directory: ");
            printf("%*s%s \tst_mode: %d \tst_size: %lld ",depth,"",entry->d_name,statbuf.st_mode, statbuf.st_size);
            //printf(" Depth is: %d \n\n", dnum);
            deepScan(entry->d_name,depth+4);
            //dnum-=1;
        }
        else
        {
            //dnum=1;
            printf("\t----Following is a file: ");
            //printf("%*s%s %d",depth,"",entry->d_name,statbuf.st_mode);
            printf("%*s%s \tst_mode: %d \tst_size: %lld ",depth,"",entry->d_name,statbuf.st_mode, statbuf.st_size);
            printf( (statbuf.st_mode & S_IRUSR) ? "r" : "-");
            printf( (statbuf.st_mode & S_IWUSR) ? "w" : "-");
            printf( (statbuf.st_mode & S_IXUSR) ? "x" : "-");
            printf( (statbuf.st_mode & S_IRGRP) ? "r" : "-");
            printf( (statbuf.st_mode & S_IWGRP) ? "w" : "-");
            printf( (statbuf.st_mode & S_IXGRP) ? "x" : "-");
            printf( (statbuf.st_mode & S_IROTH) ? "r" : "-");
            printf( (statbuf.st_mode & S_IWOTH) ? "w" : "-");
            printf( (statbuf.st_mode & S_IXOTH) ? "x" : "-");
            //printf(" Depth is: %d", dnum);
            printf("\n\n");
            
        }
    }
    if((entry = readdir(directoryP)) == NULL)
    {
        printf("\n -------- have reached end of the folder. -------- \n");
        //dnum = dnum-1;
    }
    chdir("..");
    closedir(directoryP);
}

int main()
{
    deepScan("/Users/rohitluthra/Downloads/rluthra-master/hw1",0);
    printf("done.\n");
    exit(0);
}

