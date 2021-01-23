#include <bits/stdc++.h>

int main(void) {

  unsigned int events_cnt;
  unsigned int *dp = (unsigned int *)malloc(sizeof(unsigned int));
  unsigned int cases_cnt = 0;

  while (scanf("%u", &events_cnt) != EOF) {

    if (cases_cnt != 0)
      putchar('\n');
    cases_cnt++;

    std::vector<unsigned int> adj[events_cnt];
    std::vector<unsigned int> dead_point;
    dp = (unsigned int *)realloc(dp, sizeof(unsigned int) * events_cnt);
    memset(dp, 0, sizeof(unsigned int) * events_cnt);
    dp[0] = 1;

    for (unsigned int i = 0; i < events_cnt; i++) {
      unsigned int type_cnt, in;
      if (!(scanf("%u", &type_cnt))) {
        return (1);
      }

      if (type_cnt == 0) {
        dead_point.push_back(i);
      }

      for (unsigned int j = 0; j < type_cnt; j++) {
        if (!(scanf("%u", &in))) {
          return 1;
        } else {
          adj[in].push_back(i);
        }
      }
    }

    for (unsigned int i = 1; i < events_cnt; i++) {
      for (unsigned int j = 0; j < adj[i].size(); j++) {
        dp[i] += dp[adj[i].at(j)];
      }
    }

    unsigned int paths_cnt = 0;
    for (unsigned int i = 0; i < dead_point.size(); i++) {
      paths_cnt += dp[dead_point.at(i)];
    }

    printf("%u\n", paths_cnt);
  }

  free(dp);
  return (0);
}

