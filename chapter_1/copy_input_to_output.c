#include <stdio.h>

/* copy input to output; 1st version. */
int main(int argc, char const *argv[])
{
	int c; /* we can't use char because the datatype needs to be big enough to hold any char value PLUS EOF. */

	int last_c = 'a'; /* start with any non-blank character. */
	while ((c = getchar()) != EOF) {
		if (c == ' ' && last_c == ' ')
		{
			/* do nothing. */
		}
		else
		{
			putchar(c);
		}
		last_c = c;
	}
	
	return 0;
}