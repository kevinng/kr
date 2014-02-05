#include <stdio.h>	

char *alloc(int);
void afree(char *);

int main(int argc, char const *argv[])
{
	char *cp = alloc(6);
	*cp = 'h';
	*(cp+1) = 'e';
	*(cp+2) = 'l';
	*(cp+3) = 'l';
	*(cp+4) = 'o';
	*(cp+5) = '\0';

	printf("%s\n", cp);

	*(cp+3) = 'y';

	printf("%s\n", cp);

	afree(cp);
	char *new_cp = alloc(3);
	*new_cp = 'h';
	*(new_cp+1) = 'i';
	*(new_cp+2) = '\0';

	printf("%s\n", cp);	
	afree(cp);

	return 0;
}

#define	ALLOCSIZE	10000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */

char *alloc(int n) /* return pointer to n characters */
{
	if (allocbuf + ALLOCSIZE - allocp >= n)
	{
		allocp += n;
		return allocp - n; /* old p */
	}
	else
		return 0;
}

void afree(char *p) /* free storage pointed to by p */
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}