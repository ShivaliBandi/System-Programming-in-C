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
    if(argc!=2)
    {

        printf("You must run this program with arguments\ndirectory name\n");
        return 2;
    }
    int icnt=0;
    if((stat(argv[1], &stats)!=-1) &&(S_ISDIR(stats.st_mode)!=0) )
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
                    printf("%s is FILE  \n",de->d_name);
                }
                if(de->d_type==4)
                {
                    printf("%s is DIRECTORY\n",de->d_name);
                }
                
            }
            printf("*******************%d\n",icnt);
            closedir(dr);
        
    }
    else
    {
        printf("ERROR:Directory %s doesn't exist\n",argv[1]);
        return -1;
    }     
    
      
    
    return 0; 
} 