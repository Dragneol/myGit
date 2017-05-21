#include <string.h>
#include <stdio.h>
#include <ctype.h>

char * ltrim(char * str) {
    int i, len = strlen(str);
    for (i = 0; i < len && (str[i] == ' ' || str[i] == '\n'); ++i);
    strcpy(str, str + i);
    str[len - i] = NULL;
    return str;
}

char * rtrim(char * str) {
    int i, len = strlen(str);
    for (i = len - 1; i >= 0 && (str[i] == ' ' || str[i] == '\n'); --i);
    str[i + 1] = 0;
    return str;
}

char * trim(char * str) {
    rtrim(ltrim(str));
    int lstSpc = -1, len = strlen(str), c = 0;
    int i;
    for (i = 0; i < len; ++i)
        if (str[i] == ' ') {
            if (lstSpc < 0)
                lstSpc = i;
            else
                c += 1;
        } else {
            char t = str[i - c];
            str[i - c] = str[i];
            str[i] = t;
            lstSpc = -1;
        }
    str[len - c] = 0;
    return str;
}

char * strtolower(char * str) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len; ++i) str[i] = tolower(str[i]);
    return str;
}

char * strtoupper(char * str) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len; ++i) str[i] = toupper(str[i]);
    return str;
}

char * captalize(char * str) {
    strtolower(str);
    str[0] = toupper(str[0]);
    int len = strlen(str), i;
    for (i = 1; i < len; ++i)
        if (str[i - 1] == ' ') str[i] = toupper(str[i]);
    return str;
}

int countWords(char * str) {
    int count = str[0] != ' ' ? 1 : 0;
    int len = strlen(str), i;
    for (i = 1; i < len; ++i)
        if (str[i - 1] == ' ' && str[i] != ' ') count += 1;
    return count;
}
char * strShr(char * str, int step) {
    int len = strlen(str), i;
    for (i = len - 1; i >= 0; --i)
        str[i + step] = str[i];
    str[len + step] = 0;
    return str;
}

char * replaceAll(char * str, const char * pat, const char * rep) {
    int len = strlen(str);
    int patL = strlen(pat);
    int repL = strlen(rep);
    int shorter = patL < repL;
    int i, j;
    for (i = 0; i < len; ++i) {
        if (strncmp(str + i, pat, patL) == 0) {
            if (shorter)
                strShr(str + i + patL, repL - patL);
            else
                strcpy(str + i + repL, str + i + patL);
            for (j = i; j < i + repL; ++j)
                str[j] = rep[j - i];
            i += repL;
            len += repL - patL;
        }
    }
    return str;
}

char * cistrstr(const char * str, const char * substr) {
    int strLen = strlen(str);
    int subLen = strlen(substr);
    int i, j;
    for (i = 0; i <= strLen - subLen; ++i) {
        int matched = 1;
        for (j = 0; j < subLen; ++j)
            if (tolower(substr[j]) != tolower(str[j + i])) {
                matched = 0;
                break;
            }
        if (matched)
            return (char*)str + i;
    }
    return NULL;
}

char *nameStr(char s[])
{
	trim(s);
	strlwr(s);
	int i = 0;
//	do {
//		if (s[i-1] = ' ') s[i] = toupper(s[i]);
//		i++;
//	} while ( i < strlen(s));
	for ( i = 0; i < strlen(s); i++)
		if (i == 0 || s[i-1] == ' ') s[i] = toupper(s[i]);
	return s;
}
