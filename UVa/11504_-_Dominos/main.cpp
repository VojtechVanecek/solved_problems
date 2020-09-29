// 11504 - Dominos

#include <bits/stdc++.h>

void dfs(unsigned int start, bool *visited, std::vector<unsigned int> adj[],
         std::deque<unsigned int> &order);
void dfs_(unsigned int start, bool *visited, std::vector<unsigned int> adj[]);
bool visited_all(bool *visited, unsigned int size);
int main(void) {

  unsigned int cases_cnt;
  if (!(scanf("%u", &cases_cnt))) {
    return -1;
  }
  while (cases_cnt--) {
    unsigned int vertex_cnt, edges_cnt;
    if (!(scanf("%u %u", &vertex_cnt, &edges_cnt))) {
      return -1;
    }
    std::vector<unsigned int> adj[vertex_cnt + 1];

    unsigned int from, to;
    for (unsigned int i = 0; i < edges_cnt; i++) {
      if (!(scanf("%u %u", &from, &to))) {
        return -1;
      }
      adj[from].push_back(to);
    }

    bool *visited = (bool *)malloc(sizeof(bool) * (vertex_cnt + 1));
    memset(visited, false, sizeof(bool) * (vertex_cnt + 1));
    std::deque<unsigned int> order;

    for (unsigned int i = 1; i <= vertex_cnt; i++) {
      if (!(visited[i])) {
        // dfs
        dfs(i, visited, adj, order);
      }
    }

    memset(visited, false, sizeof(bool) * (vertex_cnt + 1));
    unsigned int scc_cnt = 0;

    while (true) {

      while (visited[order.back()]) {
        order.pop_back();
      }

      dfs_(order.back(), visited, adj);
      scc_cnt++;

      if (visited_all(visited, vertex_cnt + 1)) {
        break;
      }
    }

    printf("%u\n", scc_cnt);
    free(visited);
  }

  return 0;
}
void dfs(unsigned int start, bool *visited, std::vector<unsigned int> adj[],
         std::deque<unsigned int> &order) {
  if (visited[start])
    return;
  visited[start] = true;

  for (auto u : adj[start]) {
    dfs(u, visited, adj, order);
  }
  order.push_back(start);
}
void dfs_(unsigned int start, bool *visited, std::vector<unsigned int> adj[]) {

  if (visited[start])
    return;
  visited[start] = true;

  for (auto u : adj[start]) {
    dfs_(u, visited, adj);
  }
}
bool visited_all(bool *visited, unsigned int size) {
  for (unsigned int i = 1; i < size; i++) {
    if (!(visited[i])) {
      return false;
    }
  }
  return true;
}

