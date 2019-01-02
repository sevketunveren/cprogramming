#include <stdio.h>

void f(int a[]);

int main (void)
{
	char s[]= "deep in the heart of texas";
	char *p= "deep in the heart of texas";
	int a[3];
	double d[5];
	printf("%zu\n%zu\n%zu\n%zu\n", sizeof(s), sizeof(p), sizeof(a), sizeof(d));
	f(a);
	return 0;
}

void f(int a[])
{
	printf("%zu\n", sizeof(a));
}
