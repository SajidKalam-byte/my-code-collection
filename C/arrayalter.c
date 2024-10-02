#include<stdio.h>
#define SCREEN_HEIGHT 10
void main()
{
    int ar1[5],ar2[5],result[10],x,y,c=0,d=1;
    printf("Enter the elements for Array 1: ");
    for(x=0;x<5;x++)
        scanf("%d",&ar1[x]);
    printf("Enter the elements for Array 2: ");
    for(x=0;x<5;x++)
        scanf("%d",&ar2[x]);

    printf("\nThe elements of Array 1: ");
    for(x=0;x<5;x++)
        printf("%d ",ar1[x]);

    printf("\nThe elements of Array 2: ");
    for(x=0;x<5;x++)
        printf("%d ",ar2[x]);

    for(x=0;x<10;x++)
       {
          result[c]=ar1[x];
          result[d]=ar2[x];
          c=c+2;
          d=d+2;
       }
    printf("\n\n\nThe elements of Merge: ");
    for(x=0;x<10;x++)
        printf("%d ",result[x]);
    printf("\n\n");




    for ( int i = 0; i < SCREEN_HEIGHT; i++ )
        putchar ( '\n' );
}
