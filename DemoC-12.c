#include <stdio.h>
void swap( int *pa, int *pb)
{  int t;
   t = *pa;
   *pa = *pb;
   *pb = t;
}
int main()
{  int x = 5, y = 7,t;
   printf("In main, var. x, add.:%u, value:%d\n", &x, x);
   printf("In main, var. y, add.:%u, value:%d\n", &y, y);
   printf("Addr. of main(): %u\n", &main);
   printf("Addr. of swap(...): %u\n", &swap);
   swap (&x, &y);
   printf("After swapping x and y\n");
   printf("x=%d, y=%d\n", x, y);
   getchar();
   return 0;
}

