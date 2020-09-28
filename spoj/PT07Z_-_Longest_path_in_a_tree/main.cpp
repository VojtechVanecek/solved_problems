// PT07Z - Longest path in a tree

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <list>
#include <queue>
#include <vector>

int main(void) {

  int nN, nA, nB;
  assert(scanf("%d", &nN));

  std::vector<int> adj[(nN + 1)];

  while (scanf("%d %d", &nA, &nB) != EOF) {
    adj[nA].push_back(nB);
    adj[nB].push_back(nA);
  }

  std::queue<int> q;
  bool *visited = (bool *)malloc(sizeof(bool) * (nN + 1));
  int *distance = (int *)malloc(sizeof(int) * (nN + 1));

  memset(visited, false, sizeof(bool) * (nN + 1));
  memset(distance, 0, sizeof(int) * (nN + 1));

  int startAt = 0;
  for (int i = 1; i <= nN; i++)
    if (!adj[i].empty()) {
      startAt = i;
      break;
    }

  visited[startAt] = true;
  distance[startAt] = 0;
  q.push(startAt);

  while (!q.empty()) {

    int s = q.front();
    q.pop();

    for (auto u : adj[s]) {

      if (visited[u])
        continue;
      visited[u] = true;
      distance[u] = distance[s] + 1;
      q.push(u);
    }
  }

  startAt = 0;

  for (int i = 1, j = 0; i <= nN; i++)
    if (j < distance[i]) {
      startAt = i;
      j = distance[i];
    }

  memset(visited, false, sizeof(bool) * (nN + 1));
  memset(distance, 0, sizeof(int) * (nN + 1));

  visited[startAt] = true;
  distance[startAt] = 0;
  q.push(startAt);

  while (!q.empty()) {

    int s = q.front();
    q.pop();

    for (auto u : adj[s]) {

      if (visited[u])
        continue;
      visited[u] = true;
      distance[u] = distance[s] + 1;
      q.push(u);
    }
  }

  int longestPath = 0;
  for (int i = 1; i <= nN; i++)
    longestPath = (longestPath < distance[i]) ? distance[i] : longestPath;
  printf("%d\n", longestPath);

  free(visited);
  free(distance);
  return (EXIT_SUCCESS);
}

