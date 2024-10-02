#include <stdio.h>
void main()
{
    int x,n;
    float sum=0.0;
     printf("Enter the number range: ");
    scanf("%d",&n);
    for(x=1;x<=n;x++)
    {
        sum=sum+(1/(float)x);
    }
    printf(" %f ",sum);
}
