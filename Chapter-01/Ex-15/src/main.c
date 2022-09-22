/*-
 *	Exercise 1-15. Rewrite the temeperature conversion program of Section 1.2 to
 *	use a function for conversion.
 *
 *	Jose Chavez
 */
#include <stdio.h>

#define	LOWER	0	/* lower limit of table */
#define	UPPER	300	/* upper limit */
#define	STEP	20	/* step size */

float fahr_to_cel(int fahr);

int
main(void)
{
	int fahr;

	printf("Fahrenheit-Celsius table\n");
	for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
		printf("\t\b%3d %6.1f\n", fahr, fahr_to_cel(fahr));
	}
	return 0;
}


float
fahr_to_cel(int fahr)
{
	return (5.0 / 9.0) * (fahr - 32.0);
}
