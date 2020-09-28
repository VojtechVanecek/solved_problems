// DIVSUM - Divisor Summation

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 500001

int main(void){
	
	unsigned int *precomp = (unsigned int *)malloc(sizeof(unsigned int) * MAX);
	memset(precomp, 0, sizeof(unsigned int) * 2);
	
	for(int i = 2; i < MAX; i++)
		precomp[i] = 1;
	
	for(int i = 2; i < MAX; i++)
		for(int j = i + i; j < MAX; j += i)
			precomp[j] += i;

	unsigned int input, casesCount;
	scanf("%u", &casesCount);

	while(casesCount--){

		scanf("%u", &input);
		printf("%u\n", precomp[input]);
	
	}

	free(precomp);
	return EXIT_SUCCESS;
}
