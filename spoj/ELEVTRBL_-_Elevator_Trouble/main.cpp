// ELEVTRBL - Elevator Trouble

#include <bits/stdc++.h>

#include <queue>

#define MAX 1000001

int main(void) {

  int floor_cnt, start, dest, up, down;

  if (!(scanf("%d%d%d%d%d", &floor_cnt, &start, &dest, &up, &down))) {
    exit(1);
  }

  bool *visited = (bool *)malloc(sizeof(bool) * (floor_cnt + 1));
  int *distance = (int *)malloc(sizeof(int) * (floor_cnt + 1));
  memset(visited, false, sizeof(bool) * (floor_cnt + 1));

  visited[start] = true;
  distance[start] = 0;

  std::queue<int> q;
  q.push(start);

  int curr;

  while (!(q.empty())) {

    curr = q.front();
    q.pop();

    if (((curr + up) <= floor_cnt) && (!(visited[(curr + up)]))) {
      visited[(curr + up)] = true;
      distance[(curr + up)] = distance[curr] + 1;
      q.push((curr + up));
    }

    if (((curr - down) > 0) && (!(visited[(curr - down)]))) {
      visited[(curr - down)] = true;
      distance[(curr - down)] = distance[curr] + 1;
      q.push((curr - down));
    }

    if (visited[dest]) {
      break;
    }
  }

  if (visited[dest]) {
    printf("%u\n", distance[dest]);
  } else {

    printf("use the stairs\n");
  }

  free(distance);
  free(visited);

  return 0;
}

