// 900 - Brick Wall Patterns
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=11&page=show_problem&problem=841
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 51

int main(void) {

  unsigned long int *dp =
      (unsigned long int *)malloc(sizeof(unsigned long int) * MAX_LENGTH);

  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;

  for (unsigned int i = 3; i < MAX_LENGTH; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  unsigned int in;
  while (scanf("%u", &in) && (in != 0)) {
    printf("%lu\n", dp[in]);
  }

  free(dp);
  return (0);
}

