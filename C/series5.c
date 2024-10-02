//1-2+3-4+5-6......-+n

#include<stdio.h>
void main()
{
    int x,n=6,sum=0;
    for(x=1;x<=n;x++)
    {
        if(x%2==0)
            x=x*-1;
        sum=sum+x;
    }
    printf("%d",sum);
}
