#include<stdio.h>
int main()
{
    float eng,che,maths,sci,comp,total=0;
    float per;
    printf("Enter the marks for ENG : ");
    scanf("%f",&eng);
    printf("\nEnter the marks for CHE : ");
    scanf("%f",&che);
    printf("\nEnter the marks for Maths : ");
    scanf("%f",&maths);
    printf("\nEnter the marks for SCI : ");
    scanf("%f",&sci);
    printf("\nEnter the marks for COMP : ");
    scanf("%f",&comp);
    if(eng>100 || eng<0 || che>100 || che<0 || maths>100 || maths<0 || sci>100 || sci<0 || comp>100 || comp<0)
        printf("Enter correct marks\n");
    else
    {
        total=eng+che+maths+sci+comp;
        printf("\nThe total marks obtained is %.2f",total);
        per=total/5;

        if(per>=90 && per<=100)
            printf("Congratulation!!!")
            printf("\nPercantage is %.2f%% with Grade A\n",per);
        else if(per>=80 && per<=89)
            printf("\nPercantage is %.2f%% with Grade B\n",per);
        else if(per>=70 && per<80)
            printf("\nPercantage is %.2f%% with Grade C\n",per);
        else if(per>=60 && per<70)
            printf("\nPercantage is %.2f%% with Grade D\n",per);
        else if(per<60)
        {
            printrf("Loser!!")
            printf("\nPercantage is %.2f%% with Grade E\n",per);
        }
    }


    return 0;
}
