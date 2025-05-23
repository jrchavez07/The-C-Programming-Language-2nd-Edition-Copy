/*-
 *	Exercise 1-4. Write a program to print the corresponding Celsius to Fahrenheit
 *	table.
 *
 *	Jose Chavez
 */
#include <stdio.h>

int
main(void)
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;	/* lower limit of temperature table */
	upper = 300;	/* upper limit */
	step = 20;	/* step size */

	printf("Celsius-Fahrenheit table;\n"
		" floating-point version\n\n");
	celsius = lower;
	while (celsius <= upper) {
		fahr = (celsius * 9.0 / 5.0) + 32.0;
		printf("\t%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
	return 0;
}
