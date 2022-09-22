/*-
 *	Exercise 2-2. Write a loop equivalent to the for loop above without using &&
 *	or ||.
 *
 *	Jose Chavez
 */
#include <stdio.h>

#define	MAXLINE		1024

char line[MAXLINE];

size_t get_line(void);

int
main(void)
{
	extern char line[];

	while (get_line() > 0)
		printf("%s", line);
	return 0;
}


size_t
get_line(void)
{
	unsigned int i;
	unsigned int lim = MAXLINE;
	extern char line[];

	i = 0;
	while (--lim > 0) {
		int c = getchar();
		if (c == EOF)
			break;
		line[i++] = c;
		if (c == '\n')
			break;
	}
	line[i] = '\0';
	return i;
}
