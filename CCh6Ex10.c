#include <stdio.h>

void change_it(int a[])
{
	int i = 777, *q = &i;
	a = q; //q will die after exiting scope so it will not influence a
}

int main(void)
{
	int a[5], *p;
	p = a;
	printf("p has the value %p\n",p);
	change_it(a);
	p = a;
	printf("p has the value %p\n%d\n",p, *p);
	return 0;
}
