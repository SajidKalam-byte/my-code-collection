#include <stdio.h>
void main()
{
    int pre=2,next=3,x,n,last;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    printf("%d %d ",pre,next);
    for(x=2;x<n;x++)
    {
        last=pre+next;
        pre=next;
        next=last;
        printf("%d ",last);
    }

}
