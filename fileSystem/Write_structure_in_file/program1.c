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
#include<errno.h>
struct emp
{
    int id;
    char fname[10];
    char lname[10];
    float salary;
}Emp,Emp2;
int main(int argc,char *argv[])
{
    if(argc!=5)
    {
        printf("ERROR:invalid argument..run this code using argument\nID\tFIRST NAME\tLAST NAME\tSALARY\n");
        return 5;
    }
    Emp.id=atoi(argv[1]);
    strcpy(Emp.fname,argv[2]);
    strcpy(Emp.lname,argv[3]);
    Emp.salary=atof(argv[4]);
    char buffer[1024]={'\0'};
    //printf("ID=%d\tFNAME=%s\tLNAME=%s\tSALARY=%f\n",Emp.id,Emp.fname,Emp.lname,Emp.salary);
    int wfd=creat("emp.txt",0777);
    wfd=open("emp.txt",O_RDWR);
  	int inum=write(wfd,&Emp,sizeof(Emp));
  	if(inum!=-1)
  		printf("STRUCTURE WRITTEN IN FILE SUCCESSFULLY\n");
  	else
  	printf("ERROR:UNABLE TO WRTIE STRUCTURE IN FILE\n");	
               
    lseek(wfd,0,SEEK_SET);
    read(wfd,&Emp2,sizeof(Emp2));
    printf("%d\t%s\t%s\t%f\n",Emp2.id,Emp2.fname,Emp2.lname,Emp2.salary);
        wfd=close(wfd);
    if(wfd==0)
        printf("file closed successfully\n");
    else
        printf("unable to close file");
                
               
    return 0;
}
