
static void extracted() {
    struct dirent* direntobject = readdir(directory);
}

int serialize_directory(int depth) {
    //debug("i m in serialize_directory");
    
    struct stat statttt;
    DIR * directory = opendir(path_buf);
    
    if(directory == NULL)
        return -1;
    
    extracted();
    
    /*Make dirent, stat and directory object. If directory is null then return -1;*/
    
    while((direntobject = ) != NULL)
    {
        int type = 0;
        path_push(direntobject->d_name);
        char *temporary = direntobject->d_name;
        int lengthoffile = 0;
        
        while(*temporary)
        {
            lengthoffile++;
            temporary+=1;
        }
        
        temporary = direntobject->d_name;
        stat(path_buf, &statbuff);
        
        if((*(direntobject->d_name) == '.') || (*(direntobject->d_name+1) == '.'))
        {
            path_pop();
        }
        else
        {
            if(S_ISDIR(statbuff.st_mode))
            {
                
                int magicByte_1 = 0x0c;
                int magicByte_2 = 0x0d;
                int magicByte_3 = 0xed;
                int magicByte_4 = 4;
                
                putchar(magicByte_1);
                putchar(magicByte_2);
                putchar(magicByte_3);
                putchar(magicByte_4);
                
                int i =3;
                
                while(i>-1)
                {
                    putchar((depth)>> (i*8)& 0xff);
                    i--;
                }
                
                i =7;
                long random = 28 + lengthoffile;
                
                while(i>-1)
                {
                    putchar((random)>> (i*8)& 0xff);
                    i--;
                }
                
                i = 3;
                while(i>-1)
                {
                    putchar((statbuff.st_mode) >> (i*8)& 0xff);
                    i--;
                }
                
                i =7;
                
                while(i>-1)
                {
                    putchar((statbuff.st_size) >> (i*8)& 0xff);
                    i--;
                }
                
                while(*temporary)
                {
                    putchar(*temporary);
                    temporary+=1;
                }
                
                depth++;
                
                magicByte_1 = 0x0c;
                magicByte_2 = 0x0d;
                magicByte_3 = 0xed;
                magicByte_4 = 2;
                
                putchar(magicByte_1);
                putchar(magicByte_2);
                putchar(magicByte_3);
                putchar(magicByte_4);
                
                i =3;
                
                while(i>-1)
                {
                    putchar((depth)>> (i*8)& 0xff);
                    i--;
                }
                
                i =7;
                random = 16;
                
                while(i>-1)
                {
                    putchar((random)>> (i*8)& 0xff);
                    i--;
                }
                
                
                //fprintf(stdout, "0c 0d ed %02x %08x %016x\n", 2, depth, 16);
                serialize_directory(depth);
                
                magicByte_1 = 0x0c;
                magicByte_2 = 0x0d;
                magicByte_3 = 0xed;
                magicByte_4 = 3;
                
                putchar(magicByte_1);
                putchar(magicByte_2);
                putchar(magicByte_3);
                putchar(magicByte_4);
                
                i = 3;
                
                while(i>-1)
                {
                    putchar((depth)>> (i*8)& 0xff);
                    i--;
                }
                
                i =7;
                random = 16;
                
                while(i>-1)
                {
                    putchar((random)>> (i*8)& 0xff);
                    i--;
                }
                //fprintf(stdout, "0c 0d ed %02x %08x %016x\n", 3, depth, 16);
            }
            
            else
            {
                
                int magicByte_1 = 0x0c;
                int magicByte_2 = 0x0d;
                int magicByte_3 = 0xed;
                int magicByte_4 = 4;
                
                putchar(magicByte_1);
                putchar(magicByte_2);
                putchar(magicByte_3);
                putchar(magicByte_4);
                
                int i = 3;
                
                while(i>-1)
                {
                    putchar((depth)>> (i*8)& 0xff);
                    i--;
                }
                
                i = 7;
                long random = 28 + lengthoffile;
                
                while(i>-1)
                {
                    putchar((random)>> (i*8)& 0xff);
                    i--;
                }
                
                i =3;
                
                while(i>-1)
                {
                    putchar((statbuff.st_mode) >> (i*8)& 0xff);
                    i--;
                }
                
                i =7;
                
                while(i>-1)
                {
                    putchar((statbuff.st_size) >> (i*8)& 0xff);
                    i--;
                }
                //fprintf(stdout, "0c 0d ed %02x %08x %016x %08x %016lx", 4, depth, 28 + lengthoffile, statbuff.st_mode, statbuff.st_size);
                while(*temporary)
                {
                    putchar(*temporary);
                    //fprintf(stdout, "%02x", *temporary);
                    temporary+=1;
                }
                serialize_file(depth, statbuff.st_size);
                path_pop();
            }
        }
    }
    closedir(directory);
    
    return 0;
}

