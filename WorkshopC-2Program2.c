/*
Write a program which will compute income tax of a people
*/
#include <stdio.h>
#define pa 9000000
#define pd 3600000
main() {
	long long income, tf, ti, it;
	int n;
	printf("Your income of this year: ");
	scanf("%lld", &income);
	printf("Number of dependent: ");
	scanf("%d", &n);
	tf = 12*(pa + n*pd);
	ti = (income < tf)?  0 :  income - tf;
	printf("Tax-free income: %lld\n", tf);
	printf("Taxable income: %lld\n", ti);	
	it = (ti <= 5000000)? (5*ti)/100 : 
		( it = (ti <= 10000000)? (10*(ti-5000000))/100 + (5000000*5/100) : 
			(it = (ti <= 18000000)? (10*(ti-10000000))/100 + (5000000*5/100) + (5000000*10/100): 
				(20*(ti-18000000)/100) + (5000000*5/100) + (5000000*10/100) + (8000000*15/100) ) );
	printf("Income tax: %lld\n", it);
}
