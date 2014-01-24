#include <stdio.h>

/* Print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300 */

int main(int argc, char const *argv[])
{
	int fahr, celsius;
	int lower, upper, step;

	lower = 0;		/* lower limit of temperature scale */
	upper = 300;	/* upper limit of temperature scale */
	step = 20;

	fahr = lower;

	while (fahr <= upper) {
		celsius = 5 * (fahr-32) / 9;
		printf("%d\t%d\n", fahr, celsius);
		fahr = fahr + step;
	}
	
	return 0;
}