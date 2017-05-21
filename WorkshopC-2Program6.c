/*Write a C program that will print out the ASCII code table.*/
#include <stdio.h>
main() {
	int code;
	for (code = 1; code <= 255; code++)
		{
			printf("%5c, %5d, %5o, %5X\n", code, code, code, code);
        	if (code !=0 && code %20==0) getchar();
		}
}
