// 10004 - Bicoloring

#include <cstdio>
#include <vector>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

std::vector<int> graph[210];
int isColor, rec[210];

void dfs(int start, int c) {

  if (!isColor)
    return;

  rec[start] = c;

  for (int i = 0; i < graph[start].size(); i++) {

    if (rec[graph[start][i]] == -1)
      dfs(graph[start][i], !c);

    else if (rec[graph[start][i]] == c)
      isColor = 0;
  }
}

int main(void) {
  int n, m, c = 1;
  unsigned int casesCount, nodeNumber;

  while (scanf("%u", &casesCount) && (casesCount != 0)) {

    int a, b;
    for (int i = 0; i <= casesCount; i++) {
      graph[i].clear();
    }
    memset(rec, -1, sizeof(int) * casesCount);

    assert(scanf("%u", &nodeNumber));

    while (nodeNumber--) {

      assert(scanf("%d %d", &a, &b));
      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    isColor = 1;

    dfs(0, 0);

    printf("%s", (isColor) ? "BICOLORABLE.\n" : "NOT BICOLORABLE.\n");
  }
  return (EXIT_SUCCESS);
}

