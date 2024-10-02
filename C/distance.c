#include<stdio.h>
int main(){
    float km, mtr,ft,in,cm;
    printf("Enter the distance in KM");
    scanf("%f",&km);
    mtr=1000*km;
    ft=3280.83*km;
    in=39370.07*km;
    cm=100000*km;

    printf("\n%.2fKM = %.2fmtr",km,mtr);
    printf("\n%.2fKM = %.2fft",km,ft);
    printf("\n%.2fKM = %.2fin",km,in);
    printf("\n%.2fKM = %.2fcm",km,cm);
    return 0;

}
