#include <stdio.h>

int main()
{
	int a = 0xabc;
	int b = 0xABc;
	int c = 0XABC;
	printf("a = %d b = %d c = %d\n", a, b, c);
	return 0;
}
