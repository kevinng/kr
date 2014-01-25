#include <stdio.h>

int main(int argc, char const *argv[])
{
	int fahr;

	printf("Fahrenheit to celsius table:\n");
	for (fahr = 300; fahr > 0; fahr -= 20) {
		printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
	}
	return 0;
}