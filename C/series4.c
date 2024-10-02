//  1/n 2/n 3/n............. n/n
#include<stdio.h>
void main()
{
    int n,x,y;
    printf("Enter the number of terms ");
    scanf("%d",&n);

    for(x=1;x<=n;x++)
    {
        printf("%d ",x/n);
    }
}
