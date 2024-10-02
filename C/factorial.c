#include <stdio.h>
void main()
{
    int x,n,fact=1;
     printf("Enter the number range: ");
    scanf("%d",&n);
    for(x=1;x<=n;x++)
    {
        printf("%d ",fact*=x);
    }
}
