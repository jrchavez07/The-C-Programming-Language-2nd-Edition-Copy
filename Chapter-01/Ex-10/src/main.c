/*-
 *	Exercise 1-10. Write a program to copy its input to its output, replacing each
 *	tab by \t, each backspace by \b, and each backslash by \\. This makes tabs
 *	and backspaces visible in an unambiguous way.
 *
 *	Jose Chavez
 */
#include <stdio.h>

#define	ON		1
#define OFF		0
#define	ESC_CHAR	'\\'

int
main(void)
{
	int c, status;

	while ((c = getchar()) != EOF) {
		status = OFF;
		if (c == '\t') {
			putchar(ESC_CHAR);
			putchar('t');
			status = ON;
		}
		if (c == '\b') {
			putchar(ESC_CHAR);
			putchar('b');
			status = ON;
		}
		if (c == '\\') {
			putchar(ESC_CHAR);
			putchar(ESC_CHAR);
			status = ON;
		}

		if (status == OFF)
			putchar(c);
	}
	return 0;
}
