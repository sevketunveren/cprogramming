#include <stdio.h>
#define START 4 
#define FINISH 10000000

int is_prime(int);

int main()
{
	int other;
	unsigned char goldbach_contravention;
	for(int number = START; number <= FINISH; number=number+2)
	{
		goldbach_contravention = 1;
		for(int i = 2; i <= number / 2; i = i + 1)
		{
			other = number - i;
			/*if(is_prime(i))
				printf("%d\t(Prime)\n%d\t(%s)\n+\n------------------\n%d\n\n", i, other, is_prime(other) ? "Prime":"not prime", number);*/
 			if(is_prime(i) && is_prime(other))
			{
				//printf("%d + %d = %d\n", i, other,  number);
				goldbach_contravention = 0;
				break; //verified
			}
		}
		if(goldbach_contravention)
		{
			printf("ATTENTION!\nGoldbach conjecture contravention %d\n", number);
			break;
		}
	}
	return 0;
}

int is_prime (int n)
{	
	for(int k=2; k<n; ++k)
		if(n%k==0)
			return 0;
	return 1;
}
