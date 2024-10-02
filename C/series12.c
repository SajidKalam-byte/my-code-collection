/*1 0 1 0 1
0 1 0 1
1 0 1
0 1
1
*/
#include <stdio.h>
void main()
{
    int x,y;
    for(x=1;x<=5;x++)
        {
            for(y=5;y>=x;y--)
                if((x+y)%2==0)
                    printf("1 ");
                else
                    printf("0 ");
            printf("\n");
        }
}
