// 674 - Coin Change
// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=615
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 7491
#define COIN_CNT 5

int main(void) {

  int coins[] = {1, 5, 10, 25, 50};
  int *dp = (int *)malloc(sizeof(int) * MAX_SIZE);
  for (int i = 0; i < MAX_SIZE; i++) {
    dp[i] = 1;
  }

  for (int i = 1; i < COIN_CNT; i++) {
    for (int j = 0; j < MAX_SIZE; j++) {
      if (coins[i] < j) {
        dp[j] += dp[j - coins[i]];
      }
    }
  }

  unsigned int in;
  while (scanf("%u", &in) != EOF) {
    printf("%d\n", dp[in + 1]);
  }

  free(dp);
  return (0);
}

