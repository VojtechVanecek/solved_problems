#include <bits/stdc++.h>

int main(void) {

  unsigned int cases_cnt;
  if (!(scanf("%u", &cases_cnt))) {
    return (1);
  }

  unsigned int *dp = (unsigned int *)malloc(sizeof(unsigned int));
  unsigned int *in_p = (unsigned int *)malloc(sizeof(unsigned int));
  unsigned int *in_w = (unsigned int *)malloc(sizeof(unsigned int));

  unsigned int empty, full, coin_cnt;
  while (cases_cnt--) {

    if (!(scanf("%u %u", &empty, &full)))
      return (1);

    if (!(scanf("%u", &coin_cnt)))
      return (1);

    dp = (unsigned int *)realloc(dp, sizeof(unsigned int) * (full - empty + 1));
    dp[0] = 0;
    in_p = (unsigned int *)realloc(in_p, sizeof(unsigned int) * coin_cnt);
    in_w = (unsigned int *)realloc(in_w, sizeof(unsigned int) * coin_cnt);

    for (unsigned int i = 0; i < coin_cnt; i++) {
      if (!(scanf("%u %u", &in_p[i], &in_w[i])))
        return (1);
    }

    for (unsigned int i = 1; i <= (full - empty); i++) {
      unsigned int min = UINT_MAX;
      for (unsigned int j = 0; j < coin_cnt; j++) {
        min = (i >= in_w[j] && (dp[i - in_w[j]] != UINT_MAX))
                  ? std::min(dp[i - in_w[j]] + in_p[j], min)
                  : min;
      }
      dp[i] = min;
    }

    if (dp[full - empty] != UINT_MAX) {
      printf("The minimum amount of money in the piggy-bank is %u.\n",
             dp[full - empty]);
    } else {
      printf("This is impossible.\n");
    }
  }

  free(in_w);
  free(in_p);
  free(dp);
  return (0);
}

