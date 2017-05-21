#include <stdio.h>

main()
{
//	int i,s;
//	for (i = 1, s = 0; i < 101; s+=i , i++);
//	printf("%d\n", s);
	int _code = 0;
	do
	{
		printf("%5c, %5d, %5o, %5X\n", _code, _code, _code, _code);
		_code++;
	}while(_code < 256);
}
