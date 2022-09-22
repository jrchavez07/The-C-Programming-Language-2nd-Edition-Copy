/*-
 *	Exercise 3-4. In a two's complement number representation, our version of
 *	itoa does not handle the largest negative number, that is, thhe value of n equal
 *	to -(2^wordsize-1). Explain why not. Modify it to print that value correctly,
 *	regardless of the machine on which it runs.
 *
 *	Ans:
 *		The original itoa doesn't work because the range of negative numbers is one
 *		greater than the range of positive numbers.
 *
 *	Jose Chavez
 */
#include <stdio.h>
#include <string.h>

#define MAXLINE	1024

void itoa(int n, char s[]);
void reverse(char s[]);

int
main(void)
{
	signed int n = -2147483648;
	char s[MAXLINE];

	itoa(n, s);
	printf("%s\n", s);
	return 0;
}


/* itoa: convert n to characters in s */
void
itoa(int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0)	/* record sign */
		n = -n;		/* make n positive */
	i = 0;
	do {	/* generate digits in reverse order */
		s[i++] = n % 10 + '0';	/* get next digit */
	} while ((n /= 10) != 0);	/* delete it */
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
