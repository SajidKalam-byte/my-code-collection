/*
1 1 1 1 1
2 2 2 2
3 3 3
4 4
5
*/
#include <stdio.h>
void main()
{
    int x,y;
    for(x=1;x<=5;x++)
        {
            for(y=5;y>=x;y--)
                printf("%d ",x);
            printf("\n");
        }
}
