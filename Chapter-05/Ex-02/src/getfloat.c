/*-
 *	Exercise 5-2. Write getfloat, the floating-point analog of getint. What
 *	type does getfloat return as its function value?
 *
 *	By jr.chavez07
 */
#include <stdio.h>
#include <ctype.h>

int
getfloat(float *pn)
{
	int c, sign;
	float pwr;

	while (isspace(c = getc(stdin)))	/* skip white space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetc(c, stdin);	/* it's not a number */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getc(stdin);
	for (*pn = 0.0; isdigit(c); c = getc(stdin))
		*pn = 10.0 * *pn + (c - '0');
	if (c == '.')
		c = getc(stdin);
	for (pwr = 1.0; isdigit(c); c = getc(stdin)) {
		*pn = 10.0 * *pn + (c - '0');
		pwr *= 10.0;
	}
	*pn *= sign / pwr;
	if (c != EOF)
		ungetc(c, stdin);
	return c;
}
