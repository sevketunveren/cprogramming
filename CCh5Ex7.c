#include <stdio.h>

#define INITIAL_SEED 17
#define MULTIPLIER 25173
#define INCREMENT 13849
#define MODULUS 65536
#define FLOATING_MODULUS 65536.0

static unsigned seed = INITIAL_SEED;
static double current_average = 0;

double probability(void)
{
	seed = (MULTIPLIER * seed + INCREMENT) % MODULUS;
	return (seed / FLOATING_MODULUS);
}

int main()
{
	double sum = 0;
	int n;
	printf("Enter number:");
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
	{
		sum += probability();
	}
	printf("%lf", sum/n);
}
