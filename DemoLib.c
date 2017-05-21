/* stdlib_demo.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{   
    int i, a = 5, b = 50;
    double x=3.5, y= 20.8;
    printf("10 Hardware random integers:\n");
    for (i = 0; i < 10; i++) printf("%d ", rand());
    /*Init randomise using system time-miliseconds
        Each time the program executes, the system time changes.
        So, random sequence changes
    */
     srand(time(NULL)); 
     printf("\n\n10 Software random integers:\n");
     for (i = 0; i < 10; i++) printf("%d ", rand());
     printf("\n\n10 random integers between:%d...%d\n", a, b);
     for (i = 0; i < 10; i++) printf("%d ", a + rand()% (b-a));
     printf("\n\n5 random double between:%lf...%lf\n", x, y);
     for (i = 0; i < 5 ; i++) printf("%lf ", x + (double)rand()/RAND_MAX*(y-x));
     getchar();   
}
