#include <stdio.h>
#include <string.h>
#include <math.h>

#include "calc.h"

#define DEFLEN	4
#define DEFLEN_UNS_LIBS	18	/* default length of unsupported libraries */

static const char *math_libs[] = {
				"sin",
				"cos",
				"exp",
				"pow",
			};

static const char *uns_libs[] = {			/* unsupported library functions */
				"tan", "asin",
				"acos", "atan",
				"atan2", "sinh",
				"cosh", "tanh",
				"log", "log10",
				"sqrt", "ceil",
				"floor", "fabs",
				"ldexp", "frexp",
				"frexp", "modf"
			};


/* access_to_math_libsf: access to library functions (sin, cos, exp, and pow.)*/
void
access_to_math_libf(const char s[])
{
	int n = match_libf(s);

	switch (n) {
	case 1:
		push(sin(pop()));
		break;
	case 2:
		push(cos(pop()));
		break;
	case 3:
		push(exp(pop()));
		break;
	case 4:
		{
			double op2 = pop();
			push(pow(pop(), op2));
			break;
		}
	case -1:
		printf("%s is not a supported function.\n", s);
		break;
	default:
		break;
	}
}


/* match_libf: check if the library is found or not. returns -1
 * if it is an unsupported function library. */
int
match_libf(const char s[])
{
	int loc, loc2, found;

	found = 0;
	for (loc = 0; loc < DEFLEN; loc++)
		if (strcmp(s, math_libs[loc]) == 0) {
			found = loc + 1;
			return found;
		} else {
			for (loc2 = 0; loc2 < DEFLEN_UNS_LIBS; loc2++) {
				if (strcmp(s, uns_libs[loc2]) == 0) {
					found = -1;
					return found;
				}
			}
		}

	return 0;
}

