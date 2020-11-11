#include<stdio.h> 
#include<sys/wait.h> 
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<ctype.h>
#include<string.h>
#include<dirent.h>
#include <sys/stat.h>
#include <time.h>
int capitalCount(char *filename)
{
    char buff;
    int icnt=0;
    int fd1=0,fd=open(filename,O_RDONLY);
    while((fd1=read(fd,&buff,1))>0)
    {
        if(('A'<=buff) && ('Z'>=buff))
            icnt++;      
    }
    return icnt;
}
int main() 
{ 
    int fd=creat("count.txt",0777);
    int proc1 = 0,proc2=0;
    char buffer[1024]={'\0'};
    proc1 = fork();
    
  	//using wait system call
    if(proc1 == 0)
    {
         fd=open("count.txt",O_RDWR | O_APPEND);
        memset(buffer,'\0',strlen(buffer));
        int icnt=capitalCount("hello.txt");
        sprintf(buffer,"\nCOUNT FROM hello.txt-->%d \nProcess 1 terminated...!\n",icnt);            
        write(fd,buffer,strlen(buffer));
         //printf(" hello from child. parent id-> %d\nchild pid->%d\n",getppid(),getpid()); 
    } 
    else
    {
        if((proc2=fork()) == 0)
        {
            fd=open("count.txt",O_RDWR | O_APPEND);
            memset(buffer,'\0',strlen(buffer));
            int icnt=capitalCount("demo.txt");
            sprintf(buffer,"\nCOUNT FROM demo.txt-->%d \nProcess 2 terminated...!\n",icnt);
            write(fd,buffer,strlen(buffer));
         //printf(" hello from child. parent id-> %d\nchild pid->%d\n",getppid(),getpid()); 
        } 
        else
        {
            
        }
       
    }
    return 0; 
}