#include<stdio.h>
#include<math.h>
void main()
{
    int x,z,n=3,fact=1,num;
    float sum;
    for(x=1;x<=n;x++)
        {
            fact=fact*x;
        }
    for(x=1;x<=n;x++)
    {
        num=pow(x,x);
        sum=sum+(num/fact);
    }
    printf("%f ",sum);
}
