/*-
 *	Exercise 3-1. Our binary search makes two tests inside the loop, when one
 *	would suffice (at the price of more tests outside). Write a version with only one
 *	test inside the loop and measure the difference in run-time.
 *
 *	Jose Chavez
 */
#include <stdio.h>

int binarysearch(int x, int v[], int n);

int
main(void)
{
	int arr[] = { 1, 5, 10, 11, 20 };
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("%d\n", binarysearch(11, arr, n));
	return 0;
}


/* binarysearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int
binarysearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low < high) {
		mid = (low + high) / 2;
		if (x > v[mid])
			low = mid + 1;
		else
			high = mid;
	}
	return (x == v[low]) ? low : -1;
}
