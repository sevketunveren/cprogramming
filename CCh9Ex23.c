/*(Sieve of Eratosthenes) Use an array of structures, where each structure contains a word that is divided into bit fields, to implement the sieve algorithm for primes. On a machine with 4-byte words, we can use an array of 1,000 elements to find all primes less than 32,000. Let each bit represent an integer, and initialize all bits to zero. The idea is to cross out all the multiples of a given prime. A bit that is 1 will represent a composite number. Start with the prime 2. Every second bit is made 1 starting with bit 4. Then bit 3 is still O. Every third bit is made 1, starting with bit 6. Bit 4 is 1, so it is skipped. Bit 5 is the next bit with value O. Every fifth bit is made 1, starting with bit 10. At the end of this process, only those bits that are still zero represent primes.*/
#include <stdio.h>
#include <math.h>
#include "bit_print.h"
#define SIZE 1000

typedef struct {
	unsigned int bits:32;
} word;

unsigned short isTrue(word w, unsigned short index) {
	int n = pow(2, index);
	int r = w.bits & n;
	return r == n;
}

int test_prime(int num) {
	if(num<=1) return 0;
	if(num%2==0 && num > 2) return 0;
	for(int i = 3; i < num/2; i+=2) {
		if(num%i ==0)
			return 0;
	}
	return 1;
}

int main() {
	/*word w = {0};
	w.bits = 486935;
	printf("%d\n", w.bits);
	bit_print_thirty_two(w.bits);
	printf("\n");
	printf("%d\n", isTrue(w, 13));*/
	word words[SIZE] = {0};
	int cnt, j, i = 2;
	words[0].bits = 0;
	while(i < SIZE * 32 / 2) {
		for(cnt = i - 1; cnt + i < 32 * SIZE; cnt = cnt + i)
		{
			if(isTrue(words[i / 32], (i - 1) % 32))
				break;
			else
			{
				if(!isTrue(words[(cnt + i)/32], (cnt + i) % 32)) {
					words[(cnt + i) / 32].bits += (unsigned) pow(2, (cnt + i) % 32);
				}
			}
		}
		++i;
		
	}

	/*for(j = SIZE -1 ; j >= 0; --j)
	{
		bit_print_thirty_two(words[j].bits);
		printf(" ");
	}
	printf("\n");*/
	for(j = 1; j < SIZE * 32; ++j) //1 is not prime
	{
		if(!isTrue(words[j / 32], j % 32))
		{
			printf("Prime: %d\n", j+1);
			if(test_prime(j+1) == 0)
				printf("Fail %d\n", j+1);
		}
	}
	return 0;
}	
