#include <stdio.h>
void main()
{
    int a[]={4,3,9,0,22,17};
    int y[]={2,3,7,6,4,5};
    int z[6];
    int sum=0;
    for(int x=0;x<6;x++)
    {
        printf("%d ",a[x]);
    }
    printf("\n");
    for(int x=0;x<6;x++)
    {
        printf("%d ",y[x]);
    }

    for(int x=0;x<6;x++)
    {
        z[x]=a[x]+y[x];
        sum+=z[x];
    }

    printf("\nThe Sum is %d \n",sum);

    for(int x=0;x<6;x++)
    {
        printf("% d",z[x]);
    }
}
