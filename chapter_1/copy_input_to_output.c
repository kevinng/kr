#include <stdio.h>

/* copy input to output; 1st version. */
int main(int argc, char const *argv[])
{
	int c; /* we can't use char because the datatype needs to be big enough to hold any char value PLUS EOF. */

	while ((c = getchar()) != EOF) {
		putchar(c);
	}
	
	return 0;
}