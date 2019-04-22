#include <stdio.h>
#include <math.h>

#define SQ1(x) ((x)*(x))
#define SQ2(x) x*x
#define CUBE(x) (SQ1(x)*(x))
#define F_POW(x) sqrt(sqrt(CUBE(x))) /* fractional power: 3/4)*/
int main()
{
	int i = SQ1(5+7);
	double d;
	printf("%d\n", i);
	i = SQ2(5+7); // 5+7*5+7
	printf("%d\n", i);
	i = 144/SQ1(5+7); // 144/((5+7)*(5+7))
	printf("%d\n", i);
	i = 144/SQ2(5+7);
	printf("%d\n", i);// 144/5+7*5+7
	/***************************************/
	i = CUBE(4);
	printf("%d\n", i);
	d = F_POW(16);
	printf("%lf\n", d);
}
