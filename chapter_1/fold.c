#include <stdio.h>

#define	MAX_WORD_WIDTH	25	
#define	LINE_WIDTH	80

int main(int argc, char const *argv[])
{
	char word[MAX_WORD_WIDTH];
	
	int c, i, j;
	for (i = 0; (c = getchar()) != EOF; ++i)
	{
		if (c == ' ' || c == '\n' || c == '\t')
		{
			word[j++] = c;
			word[j] = '\0';
			j = 0;

			if (i > MAX_WORD_WIDTH)
			{
				putchar('\n');
				i = 0;
			}
			
			printf("%s", word);
		}
		else
			word[j++] = c;
	}
	return 0;
}