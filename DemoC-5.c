#include <stdio.h>
//main()
//{
//	int int1,int2;
//	float fl1, fl2;
//	double lf1, lf2;
//	printf("Enter 2 integers:");
//	scanf("%d%d", &int1, &int2);
//	printf("Enter 2 floats:");
//	scanf("%f%f", &fl1, &fl2);
//	printf("Enter 2 doubles:");
//	scanf("%lf%lf", &lf1, &lf2);
//	printf("Integer1's add:%u, value:%d\n", &int1, sizeof(int1));
//	printf("Integer2's add:%u, value:%d\n", &int2, sizeof(int2));
//	printf("Float1's   add:%u, value:%d\n", &fl1, sizeof(fl1));
//	printf("Float2's   add:%u, value:%d\n", &fl2, sizeof(fl2));
//	printf("Double1's  add:%u, value:%d\n", &lf1, sizeof(lf1));
//	printf("Double2's  add:%u, value:%d\n", &lf2, sizeof(lf2));	
//}

int main()
{
	int n;
	char c;
	printf("Enter integer Number:");
	scanf("%d", &n);
	printf ("Enter a character:");
	scanf("%c", &c);
	getchar();getchar();
	return 0;
}

