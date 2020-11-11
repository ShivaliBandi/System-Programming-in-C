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
    DIR *dr = opendir(argv[1]); 
    struct stat stats,file;
    int iresult=0;
    if(argc!=2)
    {

        printf("You must run this program with arguments\ndirectory name\n");
        return 2;
    }
    char send[100];
    int icnt=0;
    int fd=0,fd1=0,inumber;
    char buffer[1000]={'\0'};
    int maxSize=0;
    char path[100]={'\0'};
    char dirName[100]={'\0'};
    if((stat(argv[1], &stats)!=-1) &&(S_ISDIR(stats.st_mode)!=0) )
    {
       
            printf("********Direcorty exists*********\n");
            if (dr == NULL)   
            { 
                printf("ERROR:Enable to open directory" ); 
                return -1; 
            } 
           strcpy(dirName,argv[1]);
            while ((de = readdir(dr)) != NULL) 
            {
                if(de->d_type==8)
                {
                    memset(path,'\0',sizeof(path));
                    strcat(path,dirName);
                    strcat(path,"/");
                    strcat(path,de->d_name);
                    struct stat stats;   
                    stat(path,&stats);
                    printf("%s-->%ld\n",de->d_name,stats.st_size);
                    if(stats.st_size>=maxSize)
                    {
                        strcpy(buffer,de->d_name);
                        maxSize=stats.st_size;

                    }

                }
               
            }
            printf("\n  FILE %s is having max size\n",buffer);
            closedir(dr);
        
    }
    else
    {
        printf("ERROR:Directory %s doesn't exist\n",argv[1]);
        return -1;
    }     
    
      
    
    return 0; 
} 
       
    
    
    //inumber=read(fd,buffer,5000);
    //printf("%s",buffer);
     

    
    
    
    
