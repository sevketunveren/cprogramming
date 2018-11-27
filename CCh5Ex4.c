#include <stdio.h>

int z;

//void f(x)
void f(x)
int x;
{
	x = 2;
	z += x;
}

int main()
{
	z = 5;
	f(z);
	printf("z = %d\n", z);
	return 0;
}
