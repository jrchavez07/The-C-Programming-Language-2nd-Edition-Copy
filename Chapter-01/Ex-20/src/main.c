/*-
 *	Exercise 1-20. Write a program detab that replaces tabs in the input with the
 *	proper number of blanks to space to the next tab stop. Assume a fixed set of
 *	tab stops, say every n columns. Should n be a variable or a symbolic paramet-
 *	er?
 *
 *	Jose Chavez
 */
#include <stdio.h>

#define TAB		'\t'
#define TAB_STOP	8

int detab(int col, int tab_stop);

int
main(void)
{
	int col = 0;

	while (1) {
		int c = getchar();

		switch (c) {
		case EOF:
			return feof(stdin);
		case TAB:
			{
				int spaces = detab(col, TAB_STOP - 1);
				if (printf("%.*s", spaces, "        ") != spaces) {
					return 1;

				}
				col += spaces;
				break;
			}
		case '\r':
		case '\n':
			col = -1;
		default:
			if (putchar(c) == EOF) {
				return 1;
			}
			++col;
		}
	}
	return 0;
}


int
detab(int col, int tab_stop)
{
	return tab_stop - (col % tab_stop);
}

