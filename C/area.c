#include<stdio.h>
int main()
{
    int l,b,r;
    printf("Enter the Length and breadth for rectangle: ");
    scanf("%d%d",&l,&b);
    printf("\nThe AREA of rectangle is %d",l*b);
    printf("\n\nEnter the radius of Circle: ");
    scanf("%d",&r);
    printf("\nThe AREA of CIRCLE is %.2f",(3.14*r*r));
    return 0;
}
