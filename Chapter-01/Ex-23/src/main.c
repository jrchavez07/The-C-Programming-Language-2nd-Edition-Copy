/*-
 *	Exercise 1-23. Write a program to remove all comments from a C program.
 *	Don't forget to handle quoted strings and character constants properly. C com-
 *	ents do not nest.
 *
 *	Jose Chavez
 */
#include <stdio.h>

int
main(void)
{
	int in_comm, in_quote;
	int ch, prev_ch;

	in_comm = in_quote = 0;
	prev_ch = 0;
	while ((ch = getchar()) != EOF) {
		if (ch == '\"')
			in_quote = 1;

		if (!in_quote) {
			if (ch == '*' && prev_ch == '/')
				in_comm = 1;

			if (ch == '/' && prev_ch == '*')
				in_comm = 0;

			if (in_comm == 1) {
				/* IGNORE THIS LINE */
			} else {
				putchar(ch);
			}
		} else {
			putchar(ch);
		}
		prev_ch = ch;
	}
	if (feof(stdin)) {
		perror("input");
		return 1;
	}
	return 0;
}

