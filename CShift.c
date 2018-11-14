#include <stdio.h>

int main()
{
	unsigned char c = 1;
	unsigned char temp;
	for(unsigned int i = 1; i <= 9; ++i)
	{
		temp =  c << i; 
		printf("%d\t%d\n", i, temp);
	}
	return 0;
}
