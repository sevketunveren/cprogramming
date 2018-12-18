#include <stdlib.h>

#define MULTIPLIER 25173
#define INCREMENT 13849
#define MODULUS 65536

static int seed;

double probability(void)
{
	return 	seed = (MULTIPLIER * seed + INCREMENT) % MODULUS;
}

int* fill_array(int start, int size)
{
	int *array  = (int*)malloc(size*sizeof(int));
	seed = start;
	for (int i = 0; i < size; ++i)
		array[i] = probability();
	return array;
}
