/*
Write a C program that will carry out some times. 
In each time, a nonnegative integer is accepted then print out the sum of its decimal digits. 
The program will terminate when its value of accepted number is negative.
*/
#include <stdio.h>

int sumDigits (int n)
{   
    int sum=0; /* initialize sum of digits */
    do {  
            int remainder = n % 10 ; /* Get a digit at unit position */
            n = n / 10;
            sum += remainder;
    } while (n>0);
    return sum;
}

main()
{
    int n;
    do {
        printf("N = ");
        scanf("%d", &n);
        printf("Sum digits = %d\n", sumDigits(n) );
    } while (n >= 0);
}