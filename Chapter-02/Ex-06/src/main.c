/*-
 *	Exercise 2-6. Write a function setbits(x, p, n, y) that returns x with the n
 *	bits that begin at position p set to the rightmost n bits of y, leaving the other
 *	bits unchanged.
 *
 *	Jose Chavez
 */
#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y);

int
main(void)
{
	unsigned x = 7;

	printf("%u\n", getbits(x, 4, 3));
	printf("%u\n", setbits(12, 3, 2, 57));
	return 0;
}


/* getbits: get n bits from position p */
unsigned
getbits(unsigned x, int p, int n)
{
	return (x >> (p + 1 - n)) & ~(~0 << n);
}


unsigned
setbits(unsigned x, unsigned p, unsigned n, unsigned y)
{
	unsigned mask;
	
	if (n == 0) {
		mask = 0;
	} else {
		mask = ~(~0 << (n - 1) << 1) << (p + 1 - n);
	}
	return (x & ~mask) | (y & mask);
}

