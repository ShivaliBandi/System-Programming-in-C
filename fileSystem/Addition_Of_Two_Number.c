#include<stdio.h>
int additionOfTwoNumbers(int inum1,int inum2)
{
    return (inum1+inum2);
}
int main()
{
    int inum1=0,inum2=0;
    printf("Enter Two Numbers To Perform Addition\n");
    scanf("%d%d",&inum1,&inum2);
   
    printf("Addition of %d + %d =%d\n",inum1,inum2,additionOfTwoNumbers(inum1,inum2));
    return 0;
}