#include <stdio.h>

char *my_strncat(char *, char *, int);

int main(int argc, char const *argv[])
{
	char s1[12] = "hello*";
	char s2[] = "world";

	printf("s1:%s::\n", s1);
	printf("s2:%s::\n", s2);

	char *s3 = my_strncat(s1, s2, 3);

	printf("s3:%s::\n", s3);
	
	return 0;
}

/* assume that s can hold at least an additional n characters */
char *my_strncat(char *s, char *ct, int n)
{
	if (n <= 0)
		return s;

	/* copy the starting pointer position of s */
	char *s_start = s;
	
	/* move to the end of s */
	if (*s) while (*++s);

	/* concatenate characters to the end of s */
	while (n-- > 0 && (*s = *ct))
	{
		s++;
		ct++;
	}

	*s = '\0';
	
	return s_start;
}