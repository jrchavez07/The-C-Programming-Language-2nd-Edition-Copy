#include <stdio.h>

#define BUFSIZE	100

static char buf[BUFSIZE];	/* buffer for ungetch */
static int bufp = 0;		/* next free position in buf */

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


