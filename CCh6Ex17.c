#include <stdio.h>

int main()
{
	char a[] ="abc", *p;
	int i;
	p = a;
	for(i = 0; i < 3; ++i)
		printf("%c\n", *p++);
	printf("%s\n",a);
	p = a;
	for(i = 0; i < 3; ++i)
		printf("%c\n", (*p)++);
	printf("%s\n",a);
	return 0;
}
