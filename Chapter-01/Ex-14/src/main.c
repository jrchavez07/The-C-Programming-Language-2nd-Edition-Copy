/*-
 *	Exercise 1-14. Write a program to print a histogram of the frequencies of dif-
 *	ferent characters in its input.
 *
 *	Jose Chavez
 */
#include <stdio.h>

#define CHR_MAX		127

int
main(void)
{
	int c;
	long arr[CHR_MAX +  1];

	long this_val = 0;
	long this_max = 0;
	int this_idx = 0;

	for (this_idx = 0; this_idx <= 93; this_idx++) {
		arr[this_idx] = 0;
	}

	while ((c = getchar()) != EOF) {
		if (33 <= c && c <= CHR_MAX) {
			this_val = ++arr[c - 33];
			if (this_val >= this_max) {
				this_max = this_val;
			}
		}
	}

	for (this_val = this_max; this_val > 0; this_val--) {
		printf("%4ld|", this_val);
		for (this_idx = 0; this_idx <= 93; this_idx++) {
			if (arr[this_idx] >= this_val) {
				printf("\u25A0");
			} else {
				putchar(' ');
			}
		}
		putchar('\n');
	}
	printf("    +");
	for (this_idx = 0; this_idx <= 93; this_idx++) {
		putchar('-');
	}
	printf("\n     ");
	for (this_idx = 0; this_idx <= 93; this_idx++) {
		putchar(this_idx + 33);
	}
	putchar('\n');
	return 0;
}
