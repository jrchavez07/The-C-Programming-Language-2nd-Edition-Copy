/*-
 *	Exercise 2-3. Write the function htoi(s), which converts a string of hexa-
 *	decimal digits (including an optional 0x or 0X) into its equivalent integer value.
 *	The allowable digits are 0 through 9, a through f, and A through F.
 *
 *	Jose Chavez
 */
#include <stdio.h>
#include <ctype.h>

#define	MAXLINE		1024
#define ul		unsigned long	/* we haven't met typedef's yet */

enum found_t { NO, YES } found;

char line[MAXLINE];

ul htoi(char s[]);
size_t get_line(void);

int
main(void)
{
	extern char line[];

	while (get_line() > 0)
		printf("%ld\n", htoi(line));
	return 0;
}


/* htoi: converts HEX digits to integer values.
 *
 * The maximum HEX digit this function can handle is 
 * up to: 0xFFFFFFFFFFFFFFF (1152921504606846975)
 */
ul
htoi(char s[])
{
	ul int n;

	found = NO;
	if ((s[0] == '0' && s[1] == 'x') || s[1] == 'X')
		found = YES;
	else
		return !found;
	
	n = 0;
	for (int i = 0; s[i] != '\0' && found; i++) {
		if (s[i] >= '0' && s[i] <= '9')
			n = 10 * n + (s[i] - '0');

		if (s[i] >= 'a' && s[i] <= 'f')
			n = 16 * n + (s[i] - 'a' + 10);

		if (s[i] >= 'A' && s[i] <= 'F')
			n = 16 * n + (s[i] - 'A' + 10);
	}
	return n;
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

