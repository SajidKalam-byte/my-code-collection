//n^1 n^2 n^3.......... n^n
#include<stdio.h>
#include<math.h>
void main()
{
    int n,x,y;
    printf("Enter the number of terms ");
    scanf("%d",&n);

    for(x=1;x<=n;x++)
    {
        y=pow(n,x);
        printf("%d ",y);
    }
}
