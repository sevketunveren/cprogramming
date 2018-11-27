#include <stdio.h>
#define FED_TAX 0.17
#define STATE_TAX 0.03

int main()
{
	double salary_sum = 0;
	double salary;
	while (scanf("%lf", &salary)==1)
	{
		salary_sum += salary;
		printf("Salary: %lf\nFederal Tax %lf\nState Tax: %lf\n", salary, salary*FED_TAX, salary*STATE_TAX);
	}
	printf("Total Salary: %lf\nTotal Federal Tax %lf\nTotal State Tax: %lf\n", salary_sum, salary_sum*FED_TAX, salary_sum*STATE_TAX);
	return 0;
}
