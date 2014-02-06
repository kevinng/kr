#include <stdio.h>

char *my_strncpy(char *, char *, int);

int main(int argc, char const *argv[])
{
	char s1[6] = "hello";
	char s2[6] = "wo";

	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);

	char *s3 = my_strncpy(s1, s2, 5);

	printf("s3: %s\n", s3);
	
	return 0;
}


char *my_strncpy(char *s, char *ct, int n)
{
	if (n <= 0)
		return s;

	/* keep copying characters from ct to s until ct reaches '\0' is reached or n is 0 */
	char *s_start = s;
	while (n-- > 0 && (*s++ = *ct++))
		;

	/* pad s with '\0' n is greater than the length of ct */
	while ((n-- > 0) && *s != '\0')
		*s++ = '\0';

	*s = '\0';

	return s_start;
}
