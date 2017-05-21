/*
Develop a program that will throw two dice until the top faces of the two dice total to a specified number. 
*/

#include <stdio.h>
#include <time.h>

int intRandom(int a, int b) {
    return ( a + rand() % (b - a + 1));
}

main()
{
	srand(time(NULL));
	int total, x, y, count, check;
    printf("Dice Thrower \n");    
    printf("============ \n");    
    do{
    	printf("Total: ");
    	fflush(stdin);
    	check = scanf("%d", &total);
    	if (check != 1 || total < 2 || total > 12) printf ("Total must be an integer in range [2..12] only!!!\n");
	} while (check != 1 ||total < 2 || total > 12);
	count = 0;
	do{
		x= intRandom(1,6);
		y= intRandom(1,6);
		printf("Result of throw %d : %d + %d \n", ++count, x, y);
	} while (x + y != total);
	printf("You got your total in %d throws!", count);
}
