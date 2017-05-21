/*
Write a C-program that will:
- Create a file, named array3.txt containing real numbers. 
- Print out number of values
- Print out the average of values contained in the above file.
*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int exist(char * filename)
{
	int existed = FALSE;
	FILE * f = fopen(filename, "r");
	if (f != '\0')
	{
		existed = TRUE;
		fclose(f);
	}
	return existed;
}

void createFile(char * filename)
{
	double element;
	int n;
	FILE * f = fopen(filename, "w");
	printf("Number of array element : ");
	scanf("%d", &n);
	int i;
	for ( i = 0; i < n; i++)
		{
			scanf("%lf", &element);
			fprintf(f, "%lf ", element);
		}
	fclose(f);
}

void processFile(char * filename, int * pCount, double * pSum)
{
	if ( !(exist(filename) ) )
	{
		printf("File does not exist!\n");
		createFile(filename);
	}
	FILE * f = fopen(filename, "r");
	*pCount = 0;
	*pSum = 0;
	double x;
	while (fscanf(f, "%lf", &x) == 1)
	{
		(*pCount)++;
		(*pSum) += x;
	}
	fclose(f);
}

int main()
{
	char fileIn[] = "array3.txt";
	int count = 0;
	double sum = 0;
	processFile(fileIn, &count, &sum);
	printf("Number of values in the file : %d\n", count);
	if (count == 0)printf("Average of values in the file : 0\n");
	else printf("Average of values in the file : %lf\n", sum/count);
	return 0;
}
