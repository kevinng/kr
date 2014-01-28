#include <stdio.h>

#define	MAXLINE	100	/* maximum input line size */

int my_getline(char line[], int limit);
int strip_trailing_blanks(char clean[], char unclean[], int uclen);

int main(int argc, char const *argv[])
{
	char line[MAXLINE]; /* the current line */
	char clean[MAXLINE]; /* the line striped of trailing blanks */
	int len; /* length of the current line */
	int clen; /* length of the cleaned line */
	while ((len = my_getline(line, MAXLINE)))
	{
		clen = strip_trailing_blanks(clean, line, len);
		if (clen > 0)
			printf("%s\n", clean);
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

/* strip_trailing_blanks: copy unclean[] to clean[], ignoring trailing blanks, and return the length of clean[] */
int strip_trailing_blanks(char clean[], char unclean[], int uclen)
{
	/* strip the trailing blanks */
	int c;
	while ((c = unclean[uclen]) == ' ' || c == '\t' || c == '\0' || c == '\n' || c == EOF)
		--uclen;
	
	/* copy the rest of the string */
	int i;
	for (i = 0; i <= uclen; ++i)
		clean[i] = unclean[i];
	clean[uclen+1] = '\0';

	return uclen;
}