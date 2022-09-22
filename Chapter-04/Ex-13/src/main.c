/*-
 *	Exercise 4-13. Write a recursive version of the function reverse(s), which
 *	reverses the string s in place.
 *
 *	By Jose Chavez
 */
#include <stdio.h>
#include <string.h>

void reverse(char [], int, int);
void swap(char [], int, int);

int
main(void)
{
	char s[] = "Taurus Silver";

	reverse(s, 0, strlen(s) - 1);
	printf("%s\n", s);
	return 0;
}


/* reverse: reverse string s in place */
void
reverse(char s[], int i, int j)
{
	if (i < j) {
		swap(s, i++, j--);
		reverse(s, i, j);
	}
}


/* swap: interchange s[i] and s[j] */
void
swap(char s[], int i, int j)
{
	int temp;

	temp = s[i];
	s[i] = s[j];
	s[j] = temp;
}
