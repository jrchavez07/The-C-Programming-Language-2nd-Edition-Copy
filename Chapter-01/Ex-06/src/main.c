/*-
 *	Exercise 1-6. Verify that the expression getchar() != EOF is 0 or 1.
 *
 *	Jose Chavez
 */
#include <stdio.h>

int
main(void)
{
	printf("The expression getchar() != EOF is: %d\n", getchar() != EOF);
	return 0;
}
