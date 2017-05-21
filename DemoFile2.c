#include <stdio.h>
#include <stdlib.h>

void readFromFile(char * filename)
{
	char myName[100];
	FILE * f = fopen(filename, "r");
	fgets(myName, 100, f);
	puts(myName);
	fclose(f);
}

void printToFile(char * fileName, char *myName)
{
	FILE * f = fopen(fileName, "w");
	fputs(myName, f);
	fclose(f);	
}

int main(int argc, char *argv[]) 
{
	char myName[100];
	char fileName = "f.text";
	printf("Input your name:");
	fflush(stdin);
	gets(myName);
	readfromFile(fileName);
	return 0;
}
