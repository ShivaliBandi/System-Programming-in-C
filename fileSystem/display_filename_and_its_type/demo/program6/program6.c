#include<stdio.h>
#include<fcntl.h>
#include <unistd.h>
#include<string.h>
int main(int argc,char *argv[])
{
     if(argc != 2)
    {
        printf("You must run this program with arguments\n enter file name\n");
        return 2;
    } 
    int fd=0,inumber;
    char buffer[20]={'\0'};
    

    fd=open(argv[1],O_RDONLY);
    if(fd==3)
        printf("File %s opened successfully\n",argv[1]);
    else
        printf("Unable to open file\n");
    getchar();
    
    //inumber=read(fd,buffer,5000);
    //printf("%s",buffer);
      int i=0;
      while((inumber=read(fd,buffer,sizeof(buffer)))>0)
      {
        write(1,buffer,inumber);
        
      }

    
    printf("\n");
    fd=close(fd);
    if(fd!=0)
        printf("Unable to close file\n");
    else
        printf("File %s closed successfully\n",argv[1]);
    
    
}