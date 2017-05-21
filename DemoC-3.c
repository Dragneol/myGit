#include <stdio.h>

main()
{
	int n;
	printf("Enter n = ");
	scanf("%d", &n);
	if (n < 0) printf("Abs(%d)=%d", n, -n);
	else printf("Abs(%d) = %d", n, n);
}
