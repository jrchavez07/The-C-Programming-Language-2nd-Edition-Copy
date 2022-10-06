/*-
 *	Exercise 5-5. Write the function strend(s, t), which returns 1 if the string
 *	t occurs at the end of the string s, and zero otherwise.
 *
 *	By jr.chavez07
 */
#include <stdio.h>

#include <criterion/criterion.h>

static int strend(char *s, char *t);

/*-
 *	[	Possible Test Cases	]
 *
 *	strend("a", "");
 *	strend("duck", "duck");
 *	strend("Unsubtle", "subtle");
 *	strend("frankly", "frank");
 *	strend("aaaaaX", "aaaaX");
 */

Test(strend, test_cases, .description = "test cases")
{
	int rval = strend("aaaaaX", "aaaaX");
	const int expected = 1;
	cr_expect(rval == expected);
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

