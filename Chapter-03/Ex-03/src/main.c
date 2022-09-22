/*-
 *	Exercise 3-3. Write a function expand(s1, s2) that expands shorthand nota-
 *	tions like a-z in the string s1 into the equivalent complete list abc...xyz in
 *	s2. Allow for letters of either case and digits and be prepared to handle cases
 *	like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is
 *	taken literally.
 *
 *	Jose Chavez
 */
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAXLINE		1024

_Bool match(int start, int end);
void expand(char s1[], char s2[]);
ssize_t get_line(char line[], size_t maxline);

int
main(void)
{
	char s1[MAXLINE];
	char s2[MAXLINE];

	while (get_line(s1, MAXLINE) > 0) {
		expand(s1, s2);
		printf("%s", s2);
	}
	return 0;
}


void
expand(char s1[], char s2[])
{
	int i, j, ch;

	for (i = j = 0; (ch = s1[i++]) != '\0'; ) {
		if (s1[i] == '-' && match(s1[i - 1], s1[i + 1])) {
			for (i++; ch < s1[i]; ) {
				s2[j++] = ch++;
			}
		} else {
			s2[j++] = ch;
		}
	}
	s2[j] = '\0';
}


_Bool
match(int start, int end)
{
	return ((isdigit(start) && isdigit(end)) && (end >= start)) ||
	       ((islower(start) && islower(end)) && (end >= start)) ||
	       ((isupper(start) && isupper(end)) && (end >= start));
}


ssize_t
get_line(char buf[], size_t bufsiz)
{
	int indx;

	indx = 0;
	while (--bufsiz > 0) {
		int ch = getchar();
		if (ch == EOF)
			break;
		buf[indx++] = ch;
		if (ch == '\n')
			break;
	}
	buf[indx] = '\0';
	return indx;
}
