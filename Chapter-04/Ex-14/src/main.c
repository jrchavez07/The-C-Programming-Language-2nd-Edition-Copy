/*-
 *
 */
#include <stdio.h>

#define dprint(expr) printf(#expr " = %g\n", expr)
/* #define paste(front, back)	front ## back */

#define swap(t, x, y)		\
	do {			\
		t temp = x;	\
		x = y;		\
		y = temp;	\
	} while (0)

/* #define _swap(t, x, y)	do { t safe ## x ## y;	safe ## x ## y = x;	x = y;	y = safe ## x ## y; } while (0) */
/* #define swap(x, y)	do { _swap(int, x, y); } while (0) */	
/* #define swap(x, y)	_swap(int, x, y); */

int
main(void)
{
	int x = 4;
	int y = 3;

	swap(int, x, y);
	printf("%d %d\n", x, y);
	return 0;
}
