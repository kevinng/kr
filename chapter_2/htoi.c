#include <stdio.h>

int htoi(char hexa_string[]);

int main(int argc, char const *argv[])
{
	printf("%d\n", htoi("aaa"));
	return 0;
}

int htoi(char hexa_string[])
{
	int c, i, j, this_int_val, ttl_int_val, pos, num_of_chars, pos_val;
	i = j = ttl_int_val = pos = num_of_chars = 0;
	pos_val = 16;

	/* first test for the optional 0x or 0X string */
	if (hexa_string[i] == '0' && (hexa_string[i+1] == 'x' || hexa_string[i+1] == 'X'))
		i = 2;
	
	/* find the number of positions to the end */
	pos = i;
	while ((c = hexa_string[pos]) != '\0')
		++pos;
	pos -= i+1; /* +1 because of 0 indexing */
	
	while ((c = hexa_string[i]) != '\0')
	{
		this_int_val = 0;
		if (c >= '0' && c <= '9')
			this_int_val = c - '0';
		else if (c >= 'a' && c <= 'f')
			this_int_val = (c - 'a') + 10;
		else if (c >= 'A' && c <= 'F')
			this_int_val = (c - 'A') + 10;

		pos_val = 1;
		for (j = 0; j < pos; ++j)
			pos_val *= 16;
		
		this_int_val *= pos_val;
		ttl_int_val += this_int_val;

		--pos;
		++i;
	}

	return ttl_int_val;
}