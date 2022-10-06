/*-
 *	Exercise 5-5. Write the function strend(s, t), which returns 1 if the string
 *	t occurs at the end of the string s, and zero otherwise.
 *
 *	By jr.chavez07
 */
#include <stdio.h>

void test(void);

static int strend(char *s, char *t);

int
main(void)
{
	test();
	return 0;
}


void
test(void)
{
	printf("> %d\n", strend("a", ""));
	printf("> %d\n", strend("duck", "duck"));
	printf("> %d\n", strend("Unsubtle", "subtle"));
	printf("> %d\n", strend("frankly", "frank"));
	printf("> %d\n", strend("aaaaaX", "aaaaX"));
	return;
}


static int
strend(char *s, char *t)
{
	char *_s, *_t;

	do {
		for (_s = s, _t = t; *_s == *_t; _s++, _t++)
			if (*_s == '\0')
				return 1;
	} while (*s++);
	return 0;
}

