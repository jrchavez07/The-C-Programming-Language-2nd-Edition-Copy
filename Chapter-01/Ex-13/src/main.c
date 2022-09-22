/*-
 *	Exercise 1-13. Write a program to print a histogram of the lengths of words in
 *	its input. It is easy to draw the histogram with the bars horizontal; a vertical
 *	orientation is more challenging.
 *
 *	Jose Chavez
 */
#include <stdio.h>

#define MAXWLEN		10	/* MAX WORD LENGTH */

int
main(void)
{
	int c;
	long wlen_arr[MAXWLEN + 1];
	int wlen = 0;

	long this_val = 0;
	long max_val = 0;
	int this_idx = 0;
	
	for (this_idx = 0; this_idx <= MAXWLEN; this_idx++) {
		wlen_arr[this_idx] = 0;
	}

	while ((c = getchar()) != EOF) {
		/*
		 *	We haven't met string.h - isspace.
		 */
		if (c != ' ' && c != '\n' && c != '\t' &&
				c != '\v' && c != '\f' && c != '\r') {
			++wlen;	
		}
		else if (wlen != 0) {
			if (wlen <= MAXWLEN) {
				this_val = ++wlen_arr[wlen - 1];
				if (this_val > max_val) {
					max_val = this_val;
				}
			} else {
				this_val = ++wlen_arr[MAXWLEN];
				if (this_val > max_val) {
					max_val = this_val;
				}
			}
			wlen = 0;
		}

	}

	for (this_val = max_val; this_val > 0; this_val--) {
		printf("%4ld  | ", this_val);

		for (this_idx = 0; this_idx <= MAXWLEN; this_idx++) {
			if (wlen_arr[this_idx] >= this_val) {
				printf("\u25A0%2c", ' ');
			} else {
				printf("%3c", ' ');
			}
		}
		putchar('\n');
	}

	printf("      +");
	for (this_idx = 0; this_idx <= MAXWLEN; this_idx++)
		printf("---");

	printf("\n       ");
	for (this_idx = 0; this_idx < MAXWLEN; this_idx++)
		printf("%2d ", this_idx + 1);
	printf(">%d\n", MAXWLEN);
	return 0;
}

