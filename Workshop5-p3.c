/*
Write a C program using the following simple menu:
1- Processing date data
2- Character data
3- Quit
Choose an operation:
-	When user chooses 1: User will enter values of date, month, year 
then the program will announce whether this date is valid or not.
-	When user chooses 2: User will enter two characters, 
then the program will print out ASCII codes of characters between them using descending order.
*/
#include <stdio.h>
#include <windows.h>

#define maxChoice '3'

char getUserChoice()
{
    char n;
    printf("1-Processing date data\n");
    printf("2-Character data\n");
    printf("3-Quit\n");
    printf("Choice [1..3] : ");
    fflush(stdin);
    scanf("%c", &n);
    return n;
}

void function3()
{
    printf("This is program coded by Duong\n");
    printf("Thank you for watching! Bye Bye!");
}

int validDate( int d, int m, int y) 
{
        int maxd = 31; /*max day of months 1, 3, 5, 7, 8, 10, 12 */
        /* basic checking */
            if ( d < 1 || d > 31 || m < 1 || m > 12 || y < 1) return 0;
        /* update maxd of a month */
            if ( m == 4 || m == 6 || m == 9 || m == 11) maxd = 30;
            else if (m == 2) 
            {
                /* leap year? */
                    maxd = ( y % 400 == 0 || ( y % 4 == 0 && y % 100 != 0) )? 29:28;
            }
        return d <= maxd; 
} 

void function1()
{
    int d, m, y;
    printf("Input day, month, year:");
    scanf("%d %d %d", &d, &m, &y);
    if ( !validDate( d, m, y) ) printf("invalid date");
    else printf("valid date");
    printf("\n");
	system("pause");
	system("cls");
}

void function2()
{
    char c1, c2;
    int c;
    printf("Input 2 character (c1'space'c2): ");
    fflush(stdin);
    scanf("%c %c", &c1, &c2);
    if (c1 < c2) c1 ^= c2 ^= c1 ^= c2;
    for (c = c1; c >= c2; c--)
        printf("%c : %3d %3Xh\n", c, c, c);
    printf("\n");
	system("pause");
	system("cls");
}

main()
{
    char userChoice;
    do
    {
        userChoice = getUserChoice();
        switch(userChoice)
        {
            case '1':function1();break;
            case '2':function2();break;
            case '3':function3();break;
            default : printf("Input 1 or 2 or 3 only!\n\n");
        }
    } while (userChoice != maxChoice);
}
