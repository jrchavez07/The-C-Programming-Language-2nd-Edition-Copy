/*-
 *	Exercise 4-8. Suppose that there will never be more than one character of
 *	pushbach. Modify getch and ungetch accordingly.
 *
 *	By Jose Chavez
 */
#include <stdio.h>
#include <string.h>

#define BUFSIZE	1

char buf[BUFSIZE];	/* buffer for ungetch */
int bufp = 0;		/* next free position in buf */

int getch(void);
void ungetch(int);
void ungets(const char []);

int
main(void)
{
	int ch;

	ungetch('>');
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
	else
		buf[bufp++] = c;
}

