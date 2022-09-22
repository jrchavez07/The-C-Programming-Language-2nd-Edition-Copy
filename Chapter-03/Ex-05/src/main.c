/*-
 *	Exercise 3-5. Write the function itob(n, s, b) that converts the integer n
 *	into a base b character representation in the string s. In particular,
 *	itob(n,  s, 16) formats n as a hexadecimal integer s.
 *
 *	Jose Chavez
 */
#include <stdio.h>
#include <string.h>

#define MAXLINE		1024

void itob(int n, char s[], unsigned int b);
void reverse(char s[]);

int
main(void)
{
	int n = 255;
	char s[MAXLINE];

	for (int i = 2; i <= 20; i++) {
		itob(n, s, i);
		printf("decimal 255 in base %-2d : %s\n", i, s);
	}
	return 0;
}


void
itob(int n, char s[], unsigned int b)
{
	int i, sign;

	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do {
		int rem = n % b;
		s[i++] = (rem <= 9) ? rem + '0' : rem + 'A' - 10;
	} while ((n /= b) != 0);
	if (sign < 0)
		s[i++] = '-';
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
