/*Write a C program that will accept two characters then print out ASCII code difference between them and characters 
between them including code values in decimal, octal, hexadecimal expansions in ascending order.*/
#include <stdio.h>
main() {
	char c1,c2;
	int d;
	printf("Input c1: ");
	scanf("%c", &c1);
	printf("Input c2: ");
	fflush(stdin);
	scanf("%c", &c2);
	if (c1 > c2) c1 ^= c2 ^= c1 ^= c2;
	d = c2 - c1;
	printf("%d\n", d);
	for (d = c1; d <= c2; d++)
		printf("%5c, %5d, %5o, %5X\n", d, d, d, d);
} 
