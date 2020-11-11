#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<ctype.h>
#include<string.h>
#include<dirent.h>
#include <sys/stat.h>
//#include <time.h>
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
   
    char send[100];
    int icnt=0;
    int fd=0,inumber;
    char buffer[100]={'\0'};
    int maxSize=0;
    int output=creat("demo.txt",0777);
    int wfd;
    char line[]="\n---------------------------------------------------------------------------------\n";
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
                memset(send,'\0',sizeof(send));
                strcat(send,argv[1]);
                strcat(send,"/");
                strcat(send,de->d_name);
                
                //printf("%s",buffer);
                wfd=open("demo.txt",O_RDWR | O_APPEND);
                if((wfd>0) && (de->d_type==8))
                {
                    //printf("file opened successfully \t %d\n",wfd);
                    printf("%s",send);
                    fd=open(send,O_RDONLY);
                    inumber=read(fd,buffer,10);
                    write(wfd,buffer,inumber);
                    write(wfd,line,sizeof(line)-1);
                    close(fd);
                }
                
               
                wfd=close(wfd);
                if(wfd==0)
                    printf("file closed successfully\n");
                else
                {
                    printf("unable to close file");
                }
               
            }
            //printf("\n  FILE %s is having max size\n",buffer);
            closedir(dr);
       
    }
    else
    {
        printf("ERROR:Directory %s doesn't exist\n",argv[1]);
        return -1;
    }    
   
     
   
    return 0;
}
