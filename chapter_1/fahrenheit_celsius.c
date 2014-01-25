#include <stdio.h>

/* Print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300 */
/* Floating-point version. */
int main(int argc, char const *argv[])
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;		/* lower limit of temperature scale */
	upper = 300;	/* upper limit of temperature scale */
	step = 20;

	fahr = lower;

	printf("Temperature Conversion Table\n");
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	
	return 0;
}