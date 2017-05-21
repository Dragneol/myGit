#include <stdio.h>
#include <stdlib.h>

const int MAXN =100;

int main()
{  
    int n;   int *p1;   int *p2;   int *p3;
    printf("Address of MAXN: %u\n", &MAXN);
    printf("Size MAXN: %d\n", sizeof(MAXN));
    printf("Main function ia allocated at: %u\n", &main);
    printf("Size main: %d\n", sizeof(main));
    printf("Address of n : %u\n", &n);
    printf("Size n: %d\n", sizeof(n));
    printf("Address of p1: %u\n", &p1);
    printf("Size p1: %d\n", sizeof(p1));
    printf("Value p1: %u\n", sizeof(p1));
    printf("Address of p2: %u\n", &p2);
    printf("Address of p3: %u\n", &p3);
    p1 = (int*)malloc(sizeof(int));    
    p2 = (int*)malloc(sizeof(int));    
    p3 = (int*)malloc(sizeof(int));    
    printf("Dynamic allocation (p1) at: %u\n", p1);
    printf("Size *p1: %d\n", sizeof(*p1));
    printf("Dynamic allocation (p2) at: %u\n", p2);
    printf("Dynamic allocation (p3) at: %u\n", p3);
    getchar();
    free(p1);
    free(p2);
    free(p3);
    return 0;
}  
