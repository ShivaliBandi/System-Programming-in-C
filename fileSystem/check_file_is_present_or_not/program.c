//check whether a particular file is present or not in a directory
//input:give directory name

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
 
int main(int argc, char *argv[])
{
    int op = 0;
struct dirent *de;
    struct stat sb, obj;
    DIR *dr;  
     printf("---- File exists or not ----\n");

if(argc == 3)
    {
        //stat operation done successfully
        //cheacking for given file is directory or not
        //use S_ISDIR macro
        //This macro returns non-zero if the file is a directory.
        if ((stat(argv[1], &sb) != -1) && (S_ISDIR(sb.st_mode) != 0))
        {
            dr = opendir(argv[1]);
            if (dr == NULL)  
            {
                printf("Unable to open %s directory...!\n",argv[1]);
                return -1;
            }
            while ((de = readdir(dr)) != NULL)
            {
               if(strcmp(de->d_name,argv[2]) == 0)
               {
                    printf("%s exists in given %s directory,,!\n",argv[2],argv[1]);
                    break;
               }
            }
            if(de == NULL)
                printf("%s doen not exists in given %s directory,,!\n",argv[2],argv[1]);
            closedir(dr);
        }
        else
        {
            printf("%s is not a directory..!\n",argv[1]);
            exit(0);
        }  
    }
    else
    {
        printf("Insufficient Arguments..!\n");
    }
       
    return 0;
} 
