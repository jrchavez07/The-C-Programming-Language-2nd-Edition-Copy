/*-
 *	Exercise 5-10. Write the program expr, which evaluates a reverse Polish
 *	expression from the command line, where each operator or operand is a separate
 *	argument. For example,
 *      
 *		expr 2 3 4 + *
 *
 *	evaluates 2 x (3 + 4).
 *
 *	By jr.chavez07
 *
 *	NOTE:
 *	To receive the expected output with the following example:
 *		2 3 4 + *
 *	'\' must be used (e.g., 2 3 4 + \* instead of *)
 */
#include <stdio.h>
#include <stdlib.h>	/* for atof() */
#include <string.h>	/* for strlen() */
#include <ctype.h>	/* for isdigit() */
#include <math.h>

#include "calc.h"

#define NUMBER	'0'	/* signal that a number was found */

void reverse_polish_calculator(int argc, char *argv[]);
int eval(int type, int argc, char *argv[]);
void eval_number(const char *arg);

/* reverse Polish calculator */
int
main(int argc, char *argv[])
{
	reverse_polish_calculator(argc, argv);
	return 0;
}


void
reverse_polish_calculator(int argc, char *argv[])
{
	int c;
	char *p = NULL;

	while (--argc > 0) {
		p = *++argv;
		argc = eval((!isdigit(c = *p) && strlen(p) == 1) ? c : NUMBER,
				argc, argv);
	}
	printf("\t%.8g\n", pop());
}


int
eval(int type, int argc, char *argv[])
{
	switch (type) {
	case NUMBER:
		eval_number(*argv);
		break;
	case '+':
		jr_add();
		break;
	case '*':
		jr_mult();
		break;
	case '-':
		jr_sub();
		break;
	case '/':
		jr_div();
		break;
	default:
		(void)fprintf(stderr,
				"error: unkown command %s\n", *argv);
		argc = 1;
		break;
	}
	return argc;
}


void
eval_number(const char *nptr)
{
	push(atof(nptr));
}



