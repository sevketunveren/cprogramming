#include <stdio.h>
#include <time.h>
#define BILLION  1000000000.0;

int main()
{
	int input=612;
	double x0 = 1, x1 = 1;
	struct timespec start, end;
	clock_gettime(CLOCK_REALTIME, &start);
	//printf("Enter sqrt(x) x:");
	//scanf("%d", &input);
	do
	{
		x0 = x1;
		x1 = (x0 + input / x0) / 2;
	}
	while (x0 != x1);
	printf("%.17f", x1);
	clock_gettime(CLOCK_REALTIME, &end);
	double time_spent = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
	printf("Time elpased is %f seconds", time_spent);
	return 0;
}
