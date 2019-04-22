#include <stdio.h>
#include "printarray.h"
#include "random.h"
#define SIZE 45
int compare(const int *a, const int *b)
{
	if(*a>*b)
		return 1;
	else if(*a==*b)
		return 0;
	else
		return -1;
}

int main()
{
	int *arr;
	arr = fill_array(1578, SIZE);
	print_array(arr, SIZE);
	*arr = sizeof(int);
	qsort(arr, SIZE, sizeof(int), compare);
	print_array(arr, SIZE);
}
