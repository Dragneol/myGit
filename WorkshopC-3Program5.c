/*
Write a C program that will print out the value at the nth position in Fibonacci sequence.
*/
#include <stdio.h>

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

main()
{
    int n;
    do {
        printf("Which in Fibonacci sequence:");
        fflush(stdin);
        scanf("%d", &n);
        if (n <= 2) printf("Positive Interger bigger than 2!!!\n");
    } while (n <= 2);
    printf("%ld", fibo(n));
}
