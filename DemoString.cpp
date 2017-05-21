#include <stdio.h>
#include <string.h>

main()
{
	char s1[21];
	char s2[21];
	printf("S1 = ")l gets(s1);
	printf("S2 = ")l gets(s2);
	prinf("Leng(s1): %d, leng(s2):%d\n", strlen(s1), strlen(s2));
	printf("Compare S1 vs S2 : %d\n", strcmp(s1,s2));
	strupr(s1);
	printf("Upcase S1 : %s\n", s1);
	strcat(s1,s2);
	printf("After append s2 to s1: %s\n", s1);
	char s3[10];
	printf("Enter substring : "); gets(s3);
	char * ptr = strstr(s1, s3);
	printf("Add s1 : %u", s1);
	printf("Add s3 : %u", s3);
	printf("Add substring : %u", ptr);
}
