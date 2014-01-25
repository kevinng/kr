#include <stdio.h>

int main(int argc, char const *argv[])
{
	int c;

	while ((c = getchar()) != EOF) {
		if (c != '\n')
		{
			printf("Not EOF\n");
		}
	}
	
	return 0;
}