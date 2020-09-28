// 11709 - Trust groups

#include <bits/stdc++.h>
#include <stdio.h>

#include <algorithm>
#include <vector>

std::vector<unsigned int> order;

void dfs(unsigned int start, bool *visited, std::vector<unsigned int> adj[]);
void plain_dfs(unsigned int start, bool *visited,
               std::vector<unsigned int> adj[]);
bool visited_all(bool *visited, unsigned int size);
int main(void) {

  unsigned int vertex_cnt, edge_cnt;

  while ((scanf("%u%u", &vertex_cnt, &edge_cnt))) {

    if ((vertex_cnt == 0) && (edge_cnt == 0))
      break;

    std::map<std::string, unsigned int> dict;
    std::string in;

    getline(std::cin, in);
    for (unsigned int i = 0; i < vertex_cnt; i++) {

      getline(std::cin, in);
      dict[in] = i;
    }

    unsigned int from_idx, to_idx;

    std::vector<unsigned int> adj[vertex_cnt];
    std::vector<unsigned int> reversed[vertex_cnt];
    for (unsigned int i = 0; i < edge_cnt; i++) {
      getline(std::cin, in);
      from_idx = dict[in];

      getline(std::cin, in);
      to_idx = dict[in];

      adj[from_idx].push_back(to_idx);
      reversed[to_idx].push_back(from_idx);
    }

    // find number of SCC with Kosaraju alg
    bool *visited = (bool *)malloc(sizeof(bool) * vertex_cnt);
    memset(visited, false, sizeof(bool) * vertex_cnt);
    order.clear();

    // first dfs
    for (unsigned int i = 0; i < vertex_cnt; i++) {
      if (!(visited[i])) {
        dfs(i, visited, adj);
      }
    }
    // second dfs
    unsigned int scc_cnt = 0;
    memset(visited, false, sizeof(bool) * vertex_cnt);
    for (unsigned int i = 0; i < vertex_cnt; i++) {

      while (visited[order.back()]) {
        order.pop_back();
      }
      plain_dfs(order.back(), visited, reversed);

      scc_cnt++;
      if (visited_all(visited, vertex_cnt))
        break;
    }

    printf("%u\n", scc_cnt);
    free(visited);
  }

  return (0);
}

void dfs(unsigned int start, bool *visited, std::vector<unsigned int> adj[]) {

  if (visited[start])
    return;
  visited[start] = true;

  for (auto u : adj[start]) {
    dfs(u, visited, adj);
  }
  order.push_back(start);
}
void plain_dfs(unsigned int start, bool *visited,
               std::vector<unsigned int> adj[]) {

  if (visited[start])
    return;
  visited[start] = true;

  for (auto u : adj[start]) {
    plain_dfs(u, visited, adj);
  }
}
bool visited_all(bool *visited, unsigned int size) {

  for (unsigned int i = 0; i < size; i++)
    if (!(visited[i]))
      return false;

  return true;
}

