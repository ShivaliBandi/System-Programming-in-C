//input output redirection
#include<stdio.h>
int main()
{
    char buffer[1000]={'\0'};
    scanf("%[^\n]%*c", buffer); 
    printf("%s",buffer);
    return 0;
}
    
