#include <stdio.h>

#define	MAXLINE	200	/* maximum input line size */

int my_getline(char line[], int limit);

int main(int argc, char const *argv[])
{
	char line[MAXLINE];
	int len = 0; /* current line length */
	while ((len = my_getline(line, MAXLINE)) != 0)
	{
		if (len > 80)
			printf("%s\n", line);
	}

	return 0;
}

/* my_getline: read a line into line[], return length */
int my_getline(char line[], int limit)
{
	int c, i;
	for (i = 0; i < limit && ((c = getchar()) != EOF) && (c != '\n'); ++i)
		line[i] = c;
	if (c == '\n')
	{
		line[i] = '\n';
		++i;
	}
	line[i] = '\0';
	return i;
}