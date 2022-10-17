/*-
 *	Exercise 5-7. Rewrite readlines to store lines in an array supplied by main,
 *	rather than calling alloc to maintain storage. How much faster is the pro-
 *	gram?
 *
 *	By jr.chavez07
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES	5000	/* max #lines to be sorted */
#define MAXLEN		1000	/* max length of any input lines */

char *lineptr[MAXLINES];	/* pointers to text lines */

ssize_t jr_getline(char *lineptr, size_t n);
int readlines(char *lineptr[], char *buf, int nlines);
void writelines(char *lineptr[], int nlines);
void jr_qsort(char *lineptr[], int left, int right);
char *alloc(int n);
void afree(char *p);

/* sort input lines */
int
main(void)
{
	int nlines;	/* number of input lines read */
	char buf[BUFSIZ];	/* array supplied by main */

	if ((nlines = readlines(lineptr, buf, MAXLINES)) >= 0) {
		jr_qsort(lineptr, 0, nlines - 1);	
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}


/* getline: get line into s, return length */
ssize_t
jr_getline(char *lineptr, size_t n)
{
	int c;
	char *p = NULL;

	p = lineptr;
	while (--n > 0 && (c = getchar()) != EOF && c != '\n')
		*p++ = c;
	if (c == '\n')
		*p++ = c;
	*p = '\0';
	return (ssize_t)(p - lineptr);
}


/* readlines: read input lines */
int readlines(char *lineptr[], char *buf, int maxlines)
{
	int len, nlines;

	char *bufmax = buf + BUFSIZ - maxlines;
	nlines = 0;
	while ((len = jr_getline(buf, MAXLEN)) > 0)
		if (nlines >= maxlines || buf > bufmax) 
			return -1;
		else {
			lineptr[nlines++] = buf;
			buf += len;
			buf[strlen(buf) - 1] = '\0';	/* delete newline */
		}
	return nlines;
}


/*  writelines: write output lines */
void
writelines(char *lineptr[], int nlines)
{
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}


/* qsort: v[left]...v[right] into increasing order */
void
jr_qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);

	if (left >= right)	/* do nothing if array contains */
		return;		/* fewer than two elements */
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	jr_qsort(v, left, last - 1);
	jr_qsort(v, last + 1, right);
}


/* swap: interchange v[i] and v[j] */
void
swap(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}


#define ALLOCSIZE	10000	/* size of available space */

static char allocbuf[ALLOCSIZE];	/* storage for alloc */
static char *allocp = allocbuf;		/* next free position */

/* alloc: return pointer to n characters */
char *
alloc(int n)
{
	if (allocbuf + ALLOCSIZE - allocp >= n) {	/* it fits */
		allocp += n;
		return allocp - n;	/* old p */
	} else	/* not enough room */
		return 0;
}


/* afree: free storage pointed to by p */
void
afree(char *p)
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}
