#include <stdio.h>
void main()
{
    int x,n,sum=0;
    printf("Enter the number range: ");
    scanf("%d",&n);
    for(x=1.;x<=n;x++)
        sum+=x;
    printf("%d",sum);
}
