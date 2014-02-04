#include <stdio.h>

#define	MAX_LINE_WIDTH 1000 /* maximum line width in characters */

int my_getline(char line[], int line_length);
int strrindex(char line[], char search_string[]);

char pattern[] = "ould"; /* pattern to search for */

int main(int argc, char const *argv[])
{
	char line[MAX_LINE_WIDTH];
	int found = 0;

	while (my_getline(line, MAX_LINE_WIDTH) > 0)
	{
		if (strrindex(line, pattern) >= 0)
		{
			printf("%s", line);
			found++;
		}
	}

	return found;
}

/* my_getline: get line into s, return length */
int my_getline(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

int strrindex(char line[], char search_string[])
{
	int i, j, k, l;

	l = -1;
	for (i = 0; line[i] != '\0'; i++)
	{
		for (j = i, k = 0; search_string[k] != '\0' && line[j] != '\0' && line[j] == search_string[k]; j++, k++)
			;
		if (k > 0 && search_string[k] == '\0')
			l = i;
	}

	return l;
}