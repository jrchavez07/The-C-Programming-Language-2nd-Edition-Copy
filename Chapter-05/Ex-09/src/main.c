/*-
 *	Exercise 5-9. Rewrite the routines day_of_year and month_day with
 *	pointers instead of indexing.
 *
 *	By jr.chavez_07
 */
#include <stdio.h>

static char daytab[2][13] = {
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);
char *month_name(int n);

int
main(void)
{
	int m = 2;
	int d = 7;

	printf("%d\n", day_of_year(2000, m, d)); 
	month_day(2000, 38, &m, &d);
	printf("%s %d\n", month_name(m), d); 

	return 0;
}

/* day_of_year: set day of year from month & day */
int
day_of_year(int year, int month, int day)
{
	int i, leap;

	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	if ((year < 1) || (month < 1 || month > 12)
		       || (day < 1 || day > daytab[leap][month]))
		return -1;

	for (i = 1; i < month; i++)
		day += *(daytab[leap] + i);
	return day;
}


/* month_day: set month, day from day of year */
void
month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
 
	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	if ((year < 1 || yearday < 1) || (yearday > (leap ? 366 : 365))) {
		*pmonth = *pday = -1;
		return;
	}
	for (i = 1; yearday > *(*(daytab + leap) + i); i++)
		yearday -= *(*(daytab + leap) + i);
	*pmonth = i;
	*pday = yearday;
}


/* month_name: return name of n-th month */
char *
month_name(int n)
{
	static char *name[] = {
		"Illegal month",
		"January", "February", "March",
		"April", "May", "June",
		"July", "August", "September",
		"October", "November", "December"
	};
	return (n < 1 || n > 12) ? name[0] : name[n];
}
