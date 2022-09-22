/*-
 *	Exercise 4-6. Add commands for handling variables. (It's easy to provide
 *	twenty-six variables with single letter names.) Add a variable for the most
 *	printed value.
 *
 *	By Jose Chavez
 */
#include <stdio.h>
#include <stdlib.h>	/* for atof() */
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#define	MAXOP	100	/* max size of operand or operator */
#define NUMBER	'0'	/* signal that a number was found */
#define ID	'I'	/* signal that a letter was found */
#define MAXVAL	100	/* maximun depth of val stack */
#define MAXVAR	26
#define BUFSIZE	100
#define DEFLEN	4
#define DEFLEN_UNS_LIBS	18	/* default length of unsupported libraries */

enum boolean { FALSE , TRUE };	/* 0, 1 */

int sp = 0;		/* next free stack position */
double val[MAXVAL];	/* value stack */
char buf[BUFSIZE];	/* buffer for ungetch */
int bufp = 0;		/* next free position in buf */
int variables[MAXVAR] = { 0.0 };

const char *math_libs[] = {
				"sin",
				"cos",
				"exp",
				"pow",
			};

const char *uns_libs[] = {			/* unsupported library functions */
				"tan", "asin",
				"acos", "atan",
				"atan2", "sinh",
				"cosh", "tanh",
				"log", "log10",
				"sqrt", "ceil",
				"floor", "fabs",
				"ldexp", "frexp",
				"frexp", "modf"
			};

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

void peek(void);
void duptop(void);
void swap(void);
void clear_stack(void);

void access_to_math_libf(const char []);
int match_libf(const char []);

_Bool handling_vars(int);

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
			if (!rval && type != '=') {
				push(variables[type - 'A']);

				if (rval == FALSE) {
					printf("error: unkown command %s\n", s);
				}
			}	
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
	if (isalpha(c)) {
		i = 0;
		while (isalpha(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if (c != EOF)
			ungetch(c);
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


/* access_to_math_libsf: access to library functions (sin, cos, exp, and pow.)*/
void
access_to_math_libf(const char s[])
{
	int n = match_libf(s);

	switch (n) {
	case 1:
		push(sin(pop()));
		break;
	case 2:
		push(cos(pop()));
		break;
	case 3:
		push(exp(pop()));
		break;
	case 4:
		{
			double op2 = pop();
			push(pow(pop(), op2));
			break;
		}
	case -1:
		printf("%s is not a supported function.\n", s);
		break;
	default:
		break;
	}
}


/* match_libf: check if the library is found or not. returns -1
 * if it is an unsupported function library. */
int
match_libf(const char s[])
{
	int loc, loc2, found;

	found = 0;
	for (loc = 0; loc < DEFLEN; loc++)
		if (strcmp(s, math_libs[loc]) == 0) {
			found = loc + 1;
			return found;
		} else {
			for (loc2 = 0; loc2 < DEFLEN_UNS_LIBS; loc2++) {
				if (strcmp(s, uns_libs[loc2]) == 0) {
					found = -1;
					return found;
				}
			}
		}

	return 0;
}


/* handling_vars: function to handle variables */
_Bool
handling_vars(int var)
{
	return ((islower(var) && isupper(var)) || var == '=') ? TRUE : FALSE;
}
