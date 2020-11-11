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
    struct stat stats;
    if(argc!=2)
    {

        printf("You must run this program with arguments\ndirectory name\n");
        return 2;
    }
    if((stat(argv[1], &stats)!=-1) &&(S_ISDIR(stats.st_mode)!=0) )
    {
       
            printf("********Direcorty exists*********\n");
            if (dr == NULL)   
            { 
                printf("ERROR:Enable to open directory" ); 
                return -1; 
            } 
            while ((de = readdir(dr)) != NULL) 
                printf("%s\n", de->d_name); 
            closedir(dr);
        
    }
    else
    {
        printf("ERROR:Directory %s doesn't exist\n",argv[1]);
        return -1;
    }     
    
      
    
    return 0; 
} 