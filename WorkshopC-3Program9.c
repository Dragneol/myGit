/*
Write a C program that will accept two positive integers 
then print out their greatest common divisor and least common multiple.
*/
#include <stdio.h>

int gcd( int a, int b)
{  
    while ( a != b )
       if ( a > b ) a -= b;
       else b -= a;
   return a;
}

int lcm( int a, int b)
{ 
    return (a * b) / gcd(a,b);
}

main()
{
    int a, b;
    do {
        fflush(stdin);
        scanf("%d%d", &a, &b);
        if (a <= 0 || b <= 0) printf("Input two positive integers!!!\n");
    } while (a <= 0 || b <= 0);
    printf("GCD(%d,%d)=%d\n", a, b, gcd(a,b));
    printf("LCM(%d,%d)=%d\n", a, b, lcm(a,b));
}