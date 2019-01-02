#include <stdio.h>
#include <string.h>

void reverse(char *s);

int main()
{
	char *str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum";
	reverse(str);
	str++;
	printf("%s\n", str);
	return 0;
}

void reverse(char *s)
{
	char *q, temp;
	int n;
	n = strlen(s);
	q = s + n - 1;
	for(s; s < q; ++s, --q)
	{
		temp = *s;
		*s = *q;
		*q = temp;
		printf("%s\n", s);
		scanf("%d",&n);
	}
}
