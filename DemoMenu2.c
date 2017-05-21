#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define maxChoice 2

int getUserChoice()
{
    int n;
    printf("1-Fibonacci sequence\n");
    printf("2-Check a date\n");
    printf("3-Quit\n");
    printf("Choice = ");
    fflush(stdin);
    scanf("%d", &n);
    return n;
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

long fibo( int n)
{
    int t1 = 1, t2 = 1, f = 1, i ;
    for ( i = 3; i <= n; i++)
    {
        f  = t1 + t2;
        t1 = t2;
        t2 = f;
    }
    return f;
}

void function1()
{
    int n;
    do {
        printf("Input a positive integer : ");
        scanf("%d", &n);
    } while (n <= 1) ;
    printf("%dth Fibo : %d\n\n",n ,fibo(n));
}

void function2()
{
    int d, m, y;
    printf("Input day, month, year:");
    scanf("%d %d %d", &d, &m, &y);
    if ( !validDate( d, m, y) ) printf("invalid date\n\n");
    else printf("valid date\n\n");
}

main()
{
    int userChoice;
    do
    {
        userChoice = getUserChoice();
        switch(userChoice)
        {
            case 1:function1();break;
            case 2:function2();break;
        }
    } while (userChoice > 0 && userChoice <= maxChoice);
}