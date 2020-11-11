#include<stdio.h>

int main(int argc,char *argv[])
{
   if(argc != 2)
  {
    printf("You must run this program with an argument\n");
    return 2;
  }
  printf("%s\n",argv[1]);
    return 0;
}