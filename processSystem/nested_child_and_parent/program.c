
//neested child and parent process
#include<stdio.h> 
#include<sys/wait.h> 
#include<unistd.h>

int main() 
{ 
    int proc1 = 0, child2 = 0, child3 = 0;
    
    proc1 = fork();
    
  	//using wait system call
    if(proc1 == 0)
    {
        printf("Process 1 PID :%d\tPPID : %d\n", getpid(), getppid());
        if((child2 = fork()) == 0) 
        {
        	printf("Child 2 PID :%d\tPPID : %d\n", getpid(), getppid()); 
        }
        else
        {
        	
        	if((child3 = fork()) == 0)
            {
                printf("Child 3 PID :%d\tPPID : %d\n", getpid(), getppid());
            }
            else
            {
            	wait(&child3);
                printf("Child 3 terminated...!\n");
                printf("Child 2 terminated...!\n");
            }
            wait(&child2);
        } 
    } 
    else
    {
    	wait(&proc1);
        printf("Process 1 terminated...!\n");
    }
    return 0; 
}
