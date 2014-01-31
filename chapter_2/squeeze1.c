#include <stdio.h>

void squeeze_char(char s[], int c);
void squeeze_char_in_str(char s[], char c[]);

int main(int argc, char const *argv[])
{
	char string_to_squeeze_1[] = "hello world 1\n";
	squeeze_char(string_to_squeeze_1, 'o');
	printf("squeeze 'c': %s\n", string_to_squeeze_1);

	char string_to_squeeze_2[] = "hello world 2\n";
	squeeze_char_in_str(string_to_squeeze_2, "hed ");
	printf("squeeze 'hld ': %s\n", string_to_squeeze_2);
	
	return 0;
}

void squeeze_char(char s[], int c)
{
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++)
	{
		if (s[i] != c)
			s[j++] = s[i];
	}
	s[j] = '\0';
}

void squeeze_char_in_str(char s[], char c[])
{
	int i, j, k, squeeze_char;

	for (i = j = 0; s[i] != '\0'; ++i)
	{
		squeeze_char = 0;
		for (k = 0; c[k] != '\0'; ++k)
		{
			if (s[i] == c[k])
				squeeze_char = 1;
		}

		if (!squeeze_char)
			s[j++] = s[i];
	}
	s[j] = '\0';
}