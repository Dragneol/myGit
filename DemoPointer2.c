/*
Use dynamic memory allocation. Develop a program that will accept two real numbers 
then sum of them, their difference, their product, and their quotient are printed out.
*/

#include <stdio.h>
#include <stdlib.h>

main()
{
	double *p1, *p2;
	p1 = (double*) malloc ( sizeof(double));
	p2 = (double*) malloc ( sizeof(double));
	printf("p1, address: %u, value: %u\n", &p1, p1);
	printf("p2, address: %u, value: %u\n", &p2, p2);
	printf("Input 2 numbers:");
	scanf( "%lf%lf", p1, p2);
	printf("Sum: %lf\n", *p1 + *p2);
	printf("Difference: %lf\n", *p1 - *p2);
	printf("Product: %lf\n", *p1 * (*p2));
	printf("Quotient: %lf\n", *p1 / *p2);
	free(p1);
	free(p2);
}
