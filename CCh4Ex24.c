#include <stdio.h>
#include <math.h>

int main()
{
	int a, b, c;
	double discriminant;
	printf("ax^2 + bx + c\n");
	printf("enter a, b, c respectively: ");
	scanf("%d %d %d", &a, &b, &c);
	if(a==0)
		if(b==0)
			printf("extremely degenerate\n");
		else
			printf("root: %lf\n", -(double)c / b);
	else
	{
		discriminant =  b * b - 4 * a * c;
		if(discriminant == 0)
			printf("root: %lf\n", -(double)b * 1 / 2 / a);
		else if (discriminant > 0)
			printf("root1: %lf\t root2: %lf\n", (-b + sqrt(discriminant)) * 1 / 2 / a, (-b - sqrt(discriminant)) * 1 / 2 / a);
		else
			printf("degenerate two complex roots multiple real roots");
	}
	return 0;
}
