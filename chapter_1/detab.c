#include <stdio.h>

#define	TAB_STOP_SIZE	4
#define	MAXLINE	100
#define	TAB_SYMBOL '+'
#define	SPACE_SYMBOL '-'	

int my_getline(char line[], int limit);

int main(int argc, char const *argv[])
{
	char original[MAXLINE];
	char entabbed[MAXLINE];
	
	int len, i, j, spaces_to_fill;
	while ((len = my_getline(original, MAXLINE)) != 0)
	{
		 j = 0;
		 for (i = 0; i < len; ++i)
		 {
		 	if (original[i] != TAB_SYMBOL)
		 		entabbed[j] = original[i];
		 	else
		 	{
				if (j > TAB_STOP_SIZE)
		 			spaces_to_fill = TAB_STOP_SIZE - (j % TAB_STOP_SIZE);
		 		else if (j < TAB_STOP_SIZE)
		 			spaces_to_fill = TAB_STOP_SIZE - j;
		 		else
		 			spaces_to_fill = TAB_STOP_SIZE;

		 		while (spaces_to_fill-- > 0)
	 				entabbed[j++] = SPACE_SYMBOL;

	 			j += spaces_to_fill;
		 	}
		 	++j;
		 }

		 entabbed[j] = '\0';
		 printf("%s\n", entabbed);
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