#include <stdio.h>

int main()
{
	int a = 1, b = 2, c = 3;
	double x = 1.0;
	printf("%d\n", a + b < ! c + c);
	printf("%d\n", a - x || b * c && b / a);
	return 0;
}
