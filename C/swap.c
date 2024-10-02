#include<stdio.h>
int main()
{
    int a=2, b=5,c;
    printf("Before Swap a= %d, b= %d\n",a,b);
    c=a;
    a=b;
    b=c;
    printf("After Swap a= %d, b= %d \n\n",a,b);

    ////////

    int x=4,y=3;
    printf("Before Swap x= %d, y= %d",x,y);
    x=x+y; // 4+3=7
    y=x-y; //7-3=4
    x=x-y; //7-4
    printf("After Swap x= %d, y= %d\n",x,y);
    return 0;
}
