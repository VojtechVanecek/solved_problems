#include <bits/stdc++.h>

int main(void) {

  unsigned int cases_cnt;
  if (!(scanf("%u", &cases_cnt))) {
    return (1);
  }

  unsigned int *gold_cnt = (unsigned int *)malloc(sizeof(unsigned int));
  unsigned long long int *dp =
      (unsigned long long int *)malloc(sizeof(unsigned long long int));

  unsigned int mon_cnt;
  unsigned int loop_cnt = 1;
  while (cases_cnt--) {

    if (!(scanf("%u", &mon_cnt))) {
      return (1);
    }

    gold_cnt =
        (unsigned int *)realloc(gold_cnt, sizeof(unsigned int) * mon_cnt);
    dp = (unsigned long long int *)realloc(dp, sizeof(unsigned long long int) *
                                                   (mon_cnt + 2));
    dp[0] = 0;
    dp[1] = 0;

    for (unsigned int i = 0; i < mon_cnt; i++) {
      if (!(scanf("%u", &gold_cnt[i]))) {
        return (1);
      }
    }

    for (unsigned int i = 2, j = 0; i < (mon_cnt + 2); i++, j++) {
      dp[i] = std::max(dp[i - 2] + gold_cnt[j], dp[i - 1]);
    }

    printf("Case %u: %llu\n", loop_cnt++, dp[mon_cnt + 1]);
  }

  free(gold_cnt);
  free(dp);

  return (0);
}

