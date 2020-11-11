//nested child
#include<stdio.h> 
#include<sys/wait.h> 
#include<unistd.h> 
  
int main() 
{ 
    int child1=fork(),child2=0,child3=0;
  // using wait system call
    if (child1== 0) 
    {
        printf("hello from child1. id-> %d\n",getpid());  
        if ((child2=fork())== 0) 
        {
            printf("hello from child2 id-> %d\tchild1(parent) pid->%d\n",getpid(),getppid()); 
            if ((child3=fork())== 0) 
                printf("hello from child3 id-> %d\tchild2(parent) pid->%d\n",getpid(),getppid());   
                
            else
            {
                wait(&child3);
                printf("child3 terminated\n");
            }
                     
        } 
         else
            {
                wait(&child2);
                printf("child2 terminated\n");
            }
    } 
    else
    {
        wait(&child1);
        printf("child1 terminated\n");
    }
    return 0; 
} 

