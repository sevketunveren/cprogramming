#include <stdio.h>

void print_byte_as_bits(char val)
{
	for (int i = 7; 0 <= i; i--)
		printf("%c", (val & (1 << i)) ? '1' : '0');
}


int main()
{
	int c;
	while ((c = getchar()) != EOF)
	{
		print_byte_as_bits(c);
		putchar(c);
	}
	print_byte_as_bits(c);
	putchar(c);
	return 0;
}
