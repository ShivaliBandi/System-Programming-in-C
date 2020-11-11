#include<stdio.h>
#include<fcntl.h>
#include <unistd.h>
#include<string.h>
int main()
{
    int fd=0,inumber;
    char fileName[20],buffer[50]={'\0'};
    printf("Enter filename that you want to open\n");
    scanf("%s",fileName);
    getchar();
     printf("Enter string you want to store in a file\n");
    scanf("%[^\n]%*c", buffer); 
    fd=open(fileName,O_RDWR);
    
    if(fd==3)
        printf("File %s opened successfully\n",fileName);
    else
        printf("Unable to open file\n");
    getchar();
     lseek(fd,0,SEEK_END);

        //writing string into file
        write(fd,"\n",1);
    inumber=write(fd,buffer,strlen(buffer));
    if(inumber==strlen(buffer))
        printf("data is written successfully");
    else 
    printf("data is not written successfully");
   
    printf("\n");
    fd=close(fd);
    if(fd!=0)
        printf("Unable to close file\n");
    else
    {
        printf("File %s closed successfully\n",fileName);
    }
    
}
