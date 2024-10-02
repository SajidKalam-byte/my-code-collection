
#include <stdio.h>

int main() {
    // Write C code here
    char a[]={'A','B','C','D'};
    char *p=&a[0];
    *p++;
    printf("%c %c", *++p, --*p);
    return 0;
}