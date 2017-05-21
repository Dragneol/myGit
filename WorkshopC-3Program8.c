/*
Write a C program that will accept the integral part and fraction of a real number 
then print out the this real number.
*/
#include <stdio.h>

double makeDouble(int  ipart, int fraction)
{  
    double d_f = fraction;
    while (d_f >= 1) d_f /= 10; /* create the fraction <1 */
    if (ipart < 0) return ipart - d_f; /* case  -51 - 0.139 */
    return ipart + d_f ;  /* case 32 + 0.25 */
}

main()
{
    int ipart, fraction;
    printf("Integer part : ");
    scanf("%d", &ipart);
    do {
        printf("Fraction part : ");
        fflush(stdin);
        scanf("%d", &fraction);
        if (fraction < 0) printf("Fraction must be Positive!!!\n");
    }while (fraction < 0);
    printf("Value = %lf", makeDouble(ipart, fraction));
}
