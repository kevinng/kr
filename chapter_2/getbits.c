#include <stdio.h>

void unsigned_to_bit_str(unsigned int_val, char bit_str[]);
unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int pos, int n, unsigned y);

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
	unsigned gb_val = getbits(unsigned_val, gb_pos, gb_n);
	unsigned_to_bit_str(gb_val, bit_str);
	printf("getbits at pos %d, %d bits in decimal: %d\n", gb_pos, gb_n, gb_val);
	printf("getbits at pos %d, %d bits in binary: %s\n", gb_pos, gb_n, bit_str);
	

	int sb_pos = 1;
	int sb_n = 3;
	int sb_y = 135;
	unsigned sb_val = setbits(unsigned_val, sb_pos, sb_n, sb_y);
	printf("sb_y in decimal: %d\n", sb_y);
	unsigned_to_bit_str(sb_y, bit_str);
	printf("sb_y in binary: %s\n", bit_str);
	printf("setbits at pos %d, %d bits in decimal: %d\n", sb_pos, sb_n, sb_val);
	unsigned_to_bit_str(sb_val, bit_str);
	printf("setbits at pos %d, %d bits in binary: %s\n", sb_pos, sb_n, bit_str);
		
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

/* returns x with the n bits that begin at position pos set to the rightmost n
	bits of y leaving the other bits unchanged */
unsigned setbits(unsigned x, int pos, int n, unsigned y)
{
	// int offset = ((sizeof(unsigned)*8)-pos-1);
	// x & ((~0 >> pos) << offset)
	// return (~0 << offset) | ((y & ~(~0 << n)) << offset);
}

/* get n bits from position n */
unsigned getbits(unsigned x, int p, int n)
{
	return x >> (p+1-n) & ~(~0 << n);
}