/*-
 *	Exercise 2-9. In a two's complement number system, x &= (x - 1) deletes the
 *	rightmost 1-bit in x. Explain why. Use this observation to write a faster ver-
 *	sion of bitcount.
 *
 *	Jose Chavez
 */
#include <stdio.h>

int bitcount(unsigned x);

int
main(void)
{
	printf("%d\n", bitcount(10));
	return 0;
}


/* bitcount: count 1 bits in x */
int
bitcount(unsigned x)
{
	int b;

	for (b = 0; x != 0; x &= (x - 1))
		b++;
	return b;
}
