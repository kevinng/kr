#include <stdio.h>

int any(char s1[], char s2[]);

int main(int argc, char const *argv[])
{
	char s1[] = "hello world";
	char s2[] = "ewd";
	printf("%s\n", s1);
	printf("pos of 'ewd': %d\n", any(s1, s2));
	return 0;
}

int any(char s1[], char s2[])
{
	int i, j;
	for (i = 0; s1[i] != '\0'; ++i)
	{
		for (j = 0; s2[j] != '\0'; ++j)
		{
			if (s1[i] == s2[j])
				return i;
		}
	}
	return -1;
}