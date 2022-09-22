/*-
 *	Exercise 2-1. Write a program to determine the ranges of char, short, int,
 *	and long variables, both signed and unsigned, by printing appropriate
 *	values from standard headers and by direct computation. Harder if you com-
 *	pute them: determine the ranges of the various floating-point types.
 *
 *	Jose Chavez
 */
#include <stdio.h>
#include <limits.h>

int
main(void)
{
	printf("char max:\t\t%d\n", CHAR_MAX); 
	printf("char min:\t\t%d\n", CHAR_MIN); 
	
	printf("short char max:\t\t%d\n", SCHAR_MAX);
	printf("short char min:\t\t%d\n", SCHAR_MIN);

	printf("unsigned char max:\t%d\n", (unsigned)UCHAR_MAX);

	printf("short max:\t\t%d\n", SHRT_MAX);
	printf("short min:\t\t%d\n", SHRT_MIN);

	printf("unsigned short max:\t%d\n", (unsigned)USHRT_MAX);

	printf("int max:\t\t%d\n", INT_MAX);
	printf("int min:\t\t%d\n", INT_MIN);

	printf("unsigned int max:\t%d\n", (unsigned)UINT_MAX);
	
	printf("long max:\t\t%ld\n", LONG_MAX);
	printf("lon min:\t\t%ld\n", LONG_MIN);
	
	printf("unsigned long max:\t%lu\n", ULONG_MAX);

	return (0);
}

