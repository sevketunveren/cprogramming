#include <stdio.h>

int main()
{
	int i, j, k;
	printf("%p\n%p\n%p\n", &i, &j, &k);
	printf("%d\n%d\n%d\n", &i, &j, &k);
	return 0;
}
