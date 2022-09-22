/*-
 *	Exercise 3-6. Write a version of itoa that accepts three arguments instead of
 *	two. The third argument is aminimun field width; the converted number must
 *	be padded with blanks on the left if necessary to make it wide enough.
 *
 *	Jose Chavez
 */
#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAXLINE		1024
#define DEFWIDTH	11
#define COUNT		8

void itoa(int n, char s[], size_t w);
void reverse(char []);

int
main(void)
{
	int n[] = { 15, -15, 6, -6, 1983, -1983, INT_MIN, INT_MAX };
	char s[MAXLINE];
	
	for (int i = 0; i < COUNT; i++) {
		itoa(n[i], s, DEFWIDTH);
		printf("%s\n", s);
	}
	return 0;
}


void
itoa(int n, char s[], size_t w)
{
	int i, sign;

	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) != 0);
	
	if (sign < 0)
		s[i++] = '-';

	while (i < (int)w)
		s[i++] = ' ';
	s[i] = '\0';
	reverse(s);
}


void
reverse(char s[])
{
	int i, j, temp;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}
