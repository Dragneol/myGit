/*
Write a C program using the following simple menu:
1- Quadratic equation ( ph??ng tr�nh b?c 2)
2- Bank deposit problem
3- Quit
Choose an operation:
-	When user chooses 1: User will enter values describing a quadratic equation then the program will print out its solution if it exists.
-	When user chooses 2: User will enter his/her deposit ( a positive number), yearly rate ( a positive number but less than or equal to 0.1), 
number of years ( positive integer), then the program will print out  his/her amount after this duration.
*/
#include <stdio.h>
#include <math.h>
#include <windows.h>

#define maxChoice '3'

char getUserChoice()
{
    char n;
    printf("1-Quadratic Equation\n");
    printf("2-Bank deposit\n");
    printf("3-Quit\n");
    printf("Choice [1..3] : ");
    fflush(stdin);
    scanf("%c", &n);
    return n;
}

void function1() // Quadratic Equation caculating function
{
    float a, b, c;
    printf("Input a b c : a*x^2 + b*x +c = 0 \n");
	scanf("%f%*c%f%*c%f", &a, &b, &c);
	if (a == 0)
	{
		// if ( (b != 0) && (c == 0) ) printf("%0.3f\n", 0); else 
		if ( (b == 0) && (c != 0) ) printf("None of root!\n"); // (a = 0, b = 0, c <> 0 => Vô nghiệm )
							else if ( (c == 0) && (b == 0) ) printf("Root in range of Real Number!\n"); // (a = 0, b = 0, c <> 0 => Vô số nghiệm )
												else printf("X = %0.3f\n", -c/b); // (phương trình có 1 nghiệm duy nhất -c/b)
	}
	else
	{
		int delta;
		delta = b*b - 4*a*c;
		if (delta < 0) printf("None of root!\n"); // Vô nghiệm
		else if (delta == 0)
				{
					printf("The Equation have double root : \n"); // phương trình có 1 nghiệm kép x = -b/(2*a)
					printf("X = %0.3f\n", -b / 2 / a );
				}
	     	else 
				{
					printf("The Equation have two root : \n"); // phương trình có 2 nghiệm
					printf("X1 = %0.3f \n", (- b - sqrt(delta) )/ 2 / a );									
					printf("X2 = %0.3f \n", (- b + sqrt(delta) )/ 2 / a );
				}
	}
	printf("\n");
	system("pause");
	system("cls");
}

void function2()
{
	printf("Bank deposit \n");    
    printf("============ \n");
	double deposit, rate, amount;
	int month, check;
	do {
    printf("Input your deposit , monthly rate and the number of months : ");
    fflush(stdin);
    check = scanf("%lf%*c%lf%*c%d", &deposit, &rate, &month);
    if (check != 3) printf("Retype 3 value please!\n");
    else {
		    if (deposit <= 0 ) printf("Deposit must be positive!\n");
		    if (month <= 0 ) printf("The number of months must be positive!\n");
		    if (rate <= 0 || rate > 0.1) printf("Monthly rate must be positive but less than or equal to 0.1!\n");
    	}
    } while ( deposit <= 0  || month <= 0  || rate <= 0 || rate > 0.1 || check != 3 );
    amount =(float) deposit * pow( (1 + rate) , month );
    printf("Your amount after duration : %f", amount);
    printf("\n");
	system("pause");
	system("cls");
}

void function3()
{
    printf("This is program coded by Duong\n");
    printf("Thank you for watching! Bye Bye!");
}

main()
{
    char userChoice;
    do
    {
        userChoice = getUserChoice();
        switch(userChoice)
        {
            case '1':function1();break;
            case '2':function2();break;
            case '3':function3();break;
            default : printf("Input 1 or 2 or 3 only!\n");
        }
    } while (userChoice != maxChoice);
}
