/*Write a C program that will carry out some times: accept two integers, swap these values, print them out to the monitor. 
The program will terminate when the value of 0 is inputted.*/
#include <stdio.h>
main() {
	int x, y;
	do {
		scanf("%d%d", &x, &y);
		fflush(stdin);
		x ^= y^= x^= y;
		(x !=0 || y!= 0)? printf("After Swap:%d %d\n", x, y):printf("\n");
	} while (x != 0 && y != 0);
}
