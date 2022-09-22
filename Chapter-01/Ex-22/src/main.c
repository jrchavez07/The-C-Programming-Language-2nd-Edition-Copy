/*-
 *	Exercise 1-22. Write a program to "fold" long input lines into two or more
 *	shorter lines after the last non-blank character that occurs before the n-th
 *	column of input. Make sure your program does something intelligent with very
 *	long lines, and if there are no blanks or tabs before the specified column.
 *
 *	Jose Chavez
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	DEFLINEWIDTH	80
#define BUFSIZE		1024

void fold(int width);
int is_blank(int c);

int
main(void)
{
	fold(DEFLINEWIDTH);

	return 0;
}


/* fold: fold long input lines */
void
fold(int width)
{
	char buf[BUFSIZE];
	int i, indx;
	int space;
	int ch;

	indx = 0;
	while ((ch = getchar()) != EOF) {
		if (ch == '\n') {
			if (printf("%.*s\n", indx, buf) < 0) {
				perror("output");
				exit(EXIT_FAILURE);
			}
			indx = 0;
		}
		if (indx >= width) {
			{
				for (i = indx; i >= 0 && !is_blank(buf[i]); i--)
					;
				space = i;
			}

			if (space >= width && space != -1) {
				if (printf("%.*s\n", space++, buf) < 0) {
					perror("output");
					exit(EXIT_FAILURE);
				}
				memmove(buf, buf + space, indx - space);

				indx -= space;	
			} else {	
				if (printf("%.*s\n", indx, buf) < 0) {
					perror("output");
					exit(EXIT_FAILURE);
				}

				indx = 0;
			}
		}
		buf[indx++] = (char)ch;
	}

	if (indx != 0) {
		if (printf("%.*s", indx-1, buf) < 0) {
			perror("output");
			exit(EXIT_FAILURE);
		}
	}

	if (ferror(stdin)) {
		perror("input");
		exit(EXIT_FAILURE);
	}
}


int
is_blank(int c)
{
	return (c == ' ' || c == '\t');
}
