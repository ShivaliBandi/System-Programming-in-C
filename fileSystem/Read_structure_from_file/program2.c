/*
write structure in file using c
we take input from command line arguments

*/

#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <fcntl.h> 
#include <sys/stat.h>
#include<stdlib.h>
#include<string.h>
struct emp
{
    int id;
    char fname[50];
    char lname[50];
    float salary;
}Emp;
int main(int argc,char *argv[])
{
    if(argc!=2)
    {
        printf("ERROR:invalid argument..run this code using argument\nFILE NAME\n");
        return 2;
    }
   
    //printf("ID=%d\tFNAME=%s\tLNAME=%s\tSALARY=%f\n",Emp.id,Emp.fname,Emp.lname,Emp.salary);
   
   
  	int wfd;
    
    wfd=open(argv[1],O_RDONLY);
    if(wfd!=-1)
        printf("file opened successfully\n");
    else
    {
        printf("unable to open file");
    	return -1;
    }
    read(wfd,&Emp,sizeof(Emp));
    printf("%d\t%s\t%s\t%f\n",Emp.id,Emp.fname,Emp.lname,Emp.salary);
        wfd=close(wfd);
    if(wfd==0)
        printf("file closed successfully\n");
    else
        printf("unable to close file");
                
               
    return 0;
}
