#include<stdio.h>
void main()
{
    int n=6,check=1;
    for(int i=2;i<=n/2;i++)
    {
        if(n%i==0)
            check=0;
        break;
    }
    if(check==1)
        printf("Prime");
    else
        printf("Not Prime");
}
