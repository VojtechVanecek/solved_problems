// 11838 - Come and Go

#include <bits/stdc++.h>

#include <deque>
#include <vector>

void dfs_order(unsigned int start, bool *visited,
               std::vector<unsigned int> adj[],
               std::deque<unsigned int> &order);
void dfs(unsigned int start, bool *visited, std::vector<unsigned int> adj[]);

int main(void) {

  unsigned int edges_cnt, vertex_cnt;

  while (scanf("%u%u", &vertex_cnt, &edges_cnt)) {

    if ((edges_cnt == 0) && (vertex_cnt == 0)) {
      break;
    }

    std::vector<unsigned int> adj[vertex_cnt + 1];
    std::vector<unsigned int> adj_rev[vertex_cnt + 1];

    unsigned int from = 0, to = 0, traj = 0;
    for (unsigned int i = 0; i < edges_cnt; i++) {
      if (!(scanf("%u%u%u", &from, &to, &traj))) {
        return -1;
      }
      if (traj == 2) {
        adj[to].push_back(from);
        adj_rev[from].push_back(to);
      }
      adj[from].push_back(to);
      adj_rev[to].push_back(from);
    }
    bool *visited = (bool *)malloc(sizeof(bool) * (vertex_cnt + 1));
    memset(visited, false, sizeof(bool) * (vertex_cnt + 1));
    std::deque<unsigned int> order;

    for (unsigned int i = 1; i <= vertex_cnt; i++) {
      if (!(visited[i])) {
        // dfs + ordering
        dfs_order(i, visited, adj, order);
      }
    }

    memset(visited, false, sizeof(bool) * (vertex_cnt + 1));

    dfs(order.back(), visited, adj_rev);

    bool possible = true;

    for (unsigned int i = 1; i <= vertex_cnt; i++) {
      if (!(visited[i])) {
        possible = false;
        break;
      }
    }

    printf("%c\n", (possible) ? '1' : '0');

    free(visited);
  }

  return 0;
}
void dfs_order(unsigned int start, bool *visited,
               std::vector<unsigned int> adj[],
               std::deque<unsigned int> &order) {
  if (visited[start])
    return;
  visited[start] = true;

  for (auto u : adj[start]) {

    dfs_order(u, visited, adj, order);
  }
  order.push_back(start);
}
void dfs(unsigned int start, bool *visited, std::vector<unsigned int> adj[]) {

  if (visited[start])
    return;
  visited[start] = true;

  for (auto u : adj[start]) {

    dfs(u, visited, adj);
  }
}

