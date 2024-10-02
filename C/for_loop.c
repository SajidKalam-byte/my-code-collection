#include<stdio.h>
#include<stdlib.h>

void main()
{
    int x;
    for(x=89;x>=17;x-=2)
        if(!x%2==0)
            printf("%d\n",x);
}
