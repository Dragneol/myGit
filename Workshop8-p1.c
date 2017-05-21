#include <stdio.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

int exist(char * filename)
{
	int existed = FALSE;
	FILE * f = fopen( filename, "r");
	if (f != '\0')
	{
		existed = TRUE;
		fclose(f);
	}
	return existed;
}

int writeFile(char * filename)
{
	char c;
	if (exist(filename))
	{
		printf("The file %s existed. Override it Y/N?", filename);
		if (toupper(getchar()) == 'N') return FALSE;
	}
	
	FILE * f = fopen(filename, "w");
	fflush(stdin);
	do
	{
		c = getchar();
		if (c != -1) fputc(c, f);
	}
	while (c != -1);
	fclose(f);
	return TRUE;
}

int main(int argCount , char * args[])
{
	if (argCount != 2) printf("Syntax : workshop8-p1 filename\n");
	else if (writeFile(args[1])) printf("Writing the file %s : done\n", args[1]);
		else printf("Cannot write the file %s \n", args[1]);
	return 0;
}
