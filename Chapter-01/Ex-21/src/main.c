/*-
 *	Exercise 1-21. Write a program entab that replaces strings of blanks by the
 *	minimun number of tabs and blanks to achieve the same spacing. Use the
 *	same tab stops as for detab. When either a tab or a single blank would suffice
 *	to reach a tab stop, which should be given preference?
 *
 *	Jose Chavez
 */
#include <stdio.h>

#define SPACE		' '
#define TAB		'\t'
#define TAB_STOP	8

int
main(void)
{
	int spaces = 0;

	while (1) {
		int c = getchar();

		switch (c) {
		case EOF:
			return feof(stdin);
		case SPACE:
			++spaces;
			if (spaces == TAB_STOP) {
				spaces = 0;
				putchar('#');
			}
			break;
		default:
			for (int i = 0; i < spaces; i++)
				putchar(' ');
			spaces = 0;

			if (putchar(c) == EOF)
				return 1;
			break;
		}
	}
	return 0;
}

