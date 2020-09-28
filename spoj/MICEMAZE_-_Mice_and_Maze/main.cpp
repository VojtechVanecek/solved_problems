// MICEMAZE - Mice and Maze

#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include <limits>
#include <queue>
#include <utility>
#include <vector>

#define MAX_DIS 0x3F3F3F3F

int main(void) {

  unsigned int cell_cnt, exit_cell, edges_cnt;
  int t_start;

  if (!(scanf("%u %u %d %u", &cell_cnt, &exit_cell, &t_start, &edges_cnt))) {
    return (1);
  }

  std::vector<std::pair<int, int>> adj[cell_cnt + 1];

  int from, to, cost;

  for (unsigned int i = 0; i < edges_cnt; i++) {
    if (!(scanf("%i %i %i", &from, &to, &cost))) {
      return (1);
    }
    adj[from].push_back({to, cost});
    adj[to].push_back({from, cost});
  }

  // dijkstra
  std::priority_queue<std::pair<int, int>> q;

  int *dist = (int *)malloc(sizeof(int) * (cell_cnt + 1));
  memset(dist, MAX_DIS, sizeof(int) * (cell_cnt + 1));

  bool *proc = (bool *)malloc(sizeof(bool) * (cell_cnt + 1));
  memset(proc, false, sizeof(bool) * (cell_cnt + 1));

  dist[exit_cell] = 0;
  q.push({0, exit_cell});

  while (!(q.empty())) {
    int a = q.top().second;
    q.pop();
    if (proc[a])
      continue;
    proc[a] = true;

    for (auto u : adj[a]) {
      int b = u.first;
      int w = u.second;

      if ((dist[a] + w) < dist[b]) {
        dist[b] = dist[a] + w;
        q.push({-dist[b], b});
      }
    }
  }

  unsigned int mice_cnt = 0;

  for (unsigned int i = 1; i <= cell_cnt; i++) {

    if (dist[i] <= t_start)
      mice_cnt++;
  }

  printf("%u\n", mice_cnt);

  free(proc);
  free(dist);
  return 0;
}

