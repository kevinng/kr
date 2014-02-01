#include <stdio.h>

void expand(char s1[], char s2[]);
void expand_alphabet(char last_c, char last_2c, char buffer[], int n);

int main(int argc, char const *argv[])
{
	
	
	return 0;
}

/* assume s2[] is large enough for the expansion */
void expand(char s1[], char s2[])
{
	char buffer[26]; /* will work for numbers too */
	int direction;

	int j = 0; /* traverses s2[] */
	
	/* deal with leading dash */
	char start_c;
	int k;
	if (s1[0] == '-')
	{
		if (is_number(s1[1]))
		{
			for (k = '0'; k < c; k++)
				s2[j++] = k;
		}
		else if (is_alphabet(s1[1]))
		{
			start_c = (c >= 'A' && c <= 'Z') ? 'A' : 'a';
			for (k = start_c; k < c; k++)
				s2[j++] = k;
		}
	}
	
	int i;
	for (i = 5; s1[i] != '\0'; i+=4)
	{
		/* normal expansion */
		if (s[i-3] != '-' &&
			s[i-1] == '-' &&
			((is_alphabet(s[i-2]) && is_alphabet(s[i-1])) || 
			(is_number(s[i-2]) && is_number(s[i-1]))))
		{
			direction = s[i] > s[i-2] ? 1 : -1;

			k = s[i-2];
			while (s[i] != k)
				s2[j++] = k + direction;
			i += 4;
		}
		else if (

		last_c = c;
		last_2c = last_c;
	}


	int i = j = k = 0;
	while (s1[i] != '\0')
	{
		for (j = k; j < i; j++)
		{
			
		}
		i++;
		/* k is the last processed position */
	}



	/* deal with trailing dash */


	s2[j] = '\0';
}

int is_alphabet(char c)
{

}

int is_number(char c)
{

}