// DCEPC501 - Save Thy Toys

#include <malloc.h>
#include <stdio.h>
#include <string.h>

#define ull unsigned long long
#define MAX 100100

ull int findMax(ull int a, ull int b);
int main(void) {

  unsigned int cases_cnt;
  scanf("%u", &cases_cnt);

  unsigned int *toy_val = (unsigned int *)malloc(sizeof(unsigned int));

  unsigned long long int *dp =
      (unsigned long long int *)malloc(sizeof(unsigned long long int));

  unsigned int toys_cnt;
  while (cases_cnt--) {

    scanf("%u", &toys_cnt);
    toy_val = (unsigned int *)realloc(toy_val, sizeof(unsigned int) * (MAX));

    for (unsigned int j = 0; j < MAX; j++)
      toy_val[j] = 0;

    for (unsigned int i = 0; i < toys_cnt; i++) {
      scanf("%u", &toy_val[i]);
    }

    dp = (ull int *)realloc(dp, sizeof(ull int) * (MAX));
    for (unsigned int j = 0; j < MAX; j++)
      dp[j] = 0;

    unsigned int i = toys_cnt;

    do {
      i--;
      dp[i] = findMax(
          toy_val[i] + dp[i + 2],
          findMax(toy_val[i] + toy_val[i + 1] + dp[i + 4],
                  toy_val[i] + toy_val[i + 1] + toy_val[i + 2] + dp[i + 6]));

    } while (i);

    printf("%llu\n", dp[0]);
  }

  free(toy_val);
  free(dp);

  return 0;
}
ull int findMax(ull int a, ull int b) {

  if (a >= b) {
    return a;
  } else {
    return b;
  }
}

