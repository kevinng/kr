#include <ctype.h>

/* atof: convert string s to double */
double atof(char s[])
{
	double val, power, expo;

	int i;
	for (i = 0; isspace(s[i]); i++)
		;
	int sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	/* dealing with exponents */
	if (s[i] == 'e' || s[i] == 'E')
		i++;
	int e_sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (; isdigit(s[i]); i++)
		expo = 10.0 * expo + (s[i] - '0');
	double factor = 10.0;
	if (e_sign == -1)
		factor = 0.1;
	while (expo-- > 0)
		val *= factor;

	return sign * val / power;
}