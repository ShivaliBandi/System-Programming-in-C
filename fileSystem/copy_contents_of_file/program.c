#include<stdio.h>
#include<fcntl.h>
#include <unistd.h>
#include<string.h>
int main(int argc,char *argv[])
{
     if(argc != 3)
    {
        printf("You must run this program with arguments\n enter file names\n");
        return 3;
    } 
    int fd=0,fd1=0,inumber;
    char buffer[1000]={'\0'};
    

    fd=open(argv[1],O_RDONLY);
    fd1=creat(argv[2],07777);
    if(fd==3)
    {
        printf("File %s opened successfully\n",argv[1]);
        if(fd1!=-1)
        {
            printf("File %s created successfully\n",argv[2]);

             //int i=0;
            while((inumber=read(fd,buffer,sizeof(buffer)))>0)
            {
                write(fd1,buffer,inumber);
                
            }
        }
        else
        {
            printf("Unable to create file %s\n",argv[2]);
            return -1;

        }
            
    }    
    else
    {
         printf("Unable to open file %s\n",argv[1]);
         return -1;
    }
       
    
    
    //inumber=read(fd,buffer,5000);
    //printf("%s",buffer);
     

    
    printf("\n");
    fd=close(fd);
    fd1=close(fd1);
    if(fd!=0)
        printf("Unable to close file\n");
    else
        printf("File %s closed successfully\n",argv[1]);
    if(fd1!=0)
        printf("Unable to close file\n");
    else
        printf("File %s closed successfully\n",argv[2]);
    
    
}



