/*
Calculate electric Bill
Unit Slap   Price/switch
---------   ------------
1-99        4.50
100-299     5.80
300-499     6.70
500-699     8.75
700+        10.60
*/

#include<stdio.h>
void main()
{
    int unit;
    float price=0.0, x,y,a,z,m,l;
    printf("Enter the total UNIT: ");
    scanf("%d",&unit);

    switch(unit)
    {

    case 1 ... 99:
        {
            price=unit*4.50;
            break;

        }
    case 100 ... 299:
        {
            x=unit-99;//234 x =135
            a=99*4.50;// a=445.5
            price=x*5.80;//783
            price=price+a;//1228.5
            break;
        }
    case 300 ... 499:
        {
             x=unit-99;//399 x =300
             a=99*4.50;// a=445.5
             y=x-199;
             z=199*5.80;//783
             m=y*6.70;
            price=a+z+m;
            break;

        }
    case 500 ... 699:
        {
            x,y,z,m;
            unit=unit-99;//411
            a=99*4.50;
            unit=unit-199;//212
            z=199*5.80;
            unit=unit-199;//13
            unit=unit*8.75;
            price=unit+z+a;
            break;
        }
    case 700 ... 99999:
        {
           unit=unit-99;//647
           a=99*4.50;//445.5
           unit=unit-199;//448
           z=199*5.80;//1154.2
           unit=unit-199;//249
           l=199*6.70;//1333.3
           unit=unit-199;//50
           m=199*8.75;//1741.25
           x=unit*10.60;//50* 530
           price=x+a+z+l+m;//5204.25
            break;
        }
        default:
            printf("Invalid input!\n");

    }
        printf("Price %.2f",price);
}
