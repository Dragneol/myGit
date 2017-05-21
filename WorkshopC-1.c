#include <stdio.h>
int n;
double x;
char c1;
int main()
{
	int m;
	short s;
	long L;
	float y;
	printf("Code of main    :%u\n", &main);
	printf("Variable n,  add:%u, memory size:%d\n", &n, sizeof(n));
	printf("Variable x,  add:%u, memory size:%d\n", &x, sizeof(x));
	printf("Variable c1, add:%u, memory size:%d\n", &c1, sizeof(c1));
	printf("Variable m,  add:%u, memory size:%d\n", &m, sizeof(m));
	printf("Variable L,  add:%u, memory size:%d\n", &L, sizeof(L));
	printf("Variable y,  add:%u, memory size:%d\n", &y, sizeof(y));
	getchar();
	return 0;
}
