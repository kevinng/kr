#include <stdio.h>

int my_strlen(char *);

int main(int argc, char const *argv[])
{
	char s[] = "Hello";

	printf("%d\n", my_strlen(s));
	
	return 0;
}


int my_strlen(char *s)
{
	int n;
	for (n = 0; *(s+n) != '\0'; n++)
		;
	return n;
}