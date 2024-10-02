#include <stdio.h>
int main()
{
    int num,a,rev,sum=0;
    printf("Enter the integer digit number : ");
    scanf("%d",&num);
    while(num!=0)
    {
        a=num%10;
        sum+=a;
        num=num/10;
    }
    printf("The sum is %d",sum);
    return 0;
}
