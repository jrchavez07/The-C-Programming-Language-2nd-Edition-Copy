#include <stdio.h>

#include "calc.h"

#define MAXVAL	100	/* maximun depth of val stack */

static int sp = 0;		/* next free stack position */
static double val[MAXVAL];	/* value stack */

/* push: f onto value stack */
void
push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}


/* pop: pop and return top value from stack */
double
pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}


/* peek: print the top element of the stack w/o popping it */
void
peek(void)
{
	printf(">\t%.8g\n", val[sp - 1]);
}


/* duptop: duplicate the top element of the stack */
void
duptop(void)
{
	double item = pop();
	push(item);
	push(item);
}


/* swap: swap the top two elements */
void
swap(void)
{
	double item_1 = pop();
	double item_2 = pop();

	push(item_1);
	push(item_2);
}


/* clear_stack: clear the stack */
void
clear_stack(void)
{
	sp = 0;
}

