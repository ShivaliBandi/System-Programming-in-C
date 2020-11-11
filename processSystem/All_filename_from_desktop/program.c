#include<stdio.h> 
#include<sys/wait.h> 
#include<unistd.h> 
  
int main() 
{ 
    int ino=fork();
 
    if (ino== 0) 
    {
        printf(" hello from child. parent id-> %d\nchild pid->%d\n",getppid(),getpid());  
        execl("./file","",NULL);       //sleep(200);    
    }
      
    else
    { 
        printf(" hello from parent process id->%d\n",getpid()); 
        
        wait(&ino);
        printf(" child has terminated \n"); 
    } 
    return 0; 
} 

