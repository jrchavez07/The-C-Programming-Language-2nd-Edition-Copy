#include <ctype.h>

#include "calc.h"

#define MAXVAR	26

int variables[MAXVAR] = { 0.0 };


/* handling_vars: function to handle variables */
_Bool
handling_vars(int var)
{
	return ((islower(var) && isupper(var)) || var == '=') ? TRUE : FALSE;
}
