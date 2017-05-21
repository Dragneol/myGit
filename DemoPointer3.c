/*
Write a C program using dynamic allocating memory to allow user entering two characters 
then the program will print out characters between these in ascending order.
*/

#include <stdio.h>
#include <stdlib.h>

void swap(char *a, char *b)
{
    char *p;
    p = (char*) malloc (sizeof(char));
    *p = *a;
    *a = *b;
    *b = *p;
}

main()
{
    char *pc1, *pc2;
    pc1 = (char*) malloc (sizeof(char));
    pc2 = (char*) malloc (sizeof(char));
    printf("Input 2 character : ");
    scanf("%c%c", pc1, pc2);
    if (*pc1 > *pc2) swap(pc1, pc2);
    printf("p1, address: %u, value: %u\n", &pc1, pc1);
	printf("p2, address: %u, value: %u\n", &pc2, pc2);
    char c;
    for (c = *pc1; c <= *pc2; c++)
        printf("%c %d %o %X\n", c,c,c,c);
    free(pc1);
    free(pc1);
}