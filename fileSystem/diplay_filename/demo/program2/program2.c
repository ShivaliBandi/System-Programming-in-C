#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<ctype.h>
#include<string.h>
#include <sys/stat.h>
#include <time.h>
int main(int argc,char *argv[])
{
    struct stat stats;

   if(argc != 3)
    {
        printf("You must run this program with arguments\n filename and mode respectively\n");
        return 3;
    }
    int fd=0,j=0;
    char ch,str[40];
   strcpy(str,argv[2]);
    while (str[j])
    { 
        ch = str[j]; 
        str[j]=tolower(ch); 
        j++;
    } 
  //  printf("%s\n",str);
    if(strcmp(str,"read")==0)
        fd=open(argv[1],O_RDONLY);
    else if(strcmp(str,"write")==0)
        fd=open(argv[1],O_WRONLY);
    else if(strcmp(str,"readandwrite")==0)
        fd=open(argv[1],O_RDWR);
    else if(strcmp(str,"append")==0)
        fd=open(argv[1],O_APPEND);

    if(fd==3)
        printf("File %s opened successfully\nfd=%d\n",argv[1],fd);
    else
        printf("Unable to open file\nfd=%d\n",fd);
    getchar();
getchar();
    fd=close(fd);
    if(fd!=0)
        printf("Unable to close file\n");
    else
    {
        printf("File %s closed successfully\n",argv[1]);
    }
}