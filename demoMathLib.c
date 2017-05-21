#include <stdio.h>
#include <time.h>
#include <math.h>

int main()
{ double x= 15.3, y=-2.6;
  printf("floor: %lf, %lf\n", floor(x), floor(y));
  printf("ceil: %lf, %lf\n", ceil(x), ceil(y));
  printf("round: %lf, %lf\n", round(x), round(y));
  printf("trunc: %lf, %lf\n", trunc(x), trunc(y));
  printf("sqrt: %lf\n", sqrt(x));
  printf("pow- x^y : %lf\n", pow(x,y));
  printf("exp- e^x: %lf\n", exp(x));
  printf("log(x): %lf\n", log(x));
  printf("log2(x): %lf\n", log(x)/log(2));
  getchar();   
}

