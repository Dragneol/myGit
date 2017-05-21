#include <stdio.h>
#include "trim.c"
#include "replaceString.c"

 main()
 {
 	char s[21], sub[21],rep[21];
 	printf("S = "); gets(s);
 	trim(s);
 	printf("After extra blanks are removed:"); puts(s);
 	nameStr(s);
 	printf("After convered to a name:"); puts(s);
 	printf("Sub = "); gets(sub);
 	printf("Rep = "); gets(rep);
//	strcpy(s,replaceAll(s,sub,rep)) 
	replaceAll(s,sub,rep);
	puts(s);
 }
