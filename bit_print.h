#include <stdio.h>
#include <limits.h>
void bit_print(int a) { //big endian
	int i;
	int n = sizeof(int) * CHAR_BIT;
	int mask = 1 << (n - 1);
	for (i = 1; i <= n; ++i) {
		putchar(((a & mask) == 0) ? '0' : '1');
		a <<= 1;
		if (i % CHAR_BIT == 0 && i < n)
			putchar(' ');
	}
}

void bit_print_four(int a) { //little endian
	int i;
	int mask = 1;
	for (i = 1; i <= 4; ++i) {
		putchar(((a & mask) ==0) ? '0' : '1');
		a >>= 1;
	}
}

void bit_print_thiryt_two(int a) {
	int i;
	int mask = 1 << 31;
	for (i = 1; i <= 32; ++i) {
		putchar(((a & mask) == 0) ? '0' : '1');
		a <<= 1;
		if (i & 4 == 0)
			putchar(' ');
	}
}
