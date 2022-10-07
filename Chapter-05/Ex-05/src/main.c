/*-
 *	Exercise 5-5. Write version of the library functions strncpy, strncat, and
 *	strncmp, which operate on at most the first n characters of their argument
 *	strings. For example, strncpy(s, t, n) copies at most n characters of t to s.
 *	Full description are in Appendix B.
 *
 *	By jr.chavez07
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <stddef.h>

char *tr_strncpy(char *dest, const char *src, size_t n);
char *tr_strncat(char *dest, const char *src, size_t n);
int tr_strncmp(const char *s1, const char *s2, size_t n);

int
main(void)
{
	char buf[BUFSIZ];

	tr_strncpy(buf, "Hello,", 5);
	printf(">= strncpy: %s\n", buf);
	tr_strncat(buf, " World!\n", 7);
	printf(">= strncat: %s\n", buf);

	_Bool ret = tr_strncmp(buf, "HelLo", 4);
	printf(">= strncmp: %d\n", ret);
	return 0;
}


char *
tr_strncpy(char *dest, const char *src, size_t n)
{
	if ((int)n < 0) {
		(void) fprintf(stderr, "error: <%ld> is negative\n", n);
		exit(EXIT_FAILURE);
	}

	char *d = dest;
	const char *s = src;
	do {
		if ((*d++ = *s++) == '\0') {
			for ( ; n != 0; --n)
				*d++ = '\0';
		}
	} while (--n != 0);
	return dest;
}


char *
tr_strncat(char *dest, const char *src, size_t n)
{
	if ((int)n < 0) {
		(void) fprintf(stderr, "error: <%ld> is negative\n", n);
		exit(EXIT_FAILURE);
	}

	char *d = dest;
	const char *s = src;
	while (*d)
		++d;
	while (--n != 0 && *src != '\0')
		*d++ = *s++;
	*d = '\0';
	return dest;
}


int
tr_strncmp(const char *s1, const char *s2, size_t n)
{
	/* returns 0, if s1 and s2 are equal */
	if (n == 0)
		return 0;
	do {
		if ((*s1 != *s2++))
			return *(unsigned char *)s1 - *(unsigned char *)s2 - 1;
		if (*s1++ == '\0')
			break;;
	} while (--n != 0);
	return 0;
}
