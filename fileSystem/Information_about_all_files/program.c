
//write information about files from a directory into output.txt
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<ctype.h>
#include<string.h>
#include<dirent.h>
#include <sys/stat.h>
#include<stdlib.h>


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
    char buffer[1000]={'\0'};
    int maxSize=0;
    int output=creat("output.txt",0777);
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
                wfd=open("output.txt",O_RDWR | O_APPEND);
                if((wfd>0) && (de->d_type==8))
                {
                    printf("file opened successfully \t %s\n",de->d_name);
                   // printf("%s",send);

                    stat(send,&stats);

                    //write(wfd,"Filename : ",11);
                    sprintf(buffer,"FILE NAME %s\n",de->d_name); 
                    write(wfd,buffer,strlen(buffer));
                    memset(buffer,'\0',strlen(buffer));
                    sprintf(buffer,"FILE SIZE %d\n",(int)stats.st_size); 
                    write(wfd,buffer,strlen(buffer));                 
                    memset(buffer,'\0',strlen(buffer));
                    sprintf(buffer,"FILE INODE NUMBER %d\n",(int)stats.st_ino);
                    write(wfd,buffer,strlen(buffer));
                    write(wfd,"\n",1);
                    memset(buffer,'\0',strlen(buffer));
                    write(wfd,"File Permissions: \t",19);
                    sprintf(buffer,"%s",(S_ISDIR(stats.st_mode)) ? "d" : "-");
                    sprintf( buffer+strlen(buffer),"%s",(stats.st_mode & S_IRUSR) ? "r" : "-");
                    sprintf( buffer+strlen(buffer),"%s",(stats.st_mode & S_IWUSR) ? "w" : "-");
                    sprintf(buffer+strlen(buffer),"%s", (stats.st_mode & S_IXUSR) ? "x" : "-");
                    sprintf(buffer+strlen(buffer),"%s", (stats.st_mode & S_IRGRP) ? "r" : "-");
                    sprintf(buffer+strlen(buffer),"%s", (stats.st_mode & S_IWGRP) ? "w" : "-");
                    sprintf( buffer+strlen(buffer),"%s",(stats.st_mode & S_IXGRP) ? "x" : "-");
                    sprintf(buffer+strlen(buffer),"%s", (stats.st_mode & S_IROTH) ? "r" : "-");
                    sprintf( buffer+strlen(buffer),"%s",(stats.st_mode & S_IWOTH) ? "w" : "-");
                    sprintf( buffer+strlen(buffer),"%s",(stats.st_mode & S_IXOTH) ? "x" : "-");
                    sprintf(buffer+strlen(buffer),"\n");
                   // printf("%s",buffer);
                    write(wfd,buffer,strlen(buffer));
                    memset(buffer,'\0',strlen(buffer));
                    sprintf(buffer,"File system number: \t\t%d\n",(int)stats.st_dev);
                    write(wfd,buffer,strlen(buffer));
                    memset(buffer,'\0',strlen(buffer));
	                sprintf(buffer,"Number of blocks allocated for file\t%d\n",(int)stats.st_blocks);
                    write(wfd,buffer,strlen(buffer));
                    write(wfd,line,strlen(line));
                    
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



