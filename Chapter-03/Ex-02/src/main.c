/*-
 *	Exercise 3-2. Write a function escape(s, t) that converts characters like
 *	newline and tab into visible escape sequences like \n and \t as it copies the
 *	string t to s. Use a switch. Write a function for the other direction as well,
 *	converting escape sequences into the real characters.
 *
 *	Jose Chavez
 */
#include <stdio.h>

#define MAXLINE		1024

enum escapes { TAB = '\t', NEWLINE = '\n', BACKSLASH = '\\' };

size_t get_line(char line[], size_t maxline);
void escape(char s[], char t[]); 
void un_escape(char s[], char t[]); 

int
main(void)
{
	char s[MAXLINE];
	char t[MAXLINE];

	while (get_line(t, MAXLINE) > 0) {
		// escape(s, t);
		un_escape(s, t);
		printf("%s", s);
	}
	return 0;
}


size_t
get_line(char buf[], size_t maxline)
{
	int indx;

	indx = 0;
	while (--maxline > 0) {
		int ch = getchar();	
		if (ch == EOF)
			break;
		buf[indx++] = ch;
		if (ch == '\n')
			break;
	}
	buf[indx] = '\0';
	return indx;
}


void
escape(char s[], char t[])
{
	int i, j;
	
	for (i = j = 0; t[i] != '\0'; ++i, ++j) {
		switch (t[i]) {
		case TAB:
			s[j] = BACKSLASH;
			s[++j] = 't';
			break;
		case NEWLINE:
			s[j] = BACKSLASH;
			s[++j] = 'n';
			break;
		default:
			s[j] = t[i];
			break;
		}
	}
	s[j] = '\0';
}


void
un_escape(char s[], char t[])
{
	int i, j;

	for (i = j = 0; t[i] != '\0'; ++i, ++j) {
		switch (t[i]) {
		case BACKSLASH:
			switch (t[++i]) {
			case 't':
				s[j] = TAB;
				break;
			case 'n':
				s[j] = NEWLINE;
				break;
			default:
				s[j] = t[i];
				break;
			}
			break;
		default:
			s[j] = t[i];
			break;
		}
	}
	s[j] = '\0';
}
