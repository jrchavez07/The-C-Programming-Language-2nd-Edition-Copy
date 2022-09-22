/*-
 *	Exercise 1-8. Write a program to count blanks, tabs, and newlines.
 *
 *	Jose Chavez
 */
#include <stdio.h>

int
main(void)
{
	int c, blanks, tabs, newlines;

	blanks = 0;
	tabs = 0;
	newlines = 0;
	while ((c = getchar()) != EOF) {

		if (feof(stdin))
			return 0;
		if (c == ' ')
			++blanks;
		if (c == '\t')
			++tabs;
		if (c == '\n')
			++newlines;
	}
	printf("Blanks: %d\nTabs: %d\nLines: %d\n", blanks, tabs, newlines);
	return 0;
}
