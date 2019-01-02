#include <stdio.h>
#include "random.h"
#include "printarray.h"

int *arr;
static unsigned int size;

void shift_element(unsigned int i)
{
	int ivalue;
	for(ivalue = arr[i]; i && arr[i-1] > ivalue; i--)
		arr[i] = arr[i-1];
	arr[i] = ivalue;
}

void shift_element_p(int *pElement)
{
	int ivalue;
	for(ivalue = *pElement; *(pElement-1) > ivalue && pElement > arr; pElement--)
		*pElement = *(pElement-1);
	*pElement = ivalue;
}

void insertion_sort()
{
	unsigned int i;
	for(i=1; i < size; i++)
		if(arr[i] < arr[i-1])
			shift_element(i);
}

void insertion_sort_p()
{
	int *pElement = arr;
	for(int i = 0; i < size; pElement++, ++i)
	{
		if(*pElement < *(pElement+1))
			shift_element_p(pElement);
	}
}

int main()
{
	unsigned int seed;
	scanf("%d%d", &size, &seed);
	arr = fill_array(seed, size);
	print_array(arr, size);
	//shift_element(5);
	//shift_element_p(&arr[1]);
	insertion_sort_p();
	print_array(arr, size);
	return 0;
}
