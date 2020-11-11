/*
compile the code using this command:gcc program1.c -lpthread
In this program we have created a simple thread and just displayed its id using pthread_self  function
threads are 

What is a Thread?
A thread is a single sequence stream within in a process. Because threads have some of the properties of processes, they are sometimes called lightweight processes.

What are the differences between process and thread?
Threads are not independent of one other like processes as a result threads shares with other threads their code section, data section and OS resources like open files and signals. But, like process, a thread has its own program counter (PC), a register set, and a stack space.

Why Multithreading?
Threads are popular way to improve application through parallelism. For example, in a browser, multiple tabs can be different threads. MS word uses multiple threads, one thread to format the text, other thread to process inputs, etc.
Threads operate faster than processes due to following reasons:
1) Thread creation is much faster.
2) Context switching between threads is much faster.
3) Threads can be terminated easily
4) Communication between threads is faster.
Can we write multithreading programs in C?
Unlike Java, multithreading is not supported by the language standard. POSIX Threads (or Pthreads) is a POSIX standard for threads. Implementation of pthread is available with gcc compiler.

https://www.geeksforgeeks.org/multithreading-c-2/


*/

#include<stdio.h>
#include<fcntl.h>
#include<pthread.h>
#include<stdlib.h>
void *fun(void *ivalue)
{
    int ireturn=100;
    //pthread_self is used to get current thread's id
    printf("inside fun thread\nthread id->%d\n",(int)pthread_self());
    printf("***********PARAMATER:%d**********\n",(int)ivalue);
  //  pthread_exit: used to terminate a thread
//Syntax:
//void pthread_exit(void *retval);
//Parameters: This method accepts a mandatory parameter retval which is the pointer
 //to an integer that stores the return status of the thread terminated. 
// The scope of this variable must be global so that any thread waiting to join this thread may read the return status.
 pthread_exit((void *)ireturn); 
  //return ;  

}
int main()
{
    pthread_t thread1;
    /*
    pthread_create - create a new thread
    #include <pthread.h>

       int pthread_create(pthread_t * thread, 
                   const pthread_attr_t * attr, 
                   void * (*start_routine)(void *), 
                   void *arg);


    
    thread: pointer to an unsigned integer value that returns the thread id of the thread created.
    attr: pointer to a structure that is used to define thread
            attributes like detached state, scheduling policy, 
            stack address, etc. Set to NULL for default thread attributes.
    start_routine: pointer to a subroutine that is executed by the thread. 
                The return type and parameter type of the subroutine must be of type void *.
                The function has a single attribute but if multiple values need to be passed to the
                function, a struct must be used.
    arg: pointer to void that contains the arguments to the function defined in the earlier argument

    On success, pthread_create() returns 0; on error, it returns an error
       number, and the contents of *thread are undefined.



    */
    int ivalue=12;
    void *iret;
    printf("in main function before creating thread\n");
    pthread_create(&thread1,NULL,fun,(void *)ivalue);
    /*
    pthread_join: used to wait for the termination of a thread.
    Syntax:

    ------int pthread_join(pthread_t th, 
                    void **thread_return);
    Parameter: This method accepts following parameters:

    th: thread id of the thread for which the current thread waits.
    thread_return: pointer to the location where the exit status of the thread mentioned in th is stored.
    
    
    pthread_self: used to get the thread id of the current thread.
    Syntax:

    pthread_t pthread_self(void);    
    */
    pthread_join(thread1,&iret);
    printf("in main function after thread\nreturn value of fun function is %d",(int)iret);


    return 0;
}