int serialize_file(int depth, off_t size) {
    FILE *filetoopen;
    char c;
    filetoopen = fopen(path_buf, "r");
    
    int magicByte_1 = 0x0c;
    int magicByte_2 = 0x0d;
    int magicByte_3 = 0xed;
    int magicByte_4 = 5;
    
    putchar(magicByte_1);
    putchar(magicByte_2);
    putchar(magicByte_3);
    putchar(magicByte_4);
    
    int i =3;
    
    while(i>-1)
    {
        putchar((depth)>> (i*8)& 0xff);
        i--;
    }
    
    i =7;
    long random = size+16;
    
    while(i>-1)
    {
        putchar((random)>> (i*8)& 0xff);
        i--;
    }
    
    while(1)
    {
        c = fgetc(filetoopen);
        if(c == EOF)
            break;
        putchar(c);
    }
    
    ////(stdout, "0c 0e ed %02x %08x %016lx", 5, depth, size+16);
    
    
    fclose(filetoopen);
    
    return 0;
    
}

/**
 * @brief Serializes a tree of files and directories, writes
 * serialized data to standard output.
 * @details This function assumes path_buf has been initialized with the pathname
 * of a directory whose contents are to be serialized.  It traverses the tree of
 * files and directories contained in this directory (not including the directory
 * itself) and it emits on the standard output a sequence of bytes from which the
 * tree can be reconstructed.  Options that modify the behavior are obtained from
 * the global_options variable.
 *
 * @return 0 if serialization completes without error, -1 if an error occurs.
 */
int serialize() {
    
    int depth = 1;
    int magicByte_1 = 0x0c;
    int magicByte_2 = 0x0d;
    int magicByte_3 = 0xed;
    int magicByte_4 = 0;
    
    putchar(magicByte_1);
    putchar(magicByte_2);
    putchar(magicByte_3);
    putchar(magicByte_4);
    
    int i = 3;
    int zeerro = 0;
    
    while(i>-1)
    {
        putchar((zeerro)>> (i*8) & 0xff);
        i--;
    }
    
    
    i =7;
    long random = 16;
    
    while(i>-1)
    {
        putchar((random)>> (i*8) & 0xff);
        i--;
    }
    
    //fprintf(stdout,"0c 0d ed 00 00000000 0000000000000010\n");
    
    magicByte_4 = 2;
    
    putchar(magicByte_1);
    putchar(magicByte_2);
    putchar(magicByte_3);
    putchar(magicByte_4);
    
    i =3;
    
    while(i>-1)
    {
        putchar((depth)>> (i*8)& 0xff);
        i--;
    }
    
    i =7;
    
    random = 16;
    
    while(i>-1)
    {
        putchar((random)>> (i*8)& 0xff);
        i--;
    }
    //fprintf(stdout, "0c 0d ed %02x %08x %016x\n", 2, depth, 16);
    
    serialize_directory(depth);
    
    
    magicByte_4 = 3;
    
    putchar(magicByte_1);
    putchar(magicByte_2);
    putchar(magicByte_3);
    putchar(magicByte_4);
    
    i =3;
    while(i>-1)
    {
        putchar((depth)>> (i*8)& 0xff);
        i--;
    }
    
    i = 7;
    random = 16;
    
    while(i>-1)
    {
        putchar((random)>> (i*8)& 0xff);
        i--;
    }
    //fprintf(stdout, "0c 0d ed %02x %08x %016x\n", 3, depth, 16);
    
    magicByte_4 = 1;
    
    putchar(magicByte_1);
    putchar(magicByte_2);
    putchar(magicByte_3);
    putchar(magicByte_4);
    
    i =3;
    //depth--;
    
    while(i>-1)
    {
        putchar((zeerro)>> (i*8)& 0xff);
        i--;
    }
    
    i =7;
    random = 16;
    
    while(i>-1)
    {
        putchar((random)>> (i*8)& 0xff);
        i--;
    }
    //fprintf(stdout,"0c 0d ed 01 00000000 0000000000000010\n");
    
    return 0;
}
