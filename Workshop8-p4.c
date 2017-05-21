/*
Write a C-program that will:
- Read the array contained in array1.txt file.
- Print its elements in ascending order to monitor.
- Write it to the file array2.txt using the same format with the file array1.txt.
*/

#include <stdio.h>

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

void createFile(char * filename)
{
	int element, n;
	FILE * f = fopen(filename, "w");
	printf("Number of array element : ");
	scanf("%d", &n);
	fprintf(f,"%d ", n);
	int i;
	for ( i = 0; i < n; i++)
		{
			scanf("%d", &element);
			fprintf(f, "%d ", element);
		}
	fclose(f);
}

void fileToArray(char * filename, int * a, int * pn)
{
	if ( !(exist(filename) ) )
	{
		printf("File does not exist!\n");
		createFile(filename);
	}
    FILE * f = fopen(filename, "r");
    fscanf(f, "%d", pn);
    int i;
    for ( i = 0; i < *pn; i++)
        fscanf(f, "%d", &a[i]);
    fclose(f);
}

void asc_sort(int * a, int n)
{
    int i, j, t;
    for ( i = 0; i < n -1; i++)
        for ( j = n - 1; j > i; j--)
            if (a[j] < a[j - 1])
            {
                t = a[j];
                a[j] = a[j - 1];
                a[j - 1] = t;
            }
}

int print(int * a, int n)
{
    int i;
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

int printFile(char * filename, int * a, int n)
{
	FILE * f = fopen(filename, "w");
	fprintf(f,"%d ", n);
	int i;
	for ( i = 0; i < n; i++)
		fprintf(f, "%d ", a[i]);
	fclose(f);
}

int main()
{
	char fileIn[]  = "array1.txt";
	char fileOut[] = "array2.txt";
	int a[100];
	int n = 0;	
	fileToArray(fileIn, a, &n);
	printf("This is what contaned in array1.txt:\n");
	print(a, n);
	asc_sort(a, n);
	print(a, n);
	printFile(fileOut, a, n);
	return 0;
}
