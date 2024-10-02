//1 4 9 16..... n

#include<stdio.h>
#include<math.h>
void main()
{
    int n;
    printf("Enter number of terms\n");
    scanf("%d",&n);//4

    for(int x=1;x<=n;x++)
    {
        int y=pow(x,2);
        printf("%d ",y);
    }
}
