#include <stdio.h>
#include<math.h>
void main()
{
    int x,n,s;
     printf("Enter the number range: ");
    scanf("%d",&n);
    for(x=1;x<=n;x++)
    {
        s=pow(x,2);
        printf(" %d ",s);
    }
}
