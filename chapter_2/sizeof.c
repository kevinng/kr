#include <stdio.h>

int main(int argc, char const *argv[])
{
	printf("char: %lu bytes\n", sizeof(char));
	printf("float: %lu bytes\n", sizeof(float));
	printf("double: %lu bytes\n", sizeof(double));
	printf("short: %lu bytes\n", sizeof(short));
	printf("int: %lu bytes\n", sizeof(int));
	printf("long: %lu bytes\n", sizeof(long));
	return 0;
}