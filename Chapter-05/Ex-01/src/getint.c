/*-
 *	Exercise 5-1. As written, getint treats a + or - not followed by a digit as a
 *	valid representation of zero. Fix it to push such a character back on the input.
 *
 *	By jr.chavez07
 */
#include <stdio.h>
#include <ctype.h>

#include "getch.h"

#define MAX	10

int getint(int *pn);

int
main(void)
{
	int i, num[MAX];
	int val;

	for (i = 0; i < MAX && (val = getint(&num[i])) != EOF; i++)
		printf("num[%d] = %d, \tvalue returned: %d (%s)\n", i, num[i], 
				val, val != 0 ? "number" : "not a number");
	return 0;
}

/* getint: get next integer from input into *pn */
int
getint(int *pn)
{
	int c, sign;
	
	*pn = 0;
	while (isspace(c = getch()))	/* skip white space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-')
		return 0;
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		c = getch();
		if (!isdigit(c)) {
			ungetch((sign == 1) ? '+' : '-');
			return 0;
		}
	}
	for ( ; isdigit(c); c = getch())
		*pn = 10 * * pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

