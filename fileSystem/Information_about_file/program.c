#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<ctype.h>
#include<string.h>
#include <sys/stat.h>
#include <time.h>
void printFileProperties(struct stat stats)
{
    
    printf("\nFile access: ");
    if (stats.st_mode & R_OK)
        printf("read ");
    if (stats.st_mode & W_OK)
        printf("write ");
    if (stats.st_mode & X_OK)
        printf("execute");

    printf("\nFile size: %ld\n", stats.st_size);
    printf("Block size %ld\n",stats.st_blksize);
    printf("ID of device containing file %ld\n",stats.st_dev);
    printf("INODE NUMBER  %ld\n",stats.st_ino);
    printf("protection  %d\n",stats.st_mode);
    printf("Link count %ld\n",stats.st_nlink);
    printf("USER ID %d\n",stats.st_uid);
    printf("GROUP ID %d\n",stats.st_gid);
    printf("NUMBER OF BLOCK ALLOCATED %ld\n",stats.st_blocks);

struct tm dt;
      dt = *(gmtime(&stats.st_ctime));
    printf("\nCreated on: %d-%d-%d %d:%d:%d", dt.tm_mday, dt.tm_mon, dt.tm_year+1900, 
                                              dt.tm_hour, dt.tm_min, dt.tm_sec);

    // File modification time
    dt = *(gmtime(&stats.st_mtime));
    printf("\nModified on: %d-%d-%d %d:%d:%d\n", dt.tm_mday, dt.tm_mon, dt.tm_year+1900, 
                                              dt.tm_hour, dt.tm_min, dt.tm_sec);
}
int main(int argc,char *argv[])
{    
struct stat stats;
   if(argc != 2)
    {
        printf("You must run this program with arguments\n filename ");
        return 2;
    }
    if (stat(argv[1], &stats) == 0)
    {
        printFileProperties(stats);
    }
    else
    {
        printf("Unable to get file properties.\n");
        printf("Please check whether '%s' file exists.\n",argv[1]);
    }
    

    
   return 0;
}
