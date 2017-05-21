#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define maxChoice 2

int getUserChoice()
{
    int n;
    printf("1-Process Prime\n");
    printf("2-Print Min Max Digit in an integer\n");
    printf("3-Quit\n");
    printf("Choice = ");
    fflush(stdin);
    scanf("%d", &n);
    return n;
}

int  isPrime( int n ) 
{
     	int m = sqrt(n); /* m: square root of n */
      	int i;  /* variable having value from 2 to m  */ 
     		if (n < 2) return 0; /* Condition 1 is not satisfied */
     		for ( i =2 ; i <= m; i++) /* checking the second condition */
         		if (n % i == 0) return 0 ; /* n is divided by i ' n is not a prime */
     	return 1; /* n is a prime */ 
}

void function1()
{
    int n;
    do {
        printf("Input a positive integer : ");
        scanf("%d", &n);
    } while (n <= 1) ;
    if (isPrime(n) == 1) printf("%d is Prime\n\n", n);
    else printf("%d is not Prime\n\n", n);
}

void function2()
{
    int n;
     do {
     printf("Input a positive integer : ");
     scanf("%d", &n);
     } while (n <= 0);
    int remainder; /* Variable for extracting 1 digit */
    int min, max ; /* Result variables */
    remainder = n % 10;  /* get the first rightmost digit: 3 */
    n /= 10; /* 1029, the remainder needs to proceed after*/
    min = max = remainder; /* initialize results */
    while (n > 0) 
    { 
        remainder = n % 10; /* Get the next digit */
        n /= 10;
        if (min > remainder) min = remainder; /* update results */
        if (max < remainder) max = remainder;
   }
   printf("Max digit = %d, Min digit = %d\n\n", max, min);
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
