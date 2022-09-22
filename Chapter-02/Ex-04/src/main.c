/*-
 *	Exercise 2-4. Write an alternate version of squeeze(s1, s2) that deletes
 *	each character in s1 that matches any character in the string s2.
 *
 *	Jose Chavez
 */
#include <stdio.h>

enum found_t { NO, YES };

void squeeze(char s1[], char s2[]);

int
main(void)
{
	char s1[] = "Write an alternate version of squeeze(s1, s2)"
		    "that deletes each character in s1 that matches"
		    "any character in the string s2.";
	char s2[] = "aeiouAEIOU";

	printf("%s\n", s1);
	squeeze(s1, s2);
	printf("%s\n", s1);
	return 0;
}


void
squeeze(char s1[], char s2[])
{
	int i, j, k;
	enum found_t found;

	k = 0;
	for (i = 0; s1[i] != '\0'; i++) {
		found = NO;
		for (j = 0; s2[j] != '\0' && !found; j++) {
			if (s1[i] == s2[j]) {
				found = YES;
			}
		}

		if (!found) {
			if (s2[j] == '\0') {
				s1[k++] = s1[i];
			}
		}
	}
	s1[k] = '\0';
}

