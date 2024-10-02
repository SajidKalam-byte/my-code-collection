#include<stdio.h>
void main()
{
    int a,r,n,x;
    printf("Enter first term: ");
    scanf("%d",&a);
    printf("Enter common ratio: ");
    scanf("%d",&r);
    printf("Enter range of n : ");
    scanf("%d",&n);
    printf("%d ",a);
    for(x=2;x<=n;x++)
    {
        r*=a;
        printf("%d ",r);
    }

}
