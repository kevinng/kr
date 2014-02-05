#include <stdio.h>
#include <ctype.h>

#define	SIZE 10	

int main(int argc, char const *argv[])
{
	int n;
	// int array[SIZE];
	int getint(int *);
	int getfloat(float *);
	float float_array[SIZE];
	
	for (n = 0; n < SIZE && getfloat(&float_array[n]) != EOF; n++)
		;

	int i;
	for (i = 0; i < SIZE; i++)
	{
		printf("%g\n", float_array[i]);
	}
	
	return 0;
}

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */

int getint(int *pn)
{
	int c, d, sign;

	while (isspace(c = getch())) /* skip white space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-')
	{
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
	{
		d = c;
		c = getch();
	}
	if (!isdigit(c))
	{
		ungetch(d); /* push the sign back onto the input */
	}
	else
	{
		for (*pn = 0; isdigit(c); c = getch())
			*pn = 10 * *pn + (c - '0');
		*pn *= sign;
		if (c != EOF)
			ungetch(c);
	}
	
	return c;
}

int getfloat(float *pn)
{
	int c, d, sign;
	float power = 1.0;

	/* skip white space */
	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-')
	{
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
	{
		d = c;
		c = getch();
	}
	if (!isdigit(c))
	{
		ungetch(d); /* push the sign back onto the input */
	}
	else
	{
		if (c == '.') /* get fraction part (if started there) */
		{
			c = getch();
			for (*pn = 0; isdigit(c); c = getch())
			{
				*pn = 10 * *pn + (c - '0');
				power *= 10;
			}
		}
		else
		{
			/* get the integer part */
			for (*pn = 0; isdigit(c); c = getch())
				*pn = 10 * *pn + (c - '0');

			if (c == '.') /* get fraction part */
			{
				c = getch();
				for (; isdigit(c); c = getch())
				{
					*pn = 10 * *pn + (c - '0');
					power *= 10;
				}
			}
		}
		
		*pn *= sign;
		*pn /= power;

		if (c != EOF)
			ungetch(c);
	}
	
	return c;
}

#define	BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}