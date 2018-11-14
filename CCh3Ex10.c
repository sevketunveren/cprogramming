#include <stdio.h>

void print_byte_as_bits(char val)
{
	for (int i = 7; 0 <= i; i--)
		printf("%c", (val & (1 << i)) ? '1' : '0');
	printf("\n");
}

int main()
{
	char two = 2;
	char c=-1;
	signed char s = -1;
	unsigned char u = -1;
	printf("c = %d s = %d u = %d\n",(unsigned char) c, s, u);
	print_byte_as_bits(c);
	print_byte_as_bits(two);
	return 0;
}
