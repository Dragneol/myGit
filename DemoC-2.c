#include <stdio.h>
#define PI 3.141592
const PI1 = 3.1411593;
const double PI2 = 3.141593;
const MAXINT1 = 12;
const int MAXINT2 = 10;
const MAXCHAR1 = 'Z';
const char MAXCHAR2 = 'A';

main()
{
	printf("%f\n", PI*3*3);
	printf("Non- type Constant : PI1 %d byte \n", sizeof(PI1));
	printf("Non- type Constant : MAXINT1 %d byte \n", sizeof(MAXINT1));
	printf("Non- type Constant : MAXCHAR1 %d byte \n", sizeof(MAXCHAR1));
	printf("Typed specific Constant : PI2 %d byte \n", sizeof(PI2));
	printf("Typed specific Constant : MAXINT2 %d byte \n", sizeof(MAXINT2));
	printf("Typed specific Constant : MAXCHAR2 %d byte \n", sizeof(MAXCHAR2));
}
