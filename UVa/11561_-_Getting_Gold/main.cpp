// 11561 - Getting Gold

#include <bits/stdc++.h>

void dfs(unsigned int start_x, unsigned int start_y, bool **visited,
         char **game);

unsigned int gold_cnt;

int main(void) {

  unsigned int height, width;

  while (scanf("%u%u", &width, &height) != EOF) {
    char **game = (char **)malloc(sizeof(char *) * height);
    bool **visited = (bool **)malloc(sizeof(bool *) * height);

    for (unsigned int i = 0; i < height; i++) {

      game[i] = (char *)malloc(sizeof(char) * (width));
      memset(game[i], '\0', sizeof(char) * (width));
      visited[i] = (bool *)malloc(sizeof(bool) * width);
      memset(visited[i], false, sizeof(bool) * width);
    }

    // input
    unsigned int player_pos_x = 1, player_pos_y = 1;
    for (unsigned int i = 0; i < height; i++) {
      for (unsigned int j = 0; j < width; j++) {

        game[i][j] = getchar();
        if (game[i][j] == '\n') {
          game[i][j] = getchar();
        }
        if (game[i][j] == 'P') {
          player_pos_x = i;
          player_pos_y = j;
        }
      }
    }

    gold_cnt = 0;
    dfs(player_pos_x, player_pos_y, visited, game);

    printf("%u\n", gold_cnt);

    for (unsigned int i = 0; i < height; i++) {
      free(game[i]);
    }
    free(game);
    free(visited);
  }
  return 0;
}

void dfs(unsigned int start_x, unsigned int start_y, bool **visited,
         char **game) {

  if (visited[start_x][start_y] || game[start_x][start_y] == '#')
    return;
  visited[start_x][start_y] = true;

  if (game[start_x][start_y] == 'G')
    gold_cnt++;

  if (game[start_x + 1][start_y] == 'T' || game[start_x - 1][start_y] == 'T' ||
      game[start_x][start_y + 1] == 'T' || game[start_x][start_y - 1] == 'T') {
    return;
  } else {
    dfs(start_x + 1, start_y, visited, game);
    dfs(start_x - 1, start_y, visited, game);
    dfs(start_x, start_y + 1, visited, game);
    dfs(start_x, start_y + -1, visited, game);
  }
}

