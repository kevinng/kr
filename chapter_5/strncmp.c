#include <stdio.h>

int my_strncmp(char *, char *, int);
int my_strncmp2(char *, char *, int);

int main(int argc, char const *argv[])
{
	char s1[] = "helloa";
	char s2[] = "hellob";

	printf("my_strncmp:%d::\n", my_strncmp(s1, s2, 5));

	printf("my_strncmp2:%d::\n", my_strncmp2(s1, s2, 5));
			
	return 0;
}


int my_strncmp(char *cs, char *ct, int n)
{
	/* move pass common characters */
	while ((n > 0) && (*cs == *ct))
	{
		--n;
		++cs;
		++ct;
	}

	/* cs and ct are the same */
	if (n == 0)
		return 0;
	
	return (*cs < *ct) ? -1 : 1;
}

int my_strncmp2(char *cs, char *ct, int n)
{
	for ( ; (n-- > 0) && (*cs == *ct); cs++, ct++)
		if (*cs == '\0' || n == 0)
			return 0;

	return *cs - *ct;
}