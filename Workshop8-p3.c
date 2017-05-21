/*
Write a C-program that will perform the following operations:
 User enters a filename of a text file
 User will enter data to the file line-by-line until a null string is inputted.
 User will see the content of the file.
(The problem of the previous demo. But, the functions fscanf() and fprintf() are used.) 
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
            fprintf(f,"%s\n",line);
    }while (length > 0);
    int success = fclose(f);
    return (success == 0);
}

int printFile(char * filename)
{
    if ( !(exist(filename) ) )
    {
        printf("The file %s does not exist.\n", filename);
        return FALSE;
    }
    FILE * f = fopen(filename, "r");
    char line[201];
    while (fscanf(f, "%[^\n]%*c", line) > 0) puts(line);
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
        printf("Data in file %s : \n", filename);
        if ( !(printFile(filename)) ) printf("File error!\n");
    }
    else printf("Writing file %s fail!\n", filename);
    return 0;
}
