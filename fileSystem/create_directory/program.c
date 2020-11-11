//create a directory
#include<stdio.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include<stdlib.h>
#include<errno.h>
#include<string.h>
int main(int argc,char *argv[])
{
    if(argc!=2)
    {

        printf("You must run this program with arguments\ndirectory name\n");
        return 2;
    }
    int fd=mkdir(argv[1],0777);
    if(fd==0)
    printf("DIRECTORY CREATED SUCCESSFULLY\n");
    else
    {
        printf("ERROR %s",strerror(errno));
        return -1;
    }

    system("dir"); 
    
   return 0;
}
    
