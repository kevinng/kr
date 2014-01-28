#include <stdio.h>

#define	MAXLINE	100

int my_getline(char line[], int limit);
void reverse_line(char original[], char reversed[], int length);

int main(int argc, char const *argv[])
{
	char line[MAXLINE]; /* current line */
	char reversed_line[MAXLINE]; /* reversed character string of line */
	
	int len;
	while ((len = my_getline(line, MAXLINE)) != 0)
	{
		reverse_line(line, reversed_line, len);
	}
	
	return 0;
}

int my_getline(char line[], int limit)
{
	int i, c;
	for (i = 0; i < limit && ((c = getchar()) != EOF) && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n')
	{
		line[i] = '\n';
		++i;
	}
	line[i] = '\0';

	return i;
}

void reverse_line(char original[], char reversed[], int length)
{
	int i;
	for (i = 0; i < length; ++i)
		reversed[length-1-i] = original[i];
	reversed[length] = '\0';
}