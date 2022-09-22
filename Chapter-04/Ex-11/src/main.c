/*-
 *	Exercise 4-11. Modify getop so that it doesn't need to use ungetch. Hint:
 *	use an internal static variable.
 *
 *	By Jose Chavez
 */
#include <stdio.h>
#include <stdlib.h>	/* for atof() */
#include <math.h>

#include "calc.h"

#define	MAXOP	100	/* max size of operand or operator */

/* reverse Polish calculator */
int
main(void)
{
	int type, rval;
	double op2;
	char s[MAXOP];

	rval = FALSE;
	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case ID:
			access_to_math_libf(s);
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop();
			if (op2 != 0.0)
				push(fmod(pop(), op2));
			else
				printf("error: zero divisor\n");
			break;
		case '?':
			peek();
			break;
		case '#':
			duptop();
			break;
		case '~':
			swap();
			break;
		case '!':
			clear_stack();
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			rval = handling_vars(type);
			if (!rval && type != '=')
				push(variables[type - 'A']);
			if (rval == FALSE)
				printf("error: unkown command %s\n", s);
			break;
		}
	}
	return 0;
}

