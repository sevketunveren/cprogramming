#include <stdio.h>
//Case-senstivice
//It works if the first three characters are different from each other.
int main()
{
	char src_1 = getchar(), src_2 = getchar(), src_3 = getchar(), c;
	unsigned int src_counter_1 = 1, src_counter_2 = 1, src_counter_3 = 1;
	while ((c = getchar()) != EOF)
	{
		if(c == src_1)
			src_counter_1++;
		else if (c == src_2)
			src_counter_2++;
		else if (c == src_3)
			src_counter_3++;
	}
	printf("%c %d times\n%c %d times\n%c %d times", src_1, src_counter_1, src_2, src_counter_2, src_3, src_counter_3);
	return 0;
}
