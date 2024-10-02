#includ e <stdio.h>
#include<math.h>
void main()
{
    int x,n,s;
     printf("Enter the number range: ");
    scanf("%d",&n);
    for(x=1;x<=n;x++)
    {
        s=pow(x,3);
        printf(" %d ",s);
    }
}
