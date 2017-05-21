/*
Develop a C-program that helps user managing an 1-D array of real numbers(maximum of 100 elements) , 
with initial number of elements is 0, using the following simple menu:
1- Add  a value
2- Search a value
3- Print out the array 
4- Print out values in a range
5- Print out the array in ascending order 
Others- Quit
*/
#include <stdio.h>
#include <stdlib.h>

#define MAXN 100

char getUserChoice()
{
	printf("1- Add a value\n");
	printf("2- Search a value\n");
	printf("3- Print out the array \n");
	printf("4- Print out the array in rages\n");
	printf("5- Print out the array in ascending order\n");	
	printf("Other - Quit\n\n");
	printf("Select [1..5] : ");
	fflush(stdin);
	char c = getchar();
	return c;
}

void print(int * a, int *pn)
{
	int i;
	for (i =0 ; i < (*pn); i++)
		printf("%3d", a[i]);
	printf("\n");
}

int isFull(int *a, int *pn) {
	return ((*pn) == MAXN);
}

int isEmpty(int *a, int *pn) {
	return ((*pn) == 0);
}

void add(int x, int *a, int *pn) {
	a[*pn] = x;
	(*pn)++;
}

void acSelectionSort( int * a, int *pn) {
	int i,j,c;
	for (i = 0 ; i < (*pn) - 1 ; i++)
		{
			c = i;
			for (j = i + 1 ; j < (*pn); j++)
				if (a[c] > a[j])  c = j;
			if ( c > i)
			{
				j = a[c];
				a[c] = a[i];
				a[i] = j;
			}
		}
	print(a, pn);
}

int posSearch(int x, int * a, int *pn, int * look) {
	int i,j = 0;
	for (i = 0; i < (*pn); i++)
		if (a[i] == x) 
			{
				look[j] = i;
				j++;
			}
	if (j == 0) printf("Not found\n");
	return j;
}

void inRage(int * a, int * pn)
{
	int minVal, maxVal, i;
	printf("minVal = ");
	scanf("%d", &minVal);
	printf("maxVal = ");
	scanf("%d", &maxVal);
	if (minVal > maxVal ) minVal ^= maxVal ^= minVal ^= maxVal;
	for (i = 0; i < (*pn); i++)
		if (a[i] >= minVal && a[i] <= maxVal) printf("%3d");
	printf("\n");
}

main()
{
	char choose;
	int n = 0, value, m;
	int * a, * look;
	a = calloc ( n+1 ,sizeof(int) );
	do {
		a =(int*) realloc(a,n+1);
		look = calloc ( n+1 ,sizeof(int) );
		choose = getUserChoice();
		switch (choose) 
		{
			case '1':
				if (isFull(a, &n)) printf("Array is full\n\n");
				else 
					{
						printf("Input an added value : ");
						scanf("%*c%d", &value);
						add(value, a, &n);
						printf("Added\n\n");
					}
				break;
			case '2':
				if (isEmpty(a, &n)) printf("Array is empty\n\n");
				else
					{
						printf("Input the searched value : ");
						scanf("%*c%d", &value);
						printf("Value at : ");
						value = posSearch(value, a, &n, look);
						for (m = 0; m < value; m++)
							printf("%3d", look[m]);
						printf("\n\n");
					}
				break;
			case '3':
				if (isEmpty(a, &n)) printf("Array is empty\n\n");
				else print(a, &n);
				break;
			case '4':
				if (isEmpty(a, &n)) printf("Array is empty\n\n");
				else inRage(a, &n);
				break;
			case '5':
				if (isEmpty(a, &n)) printf("Array is empty\n");
				else acSelectionSort(a, &n);
				break;
			default: 
				free(a);
				free(look);
				printf("You choose quit the program, bye bye!");
		}
	} while (choose >= '1' && choose <='5');
}
