#include <stdio.h>

#define	UPPER	300
#define	STEP	20

float fahrenheit_to_celsius(float fahrenheit);

int main(int argc, char const *argv[])
{
	printf("Fahrenheit\tCelsius\n");
	float i;
	for (i = 0; i < UPPER; i+=STEP)
		printf("%3.3f\t\t%3.3f\n", i, fahrenheit_to_celsius(i));
	return 0;
}

float fahrenheit_to_celsius(float fahrenheit)
{
	return (5.0/9.0) * (fahrenheit-32.0);
}