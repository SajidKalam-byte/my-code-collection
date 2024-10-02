#include <stdio.h>
void main()
{
    int x,n;
     printf("Enter the number range: ");
    scanf("%d",&n);
    for(x=1;x<=n;x++)
    {
        if(x%2==0)
            printf(" %d ",x);
    }
}
