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

ssize_t jr_getline(char *lineptr, size_t n);
int jr_atoi(const char *nptr);
char *jr_itoa(int n, char *nptr);
char *jr_strrev(char *s);
int strindex(char *s, char *t);

int
main(void)
{
	int num;
	char buf[BUFSIZ];
	char itoa_buf[BUFSIZ];

	printf(">>> please enter a number: ");
	jr_getline(buf, BUFSIZ);
	num = jr_atoi(buf);
	
	printf("\n[ str: ] = %s[ int: ] = %d\n", buf, num);
	printf("[ int: %d ], [ str: %s ]\n", INT_MIN, jr_itoa(INT_MIN, itoa_buf));

	char s[100] = "abcdeDFabcde";
	int ret = strindex(s, "abc");
	if (ret == -1) {
		printf( "The substring (string 2) was not found in the "
			"base string (string 1).\n");
	} else {
		printf( "The substring was found in the base string, "
			"starting at position %d.\n", ret);
	}
	return 0;
}


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
