#include <stdio.h>

int main(int argc, char const *argv[])
{
	int word_len[19]; /* counts of words with length from 1 to 20 */

	/* zero out the integer array */
	int i;
	for (i = 0; i < 19; ++i)
		word_len[i] = 0;
	
	/* compute word lengths */
	int c, len;
	len = 0;
	while ((c = getchar()) != EOF)
	{
		 if ((c == ' ' || c == '\t' || c == '\n') && len != 0) 
		 {
		 	++word_len[len-1];
		 	len = 0;
		 } 
		 else
		 {
		 	 ++len;
		 }
	}

	/* print histogram */
	printf("Word Length Histogram\n");
	int j; /* i has already been declared above */
	for (i = 0; i < 19; ++i)
	{
		printf("%3d: ", i+1);
		for (j = 0; j < word_len[i]; ++j)
			putchar('*');
		putchar('\n');
	}
			
	return 0;
}