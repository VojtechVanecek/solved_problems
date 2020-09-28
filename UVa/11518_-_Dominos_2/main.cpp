// 11518 - Dominos 2

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

void dfs(unsigned int start, bool *visited, std::vector<unsigned int> adj[]);
int main(void) {

  unsigned int num_of_cases, num_of_dom, num_of_edges, num_of_start;
  scanf("%u", &num_of_cases);
  while (num_of_cases--) {

    scanf("%u%u%u", &num_of_dom, &num_of_edges, &num_of_start);
    std::vector<unsigned int> adj[num_of_dom + 1];

    unsigned int from, to;
    for (unsigned int i = 0; i < num_of_edges; i++) {
      scanf("%u %u", &from, &to);
      adj[from].push_back(to);
    }

    unsigned int starting_node = 0;
    bool *visited_all = (bool *)malloc(sizeof(bool) * (num_of_dom + 1));
    memset(visited_all, false, sizeof(bool) * (num_of_dom + 1));

    bool *visited = (bool *)malloc(sizeof(bool) * (num_of_dom + 1));
    for (unsigned int i = 0; i < num_of_start; i++) {
      scanf("%u", &starting_node);

      memset(visited, false, sizeof(bool) * (num_of_dom + 1));
      // dfs
      dfs(starting_node, visited, adj);

      for (unsigned int j = 1; j <= num_of_dom; j++) {

        if (visited[j] && (!(visited_all[j]))) {
          visited_all[j] = true;
        }
      }
    }

    // count
    unsigned int count = 0;
    for (unsigned int i = 1; i <= num_of_dom; i++)
      count = (visited_all[i]) ? (count + 1) : count;
    printf("%u\n", count);

    free(visited_all);
    free(visited);
  }

  return (EXIT_SUCCESS);
}
void dfs(unsigned int start, bool *visited, std::vector<unsigned int> adj[]) {

  if (visited[start])
    return;
  visited[start] = true;

  for (unsigned int i = 0; i < adj[start].size(); i++) {
    dfs(adj[start].at(i), visited, adj);
  }
}
