#include <stdio.h>
#include <math.h>
#include <ctype.h>

char menu(char choice)
{
	printf("1:Check vowel\n");
	printf("2:Sum of divisors\n");
	printf("3:Check prime\n");
	printf("Other : Exit\n");
	printf("Choose [1..3]:");
	fflush(stdin);
	choice = getchar();
	return choice;
}

char isVowel(int c)
{
	return (toupper(c) == 'A' || 
			toupper(c) == 'I' || 
			toupper(c) == 'U' || 
			toupper(c) == 'E' || 
			toupper(c) == 'O');
}

int sumDivisor(int n)
{
	int s = 1, i;
	for (i = 2; i <= n/2; i++)
		if (n % i == 0) s += i;
	return s;
}

int isPrime(int n)
{
		int m = sqrt(n); /* m: square root of n */
      	int i;  /* variable having value from 2 to m  */ 
     		if (n < 2) return 0; /* Condition 1 is not satisfied */
     		for ( i = 2; i <= m; i++) /* checking the second condition */
         		if (n % i == 0) return 0 ; /* n is divided by i ' n is not a prime */
     	return 1; /* n is a prime */ 
}
main()
{
	int check = 1, n;
	char choice;
	do {
	choice = menu(choice);
	if (choice < '1' || choice > '3') check = 0;
	switch (choice)
	{
		case '1':
			printf("Enter a character:");
			fflush(stdin);
			char c = getchar();
			if (isVowel(c) == 1) printf("It is a vowel\n\n");
			else printf("It is not a vowel\n\n");
		break;
		case '2':
			do {
				printf("Input a positive number:");				
				fflush(stdin);
				scanf("%d", &n);
			} while (n <= 0);
			printf("Sum of divisiors : %d\n\n", sumDivisor(n) );
		break;			
		case '3':
			do {
			printf("Input an integer:");
			fflush(stdin);
			scanf("%d", &n);
			} while (n <= 0);
			if(isPrime(n) == 1) printf("It is a prime\n\n");
			else printf("It is not a prime\n\n");
		break;
		default:printf("Goodbye!"); }
	} while (check == 1);	
}