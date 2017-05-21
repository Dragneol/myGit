/*
Write a C-program that will performs the following operations:
 User enters a filename of a text file
 User will enter data to the file line-by-line until a null string is inputted.
 User will see the content of the file.
*/
#include <stdio.h>
#include <string.h>

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
	if (exist(filename))
	{
		printf("The file %s existed. Override it Y/N?", filename);
		if (toupper(getchar()) == 'N') return FALSE;
	}
    char line[201];
    int length = 0;
    FILE * f = fopen(filename, "w");
	fflush(stdin);
    do{
        gets(line);
        length =  strlen(line);
        if (length > 0)
        {
            fputs(line, f);
            fputs("\n", f);
        }
    }while (length > 0);
    int success = fclose(f);
    return (success == 0);
}

int printFile(char * filename)
{
    char c;
    if ( !(exist(filename) ) )
    {
        printf("The file %s does not exist.\n", filename);
        return FALSE;
    }
    FILE * f = fopen(filename, "r");
    while ( (c = fgetc(f) )!= EOF ) putchar(c);
    int success = fclose(f);
    return (success == 0);
}

int main(int argCount, char * args[])
{
    char filename[81];
    printf("Program for writing and reading a file\n");
    printf("Enter a filename : ");
    gets(filename);
    printf("Write File : \n");
    if (writeFile(filename))
    {
        printf("Data in file %s\n", filename);
        if ( !(printFile(filename)) ) printf("File error!\n");
    }
    else printf("Writing file %s fail!\n", filename);
    return 0;
}
