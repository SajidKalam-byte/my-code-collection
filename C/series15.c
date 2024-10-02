/*
 1
 1  1
 1  2  1
 1  3  3  1
 1  4  6  4  1
 1  5  10  10  5  1
 */
#include <stdio.h>
void main()
{
    int x,y,a;
    for(x=0;x<6;x++)
        {
            a=1;
            for(y=0;y<=x;y++)
            {
                printf(" %d ",a);
                a=a*(x-y)/(y+1);
            }
            printf("\n");
        }
}
