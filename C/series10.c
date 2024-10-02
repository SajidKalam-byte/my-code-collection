/*
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
*/
#include <stdio.h>
void main()
{
    int x,y,c=1;
    for(x=1;x<=5;x++)
        {
            for(y=1;y<=x;y++)
                printf("%d ",c++);
            printf("\n");
        }
}
