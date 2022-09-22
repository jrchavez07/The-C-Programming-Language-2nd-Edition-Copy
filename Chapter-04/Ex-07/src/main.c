/*-
 *	Exercise 4-7. Write a routine ungets(s) that will push back an entire string
 *	onto the input. Should ungets know about buf and bufp, or should it just
 *	used ungetch?
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
	char s[] = "Hello, World! > this is a test.\n";
	int ch;

	ungets(s);
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


/* ungets: push back an entire string onto the input */
void
ungets(const char s[])
{
	size_t n = strlen(s);	

	while (n > 0)
		ungetch(s[--n]);
}
