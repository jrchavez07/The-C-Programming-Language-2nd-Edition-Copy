/*-
 *	Exercise 4-9. Our getch and ungetch do not handle a pushed-back EOF
 *	correctly. Decide what their properties ought to be if an EOF is pushed back,
 *	ten implement your design.
 *
 *	By Jose Chavez
 */
#include <stdio.h>
#include <string.h>

#define BUFSIZE	100

char buf[BUFSIZE];	/* buffer for ungetch */
int bufp = 0;		/* next free position in buf */

int getch(void);
void ungetch(int);
void ungets(const char []);

int
main(void)
{
	int ch;

	ungetch(EOF);
	while ((ch = getch()) != EOF)
		putchar(ch);
	return 0;
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
	else if (c != EOF)
		buf[bufp++] = c;
}

