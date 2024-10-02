/*
      4
    3 4 3
  2 3 4 3 2
1 2 3 4 3 2 1

*/
#include <stdio.h>
void main()
{
    int i,j,k,l;
    for(i=4;i>=1;i--)
        {
            for(j=1;j<i;j++)
                printf("  ");

            for(k=i;k<=4;k++)
                    printf("%d ",k);

            for(l=3;l>=i;l--)
                printf("%d ",l);

            printf("\n");
        }

}
