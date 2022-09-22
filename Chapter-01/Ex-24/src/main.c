/*-
 *	Exercise 1-24. Write a program to check a C program for rudimentary syntax
 *	errors like unbalanced parentheses, brackets, and braces. Don't orget about
 *	quotes, both single and double, escape sequences, and comments. (This pro-
 *	gram is hard if you do it in full generality.)
 *
 *	This program does not handle single and double quotes. Doesn't handl comments
 *	either.
 *
 *	Jose Chavez
 */
#include <stdio.h>

int pflag = 0;
int bflag = 0;
int brflag = 0;

int
main(void)
{
	int ch, prev_ch;

	prev_ch = 0;
	while ((ch = getchar()) != EOF) {
		if (ch == '(')
			pflag++;
		if (prev_ch == ')')
			pflag--;

		if (ch == '[')
			bflag++;
		if (prev_ch == ']')
			bflag--;

		if (ch == '{')
			brflag++;
		if (prev_ch == '}')
			brflag--;

		prev_ch = ch;
	}
	if (pflag != 0 || bflag != 0 || brflag != 0)
		printf("syntax error.\n");
	else
		printf("syntax appears to be correct.\n");
	return 0;
}
