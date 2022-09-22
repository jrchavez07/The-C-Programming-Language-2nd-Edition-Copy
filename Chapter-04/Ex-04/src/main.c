/*-
 *	Exercise 4-4. Add commands to print the top element of the stack without pop-
 *	ping, to duplicate it, and to swap the top two elements. Add a command to
 *	clear the stack.
 *
 *	By Jose Chavez
 */
#include <stdio.h>
#include <stdlib.h>	/* for atof() */
#include <ctype.h>
#include <math.h>

#define	MAXOP	100	/* max size of operand or operator */
#define NUMBER	'0'	/* signal that a number was found */
#define MAXVAL	100	/* maximun depth of val stack */
#define BUFSIZE	100

int sp = 0;		/* next free stack position */
double val[MAXVAL];	/* value stack */
char buf[BUFSIZE];	/* buffer for ungetch */
int bufp = 0;		/* next free position in buf */

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

void peek(void);
void duptop(void);
void swap(void);
void clear_stack(void);

/* reverse Polish calculator */
int
main(void)
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
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
			printf("error: unkown command %s\n", s);
			break;
		}
	}
	return 0;
}


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


/* getop: get next operator or numeric operand */
int
getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
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
		ungetch(c);
	return NUMBER;
}


/* getch: get a (possibly pushed back) character */
int
getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}


/* ungetch: push character back on input */
void
ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
