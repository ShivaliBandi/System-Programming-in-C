#include<stdio.h> 
#include<unistd.h> 
#include <sys/time.h>
#include <sys/resource.h>

int main(int argc,char *argv[]) 
{ 
nice(2);
/*
The range of the nice value is +19 (low priority) to -20 (high
       priority).  Attempts to set a nice value outside the range are
       clamped to the range.

       Traditionally, only a privileged process could lower the nice value
       (i.e., set a higher priority).  However, since Linux 2.6.12, an
       unprivileged process can decrease the nice value of a target process
       that has a suitable RLIMIT_NICE soft limit;
*/   
printf("PRIORITY OF PROCESS IS %d\n",getpriority(PRIO_PROCESS,getpid()));    

    return 0; 
} 
