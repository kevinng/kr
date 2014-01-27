#include <stdio.h>

#define	NUM_ALPHABETS	26

int main(int argc, char const *argv[])
{
	int alphabet_count[NUM_ALPHABETS];
	int i;
	for (i = 0; i < NUM_ALPHABETS; ++i)
		alphabet_count[i] = 0;
	
	/* compute word lengths */
	int c, len;
	while ((c = getchar()) != EOF)
	{
		if (c >= 'A' && c <= 'Z')
			++alphabet_count[c-'A'];
		else if (c >= 'a' && c <= 'z')
			++alphabet_count[c-'a'];
	}

	/* print histogram */
	int j;
	for (i = 0; i < NUM_ALPHABETS; ++i)
	{
		printf("%c: ", 'a'+i);
		for (j = 0; j < alphabet_count[i]; ++j)
		{
			putchar('*');
		}
		putchar('\n');
	}
	
	return 0;
}