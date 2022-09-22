/*-
 *	Exercise 4-1. Write a function strrindex(s, t), which returns the position
 *	of the rightmost occurrence of t in s, or -1 if there is none.
 *
 *	Jose Chavez
 */
#include <stdio.h>

int strrinx(char s[], char t[]);

int
main(void)
{
	int pos;
	char line[] = "abcdedfabcde";


	pos = strrinx(line, "abc");
	printf("pos = %d: s = %s\n", pos, line);
	return 0;
}


int
strrinx(char s[], char t[])
{
	int i, j, k;
	int pos;

	pos = -1;
	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			pos = i;
	}
	return pos;
}
