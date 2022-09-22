/*-
 *	Exercise 2-7. Write a function invert(x, p, n) that returns x with the n bits
 *	that begin at position p inverted (ie., 1 changed into 0 and vice versa), leaving
 *	the others unchanged.
 *
 *	Jose Chavez
 */
#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y);
unsigned invert(unsigned x, unsigned p, unsigned n);

int
main(void)
{
	unsigned x = 7;

	printf("getbits: %u\n", getbits(x, 4, 3));
	printf("setbits: %u\n", setbits(12, 3, 2, 57));
	printf("invert: %u\n", invert(7, 4, 3));
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


unsigned
invert(unsigned x, unsigned p, unsigned n)
{
	return setbits(x, p, n, ~x);
}
