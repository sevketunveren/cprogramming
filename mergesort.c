#include <stdio.h>
#include "random.h"
#include "printarray.h"
#include "merge.h"
#define SIZE 1024*1024

int main()
{
	int *a, *temp,  seed;
	printf("Enter a random integers: ");
	scanf("%d", &seed);
	a = fill_array(seed, SIZE);
	print_array(a, SIZE);
	temp = 	(int*)calloc(SIZE,sizeof(int));
	for(int i = 1; i < SIZE; i *= 2)
	{
		for(int j = 0; j < SIZE - i; j += 2 * i)
			merge(a + j, a + j + i, temp + j, i, i);
		for(int c = 0; c < SIZE; c++)
			a[c] = temp[c];
	}
}
