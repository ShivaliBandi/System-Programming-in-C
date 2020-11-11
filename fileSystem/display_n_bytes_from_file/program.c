// C program to read nth byte of a file and 
// copy it to another file using lseek 
#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <fcntl.h> 
#include <sys/stat.h>
#include<stdlib.h>
#include<string.h>
// Driver code 
int main(int argc,char* argv[]) 
{ 
    
     if(argc!=3)
    {

        printf("You must run this program with arguments\nfile name and position\n");
        return 3;
    }
   
	// Open the file for READ only. 
	int f_read = open(argv[1], O_RDONLY); 
    int inumber=0,count=atoi(argv[2]);
    struct stat stats;
    stat(argv[1],&stats);
    char *buffer=(char *)malloc(stats.st_size*sizeof(char));
	// Open the file for WRITE and READ only. 
	//int f_write = open("output.txt", O_WRONLY); 
	lseek(f_read,count,SEEK_SET);
	inumber=read(f_read,buffer,20);
    write(1,buffer,strlen(buffer));
                
//	close(f_write); 
	close(f_read); 
	return 0; 
} 	
