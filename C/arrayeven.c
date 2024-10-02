#include<stdio.h>
void main()
{
    int x[5],y[5],i,j,res[10],c=0;
    printf("Enter elements for Array 1: ");
    for(i=0;i<5;i++)
        scanf("%d",&x[i]);
    printf("Enter elements for Array 2: ");
    for(i=0;i<5;i++)
        scanf("%d",&y[i]);

    for(i=0,j=0;i<5,j<5;i++,j++)
    {
        if(x[i]%2==0)
           {
                res[c]=x[i];
                c++;
           }
        if(y[j]%2==0)
           {
                res[c]=y[j];
                c++;
           }
    }
        printf("\n\nThe even number from array 1 and 2 are: ");
        for(i=0;i<c;i++)
        printf("%d ",res[i]);
}
