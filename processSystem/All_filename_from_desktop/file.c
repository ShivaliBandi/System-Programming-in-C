#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<ctype.h>
#include<string.h>
#include<dirent.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc,char *argv[]) 
{ 
    struct dirent *de;  
    DIR *dr = opendir("/home/programmerinsane/Desktop"); 
    struct stat stats,file;
    int fd=creat("demo.txt",0777);
    if((stat("/home/programmerinsane/Desktop", &stats)!=-1) &&(S_ISDIR(stats.st_mode)!=0) )
    {
       
            printf("********Direcorty exists*********\n");
            if (dr == NULL)   
            { 
                printf("ERROR:Enable to open directory" ); 
                return -1; 
            } 
            
            while ((de = readdir(dr)) != NULL) 
            {
                if(de->d_type==8)
                {
                    write(fd,&de->d_name,strlen(de->d_name));
                    write(fd,"\n",1);
                }
                
                
            }
            close(fd);
            printf("SUCCESSFULLY Written all filename in demo.txt\n");
            closedir(dr);
        
    }
    else
    {
        printf("ERROR:Directory  doesn't exist\n");
        return -1;
    }     
    
      
    
    return 0; 
} 