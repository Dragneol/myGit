/*Write a C program that will print out sum of integers inputted 
from the keyboard until  the value 0 is inputted.*/
#include <stdio.h>
main() {
	int x, s = 0;
	do {
		fflush(stdin);
		scanf("%d", &x);		
		s += x;
	} while (x != 0);
	printf("%d", s);
}
