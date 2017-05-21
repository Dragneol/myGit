/*
Write a program that allows user inputting a simple expression containing one of four operators +, -, *, / 
then the result is printed out to the monitor. Input format:  num1 operator num2,
An example of user interface
Enter an expression (+ - * /): 4*5 
Result: 20
*/
#include <stdio.h>
main()
{
	double num1, num2, result;
	char op;
	printf("Enter an expression (+ - * /): ");
	scanf("%lf%c%lf", &num1, &op,&num2);
	switch (op)
	{
		case '+':
			 	result = num1 + num2;
			 	printf("Result: %3lf", result);
			break;
		case '-':
			 	result = num1 - num2;
			 	printf("Result: %3lf", result);
			break;
		case '*':
			 	result = num1 * num2;
			 	printf("Result: %3lf", result);
			break;
		case '/':
			 	result = num1 / num2;
			 	printf("Result: %3lf", result);
			break;
		default:
			printf("Op is not supported");
	}
}
