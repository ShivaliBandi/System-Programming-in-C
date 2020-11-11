//delete specific amount of data from a file
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    int fd1 = 0, fd2 = 0, i = 0, cnt = atoi(argv[2]), size1 = 0,size2 = 0;
    struct stat sb1,sb2;
    char buff[10] = {'\0'},path[50] = {'\0'};
    printf("---- Remove data from particular Offset ----\n");
  
    if(argc == 3)
    {
        //Open the original file
        fd1 = open(argv[1],O_RDONLY);
        strcpy(path,argv[1]);
        //Open the copied file
        fd2 = open("copy.txt",O_RDWR | O_CREAT ,0777);
        if(fd1 > 0)
        {           
            stat(argv[1],&sb1);
            size1 = sb1.st_size;

            printf("Size before removing data : %d \n",(int)size1);

            //If given offset value is greater then actual size of file, then read whole file only.
            if((int)size1 < cnt)
            {
                while((i = read(fd1,buff,sizeof(buff))) > 0)
                {
                    write(fd2,buff,i);
                }
            }
            //else read the given offsets only
            else
            {
                while(cnt > 0)
                {
                    cnt = cnt - (int)sizeof(buff);
                    i = read(fd1,buff,sizeof(buff));
                    write(fd2,buff,i);
                    memset(buff,'\0',10);
                }
                
            }

            //printf("File copied successfully\n\n");
            
            //remove the original file
            remove(path);

            //change the name of copied file
            rename("copy.txt",path);

            stat(argv[1],&sb2);
            size2 = sb2.st_size;

            printf("Size after removing data : %d \n",(int)size2);
            close(fd1);
            close(fd2);
            
        }
        else
        {
            printf("Unable to open the file\n");
            return -1;
        }
        return 0;
    }
    else
    {
        printf("Insufficient Argument..!\n");
        return -1;
    }
}
