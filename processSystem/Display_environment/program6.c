#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

int main()
{
    //Our running process is SHELL.
    printf("Environment of current process : %s\n",getenv("SHELL"));
    return 0;
}