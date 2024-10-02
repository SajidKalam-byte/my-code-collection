#include <stdio.h>
int main()
{
    float salary, allowance,rent,gross;
    printf("Enter the basic Salary: ");
    scanf("%f",&salary);
    allowance=0.4*salary;
    rent=0.2*salary;
    gross=salary+allowance+rent;
    printf("Ramesh's gross Salary is: %0.2f \n\n",gross);
    return 0;

}
