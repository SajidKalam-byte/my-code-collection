#include<stdio.h>
int main(){
    int x,y,n=10;
    for(x=1,y=-2;x<n;x+=2,y-=2)
        printf(" %d %d %d ",x,y,(x*y));

    return 0;
}
