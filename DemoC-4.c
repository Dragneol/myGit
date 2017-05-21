#include <stdio.h>

main()
{
	int n;
	printf("Buying Number :", &n);
	scanf("%d", &n);
	(n <= 3) ? printf ("Money = %d000", n*120) : (n <= 6) ? printf("Money = %d000",(3*120) + ((n-3)*90)) : printf("Money = %d000",(3*120) + (3*90) + (4*85) + ((n-10)*70));
}
