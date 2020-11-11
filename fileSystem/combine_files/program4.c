//combine data of all files using structure as filename and file size as a seperator
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<ctype.h>
#include<string.h>
#include<dirent.h>
#include <sys/stat.h>
#include<stdlib.h>

struct FileDet
{
    char fname[100];
    int fsize;
}filename;
int main(int argc,char *argv[])
{
   struct dirent *de;  
    DIR *dr = opendir(argv[1]);
    struct stat stats;
    int iresult=0;
    if(argc!=2)
    {
        printf("You must run this program with arguments\ndirectory name\n");

        return 2;
    }
   
    //char send[100];
    int icnt=0;
    int fd=0,inumber;
    char buffer[1000]={'\0'};
    int maxSize=0;
    int fddest=creat("output.txt",0777);
    int fdsrc;
    int wfd;
    char path[1000]={'\0'};
    char line[]="\n---------------------------------------------------------------------------------\n";
    if((stat(argv[1], &stats)!=-1) &&(S_ISDIR(stats.st_mode)!=0) )
    {
       
            printf("********Direcorty exists*********\n");
            if (dr == NULL)  
            {
                printf("ERROR:Enable to open directory" );
                return -1;
            }
         
            while (((de = readdir(dr)) != NULL) && ((de->d_type)==8))
            {
                sprintf(path,"%s/%s",argv[1],de->d_name);
                stat(path,&stats);
                strcpy(filename.fname,de->d_name);
                filename.fsize=stats.st_size;
                write(fddest,&filename,sizeof(filename));
                memset(&filename,0,sizeof(filename));


                fdsrc=open(path,O_RDONLY);
                while((wfd=read(fdsrc,&buffer,sizeof(buffer)))!=0)
                {
                    write(fddest,buffer,wfd);
                }
                memset(buffer,0,sizeof(buffer));
                close(fdsrc);
                

            }
            
       closedir(dr);
   
    close(fddest);  
    }
  
    else
    {
        printf("ERROR:Directory %s doesn't exist\n",argv[1]);
        return -1;
    }    
   
     
   
    return 0;
}



