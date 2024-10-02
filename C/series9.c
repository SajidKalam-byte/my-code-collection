/*
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
*/

#include <stdio.h>
void main()
{
    int x,y;
    for(x=1;x<=5;x++)
        {
            for(y=1;y<=x;y++)
                printf("%d ",y);
            printf("\n");
        }
}
