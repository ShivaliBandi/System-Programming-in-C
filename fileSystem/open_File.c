#include<stdio.h>
#include<fcntl.h>
#include <unistd.h>
int main()
{
    int fd=0;
    char fileName[20];
    fd=open(fileName,O_RDONLY);
    if(fd==3)
        printf("File %s opened successfully\n",fileName);
    else
        printf("Unable to open file\n");
    getchar();
getchar();
    fd=close(fd);
    if(fd!=0)
        printf("Unable to close file\n");
    else
    {
        printf("File %s closed successfully\n",fileName);
    }
    
}
