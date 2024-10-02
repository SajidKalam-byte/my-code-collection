#include<stdio.h>
int main()
{
    float a,b;
    printf("Enter two numbers: ");
    scanf("%f %f",&a,&b);
    if(a>0 && b>0)
        printf("The sum of two number is: %.2f",a+b);
    else
        printf("\nWrong input");
    return 0;
}
