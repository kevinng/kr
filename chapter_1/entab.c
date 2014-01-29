#include <stdio.h>

#define	MAX_TAB_STOP	4
#define MAX_LINE	100
#define	TAB_SYMBOL '+'
#define	SPACE_SYMBOL '-'

int my_getline(char line[] , int limit);

int main(int argc, char const *argv[])
{
	char original[MAX_LINE];
	char entabbed[MAX_LINE];
	int len;
	int c, spaces_in_a_row, real_spaces;
	int i, j;
	while ((len = my_getline(original, MAX_LINE)) > 0)
	{
		spaces_in_a_row = real_spaces = j = 0;
		for (i = 0; i < len; ++i)
		{
			c = original[i];

			if (c == SPACE_SYMBOL)
			{
				++real_spaces;
				++spaces_in_a_row;

				if ((real_spaces % MAX_TAB_STOP) == 0) /* is a tab stop */
				{
					entabbed[j++] = TAB_SYMBOL;
					spaces_in_a_row = 0;
				}
			}
			else if (c == TAB_SYMBOL)
			{
				real_spaces += (MAX_TAB_STOP - spaces_in_a_row);

				entabbed[j++] = TAB_SYMBOL;
				spaces_in_a_row = 0;
			}
			else /* is a character */
			{
				++real_spaces;

				/* fill in the white spaces */
				while (spaces_in_a_row > 0)
				{
					entabbed[j++] = SPACE_SYMBOL;
					--spaces_in_a_row;
				}

				entabbed[j++] = original[i];
			}
		}
		entabbed[j] = '\0';
		
		printf("Original: %s\n", original);
		printf("Entabbed: %s\n", entabbed);

		/* reset strings */
		entabbed[0] = '\0';
		original[0] = '\0';
	}
	
	return 0;
}

/* my_getline: read a line into line[], and return the length */
int my_getline(char line[] , int limit)
{
	int c, i;
	for (i = 0; i < limit && ((c = getchar()) != EOF) && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n')
	{
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}