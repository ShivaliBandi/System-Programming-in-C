#include<stdio.h>
#include<fcntl.h>
#include <unistd.h>
#include<string.h>
int main(int argc,char *argv[])
{
    int fd=0,inumber;
    //char fileName[20],buffer[50]={'\0'};
       if(argc != 3)
    {
        printf("You must run this program with arguments\n enter file name and text that you want to write in file\n");
        return 3;
    } 
    fd=open(argv[1],O_RDWR);
    
    if(fd==3)
        printf("File %s opened successfully\n",argv[1]);
    else
        printf("Unable to open file\n");
    getchar();
     lseek(fd,0,SEEK_END);

        //writing string into file
        write(fd,"\n",1);
    inumber=write(fd,argv[2],strlen(argv[2]));
    if(inumber==strlen(argv[2]))
        printf("data is written successfully\n data is %s\n",argv[2]);
    else 
    printf("data is not written successfully");
   
    printf("\n");
    fd=close(fd);
    if(fd!=0)
        printf("Unable to close file\n");
    else
    {
        printf("File %s closed successfully\n",argv[1]);
    }
    
}
