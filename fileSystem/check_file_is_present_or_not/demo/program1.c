#include<stdio.h>
#include<fcntl.h>
#include <unistd.h>
int main(int argc,char *argv[])
{
   if(argc != 2)
  {
    printf("You must run this program with an argument\n");
    return 2;
  }
    int fd=0;
    fd=open(argv[1],O_RDONLY);
    if(fd==3)
        printf("File %s opened successfully\n",argv[1]);
    else
        printf("Unable to open file\n");
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