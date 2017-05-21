#include <stdio.h>
double Divisor(double r1, double r2, double r3) {
	double s = (1/r1) + (1/r2) + (1/r3);
	return (1/s);
}

main() {
	double r1,r2,r3,n;
	scanf("%lf%lf%lf", &r1, &r2, &r3);
	n = Divisor(r1,r2,r3);
	printf("%lf", n); 
}
