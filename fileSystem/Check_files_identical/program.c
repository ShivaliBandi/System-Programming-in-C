//check two file's data..whether they are identical or not
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

///Function which checks that 10 bytes array of both files are same or not
int cmpFiles(char *buff1,char *buff2, int n)
{
    while (n-- > 0)
    {
        if (*buff1++ != *buff2++)
            return 0;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    int fd1 = 0, fd2 = 0, n1 = 0 , n2 = 0, flag = 1;
    char buff1[10] = {'\0'}, buff2[10] = {'\0'};
    printf("---- Files are Identical or not ----\n\n");

    if(argc == 3)
{
        //Opening the file in read mode for comparing
//printf("Checking for two files are identical or not\n");
fd1 = open(argv[1], O_RDONLY);
        fd2 = open(argv[2], O_RDONLY);

if(fd1 > 0 && fd2 > 0)
{
            while(1)
            {
                n1 = read(fd1,buff1,sizeof(buff1));
                n2 = read(fd2,buff2,sizeof(buff2));

                //no of bytes read by files are different
                if((n1 < n2) || (n1 > n2))
                {
                    flag = 0;
                    break;
                }
                //when control reach to the end of file, without setting it to flag just break
                else if(n1 == 0 || n2 == 0)
                {
                    break;
                }
                //If function returns zero
                else if(cmpFiles(buff1,buff2,n1) == 0)
                {
                    //printf("hiu");
                    flag = 0;
                    break;
                }
                //memset(buff1,'\0',10);
                //memset(buff2,'\0',10);
            }
            if(flag == 1)
                printf("Contents of %s and %s are equal\n",argv[1],argv[2]);
            else
                printf("Contents of %s and %s are not equal...!(NOT SAME)\n",argv[1],argv[2]);            
}
else
{
printf("Unable to open the file\n");
exit(0);
}
        //Closing both the files
        close(fd1);
        close(fd2);
        return 0;
    }
else
{
printf("Insufficient Argument..!\n");
return -1;
}
}
