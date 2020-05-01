/* In commercial applications, it is sometimes useful to use binary coded decimal codes (BCD), where 4 bits are used to represent a decimal digit. A 32-bit word can be used to represent an 8-digit decimal number. Use bit fields to implement this code. Write two conversion routines, one from binary to BCD and the second from BCD to binary. */
#include <stdio.h>
#include <math.h>
#include "bit_print.h"

typedef struct
{
	unsigned b0 : 4, b1 : 4, b2 : 4, b3 : 4, b4 : 4, b5 : 4, b6 : 4, b7 : 4;
} bcd;

unsigned bcdtoi(bcd b)
{
	return b.b0 * 10000000 + b.b1* 1000000 + b.b2 * 100000 + b.b3 * 10000 + b.b4 * 1000 + b.b5 * 100 + b.b6 * 10 + b.b7;
}

bcd itobcd(unsigned i)
{
	bcd b = {0};
	unsigned cnt = 0;
	unsigned remainder = 0;
	while (i > 0)
	{
		remainder = i % 10;
		i /= 10;
		if (cnt == 0)
		{
			b.b7 = remainder;
		}
		else if (cnt == 1)
		{
			b.b6 = remainder;
		}
		else if (cnt == 2)
		{
			b.b5 = remainder;
		}
		else if (cnt == 3)
		{
			b.b4 = remainder;
		}
		else if (cnt == 4)
		{
			b.b3 = remainder;
		}
		else if (cnt == 5)
		{
			b.b2 = remainder;
		}
		else if (cnt == 6)
		{
			b.b1 = remainder;
		}
		else if (cnt == 7)
		{
			b.b0 = remainder;
		}
		cnt++;
	}
	return b;
}

void print_bcd(bcd b)
{
	unsigned cnt = 0;
	while (cnt < 8)
	{
		if (cnt == 0)
		{
			bit_print_four(b.b0);
			printf(" ");
		}
		else if (cnt == 1)
		{
			bit_print_four(b.b1);
			printf(" ");
		}
		else if (cnt == 2)
		{
			bit_print_four(b.b2);
			printf(" ");
		}
		else if (cnt == 3)
		{
			bit_print_four(b.b3);
			printf(" ");
		}
		else if (cnt == 4)
		{
			bit_print_four(b.b4);
			printf(" ");
		}
		else if (cnt == 5)
		{
			bit_print_four(b.b5);
			printf(" ");
		}
		else if (cnt == 6)
		{
			bit_print_four(b.b6);
			printf(" ");
		}
		else if (cnt == 7)
		{
			bit_print_four(b.b7);
			printf("\n");
		}
		cnt++;
	}
}

void main()
{
	unsigned i = 0, cnt = 0;
	char *c, *s;
	bcd b = {0};
	printf("Enter binary: ");
	scanf("%s", c);
	while (*c != '\0')
	{
		i = i + ((unsigned int)(*(c++)) - 48) * pow(2, cnt++);
	}
	printf("Integer: %d\n", i);
	print_bcd(itobcd(i));
	cnt = 0;
	printf("Enter bcd: ");
	scanf("%s", s);
	while (*s != '\0')
	{
		if (cnt < 4)
		{
			b.b0 = b.b0 + ((unsigned int)(*(s++)) - 48) * pow(2, cnt++);
		}
		else if (cnt < 8)
		{
			b.b1 = b.b1 + ((unsigned int)(*(s++)) - 48) * pow(2, cnt++ % 4);
		}
		else if (cnt < 12)
		{
			b.b2 = b.b2 + ((unsigned int)(*(s++)) - 48) * pow(2, cnt++ % 4);
		}
		else if (cnt < 16)
		{
			b.b3 = b.b3 + ((unsigned int)(*(s++)) - 48) * pow(2, cnt++ % 4);
		}
		else if (cnt < 20)
		{
			b.b4 = b.b4 + ((unsigned int)(*(s++)) - 48) * pow(2, cnt++ % 4);
		}
		else if (cnt < 24)
		{
			b.b5 = b.b5 + ((unsigned int)(*(s++)) - 48) * pow(2, cnt++ % 4);
		}
		else if (cnt < 28)
		{
			b.b6 = b.b6 + ((unsigned int)(*(s++)) - 48) * pow(2, cnt++ % 4);
		}
		else if (cnt < 32)
		{
			b.b7 = b.b7 + ((unsigned int)(*(s++)) - 48) * pow(2, cnt++ % 4);
		}
	}
	printf("%d\n", bcdtoi(b));
}
