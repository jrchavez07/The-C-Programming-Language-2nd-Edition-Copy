/*-
 *	Exercise 1-19. Write a function reverse(s) that reverses the character
 *	string s. Use it to write a program that reverses its input a line at a time.
 *
 *	Jose Chavez
 */
#include <stdio.h>

#define MAXLINE	1000

int get_line(char line[], int maxline);
void reverse(char line[]);
int len(char line[]);

int
main(void)
{
	char line[MAXLINE];
	
	while (get_line(line, MAXLINE) > 0) {
		reverse(line);
		printf("%s\n", line);
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


void
reverse(char s[])
{
	int i, j = len(s);

	for (i = 0, j = len(s) - 1; i < j; ++i, --j) {
		int temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}


int
len(char s[])
{
	int i;

	for (i = 0; s[i] != '\0'; ++i)
		;
	return (i);
}
