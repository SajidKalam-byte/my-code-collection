// x^1 - x^3 + x^5 -x^7 .....x^n
#include <stdio.h>
#include <math.h>
void main()
{
    int x, n, i,sum=0,sign=1;
    printf("Enter value of x :");
    scanf("%d",&x);
    printf("Enter range :");
    scanf("%d",&n);

    for(i=1;i<=n;i+=2)
    {
        sum=sum+pow(x,i)*sign;
        sign=sign*(-1);
    }
    printf("The sum is %d",sum);
}

