// 10099 - The Tourist Guide

#include <bits/stdc++.h>

int main(void) {

  unsigned int vertex_cnt, edges_cnt;
  unsigned int cases_cnt = 0;

  while ((scanf("%u%u", &vertex_cnt, &edges_cnt)) &&
         ((vertex_cnt != 0) && (edges_cnt != 0))) {

    int **dp = (int **)malloc(sizeof(int *) * (vertex_cnt + 1));

    for (unsigned int i = 0; i <= vertex_cnt; i++) {
      dp[i] = (int *)malloc(sizeof(int) * (vertex_cnt + 1));
      memset(dp[i], -1, sizeof(int) * (vertex_cnt + 1));
      dp[i][i] = 0;
    }

    int from, to, cost;
    for (unsigned int i = 0; i < edges_cnt; i++) {

      if (!(scanf("%d%d%d", &from, &to, &cost))) {
        return -1;
      }

      dp[from][to] = cost - 1;
      dp[to][from] = cost - 1;
    }
    int start, end, tourist_cnt;
    if (!(scanf("%d%d%d", &start, &end, &tourist_cnt))) {
      return -1;
    }
    // dp
    for (unsigned int k = 1; k <= vertex_cnt; k++) {
      for (unsigned int i = 1; i <= vertex_cnt; i++) {
        for (unsigned int j = 1; j <= vertex_cnt; j++) {

          dp[i][j] = std::max(dp[i][j], std::min(dp[i][k], dp[k][j]));
        }
      }
    }
    printf("Scenario #%u\nMinimum Number of Trips = %u\n\n", ++cases_cnt,
           (unsigned int)ceil((float)tourist_cnt / float(dp[start][end])));
  }
  return 0;
}

