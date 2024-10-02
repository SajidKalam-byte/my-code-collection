#include <stdio.h>
int main()
{
    int f,c;
    printf("Enter the fahrenheit: ");
    scanf("%d",&f);
    c=(f-32)*5/9;
    printf("%d F -> %d C",f,c);
    return 0;
}
