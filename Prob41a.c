#include <stdio.h>
#include "random.h"
#include "printarray.h"

int *arr;

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
	for(ivalue = *pElement; *(pElement-1) > ivalue && pElement != 0; pElement--)
	{
		*pElement = *(pElement-1);
	}
	*pElement = ivalue;
}

int main()
{
	unsigned int size, seed;
	scanf("%d%d", &size, &seed);
	arr = fill_array(seed, size);
	print_array(arr, size);
	//shift_element(5);
	shift_element_p(&arr[5]);
	print_array(arr, size);
	return 0;
}
