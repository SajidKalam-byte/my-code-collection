//find the average of three numbers.
//Print multiply if avg>23.
//Print what value should be added to avg to make it exact when avg<23.

#include<stdio.h>
void main()
{
    int avg,a,b,c;
    printf("Enter three numbers: ");
    scanf("%d%d%d",&a,&b,&c);
    avg=(a+b+c)/3;
    printf("\nAverage is : %d\n",avg);
    if(avg>23)
    {
        printf("\nThe product is %d\n",a*b*c);
    }else
    {
        int x=(23-avg)+1;
        printf("\nValue to add is %d\n",x);
        avg=avg+x;
        printf("\nAverage after adding value is : %d\n",avg);
    }
}
