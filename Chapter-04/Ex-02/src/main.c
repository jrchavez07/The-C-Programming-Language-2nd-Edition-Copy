/*-
 *	Exercise 4-2. Expand atof to handle scientific notation of the form
 *		123.45e-6
 *	where a floating-point number may be followed by a e or E and an optionally
 *	signed exponent.
 *
 *	Jose Chavez
 */
#include <stdio.h>
#include <ctype.h>

#define MAXLINE	100

/* rudimentary calculator */
int
main(void)
{
	double sum, atof(char []);
	char line[MAXLINE];
	ssize_t get_line(char line[], size_t max);

	sum = 0;;
	while (get_line(line, MAXLINE) > 0)
		printf("\t%g\n", sum += atof(line));
	return 0;
}


ssize_t
get_line(char buf[], size_t bufsiz)
{
	int indx;

	indx = 0;
	while (--bufsiz > 0) {
		int ch = getchar();
		if (ch == EOF)
			break;
		buf[indx++] = ch;
		if (ch == '\n')
			break;
	}
	buf[indx] = '\0';
	return indx;
}


/* atof: convert string s to double */
double
atof(char s[])
{
	double val, power;
	int i, sign, exp, esign, pwr(int base, int exp);

	esign = 0;
	for (i = 0; isspace(s[i]); i++)	/* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	
	if (s[i] == 'e' || s[i] == 'E')
		i++;
	if (s[i] == '+' || s[i] == '-')
		esign = s[i++];
	for (exp = 0; isdigit(s[i]); i++)
		exp = 10 * exp + (s[i] - '0');
	return (esign == '-') ? sign * (val / power) / pwr(10, exp) :
				sign * (val / power) * pwr(10, exp);	
}


/* pwr: raise base to n-th power; n >= 0 */
int
pwr(int b, int n)
{
	int p;

	for (p = 1; n > 0; --n)
		p *= b;
	return p;
}
