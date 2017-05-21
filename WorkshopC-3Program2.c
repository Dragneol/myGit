/*
Write a C program that will accept data of a day then print out whether they are valid or not.
*/
#include <stdio.h>

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

main()
{
    int d, m, y;
    printf("Input day, month, year:");
    scanf("%d %d %d", &d, &m, &y);
    if ( !validDate( d, m, y) ) printf("invalid date");
    else printf("valid date");
}
