//https://www.geeksforgeeks.org/write-an-efficient-c-program-to-reverse-bits-of-a-number/
//CS Ch2Ex35
#include <stdio.h>

unsigned char reverseBits(unsigned char num)
{
	unsigned char NO_OF_BITS = sizeof(num) * 8;
	unsigned char reverse_num = 0, i, temp;

	for (i = 0; i < NO_OF_BITS; i++)
	{
		printf("\n*****ITERATION%d*****\n",i+1);
		printf("%d AND (1 LEFT SHIFT %d) = %d = TEMP\n", num, i, temp = (num & (1 << i)));
		if(temp)
		{
			printf("%d OR (1 LEFT SHIFT ((%d - 1) - %d)))\n", reverse_num, NO_OF_BITS, i);
			reverse_num |= (1 << ((NO_OF_BITS - 1) - i));
		}
}

	return reverse_num;
}

int main()
{
	unsigned char x;
	printf("Enter a character: ");
	scanf("%c", &x);
	printf("REVERSE = %d\n", reverseBits(x));
}
