#include <stdio.h>
#include <stddef.h>

int strend(char *, char *);

int main(int argc, char const *argv[])
{
	char *s = "mickey mouse";
	char *t = "mouse";

	printf("%d\n", strend(s, t));
	
	return 0;
}


/* not working as expected */
int strend(char *s, char *t)
{
	if (*s)	while (*++s);

	char *t_start = t;
	if (*t)	while (*++t);

	while (*s == *t && t > t_start)
	{
		s--;
		t--;
	}

	return t_start == t;

	return 0;
}