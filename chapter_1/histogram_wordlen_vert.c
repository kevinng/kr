#include <stdio.h>

#define	MAX_LEN_MINUS_1 19	/* the maximum word length we can track */

int main(int argc, char const *argv[])
{
	int word_length[MAX_LEN_MINUS_1]; /* tracks the number of words from length 1 to 20 */

	/* zero array */
	int i;
	for (i = 0; i < MAX_LEN_MINUS_1; ++i)
		word_length[i] = 0;
	
	/* compute word lengths */
	int c, len, largest_count;
	len = largest_count = 0;
	while ((c = getchar()) != EOF)
	{
		if ((c == ' ' || c == '\t' || c == '\n') && len != 0)
		{
			++word_length[len-1];
			if (word_length[len-1] > largest_count)
				largest_count = word_length[len-1];
			len = 0;
		}
		else
		{
			++len;
		}
	}

	/* print word length */
	for (i = 0; i < MAX_LEN_MINUS_1; ++i)
	{
		printf("%3d: %d\n", i+1, word_length[i]);
	}
	
	/* print vertical histogram */
	printf("Word Length Vertical histogram\n");
	int j; /* i has already been declared above */
	for (i = largest_count; i > 0; --i)
	{
		for (j = 0; j < MAX_LEN_MINUS_1; ++j)
		{
			if (word_length[j] >= i)
			{
				printf("  *  ");
			}
			else
			{
				printf("     ");
			}
		}
		putchar('\n');
	}
	/* print labels */
	for (i = 0; i < MAX_LEN_MINUS_1; ++i)
	{
		printf("  %02d ", i+1);
	}
	putchar('\n');

	return 0;
}