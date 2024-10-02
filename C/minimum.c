#include<stdio.h>
void main()
{
    int a,b,c,max,min;
    printf("Enter three numbers to check minimum: ");
    scanf("%d%d%d",&a,&b,&c);
    //if(a>b && a>c)
    if(a<b && a<c)
            //printf("Minimum number is %d",a);
            printf("1. Maximum number is %d",a);
    //else if(b<c && b<a)
    else if(b>c && b>a)
        //printf("Minimum number is %d",b);
        printf("2. Maximum number is %d",b);
    else
        //printf("Minimum number is %d",c);
        printf("3. Maximum number is %d",c);
}
