//delete files greater than 100bytes
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h> 
#include <stdlib.h>
#include <unistd.h>
  
int main(int argc,char *argv[]) 
{ 
    struct dirent *de;
    struct stat stats, obj; 
    DIR *dr;
    char name[50] = {'\0'};
    
    if(argc!= 2)
    {
        printf("ERROR:INVALID ARGUMENTS\nRUN CODE WITH ARGUMENT\n DIRECTORY\n");
        return 2;
       
    }
    if ((stat(argv[1], &stats) != -1) && (S_ISDIR(stats.st_mode) != 0))
		{
            dr = opendir(argv[1]);
            if (dr == NULL)   
            { 
                printf("Unable to open %s directory...!\n",argv[1]); 
                return -1; 
            }

            printf("Deleting all such files whose size is greater than 100 bytes from %s directory\n",argv[1]);
            while ((de = readdir(dr)) != NULL) 
            {
                
                if(de->d_type == 8)
                {
                    
                    strcat(name,argv[1]);
                    strcat(name,"/");
                    strcat(name,de->d_name);
                    

                    if(stat(name,&obj)==0)
                    {
                        
                        if(100 < (int)obj.st_size)
                        {
                            printf("%s is deleted\n",de->d_name);
                            
                            unlink(name);
                        }
                    }
                    
                    memset(name,'\0',50);
                }
            }
            closedir(dr);
        }
        else
        {
            printf("ERROR:DIRECTORY DOESNT EXSIST\n");
            exit(0);
        }   
        
    return 0; 
} 
