/*
4 4 4 4
3 3 3
2 2
1
*/
#include <stdio.h>
void main()
{
    int x,y;
    for(x=4;x>=1;x--)
        {
            for(y=1;y<=x;y++)
                printf("%d ",x);
            printf("\n");
        }
}
