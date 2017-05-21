#include <stdio.h>

double average(int a, int b, int c)
{
	double result;
	result = (a+b+c)/3.;
	return result;
}

main()
{
	int a,b,c;
	scanf("%d%d%d", &a, &b, &c);
	double d = average(a,b,c);
	printf("%0.3lf", d);
}
