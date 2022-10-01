/*-
 *	Exercise 5-3. Write a pointer version of the function strcat that we showed
 *	in Chapter 2: strcat(s, t) copies the string t to the end of s.
 *
 *	By jr.chavez07
 */
#include <stdio.h>
#include <string.h>

static char *
my_strcat(char *s, const char *append)
{
	while (*s)
		++s;
	strcpy(s, append);
	return s;
}
