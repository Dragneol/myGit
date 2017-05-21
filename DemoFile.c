#include <stdio.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0
//int printf(char)
//
int exist(char* filename)
{
	int existed = FALSE;
	FILE* f= fopen (filename , "r");
	if (f !=NULL)
	{
		existed = TRUE;
		fclose(f);
	}
	return existed;
}

int write(char* filename)
{
	char c;
	int CTRL_Z = -1;
	if (exist (filename) == TRUE)
	{
		printf("File %s already existed. Rewrite? Y/N? :", filename);
		if ( toupper( getchar() ) == "N") return FALSE;
	}
	FILE* f = fopen( filename , "w");
	fflush(stdin);
	do
	{
		c = getchar();
		if (c!=CTRL_Z) fputc(c,f);
	}
	while (c != CTRL_Z);
	fclose(f);
	return TRUE;
}

int main()
{
	write("f1.txt");
}
