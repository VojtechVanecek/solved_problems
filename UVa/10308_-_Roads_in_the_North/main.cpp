// 10308 - Roads in the North

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <sstream>
#include <utility>
#include <vector>

#define N 10000

std::vector<std::pair<int, int>> adj[N];
bool *visited = (bool *)malloc(sizeof(bool) * N);
int *distance = (int *)malloc(sizeof(int) * N);
int startAt;

int main(void) {
  std::ios::sync_with_stdio(false);
  int from, to, len;
  std::string input;

  while (!(std::cin.eof())) {

    memset(visited, false, sizeof(bool) * N);
    memset(distance, 0, sizeof(int) * N);
    for (int i = 0; i < N; i++)
      adj[i].clear();

    getline(std::cin, input);

    while ((input.length() > 0) && (!(std::cin.eof()))) {

      std::stringstream ss;
      ss << input;
      ss >> from >> to >> len;

      adj[from].push_back({to, len});
      adj[to].push_back({from, len});
      getline(std::cin, input);
    }

    startAt = 0;
    for (int i = 0; i < N; i++) {
      if (!(adj[i].empty())) {
        startAt = i;
        break;
      }
    }

    // bfs
    std::queue<int> q;
    distance[startAt] = 0;
    visited[startAt] = true;

    q.push(startAt);
    while (!q.empty()) {
      int s = q.front();
      q.pop();
      // process node s
      for (auto u : adj[s]) {
        if (visited[u.first])
          continue;
        visited[u.first] = true;
        distance[u.first] = distance[s] + u.second;
        q.push(u.first);
      }
    }

    // find maximum
    int max = 0;
    for (int i = 0; i < N; i++) {
      if (!(adj[i].empty())) {
        max = (distance[i] > distance[max] ? i : max);
      }
    }

    // clear
    memset(visited, false, sizeof(bool) * N);
    memset(distance, 0, sizeof(int) * N);

    // bfs
    distance[max] = 0;
    visited[max] = true;
    q.push(max);
    while (!q.empty()) {
      int s = q.front();
      q.pop();
      // process node s
      for (auto u : adj[s]) {
        if (visited[u.first])
          continue;
        visited[u.first] = true;
        distance[u.first] = distance[s] + u.second;
        q.push(u.first);
      }
    }

    max = 0;
    for (int i = 0; i < N; i++) {
      if (!(adj[i].empty())) {
        max = (max < distance[i]) ? distance[i] : max;
      }
    }

    printf("%d\n", max);
  }
  free(visited);
  free(distance);
  return EXIT_SUCCESS;
}

