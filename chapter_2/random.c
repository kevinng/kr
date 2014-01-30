#include <stdio.h>

unsigned long int next = 1;

int rand();
void srand(unsigned int seed);

int main(int argc, char const *argv[])
{
	srand(100);
	printf("%d\n", rand());
	printf("%d\n", rand());
	return 0;
}

/* rand: return pseudo-random integer on 0...32767 */
int rand()
{
	next = next * 1103515145 + 12345;
	return (unsigned int)(next/65536) % 32768;
}

/* srand: set seed for rand() */
void srand(unsigned int seed)
{
	next = seed;
}