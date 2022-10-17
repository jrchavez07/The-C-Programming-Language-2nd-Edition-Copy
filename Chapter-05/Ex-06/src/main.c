/*-
 *	Exercise 5-6. Rewrite appropriate programs from earlier chapters and exercises
 *	with pointers instead of array indexing. Good possibilities include getline
 *	(Chapters 1 and 4), atoi, itoa, and their variants (Chapters 2, 3, and 4),
 *	reverse (Chapter 3), and strindex and getop (Chapter 4).
 *
 *	By jr.chavez07
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stddef.h>

#define	MAXOP	100	/* max size of operand or operator */
#define NUMBER	'0'	/* signal that a number was found */
#define BUFSIZE	100

char buf[BUFSIZE];	/* buffer for ungetch */
int bufp = 0;		/* next free position in buf */

ssize_t jr_getline(char *lineptr, size_t n);
int jr_atoi(const char *nptr);
char *jr_itoa(int n, char *nptr);
char *jr_strrev(char *s);
int strindex(char *s, char *t);
int getop(char *s);
int getch(void);
void ungetch(int);

int
main(void)
{
	int num;
	int type;
	char buf[BUFSIZ];
	char itoa_buf[BUFSIZ];
	char s[MAXOP];

	printf(">>> please enter a number: ");
	jr_getline(buf, BUFSIZ);
	num = jr_atoi(buf);
	
	printf("\n[ str: ] = %s[ int: ] = %d\n", buf, num);
	printf("[ int: %d ], [ str: %s ]\n", INT_MIN, jr_itoa(INT_MIN, itoa_buf));

	char str[BUFSIZ] = "abcdeDFabcde";
	int ret = strindex(str, "abc");
	if (ret == -1) {
		printf( "The substring (string 2) was not found in the "
			"base string (string 1).\n");
	} else {
		printf( "The substring was found in the base string, "
			"starting at position %d.\n", ret);
	}

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			printf("found a number: %s\n", s);
			break;
		case '+':
			printf("found \'+\'");
			break;
		case '\n':
			printf("found line break.\n");
			break;
		default:
			printf("found something else: %s\n", s);
			break;
		}
	}
	return 0;
}


/* getline: get line into s, return length */
ssize_t
jr_getline(char *lineptr, size_t n)
{
	int c;
	char *p = NULL;

	p = lineptr;
	while (--n > 0 && (c = getchar()) != EOF && c != '\n')
		*p++ = c;
	if (c == '\n')
		*p++ = c;
	*p = '\0';
	return (ssize_t)(p - lineptr);
}


/* atoi: convert s to integer */
int
jr_atoi(const char *nptr)
{
	int n, sign;
	const char *pn = NULL;

	pn = nptr;
	for ( ; isspace(*pn); pn++)	/* skip white space */
		;
	sign = (*pn == '-') ? -1 : 1;
	if (*pn == '+' || *pn == '-')	/* skip sign */
		pn++;
	for (n = 0; isdigit(*pn); pn++)
		n = 10 * n + (*pn - '0');
	return sign * n;
}


/* itoa: convert n to characters in s */
char *
jr_itoa(int n, char *nptr)
{
	int sign;
	char *pn = NULL;

	if ((sign = n) < 0)	/* record sign */
		n = -n;		/* make it positive */
	pn = nptr;
	do {	/* generate digits in reverse order */
		*pn++ = (n % 10) + '0';	/* get next digit */
	} while ((n /= 10) != 0);	/* delete it */
	if (sign < 0)
		*pn++ = '-';
	*pn = '\0';
	jr_strrev(nptr);
	return nptr;
}


/* reverse: reverse string s in place */
char *
jr_strrev(char *s)
{
	int temp;
	char *p = NULL;

	p = s;
	while (*p)
		p++;
	p--;
	while (s <= p) {
		temp = *s;
		*s = *p;
		*p = temp;

		s++;
		p--;
	}
	return s;
}


/* strindex: return index of t in s, -1 if none */
int
strindex(char *s, char *t)
{
	int i, j;
	char *s1 = s;
	char *s2 = s;
	char *t1 = t;

	i = j = 0;
	while (*s1) {
		t1 = t;
		s2 = s1;
		for (j = 0; *t1 != '\0' && *s2 == *t1; s2++, t1++, j++) {
			if (j > 0 && *(t1 + 1) == '\0') {
				return i;
			}
		}
		i++;
		s1++;
	}
	return -1;
}


/* getop: get next operator or numeric operand */
int
getop(char *s)
{
	int c;

	while ((*s++ = c = getch()) == ' ' || c == '\t')
		;
	*s = '\0';
	if (!isdigit(c) && c != '.')
		return c;	/* not a number */
	if (isdigit(c))	/* collect integer part */
		while (isdigit(*s++ = c = getch()))
			;
	if (c == '.')	/* collect fraction part */
		while (isdigit(*s++ = c = getch()))
			;
	*--s = '\0';
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
