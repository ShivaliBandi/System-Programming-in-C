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
     /////////////
     
     fd=open(fileName,O_RDONLY);
    if(fd==3)
        printf("File %s opened successfully\n",fileName);
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
        printf("File %s closed successfully\n",fileName);
     
     
     
     
     
     
     /////////////////////////
     printf("Enter string you want to store in a file\n");
    scanf("%[^\n]%*c", buffer); 
   int fd1=open(fileName,O_RDWR);
    
    if(fd1==3)
        printf("File %s opened successfully\n",fileName);
    else
        printf("Unable to open file\n");
    getchar();
     lseek(fd1,0,SEEK_END);

        //writing string into file
        write(fd1,"\n",1);
    inumber=write(fd1,buffer,strlen(buffer));
    if(inumber==strlen(buffer))
        printf("data is written successfully");
    else 
    printf("data is not written successfully");
   
    printf("\n");
    fd1=close(fd1);
    if(fd1!=0)
        printf("Unable to close file\n");
    else
    {
        printf("File %s closed successfully\n",fileName);
    }
    
    
}
