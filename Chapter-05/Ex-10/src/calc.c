#include <stdio.h>

#include "calc.h"

void
jr_add(void)
{
	push(pop() + pop());
}


void
jr_mult(void)
{
	push(pop() * pop());
}


void
jr_sub(void)
{
	int op2 = pop();
	push(pop() - op2);
}


void
jr_div(void)
{
	int op2 = pop();
	
	if (op2 != 0.0)
		push(pop() / op2);
	else
		(void)fprintf(stderr, "error: zero divisor\n");
}
