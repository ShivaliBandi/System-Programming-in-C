#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include<string.h>
#include<fcntl.h>
#include<ctype.h>
#include<stdlib.h>
int main (int argc, char* argv[])
{
 char* path = argv[1];
 int rval,j=0;
  char ch,str[40];
  if(argc != 3)
    {
        printf("You must run this program with arguments\n filename and mode respectively\n");
        return 3;
    }
   strcpy(str,argv[2]);
    while (str[j])
    { 
        ch = str[j]; 
        str[j]=tolower(ch); 
        j++;
    } 
 /* Check file existence. */
 rval = access (path, F_OK);
 if (rval == 0) 
	printf ("%s exists\n", path);
 else
 {
	  if (errno == ENOENT) 
	   printf ("%s does not exist\n", path);
	  else if (errno == EACCES) 
	   printf ("%s is not accessible\n", path);
	  return 0;
 }

 /* Check read access. */
 if(strcmp(str,"read")==0)
 {
    rval = access (path, R_OK);
    if (rval == 0)
        printf ("%s is readable\n", path);
    else
        printf ("%s is not readable (access denied)\n", path);

 }
 
 /* Check write access. */
 if(strcmp(str,"write")==0)
 {
rval = access (path, W_OK);
 if (rval == 0)
 	printf ("%s is writable\n", path);
 else if (errno == EACCES)
 	printf ("%s is not writable (access denied)\n", path);
 else if (errno == EROFS)
 	printf ("%s is not writable (read-only filesystem)\n", path);
 

 }

 //checking for execute permission
		if(strcmp(argv[2],"execute") == 0)
		{
			rval= access(argv[1],X_OK);
			if(rval!= -1)
			{
				printf("File is executable(Allowed) \n");
			}
			else
			{
				printf("File is not executable(Access Denied)...!\n");
				exit(0);
			}
		}
		
		//close system call
    	if(close(rval) == 0)
		{
		    printf("File closed successfully\n");
		}
		else
		{
		    printf("Unable to close file\n");
		    exit(0);
		}
		return 0;
}
