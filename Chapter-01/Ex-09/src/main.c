/*-
 *	Exercise 1-9. Write a program to copy its input to its output, replacing each
 *	string of one or more blanks by a single blank.
 *
 *	Jose Chavez
 */
#include <stdio.h>

int
main(void)
{
	int c, prev_c;

	prev_c = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			if (prev_c != ' ') {
				if (putchar(c) == EOF)
					return 1;
			}
		}

		/* we haven't met else statement yet. */
		if (c != ' ') {
			if (putchar(c) == EOF)
				return 1;
		}
		prev_c = c;
	}
	return 0;
}

