//A A A
//B B B
//C C C

#include <stdio.h>
#include <math.h>
void main()
{
    int i,j;
    char ch='A';
    for(i=0;i<=4;i++)
    {
        for(j=1;j<=3;j++)
        {
            printf("%c ",ch);
        }
        ch++;
        printf("\n");
    }
}
