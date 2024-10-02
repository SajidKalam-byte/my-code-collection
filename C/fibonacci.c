#include <stdio.h>
void main()
{
    int t1=0,t2=1,tz=0,x,n;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    printf("%d %d ",t1,t2);
    for(x=2;x<=n;x++)
    {
        tz=t1+t2;
        t1=t2;
        t2=tz;
        printf("%d  ",tz);
    }

}
