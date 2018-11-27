#include <stdio.h>

unsigned long compute_next(unsigned long);

int main()
{
	unsigned long i = 1;
	while(1)
		if(compute_next(i++)!=1)
			printf("ATTENTION!\nHailstone controvension\n");
	return 0;
}

unsigned long compute_next(unsigned long current)
{
	printf("%ld\n", current);
	if(current==1)
		return 1;
	else if(current%2==0)
		return compute_next(current/2);
	else
		return compute_next(current*3+1);
}
