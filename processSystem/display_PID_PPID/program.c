//parent and pchild process id
#include<stdio.h> 
#include<sys/wait.h> 
#include<unistd.h> 
  
int main() 
{ 
    int ino=fork();
  // using wait system call
    if (ino== 0) 
    {
        printf(" hello from child. parent id-> %d\nchild pid->%d\n",getppid(),getpid());         //sleep(200);    
    }
      
    else
    { 
        printf(" hello from parent process id->%d\n",getpid()); 
        //sleep(200);   
           /*
        when we put sleep statment before wait
        it gives us dead child..
        so called zombie
        From your output we see a "defunct", which means the process has either completed its 
        task or has been corrupted or killed, but its child processes are still running or
         these parent process is monitoring its child process. To kill this kind of process, 
         kill -9 PID doesn't work. 
        You can try to kill them with this command but it will show this again and again.
       
       */
        int iwait= wait(&ino); //wait(NULL)
        printf(" child has terminated \t wait return value %d\n",iwait); 
    } 
    return 0; 
} 

/*


using waitid
 int ino=fork();
    if (ino== 0) 
        printf(" hello from child. parent id-> %d\n",getppid()); 
    else
    { 
        printf(" hello from parent process id->%d\n",getpid()); 
        //waitpid(0,&ino,0); 
        //printf(" child has terminated\n"); 
    } 
  
    
*/
