#include<stdio.h>
#include<fcntl.h>
#include <unistd.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
    int fd=0,inumber;
    char buffer[50];
    if(argc != 3)
    {
        printf("You must run this program with arguments\n filename and number of bytes you want to read from the file respectively\n");
        return 3;
    } 
    int  ino=atoi(argv[2]);
    fd=open(argv[1],O_RDONLY);
    if(fd==3)
        printf("File %s opened successfully\n",argv[1]);
    else
        printf("Unable to open file\n");
    getchar();
    inumber=read(fd,buffer,ino);
    for(int i=0;i<=ino;i++)
    {
        printf("%c",buffer[i]);
    }
    printf("\n");
    fd=close(fd);
    if(fd!=0)
        printf("Unable to close file\n");
    else
    {
        printf("File %s closed successfully\n",argv[1]);
    }
    
}