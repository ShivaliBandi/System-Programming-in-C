//delete all empty files from a directory
//input:directory name

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<ctype.h>
#include<string.h>
#include<dirent.h>
#include <sys/stat.h>
#include <time.h>
int move(char *filename,char *dirName)
{
    int fd=0,fd1=0,inumber;
    //char buffer[1000]={'\0'};
    
    char path[100]={'\0'};
    strcat(path,dirName);
    strcat(path,"/");
    strcat(path,filename);
    struct stat stats;
    
    //printf("\t\t%s\n",pathDes);
    //printf("\t\t%s\n",pathSour);
    fd=open(path,O_RDONLY);
    //fd1=creat(pathDes,07777);
    if(fd>=3)
    {
        printf("File %s opened successfully %d\n",filename,fd);
       
            stat(path,&stats);
            if(stats.st_size==0)
            {
                fd=close(fd);
                printf("**FILE IS EMPTY**** \n");
                unlink(path);
            }
            else
            {
                fd=close(fd);
            }
            
            if(fd!=0)
                printf("Unable to close file\n");
            else
                printf("File %s closed successfully\n",path);
           
        
        
    }    
    else
    {
         printf("Unable to open file %d\n",fd);
         return -1;
    }
    printf("\n");
    
   
    return 0;
}
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
                
                
                    
                

                icnt=move(de->d_name,argv[1]);
                
                
               
            }
            //printf("*******************%d\n",icnt);
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
     

    
    
    
    
