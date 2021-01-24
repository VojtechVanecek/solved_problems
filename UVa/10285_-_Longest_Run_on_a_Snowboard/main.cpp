#include <bits/stdc++.h>

#define STR_MAX 100

int dir_v[] = {1, -1, 0, 0};
int dir_h[] = {0, 0, -1, 1};

void dfs(unsigned int start, bool *visited, std::vector<unsigned int> adj[],
         std::stack<unsigned int> &topol_sort);
int main(void) {

  unsigned int cases_cnt;
  if (!(scanf("%u", &cases_cnt))) {
    return (1);
  }

  char *name = (char *)malloc(sizeof(char) * STR_MAX);
  unsigned int row_cnt = 0, column_cnt = 0;

  while (cases_cnt--) {

    memset(name, '\0', sizeof(char) * STR_MAX);
    getchar();
    char temp;
    unsigned int str_cnt = 0;
    while ((temp = getchar()) && (temp != ' ')) {
      name[str_cnt++] = temp;
    }

    if (!(scanf("%u %u", &row_cnt, &column_cnt))) {
      return (1);
    }

    unsigned int **grid =
        (unsigned int **)malloc(sizeof(unsigned int *) * (row_cnt + 2));
    for (unsigned int i = 0; i < (row_cnt + 2); i++) {
      grid[i] = (unsigned int *)malloc(sizeof(unsigned int) * (column_cnt + 2));
      grid[i][0] = UINT_MAX;
      grid[i][(column_cnt + 1)] = UINT_MAX;
    }
    memset(grid[0], UINT_MAX, sizeof(unsigned int) * (column_cnt + 2));
    memset(grid[(row_cnt + 1)], UINT_MAX,
           sizeof(unsigned int) * (column_cnt + 2));

    for (unsigned int i = 1; i < (row_cnt + 1); i++) {
      for (unsigned int j = 1; j < (column_cnt + 1); j++) {
        if (!(scanf("%u", &grid[i][j]))) {
          return (1);
        }
      }
    }

    // create graph
    std::vector<unsigned int> adj[(column_cnt) * (row_cnt) + 1];
    std::vector<unsigned int> adj_rev[(column_cnt) * (row_cnt) + 1];

    for (unsigned int i = 1; i < (row_cnt + 1); i++) {
      for (unsigned int j = 1; j < (column_cnt + 1); j++) {
        for (unsigned int k = 0; k < 4; k++) {
          if (grid[i][j] > grid[i + dir_v[k]][j + dir_h[k]]) {
            adj[j + ((i - 1) * column_cnt)].push_back(
                (j + dir_h[k]) + (((i + dir_v[k]) - 1) * column_cnt));
            adj_rev[(j + dir_h[k]) + (((i + dir_v[k]) - 1) * column_cnt)]
                .push_back(j + ((i - 1) * column_cnt));
          }
        }
      }
    }

    // topological sort (extended dfs)
    unsigned int *sorted =
        (unsigned int *)malloc(sizeof(unsigned int) * ((column_cnt * row_cnt)));
    unsigned int *sorted_idx = (unsigned int *)malloc(
        sizeof(unsigned int) * ((column_cnt * row_cnt) + 2));
    std::stack<unsigned int> topol_sort;
    bool *visited = (bool *)malloc(sizeof(bool) * ((column_cnt * row_cnt) + 1));
    memset(visited, false, sizeof(bool) * ((column_cnt * row_cnt) + 1));

    for (unsigned int i = 1; i <= (column_cnt * row_cnt); i++) {
      if (!(visited[i])) {
        dfs(i, visited, adj, topol_sort);
      }
    }

    for (unsigned int i = 0; !(topol_sort.empty()); i++) {
      sorted[i] = topol_sort.top();
      sorted_idx[topol_sort.top()] = i;
      topol_sort.pop();
    }

    // dp
    unsigned int *dp =
        (unsigned int *)malloc(sizeof(unsigned int) * (column_cnt * row_cnt));
    memset(dp, 0, sizeof(unsigned int) * (column_cnt * row_cnt));

    unsigned int all_max = 0;
    for (unsigned int i = 0; i < (column_cnt * row_cnt); i++) {
      for (unsigned int j = 0; j < adj_rev[sorted[i]].size(); j++) {
        dp[i] = std::max(dp[i], dp[sorted_idx[adj_rev[sorted[i]].at(j)]] + 1);
      }
      all_max = std::max(dp[i], all_max);
    }

    printf("%s: %u\n", name, (all_max + 1));
    free(dp);
    free(sorted);
    free(sorted_idx);
    free(visited);
    for (unsigned int i = 0; i < (row_cnt + 2); i++) {
      free(grid[i]);
    }
    free(grid);
  }

  free(name);
  return (0);
}
void dfs(unsigned int start, bool *visited, std::vector<unsigned int> adj[],
         std::stack<unsigned int> &topol_sort) {

  visited[start] = true;

  for (auto u : adj[start]) {
    if (!(visited[u])) {
      dfs(u, visited, adj, topol_sort);
    }
  }

  topol_sort.push(start);
}

