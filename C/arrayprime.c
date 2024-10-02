#include<stdio.h>
void main()
{
    int arr[5],x,check=1;
    printf("Enter elements : ");
    for(x=0;x<5;x++)
        scanf("%d",&arr[x]);//2 3 4 5  6 7 11
    for(x=0;x<5;x++)
    {
        for(int i=2;i<(int)(arr[x]/2)   ;i++)
        {
            if(arr[x]%i==0)
                check=0;
            break;
        }
        if(check==1)
            printf("Prime %d ",arr[x]);
        else
            printf("\nNot Prime %d ",arr[x]);
    }
}
