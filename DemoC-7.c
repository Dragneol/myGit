#include <stdio.h>

main()
{
	int m, n,s=0;
	scanf("%da%d", &n, &m);
	int i;
	for (i = m;i<=n; i++) 
	{
		s+=i;
		printf("i=%d, s=%d\n",i,s);
	}
	printf("%d", s);
}
