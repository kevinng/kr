#include <stdio.h>

/* Celsius to fahrenheit table. */

int main(int argc, char const *argv[])
{
	float celsius, fahrenheit;
	int lower, upper, step;

	lower = 0;		/* Start from 0 degs */
	upper = 100;	/* Step at 100 degs */
	step = 20;

	celsius = 0;
	printf("Celsius to Fahrenheit table:\n");
	while (celsius <= upper) {
		fahrenheit = celsius * (9.0/5.0) + 32.0;
		printf("%6.1f %6.1f\n", fahrenheit, celsius);
		celsius += step;
	}
	
	return 0;
}