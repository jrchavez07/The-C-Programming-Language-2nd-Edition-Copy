/*-
 *	Exercise 2-10. Rewrite the function lower, which converts upper case letters
 *	to lower case, with a conditional expression instead of if-else.
 *
 *	Jose Chavez
 */
#include <stdio.h>
#include <ctype.h>

int lower(int c);

int
main(void)
{
	int ch;

	while ((ch = getchar()) != EOF)
		if (putchar(lower(ch)) < 0) {
			perror("output");
			return 1;
		}

	if (ferror(stdin)) {
		perror("input");
		return 1;
	}
	return 0;
}

int
lower(int c)
{
	return (isupper(c)) ? c + 'a' - 'A': c;
}
