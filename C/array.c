#include <stdio.h>
#define SCREEN_HEIGHT 25
void main()
{
    int a[]={1,2,3,4,5,6};
    int avg,sum=0;
    for(int x=5;x>=0;x--)
    {
        printf("%d ",a[x]);
        sum+=a[x];
        avg=sum/6;
    }

    printf("\nThe Avg is %d ",avg);


     for ( int i = 0; i < SCREEN_HEIGHT; i++ )
    putchar ( '\n' );

}
