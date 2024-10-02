/*
 Write a c program that will rank the players based on their one day T20 runs.
 Inputs: no of 50's, 4's, 6's, 100's, no. of matches.
______________________________________________________
*/
#include<stdio.h>
#include<stdlib.h>
void main()
{
    int score,rank;
    int fif,hun,four,six,day,fif2,hun2,four2,six2,day2,fif3,hun3,four3,six3,day3;
    char player1[20],player2[20],player3[30];
    printf("Enter the players name: ");
    scanf("%s",&player1);
    printf("Enter the players name: ");
    scanf("%s",&player2);


    printf("\nEnter the score for %s ",player1);
    printf("\nNumber of 4's: ");
    scanf("%d",&four);
    printf("\nNumber of 6's: ");
    scanf("%d",&six);
    printf("\nNumber of 50's: ");
    scanf("%d",&fif);
    printf("\nNumber of 100's: ");
    scanf("%d",&hun);
    printf("\nNumber of Days played: ");
    scanf("%d",&day);


    printf("\nEnter the score for %s ",player2);
    printf("\nNumber of 4's: ");
    scanf("%d",&four2);
    printf("\nNumber of 6's: ");
    scanf("%d",&six2);
    printf("\nNumber of 50's: ");
    scanf("%d",&fif2);
    printf("\nNumber of 100's: ");
    scanf("%d",&hun2);
    printf("\nNumber of Days played: ");
    scanf("%d",&day2);
    system("CLS");
    printf("Rank of Player is\n_____________________________");
    /*
    printf("Enter the score for %s ",player3);
    printf("Number of 4's: ");



    scanf("%d",&four3);
    printf("Number of 6's: ");
    scanf("%d",&six3);
    printf("Number of 50's: ");
    scanf("%d",&fif3);
    printf("Number of 100's: ");
    scanf("%d",&hun3);
    printf("Number of Days played: ");
    scanf("%d",&day3);
*/

    int avg1,avg2,avg3;
    avg1=hun/day;
    avg2=hun2/day2;
    //avg3=hun3/day3;

    switch(avg1>avg2)
    {
   case 1:
       {
        printf("\n1. %s",player1);
        printf("\n2. %s",player2);
        break;
       }
   case 0:
    {
        printf("\n1. %s",player2);
        printf("\n2. %s",player1);
        break;
    }
    }

}
