#include <stdio.h>
#include <stdlib.h>

int compress(char *s)
{
	char *p;
	int a = 0, shift;
	for (p = s; *p != '\0'; ++p)
	{
		a = (a << 4) | *p - '0';
	}
	return a;
}

char* bit_print(int compressed, char *bitstring)
{
	int i;
	int n = sizeof(int) * 8;
	int mask = 1 << (n - 1);
	int c = 0;
	printf("%d\t",compressed);
	for (i = 1; i <= n; ++i)
	{
		bitstring[c++] = ((compressed & mask) == 0) ? '0' : '1';
		compressed <<= 1;
		if (i % 4 == 0 && i < n)
			bitstring[c++] = ' ';
	}
	bitstring[c++] = '\0';
	printf("%s\n", bitstring);
	return bitstring;
}

void decompress(int compressed, char*decompressed)
{
	int mask = 15;
	int i;
	char c;
	decompressed[8] = '\0';
	for (i = 1; i <= 8; ++i)
	{
		c = compressed & mask;
		decompressed[8-i] = c + '0';
		compressed = compressed >> 4;
	}
}

void main()
{
	char decompressed[9];
	int compressed;
	char string[40];
	printf("Input a string of decimal strings: ");
	scanf("%s", string);
	printf("%s\n", string);
	getchar();
	bit_print(compressed = compress(string), string);
	decompress(compressed, decompressed);
	printf("%s\n", decompressed);
	getchar();
}