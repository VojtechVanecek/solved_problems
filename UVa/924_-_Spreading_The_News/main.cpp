// 924 - Spreading The News

#include <bits/stdc++.h>

int main(void) {

  unsigned int vertex_cnt;
  if (!(scanf("%u", &vertex_cnt))) {
    return (1);
  }

  std::vector<unsigned int> adj[vertex_cnt];

  unsigned int friend_id;
  unsigned int friend_cnt;
  for (unsigned int i = 0; i < vertex_cnt; i++) {
    if (!(scanf("%u", &friend_cnt))) {
      return (1);
    }
    for (unsigned int j = 0; j < friend_cnt; j++) {
      if (!(scanf("%u", &friend_id))) {
        return (1);
      }
      adj[i].push_back(friend_id);
    }
  }

  unsigned int cases_cnt;
  if (!(scanf("%u", &cases_cnt))) {
    return (1);
  }

  unsigned int *src = (unsigned int *)malloc(sizeof(unsigned int) * cases_cnt);
  for (unsigned int i = 0; i < cases_cnt; i++) {
    if (!(scanf("%u", &src[i]))) {
      return (1);
    }
  }

  bool *visited = (bool *)malloc(sizeof(bool) * vertex_cnt);
  unsigned int *time_ack =
      (unsigned int *)malloc(sizeof(unsigned int) * vertex_cnt);
  unsigned int *max_boom =
      (unsigned int *)malloc(sizeof(unsigned int) * vertex_cnt);
  std::queue<unsigned int> q;

  for (unsigned int i = 0; i < cases_cnt; i++) {
    memset(visited, false, sizeof(bool) * vertex_cnt);
    memset(time_ack, 0, sizeof(unsigned int) * vertex_cnt);
    memset(max_boom, 0, sizeof(unsigned int) * vertex_cnt);

    visited[src[i]] = true;
    q.push(src[i]);

    while (!(q.empty())) {

      unsigned int curr = q.front();
      q.pop();

      for (auto u : adj[curr]) {
        if (!(visited[u])) {
          visited[u] = true;
          time_ack[u] = time_ack[curr] + 1;
          q.push(u);
        }
      }
    }

    for (unsigned int j = 0; j < vertex_cnt; j++) {
      max_boom[time_ack[j]]++;
    }
    unsigned int boom_cnt = 0, boom_time = 0;
    for (unsigned int j = 1; j < vertex_cnt; j++) {
      if (max_boom[j] > boom_cnt) {
        boom_cnt = max_boom[j];
        boom_time = j;
      }
    }

    if (boom_cnt) {
      printf("%u %u\n", boom_cnt, boom_time);
    } else {
      puts("0");
    }
  }

  free(max_boom);
  free(time_ack);
  free(visited);
  free(src);
  return (0);
}

