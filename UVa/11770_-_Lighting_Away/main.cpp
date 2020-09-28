// 11770 - Lighting Away

#include <bits/stdc++.h>

std::vector<unsigned int> order;

void dfs_f(unsigned int start, bool *visited, std::vector<unsigned int> adj[]);
void dfs_s(unsigned int start, bool *visited, std::vector<unsigned int> adj[]);
bool vis_all(bool *visited, unsigned int size);
int main(void) {

  unsigned int cases_cnt;
  unsigned int ans_cnt = 0;

  if (!(scanf("%u", &cases_cnt))) {
    return -1;
  }
  unsigned int vertex_cnt, edges_cnt;
  while (cases_cnt--) {
    if (!(scanf("%u %u", &vertex_cnt, &edges_cnt))) {
      return -1;
    }

    std::vector<unsigned int> adj[vertex_cnt + 1];

    unsigned int from, to;
    for (unsigned int i = 0; i < edges_cnt; i++) {
      if (!(scanf("%u%u", &from, &to))) {
        return -1;
      }
      adj[from].push_back(to);
    }

    // first dfs
    bool *visited = (bool *)malloc(sizeof(bool) * (vertex_cnt + 1));
    memset(visited, false, sizeof(bool) * (vertex_cnt + 1));
    order.clear();

    for (unsigned int i = 1; i <= vertex_cnt; i++) {
      if (!(visited[i])) {
        dfs_f(i, visited, adj);
      }
    }

    // second dfs
    unsigned int scc_cnt = 0;
    memset(visited, false, sizeof(bool) * (vertex_cnt + 1));

    for (unsigned int i = 1; i <= vertex_cnt; i++) {
      while (visited[order.back()]) {
        order.pop_back();
      }
      dfs_s(order.back(), visited, adj);
      scc_cnt++;

      if (vis_all(visited, vertex_cnt)) {
        break;
      }
    }
    printf("Case %u: %u\n", ++ans_cnt, scc_cnt);
    free(visited);
  }
  return 0;
}

void dfs_f(unsigned int start, bool *visited, std::vector<unsigned int> adj[]) {
  if (visited[start])
    return;
  visited[start] = true;

  for (auto u : adj[start]) {
    dfs_f(u, visited, adj);
  }
  order.push_back(start);
}
void dfs_s(unsigned int start, bool *visited, std::vector<unsigned int> adj[]) {

  if (visited[start])
    return;
  visited[start] = true;

  for (auto u : adj[start]) {
    dfs_s(u, visited, adj);
  }
}

bool vis_all(bool *visited, unsigned int size) {

  for (unsigned int i = 1; i <= size; i++) {
    if (!(visited[i]))
      return false;
  }
  return true;
}

