/*-
 *	Exercise 2-8. Write a function rightrot(x, n) that returns the value of the
 *	integer x rotated to the right by n bit positions.
 *
 *	Jose Chavez
 */
#include <stdio.h>

#define BITS	sizeof(int) * 8

unsigned leftrot(unsigned x, unsigned n);
unsigned rightrot(unsigned x, unsigned n);

int
main(void)
{
	printf("%u\n", leftrot(-15, 2));
	printf("%u\n", rightrot(-15, 2));
	return 0;
}


unsigned
leftrot(unsigned x, unsigned n)
{
	return (x << n) | (x >> (BITS - n));
}


unsigned
rightrot(unsigned x, unsigned n)
{
	return (x >> n) | (x << (BITS - n));
}
