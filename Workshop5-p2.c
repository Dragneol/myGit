/*
Develop a program that will pick two number until the total of the two to a specified number. 
*/
#include <stdio.h>
#include <time.h>

int intRandom(int a, int b) {
    return ( a + rand() % (b - a + 1));
}

main()
{
	int total, x, y, count, check;
    printf("Ball Lottery \n");    
    printf("============ \n");    
    do{
    	printf("Total: ");
    	fflush(stdin);
    	check = scanf("%d", &total);
    	if (check != 1 || total < 2 || total > 20) printf ("Total must be an integer in range [2..20] only!!!\n");
	} while (check != 1 ||total < 2 || total > 20);
	count = 0;
	do{
		x= intRandom(1,10);
		y= intRandom(1,10);
		printf("Result of picks %d and %d: %d + %d \n", count++, ++count, x, y);
	} while (x + y != total);
	printf("You got your total in %d picks!", count);
}
