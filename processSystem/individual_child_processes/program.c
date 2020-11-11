
//individual child processes of one parent process
#include<stdio.h> 
#include<sys/wait.h> 
#include<unistd.h> 
int main()
{
    int process1=0,process2=0,process3=0;
    if((process1=fork())==0)
        printf("child of process1\tPID->%d\tPPID->%d\n",getpid(),getppid());
    else
    {
        wait(&process1);
        printf("process1\t        PID->%d\tPPID->%d\n",getpid(),getppid());
        if((process2=fork())==0)
            printf("child of process2\tPID->%d\tPPID->%d\n",getpid(),getppid());
        else
        {
            wait(&process2);
            printf("process2\t        PID->%d\tPPID->%d\n",getpid(),getppid());
            if((process3=fork())==0)
                printf("child of process3\tPID->%d\tPPID->%d\n",getpid(),getppid());
            else
            {
                wait(&process3);
                printf("process3\t        PID->%d\tPPID->%d\n",getpid(),getppid());
            }
            
        }
        
    }
    
    return 0;
}
