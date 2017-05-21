/*
Write a C program that will accept a point and a circle having the center is (0,0) 
then print out the relative position of this point with the circle.
*/
#include <stdio.h>

int getRelPos( double x, double y, double r) 
{
   double d2=x*x + y*y;  /* d2= x2+ y2  */
   double r2= r*r;            /* r2*/  
   if ( d2 < r2 ) return 1 ; /* d2<r2 : the point is in the circle */
   else if ( d2 == r2 ) return 0 ; /* d2=r2 : the point is on the circle */
   return -1 ; /* d2 > r2 : the point is out of the circle */
}

main()
{
    double x, y, r;
    printf("Input co-ordinate(x,y):");
    scanf("%lf%lf", &x, &y);
    do {
        printf("Radius = ");
        scanf("%lf", &r);
        if (r <= 0) printf("Input a positive Radius!!!\n");
    } while (r <= 0);
    ( getRelPos( x, y, r) == 1 )? printf("the point is in the circle"):
    	( !( getRelPos( x, y, r) )? printf("the point is on the circle"): printf("the point is out of the circle") );
}
