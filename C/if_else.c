#include <stdio.h>
void main()
{
    int a,b,c,d,e,count=0;
    printf("Enter 5 numbers: ");
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    if(a<=0)
        count++;
    if (b<=0)
        count++;
    if(c<=0)
        count++;
    if(d<=0)
        count++;
    if(e<=0)
        count++;
    printf("The total number of inputs less than or equal to ZERO : %d\n",count);
}
