#include <stdio.h>

int main()
{
	char c;
	int cnt = 0, digit_cnt = 0, i, n, total;
	/*while (c = getchar())*/ while (c = getchar() != 'E')
	{
		/*if (c=='E')
			break;*/
		++cnt;
		if (c >= '0' && c <= '9')
			++digit_cnt;
	}
	printf("%d\t%d\n", cnt, digit_cnt);
	/****************************************************/
	i = -5;
	n = 50;
	while (i < n)
	{
		++i;
		/*if (i == 0)*/ if( i < 0 || i > 0)
			/*continue;*/
		{
			total +=i;
			printf("i = %d and total = %d\n", i, total);
		}
	}
	return 0;
}
