#include <stdio.h>

void* print_array(int *array, int SIZE)
{
        printf("Array: ");
        for(int i = 0; i < SIZE; ++i)
                printf("%d\t", *(array  + i));
        printf("\n");
}

