/*
	Develop a C-program that allows user:
-	Adding a new student
- 	Editting list for information
-	Find data about students using a name inputted.
-	Remove an stdudent based on a code inputted
-	Print the list in descending order based on salary + allowance.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "trim.c"

const MAXN = 100;
const MAXCHOICE = '5';

char getUserChoice()
{
    int c;
    printf("1-Adding a new student\n");
    printf("2-Find data about students using a name inputted\n");
    printf("3-Remove an student based on a code inputted\n");
    printf("4-Print the list in descending order based on salary + allowance\n");
    printf("5-Quit\n");
    printf("Choice = ");
    fflush(stdin);
    scanf("%c", &c);
    return c;
}

void add (char code[][8], char name[][21], double salary[],double allowance[], int *pn)
{  
	char ts[21];
	double g;
	int i, existed;
	do {
	printf("New Code(8 character) : ");
	fflush(stdin);
	scanf("%8[^\n]", ts);
	existed = 1;
	for ( i = 0; i < *pn; i++)
		if (strcmp(ts,code[i]) == 0) 
			{
				printf("Code existed!Retype!\n");
				existed = 0;
				i = *pn - 1;
			}
	} while (!existed);
	strcpy(code[*pn], ts);
	do {
	printf("New Name(20 character) : ");
	fflush(stdin);
	scanf("%20[^\n]", ts);
	existed = 1;
	for ( i = 0; i < *pn; i++)
		if (strcmp(ts,name[i]) == 0) 
			{
				printf("Name existed!Retype!\n");
				existed = 0;
				i = *pn - 1;
			}
	} while (!existed);
	nameStr(ts);
	strcpy(name[*pn], ts);
	printf("salary : ");
	scanf("%lf", &g);    
	salary[*pn] = g;
	printf("allowance : ");
	scanf("%lf", &g);    
	allowance[*pn] = g;
	(*pn)++;
	printf("Added!!\n\n");
  	system("pause");
    system("cls");
}

void search(char code[][8], char name[][21], double salary[],double allowance[], int *pn)
{
	int i;
	printf("Searching for : ");
	char nv[21];
	fflush(stdin);
    scanf("%20[^\n]", &nv);
    nameStr(nv);
	for (i = 0; i < *pn; i++)
		{
			int j;
			char * ptr = strstr(name[i], nv);
			if (ptr != '\0') printf("RESULT :[%d] := Code:%8s|Name:%20s|salary:%3.3lf|allowance:%3.3lf \n"
											, i	, code[i]	, name[i]	, salary[i]	, allowance[i]);
		}
	system("pause");
    system("cls");
}

void deleted(char code[][8], char name[][21], double salary[],double allowance[], int *pn)
{
	int i,j;
	for (i = 0; i < *pn; i++)
    	printf("Code:%8s|Name:%20s|salary:%3.3lf|allowance:%3.3lf \n", code[i], name[i], salary[i], allowance[i]);
	char del[8];
	fflush(stdin);
	printf("Code for deleted(Success only when code exist) : ");
	scanf("%8[^\n]", &del);
	
	for (i = 0; i < *pn; i++)
		if (strcmp(code[i], del) == 0)
		{ 
			for (j = i+1; j < *pn; j++)
				{ 
		            strcpy(name[i-1], name[i]);
		            strcpy(code[i-1], code[i]);
		            salary[i-1] = salary[i];
		            allowance[i-1] = allowance[i];
		        }
		    (*pn)--;
		    printf("Success!\n\n");
		}
	system("pause");
    system("cls");
}

void print(char code[][8], char name[][21], double salary[],double allowance[], int *pn)
{
	
	int i, j;
	for (i = 0; i < *pn-1; i++)
		for (j = *pn-1; j > i; j--)
			if ( (salary[j] + allowance[j]) > (salary[j-1] + allowance[j-1]) )
			{
				char t[21];
	            strcpy(t, name[j]);
	            strcpy(name[j], name[j-1]);
	            strcpy(name[j-1], t);
	            
	            char tu[8];
	            strcpy(tu, code[j]);
	            strcpy(code[j], code[j-1]);
	            strcpy(code[j-1], tu);
	            
	            double tg = salary[j];
	            salary[j]=salary[j-1];
	            salary[j-1]=tg;
	            
	            double tb = allowance[j];
	            allowance[j]=allowance[j-1];
	            allowance[j-1]=tb;
			}
	for (i = 0; i < *pn; i++)
    	printf("Code:%8s|Name:%20s|salary:%3.3lf|allowance:%3.3lf \n", code[i], name[i], salary[i], allowance[i]);
	if (*pn)printf("Success!\n\n");
	else printf("Nothing to print!\n\n");
	system("pause");
    system("cls");
}
void halt()
{
	printf("This program coded by Duong\n");
	printf("Thank you for watching\n");
}

main()
{
    char userChoice;
    char code[MAXN][8],name[MAXN][21];
	double salary[MAXN], allowance[MAXN];
    int n = 0;
    do
    {
        userChoice = getUserChoice();
        switch(userChoice)
        {
            case '1':
				if (n == MAXN) printf("Can't Add anymore!\n");
				else add(code, name, salary, allowance, &n);
				break;
            case '2':
				if (n == 0) printf ("Nothing to search!\n");
				else search(code, name, salary, allowance, &n);
				break;
            case '3':
				if (n == 0) printf ("Nothing to deleted");
				else deleted(code, name, salary, allowance, &n);break;
            case '4':
				if (n == 0) printf ("Nothing to print");
				else print(code, name, salary, allowance, &n);break;
            case '5':halt();break;
        }
       if (userChoice < '1'  || userChoice >'5') printf("1 to 5 only!\n");
    } while (userChoice != MAXCHOICE);
}
