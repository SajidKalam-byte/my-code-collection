#include<stdio.h>
int main()
{
    float income,tax,salary;
    printf("Enter your income\n");
    scanf("%f",&income);
    if(income>=30)
    {
        tax=0.25*30;
        printf("The final income with 25%% tax is %.2f",income-tax);
    }
    else if(income>=15)
    {
        tax=0.15*15;
        printf("The final income with 15%% tax is %.2f",income-tax);
    }
    else if(income>=10)
    {
        tax=0.08*10;
        printf("The final income with 8%% tax is %.2f",income-tax);
    }
     else if(income>=60)
    {
        tax=0.05*60;
        printf("The final income with 5%% taxis %.2f",income-tax);
    }
    else
        printf("The final income without tax %.2f",income);
return 0;
}
