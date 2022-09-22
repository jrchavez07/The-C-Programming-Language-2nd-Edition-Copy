/*-
 *	Exercise 1-17. Write a program to print all input lines that are longer than 80
 *	characters.
 *
 *	Jose Chavez
 */
#include <stdio.h>

#define MAXLINE	1000	/* maximun input line size */
#define DEF_LEN	80

int get_line(char line[], int maxline);

/* print longest input line */
int
main(void)
{
	int len;	/* current line length */
	char line[MAXLINE];	/* current input line */

	while ((len = get_line(line, MAXLINE)) > 0)
		if (len >= DEF_LEN) {
			printf("%d: %s", len, line);
		} else {
			printf("line < 80\n");
		}
	return 0;
}


/* get_line: read a line into s, return length */
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

