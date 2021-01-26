// 10986 - Sending email

#include <bits/stdc++.h>

#define MAX_C 0x3F3F3F3F

int main(void) {

  unsigned int cases_cnt;
  if (!(scanf("%u", &cases_cnt))) {
    return (1);
  }

  int *dist = (int *)malloc(sizeof(int));
  bool *proc = (bool *)malloc(sizeof(bool));

  unsigned int c_cnt = 1;
  int vertex_cnt, edge_cnt, sender, receiver;
  while (cases_cnt--) {
    if (!(scanf("%d %d %d %d", &vertex_cnt, &edge_cnt, &sender, &receiver))) {
      return (1);
    }

    proc = (bool *)realloc(proc, sizeof(bool) * vertex_cnt);
    dist = (int *)realloc(dist, sizeof(int) * vertex_cnt);

    std::vector<std::pair<unsigned int, unsigned int>> adj[vertex_cnt];
    int from, to, cost;
    for (int i = 0; i < edge_cnt; i++) {
      if (!(scanf("%d %d %d", &from, &to, &cost))) {
        return (1);
      }

      adj[from].push_back({to, cost});
      adj[to].push_back({from, cost});
    }

    // dijkstra
    memset(dist, MAX_C, sizeof(int) * vertex_cnt);
    memset(proc, false, sizeof(bool) * vertex_cnt);
    std::priority_queue<std::pair<int, int>> q;
    dist[sender] = 0;
    q.push({0, sender});
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

    if (dist[receiver] < MAX_C) {
      printf("Case #%u: %d\n", c_cnt++, (dist[receiver]));
    } else {
      printf("Case #%u: unreachable\n", c_cnt++);
    }
  }

  free(dist);
  free(proc);
  return (0);
}

