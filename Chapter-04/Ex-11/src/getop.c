#include <stdio.h>
#include <ctype.h>

#include "calc.h"

/* getop: get next operator or numeric operand */
int
getop(char s[])
{
	int i, c;
	static int prev_c;

	prev_c = 0;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (isalpha(c)) {
		i = 0;
		while (isalpha(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if (c != EOF)
			prev_c = c;
		return ID;
	}

	if (!isdigit(c) && c != '.')
		return c;	/* not a number */
	i = 0;
	if (isdigit(c))		/* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')		/* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		prev_c = c;
	return NUMBER;
}


