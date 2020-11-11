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
    char oldPath[1024]={'\0'};
    char newPath[1024]={'\0'};
    char temp[1024]={'\0'};
    char filename[1024]={'\0'};
    int icnt=1;

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
                    
                    char  *iresult=strstr(de->d_name,".txt");
                    if(strcmp(iresult,".txt")==0)
                    {
                        memset(oldPath,'\0',strlen(oldPath));
                        memset(newPath,'\0',strlen(newPath));
                        sprintf(oldPath,"%s/%s",argv[1],de->d_name);
                        sprintf(newPath,"%s/%d.txt",argv[1],icnt);
                        icnt++;
                        int ret=rename(oldPath,newPath);
                        if(ret==0)
                            printf("FILE %s renamed to %s\n",oldPath,newPath);
                       //rename
                    }
                    }
                
                
            }
           
            
            closedir(dr);
        
    }
    else
    {
        printf("ERROR:Directory  doesn't exist\n");
        return -1;
    }     
    
      
    
    return 0; 
} 