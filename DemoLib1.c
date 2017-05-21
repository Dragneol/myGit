/* stdlib_demo.c */
/* Evaluate time cost of 1000000000 mathematic operations */
#include <stdio.h>
#include <time.h>
int main()
{
 int i, n=1;
  double x=1.5;
  /* Use time_t data type */
  time_t t1 = time(NULL); /*Get current time */
  for (i = 0; i < 1000000000; i++) x = x+1;
  time_t t2 = time(NULL); /*Get current time */
  double dt = difftime(t2,t1);
  printf("\nCost of 1 billion real number adding operations: %lf sec\n", dt);
  t1 = time(NULL); /*Get current time */
  for (i = 0; i < 1000000000; i++) n = n+1;
  t2 = time(NULL); /*Get current time */
  dt = difftime(t2,t1);
  printf("\nCost of 1 billion integral number adding operations: %lf sec\n", dt);
  /* Use clock_t data type */
  n = 1;
  clock_t ct1 = clock(); /*Get current time */
  for (i = 0; i < 1000000000; i++) n = n+1;
  clock_t ct2 = clock(); /*Get current time */
  printf("\nCost of 1 billion integral number adding operations: %ld ticks\n", ct2-ct1);
  printf("\nor %lf secs\n", ((double)(ct2-ct1)/CLOCKS_PER_SEC));
  getchar();
}
