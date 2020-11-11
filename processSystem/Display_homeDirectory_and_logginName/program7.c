#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
int main()
{
    //Our running process is SHELL.
    printf("Home directory : %s\n",getenv("HOME"));
    printf("Loggin user name : %s\n",getenv("LOGNAME"));

    return 0;
}