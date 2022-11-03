/*-
 *	Exercise 5-11. Modify the programs entab and detab (written as exercises in
 *	Chapter 1) to accept a list of tab stops as arguments. Use the default tab set-
 *	ings if there are no arguments.
 *
 *	By jr.chavez__07
 */
#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>

#define DTAB_STOP       8       /* DEFAULT TAB STOP */
#define MAX_TAB_STOP    100

enum escapes { BACKSPACE = '\b', TAB = '\t', NEWLINE = '\n', RETURN = '\r' };

int nstops;
int tabstops[MAX_TAB_STOP];

static void parse_args(int argc, char *argv[]);
static int getstops(const char *cp);

int
main(int argc, char *argv[])
{
	wint_t wch;
	int n;
	int width, column;


	setlocale(LC_CTYPE, "");
	parse_args(argc, argv);

	column = 0;
	while ((wch = getwchar()) != WEOF) {
		switch (wch) {
		case TAB:
			if (nstops == 0) {
				do {
					putwchar('-');
					column++;
				} while (column & 07);
				continue;
			}
			if (nstops == 1) {
				do {
					putwchar('-');
					column++;
				} while (((column - 1) % tabstops[0]) != (tabstops[0] - 1));
				continue;
			}
			for (n = 0; n < nstops; n++)
				if (tabstops[n] > column)
					break;
			if (n == nstops) {
				putwchar('-');
				column++;
				continue;
			}
			while (column < tabstops[n]) {
				putwchar('-');
				column++;
			}
			continue;
		case BACKSPACE:
			if (column > 0)
				column--;
                        putwchar(BACKSPACE);
			continue;
		case RETURN:
		case NEWLINE:
			putwchar(wch);
			column = 0;
			continue;
		default:
			putwchar(wch);
			if ((width = wcwidth(wch)) > 0)
				column += width;
			continue;
		}
	}
	if (ferror(stdin)) {
		perror("stdin");
                return EXIT_FAILURE;
	}
	return 0;
}


static void
parse_args(int argc, char *argv[])
{
	nstops = argc - 1;
	if (nstops > MAX_TAB_STOP) {
		fprintf(stderr, "error: more than %d args.\n", MAX_TAB_STOP + 1);
		exit(EXIT_FAILURE);
	}
	for (int indx = 1; indx < argc; indx++)
		tabstops[indx - 1] = getstops(argv[indx]);
}


static int
getstops(const char *cp)
{
	errno = 0;
	char *endptr;
	long val = strtol(cp, &endptr, 0);
	
	if (cp == endptr || *endptr) {
		fprintf(stderr, "non-numeric conversion <%s>\n", cp);
		exit(EXIT_FAILURE);
	}
	if (errno || val < 0 || val > INT_MAX) {
		fprintf(stderr, "invalid tab stop <%ld>\n", val);
		exit(EXIT_FAILURE);
	}
	return (int)val;
}
