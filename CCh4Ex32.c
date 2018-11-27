#include <stdio.h>

int main()
{
	for (putchar('1'); putchar('2'); putchar('3'))
	{
		putchar('4');
		continue;
		putchar('S');
	}
	return 0;
}
