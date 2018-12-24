#include <stdio.h>

int main()
{
	int i = 1, j = 2, *p, *q;
	p = &i; //legal
	q = &j; //legal
	printf("i: %d\nj: %d\np: %d\nq: %d\n", i, j, *p, *q);

	p = &*&i; //legal
	printf("i: %d\nj: %d\np: %d\nq: %d\n", i, j, *p, *q);

	i = (int)p; //illegal
	printf("i: %d\nj: %d\np: %d\nq: %d\n", i, j, *p, *q);

	q = &p; //illegal
	printf("i: %d\nj: %d\np: %d\nq: %d\n", i, j, *p, *q);

	*q = &j; //illegal
	printf("i: %d\nj: %d\np: %d\nq: %d\n", i, j, *p, *q);

	//i = (*&)j; //illegal
	i = *&*&j;
	printf("i: %d\nj: %d\np: %d\nq: %d\n", i, j, *p, *q);

	q = &j;
	i = *p++ + *q;
	printf("i: %d\nj: %d\np: %d\nq: %d\n", i, j, *p, *q);
	return 0;
}
