/*
Write a C program that will accept a positive integer then print out its factorial.
*/
#include <stdio.h>

long long factorial( int n) 
{
    long long p=1;
    int i;
    for (i=2; i<=n; i++) p *= i;
    return p;
} 

main()
{
    int n;
    do {
        printf("Input a positive integer:");
        fflush(stdin);
        scanf("%d", &n);
        if (n <= 0) printf("Positive Integer!!!\n");
    } while (n <= 0);
    printf("%lld", factorial(n));
}
