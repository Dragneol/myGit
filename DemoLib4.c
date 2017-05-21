#include <stdio.h>

void clear () 
{ 
    while ( getchar() != '\n' ); 
} 


int main()
{  char c1, c2;
   printf("Input the 1st character:");
   clear();
//    fflush(stdin);
   scanf("%c", &c1);
   printf("Input the 2st character:");
//   clear(); 
//    fflush(stdin);
            fpurge(stdin);
   c2 = getchar();
   printf("c1=%c, ASCII:%d\n", c1, c1);
   printf("c2=%c, ASCII:%d\n", c2, c2);
   getchar();
}
