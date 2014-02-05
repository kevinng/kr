#include <stdio.h>

void my_strcat(char *, char *);

int main(int argc, char const *argv[])
{
	char s[20] = "hello ";
	char *t = "world";

	printf("%s\n", s);
	printf("%s\n", t);

	my_strcat(s, t);

	printf("%s\n", s);
	
	return 0;
}

void my_strcat(char *s, char *t)
{
	/* move to the end of *s */
	while (*s++)
		;
	s--; /* overshot by 1 */
	while ((*s++ = *t++))
		;
}