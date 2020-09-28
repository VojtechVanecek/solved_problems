// APS - Amazing Prime Sequence

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARR 10000001

int main(void) {

  unsigned long long int *lpf = (unsigned long long int *)malloc(
      sizeof(unsigned long long int) * MAX_ARR);
  memset(lpf, 0, sizeof(int) * MAX_ARR);

  lpf[1] = 0;
  for (unsigned long long int i = 2; i < MAX_ARR; i++)
    if (lpf[i] == 0)
      for (unsigned long long int j = i; j < MAX_ARR; j += i)
        if (lpf[j] == 0)
          lpf[j] = i;

  unsigned long long int *ans = (unsigned long long int *)malloc(
      sizeof(unsigned long long int) * MAX_ARR);

  ans[1] = 0;
  for (unsigned long long int i = 2; i < MAX_ARR; i++) {
    ans[i] = ans[i - 1] + lpf[i];
  }

  unsigned long long int casesCount, input;
  scanf("%llu", &casesCount);

  while (casesCount--) {
    scanf("%llu", &input);
    printf("%llu\n", ans[input]);
  }

  free(ans);
  free(lpf);
  return EXIT_SUCCESS;
}

