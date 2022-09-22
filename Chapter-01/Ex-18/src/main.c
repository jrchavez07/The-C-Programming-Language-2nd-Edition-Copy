/*-
 *	Exercise 1-18. Write a program to remove trailing blanks and tabs from each
 *	line of input, and to delete entirely blank lines.
 *
 *	Jose Chavez
 */
#include <stdio.h>

#define MAXLINE	1000

int get_line(char line[], int maxline);
int remove_trailing_blanks(char line[], int len);

int
main(void)
{
	int len;
	char line[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0) {
		if (remove_trailing_blanks(line, len) > 0)
			printf("%s", line);
	}
	return 0;
}


int
get_line(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}


int
remove_trailing_blanks(char s[], int n)
{
	for ( ; n >= 0; --n) {
		if (s[n] != ' ' && s[n] != '\n' && s[n] != '\t')
			break;
	}
	s[n + 1] = '\0';
	return (n);
}
