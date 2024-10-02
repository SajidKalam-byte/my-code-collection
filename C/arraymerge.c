#include<stdio.h>
#define SCREEN_HEIGHT 10
void main()
{
    int ar1[5],ar2[5],result[10],x,y,c=0;
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

    for(x=0,y=5;x<5,y<10;x++,y++)
       {
          result[x]=ar1[x];
          result[y]=ar2[x];
       }
    printf("\nThe elements of Merge: ");
    for(x=0;x<10;x++)
        printf("%d ",result[x]);
    printf("\n\n");

     for ( int i = 0; i < SCREEN_HEIGHT; i++ )
    putchar ( '\n' );
}
