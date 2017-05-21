/*
Write a C-program that helps user managing a list of 100  student names using the following menu:
1- Add a student
2- Remove a student
3- Search a student
4- Print the list in ascending order
5- Quit
*/

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include "trim.c"

const MAXN = 100;
const MAXCHOICE = '5';

char getUserChoice()
{
    int c;
    printf("1-Add a student\n");
    printf("2-Remove a student\n");
    printf("3-Search a student\n");
    printf("4-Print the list in ascending order\n");
    printf("5-Quit\n");
    printf("Choice = ");
    fflush(stdin);
    scanf("%c", &c);
    return c;
}

int isFull(char list[MAXN][21], int *pn) {
	return ((*pn) == MAXN);
}

int isEmpty(char list[MAXN][21], int *pn) {
	return ((*pn) == 0);
}

void add(char list[MAXN][21], int *pn) {
	char hs[21];
	int i, existed;
	do {
		printf("Add a student : ");
		fflush(stdin);
		scanf("%20[^\n]", hs);
		existed = 1;
		for ( i = 0; i < *pn; i++)
			if (strcmp(hs,list[i]) == 0) 
				{
					printf("Name existed!Retype!\n");
					existed = 0;
					i = *pn - 1;
				}
	} while (!existed);
    strcpy(list[*pn], hs);
    (*pn)++;
    printf("Added!\n");
    system("pause");
    system("cls");
}

void search(char list[MAXN][21], int *pn)
{
	int i;
	printf("Searching for : ");
	char hs[21];
	fflush(stdin);
    scanf("%20[^\n]", &hs);
	for (i = 0; i < *pn; i++)
		{
			nameStr(hs);
			nameStr(list[i]);
			char * ptr = strstr(list[i], hs);
			if (ptr != '\0') printf("RESULT : Name[%d] : %s\n", i, list[i]);
		}
}
void removed(char list[MAXN][21], int *pn)
{
	search(list, pn);
	printf("Which Name you want to removed?(input a number) : ");
	int del, i;
	scanf("%d", &del);
	if (del >= 0 && del < *pn) {
	for (i = del + 1; i < *pn; i++)
		strcpy(list[i-1], list[i]);
	printf("Removed!\n");
	(*pn)--;
	} else printf("UnRemoved!\n");
	system("pause");
    system("cls");
}
void print(char list[MAXN][21], int *pn)
{
	int i, j;
   	for (i = 0 ; i < *pn-1; i++)
     	for (j = *pn-1; j > i; j--)
     		if (strcmp(list[j] , list[j-1]) < 0)
     			{
     				char t[21];
		            strcpy(t, list[j]);
		            strcpy(list[j], list[j-1]);
		            strcpy(list[j-1], t);
				}
	for (i = 0; i < (*pn); i++)
		{
			nameStr(list[i]);
			printf("Name[%d] : %s \n", i, list[i]);
		}
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
    char list[MAXN][21];
    int n = 0;
    do
    {
        userChoice = getUserChoice();
        switch(userChoice)
        {
            case '1':
				if (isFull(list, &n)) printf("Impossible to add!\n");
				else add(list, &n);
				break;
            case '2':
				if (isEmpty(list, &n)) printf("Impossible to remove!\n");
				else removed(list, &n);break;
            case '3':
				if (isEmpty(list, &n)) printf("Nothing to search!\n");
				else search(list, &n);
				system("pause");
			    system("cls");
				break;
            case '4':
				if (isEmpty(list, &n)) printf("Nothing to print!\n");
				else print(list, &n);
				break;
            case '5':
				halt();
				break;
        }
       if (userChoice < '1'  || userChoice >'5') printf("1 to 5 only!\n");
    } while (userChoice != MAXCHOICE);
}
