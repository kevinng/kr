#include <stdio.h>

#define	IN	1
#define	OUT	0

int main(int argc, char const *argv[])
{
	int state;
	state = OUT;

	int c, last_c;
	last_c = '/';
	while ((c = getchar()) != EOF)
	{
		if (last_c == '/' && c == '*')
			state = IN;
		else if (last_c == '*' && c == '/')
			state = OUT;

		if (state == OUT && c != '/' && last_c != '/')
			putchar(last_c);
		
		   last_c = c;
	}
	
	return 0;
}