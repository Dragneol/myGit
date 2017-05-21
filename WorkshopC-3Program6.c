/*
Write a C program that will accept a positive integer
then print out whether it is an element of the Fibonacci sequence or not.
*/
#include <stdio.h>

int isFibonacci(int n)
{
    int t1 = 1, t2 = 1, f = 1;
    if (n == 1) return 1;   /* n belongs to the Fibonacci sequence*/
    while (f < n)           /* Find out the Fibo number f to n */
        {
            f  = t1 + t2;
            t1 = t2;
            t2 = f;
        }
    return n == f;  /* if n==f : n is Fibo element -> return 1 */
}

main()
{
    int n;
    do {
          printf("Input a positive integer:");
          fflush(stdin);
          scanf("%d", &n);
          if (n < 1) printf("Positive Integer!!!\n");
     } while (n < 1);
     printf( ( isFibonacci(n))? "It is a Fibonacci element." :"It is not a Fibonacci element.");
}
