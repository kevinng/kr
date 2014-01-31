#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(int argc, char const *argv[])
{
	int needle = 3;
	int haystack[] = {2, 4, 5, 1, 6, 7, 3, 2, 5, 1, 7, 8, 9};

	int i;
	for (i = 0; i < 13; ++i)
		printf("%d ", i);
	putchar('\n');

	for (i = 0; i < 13; ++i)
		printf("%d ", haystack[i]);
	putchar('\n');

	int nee_pos = binsearch(needle, haystack, 13);
	printf("pos: %d\n", nee_pos);
	
	return 0;
}


int binsearch(int x, int v[], int n)
{
	int low, mid, high;

	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low+high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else /* found match */
			return mid;
	}
	return -1; /* no match */
}










