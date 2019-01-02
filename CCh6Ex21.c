#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

unsigned char is_palindrome(char *c);
char* remove_spaces(char *c);
int count_spaces(const char *str);

int main()
{
	char *c = "A man a plan a canal Panama";
	c = remove_spaces(c);
	printf("%d\n", is_palindrome(c));
	return 0;
}

unsigned char is_palindrome(char *c)
{
	unsigned int length = strlen(c), limit = length/2, counter = 0;
	for(; counter < limit; ++counter)
		if(toupper(c[counter]) != toupper(c[length-counter-1]))
			return 0;
	return 1;
}

char* remove_spaces(char *str)
{
	unsigned int counter = 0;
	char* c = (char*) malloc((strlen(str)-count_spaces(str)+1) * sizeof(char));
	while(str[0] != 0)
	{
		if(!isspace(str[0]))
			c[counter++]  = str[0];
		str++;
	}
	return c;
}

int count_spaces(const char *str)
{
		int count = 0;
		char c ;
		while((c = *str++) != 0)
			if (c == ' ')
				count++ ;
		return count ;
}
