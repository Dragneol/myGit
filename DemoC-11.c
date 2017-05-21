#include <stdio.h>
#include "isPrime.c"

main() {
	int n;
	scanf("%d", &n);
	if (isPrime(n) == 0) printf("YES");
	else printf("NO");
}
