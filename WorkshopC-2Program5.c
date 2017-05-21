/*Write a C program that will:
-	permit user inputting a string of characters. The input operation will terminate if the ENTER key is stroked. 
-	print out the number of vowels, number of consonants, and number of others to the monitor.
*/
#include <stdio.h>
#include <ctype.h>
main() {
	char ch;
	int nVowels = 0, nConsonants = 0, nOthers = 0;
	do{
		fflush(stdin);
		scanf("%c", &ch);
		ch = toupper(ch);
		if ( ch>='A' && ch <='Z') 
		{
			switch(ch) {
				 case 'A' :
		         case 'E' :
		         case 'I' :
		         case 'O' :
		         case 'U' : 
				 	nVowels++; 
					break;
				default :
					nConsonants++;
			}
		} else nOthers++;
	} while (ch != '\n');
	printf("Number of Vowels: %d\n", nVowels);
	printf("Number of Consonants: %d\n", nConsonants);
	printf("Number of Others: %d\n", nOthers);
}
