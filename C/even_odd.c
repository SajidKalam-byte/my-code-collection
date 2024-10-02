#include <stdio.h>
void main()
{
    int num;
    printf("Enter the number to check EVEN or ODD: ");
    scanf("%d",&num);
    if(num%2==0)
        printf("\nThe number is even\n");
    else
        printf("\nThe number is ODD\n");
}
