#include <stdio.h>
int main()
{
    int num,a=0,a1=0;
    printf("Enter the 4 digit number : ");
    scanf("%d",&num);//1234
    a=num%10;//4
    a1=num/1000;
    printf("The sum of first and last digit is %d",(a+a1));
    return 0;
}
