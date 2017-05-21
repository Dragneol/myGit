#include <stdio.h>
int n;
double x;
char c1;
int main()
{
	int m;
	short s;
	long l;
	float y;
	printf("Code of main    :%u, memory size:%d\n", &main, sizeof(main));
	printf("Variable n,  add:%u, memory size:%d\n", &n, sizeof(n));
	printf("Variable x,  add:%u, memory size:%d\n", &x, sizeof(x));
	printf("Variable c1, add:%u, memory size:%d\n", &c1, sizeof(c1));
	printf("Variable m,  add:%u, memory size:%d\n", &m, sizeof(m));
	printf("Variable s,  add:%u, memory size:%d\n", &s, sizeof(s));
	printf("Variable l,  add:%u, memory size:%d\n", &l, sizeof(l));
	printf("Variable y,  add:%u, memory size:%d\n", &y, sizeof(y));
	return 0;
}
