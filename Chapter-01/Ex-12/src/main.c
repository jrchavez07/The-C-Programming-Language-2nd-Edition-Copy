/*-
 *	Exercise 1-12. Write a program that prints its input one word per line.
 *
 *	Jose Chavez
 */
#include <stdio.h>

#define IN	1
#define OUT	0

int
main(void)
{
	int c, inspace;

	inspace = IN;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (inspace == OUT) {
				inspace = IN;
				putchar('\n');
			}
		} else {
			inspace = OUT;
			putchar(c);
		}
	}
	return 0;
}
