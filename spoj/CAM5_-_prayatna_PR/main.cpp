// CAM5 - prayatna PR

#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include <vector>

bool vis_all(bool *visited, unsigned int size);
void dfs(unsigned int start, bool *visited, std::vector<unsigned int> adj[]);
int main(void) {

  unsigned int cases_cnt;
  scanf("%u", &cases_cnt);

  unsigned int vertex_cnt, edges_cnt;

  while (cases_cnt--) {
    scanf("%u %u", &vertex_cnt, &edges_cnt);

    std::vector<unsigned int> adj[vertex_cnt];

    unsigned int from, to;
    for (unsigned int i = 0; i < edges_cnt; i++) {
      scanf("%u %u", &from, &to);
      adj[from].push_back(to);
      adj[to].push_back(from);
    }

    bool *visited = (bool *)malloc(sizeof(bool) * vertex_cnt);
    memset(visited, false, sizeof(bool) * vertex_cnt);

    unsigned int component_cnt = 0;

    while (!(vis_all(visited, vertex_cnt))) {

      for (unsigned int i = 0; i < vertex_cnt; i++) {
        if (!(visited[i])) {
          component_cnt++;
          dfs(i, visited, adj);
        }
      }
    }
    printf("%u\n", component_cnt);
  }
  return 0;
}

void dfs(unsigned int start, bool *visited, std::vector<unsigned int> adj[]) {

  if (visited[start])
    return;
  visited[start] = true;

  for (auto u : adj[start]) {
    dfs(u, visited, adj);
  }
}

bool vis_all(bool *visited, unsigned int size) {

  for (unsigned int j = 0; j < size; j++) {
    if (!(visited[j]))
      return false;
  }
  return true;
}

