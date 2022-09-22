/*-
 *	Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa;
 *	that is, convert an integer into a string by calling a recursive routine.
 *
 *	By Jose Chavez 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/* printd: print n in decimal */
void
printd(int n)
{
	if (n < 0) {
		putchar('-');
		n = -n;
	}
	if (n / 10)
		printd(n / 10);
	putchar(n % 10 +  '0');
}


/* qsort: sort v[left]...v[right] into increasing order */
void
q_sort(int v[], int left, int right)
{
	int i, last;
	void swap(int v[], int i, int j);

	if (left >= right)	/* do nothing if array contains */
		return;		/* fewer than two elements */
	swap(v, left, (left + right) / 2);	/* move partition elem */
	last = left;				/* to v[0] */
	for (i = left + 1; i <= right; i++)	/* partition */
		if (v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last);			/* restore partition elem */
	q_sort(v, left, last - 1);
	q_sort(v, left+1, right);
}


/* swap: interchange v[i] and v[j] */
void
swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}


/* itoa: convert n to characters in s; recursive version */
int
itoa(int n, char s[], int i)
{
	if (n < 0) {
		s[i++] = '-';
		n = -n;
	}
	if (n / 10)
		i = itoa(n / 10, s, i++); 
	s[i++] = n % 10 + '0';
	s[i] = '\0';
	return i;
}


/* main function */
int
main(void)
{
	int v[] =  { 8, 1, 4, 3, 2, 7, 5, 6 };
	size_t size = sizeof(v) / sizeof(v[0]);

	printd(123);
	putchar('\n');

	q_sort(v, 1, 8);
	for (int indx = 0; indx < (int)size; indx++)
		printf("%d ", v[indx]);
	putchar('\n');

	char s[BUFSIZ];

	itoa(INT_MIN, s, 0);
	printf("%s\n", s);
	return 0;
}
