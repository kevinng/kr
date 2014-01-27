#include <stdio.h>

int main(int argc, char const *argv[])
{
	int c;
	while ((c = getchar()) != EOF)
	{
		if (c != ' ' && c != '\t' && c != '\n')
			putchar(c);
		else
			putchar('\n');
	}
	return 0;
}