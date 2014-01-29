#include <stdio.h>

int main(int argc, char const *argv[])
{
	int len = 3;
	char string[len];

	int i;
	for (i = 0; i < len-1; ++i)
	{
		string[i] = '-';
	}
	printf("%s\n", string);

	string[2] = '\0';
	string[0] = '0';
	string[1] = '0';
	printf("%s\n", string);

	int j = 0;
	string[j] = '1';
	string[++j] = '2';
	printf("%s\n", string);

	j = 0;
	if (--j == 0)
	{
		printf("IN\n");
	}
	else
	{
		printf("OUT\n");
	}

	
	return 0;
}