
//creating file into a specific directory
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
    int fd = 0;
    char path[100];
    DIR *dr;   
    printf("File Creation in particular Directory \n");

	if(argc != 3)
    {
        printf("ERROR:INVALID ARGUMENT\nRUN CODE WITH ARGUMENTS\nDIRECTORY NAME AND FILE NAME");
        return 3;
    }
   dr = opendir(argv[1]);
        if (dr == NULL)   
        { 
            printf("Unable to open %s directory\n",argv[1]); 
            return -1; 
        }

        //Creating file inside given directory - for that purpose creating path
        sprintf(path,"%s",argv[1]);
        sprintf(path+strlen(path),"/");
        sprintf(path+strlen(path),"%s",argv[2]);

        //printf("%s",path);
        fd = creat(path,0777);
        if(fd == -1)
        {
            printf("Unable to create file\n");
            return -1;
        }
        else
        {
            printf("File Created Successfully\n");
        }
        closedir(dr); 
        
    return 0; 
} 
