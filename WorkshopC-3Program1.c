/*
Write a C that will accept a positive integer n, n>=2 
then print out primes between 2 and n.
*/
#include <stdio.h>
#include <math.h>

int  prime( int n ) {
     	int m = sqrt(n); /* m: square root of n */
      	int i;  /* variable having value from 2 to m  */ 
     		if (n < 2) return 0; /* Condition 1 is not satisfied */
     		for ( i =2 ; i <= m; i++) /* checking the second condition */
         		if (n % i == 0) return 0 ; /* n is divided by i ' n is not a prime */
     	return 1; /* n is a prime */ 
}

main()
{
	int n, i;
	do {
		printf("Enter positive num bigger than 2: ");
		fflush(stdin);
		scanf("%d", &n);
		if (n <= 2) printf("Positive Integer bigger than 2!!!\n");
	} while (n <= 2);
	for (i = 2; i <= n; i++)
		if ( prime(i) ) printf("%3d", i);
}
