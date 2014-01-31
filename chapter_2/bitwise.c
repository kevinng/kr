#include <stdio.h>

void unsigned_to_bit_str(unsigned int_val, char bit_str[]);
unsigned getbits(unsigned x, int p, int n);

int main(int argc, char const *argv[])
{
	int bit_str_len = sizeof(int) * 8;
	char bit_str[bit_str_len+1];
	bit_str[0] = '\0';

	unsigned unsigned_val = 236;
	unsigned_to_bit_str(unsigned_val, bit_str);
	printf("decimal: %d\nbinary: %s\n", unsigned_val, bit_str);
	
	int gb_pos = 5;
	int gb_n = 3;
	int gb_val = getbits(unsigned_val, gb_pos, gb_n);
	unsigned_to_bit_str(gb_val, bit_str);
	printf("getbits at pos %d, %d bits in decimal: %d\n", gb_pos, gb_n, gb_val);
	printf("getbits at pos %d, %d bits in binary: %s\n", gb_pos, gb_n, bit_str);
	
	return 0;
}

/* make sure bit_str is large enough to store the bits of an int */
void unsigned_to_bit_str(unsigned int_val, char bit_str[])
{
	unsigned i;
	int j = 0;
	for (i = int_val; i > 0; i >>= 1)
		bit_str[j++] = i & 1 ? '1' : '0';
	bit_str[j] = '\0';
}

unsigned getbits(unsigned x, int p, int n)
{
	return x >> (p+1-n) & ~(~0 << n);
}