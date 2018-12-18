#include <stdio.h>
#include "random.h"
#include "printarray.h"

#define SIZE 1000

void* swap (int*, int*);

int main()
{
	int *array, start;
	printf("Enter a random integer: ");
	scanf("%d", &start);
	array = fill_array(start, SIZE);
	print_array(array, SIZE);
	for(int j=SIZE-1; j > 1; --j)
		for(int i = 0; i < j; ++i)
			if(*(array+i) > *(array+i+1))
				swap(array+i, array+i+1);
	print_array(array, SIZE);
}

void* swap (int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
