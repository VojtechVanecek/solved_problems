// MAKEMAZE - VALIDATE THE MAZE
// https://www.spoj.com/problems/MAKEMAZE/
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <queue>
#include <vector>

int dir_row[] = {1, -1, 0, 0};
int dir_col[] = {0, 0, 1, -1};

int main(void) {

  unsigned int cases_cnt;
  scanf("%u", &cases_cnt);

  unsigned int row_cnt, column_cnt;
  while (cases_cnt--) {
    scanf("%u %u", &row_cnt, &column_cnt);
    getchar();

    char **maze = (char **)malloc(sizeof(char *) * row_cnt);
    for (unsigned int i = 0; i < row_cnt; i++) {
      maze[i] = (char *)malloc(sizeof(char) * column_cnt);
      memset(maze[i], '\0', sizeof(char) * column_cnt);
    }

    for (unsigned int i = 0; i < row_cnt; i++) {
      for (unsigned int j = 0; j < column_cnt; j++) {
        maze[i][j] = getchar();
      }
      getchar();
    }

    std::vector<std::pair<unsigned int, unsigned int>> entrences;
    for (unsigned int i = 0; i < row_cnt; i++) {
      for (unsigned int j = 0; j < column_cnt; j++) {
        if ((i == 0 || j == 0 || i == (row_cnt - 1) || j == (column_cnt - 1)) &&
            (maze[i][j] == '.')) {
          entrences.push_back({i, j});
        }
      }
    }

    if (entrences.size() == 2) {

      bool **visited = (bool **)malloc(sizeof(bool *) * row_cnt);
      for (unsigned int i = 0; i < row_cnt; i++) {
        visited[i] = (bool *)malloc(sizeof(bool) * column_cnt);
      }
      bool possible = false;
      for (unsigned int i = 0; i < entrences.size() && (!(possible)); i++) {
        for (unsigned int j = 0; j < row_cnt; j++) {
          memset(visited[j], false, sizeof(bool) * column_cnt);
        }

        std::queue<std::pair<unsigned int, unsigned int>> q;
        q.push({entrences.at(i).first, entrences.at(i).second});
        visited[entrences.at(i).first][entrences.at(i).second] = true;

        while (!(q.empty())) {
          int curr_row = q.front().first;
          int curr_col = q.front().second;
          q.pop();
          visited[curr_row][curr_col] = true;

          for (int j = 0; j < 4; j++) {
            if (((curr_row + dir_row[j]) >= 0) &&
                ((curr_row + dir_row[j]) < (int)row_cnt) &&
                ((curr_col + dir_col[j]) >= 0) &&
                ((curr_col + dir_col[j]) < (int)column_cnt)) {
              if ((!(visited[curr_row + dir_row[j]][curr_col + dir_col[j]])) &&
                  (maze[curr_row + dir_row[j]][curr_col + dir_col[j]] == '.')) {
                q.push({curr_row + dir_row[j], curr_col + dir_col[j]});
              }
            }
          }
        }

        for (unsigned int j = 0; j < entrences.size(); j++) {
          if (j != i &&
              visited[entrences.at(j).first][entrences.at(j).second]) {
            possible = true;
            break;
          }
        }
      }

      if (possible) {
        puts("valid");
      } else {
        puts("invalid");
      }

      for (unsigned int i = 0; i < row_cnt; i++) {
        free(visited[i]);
      }
      free(visited);

    } else {
      puts("invalid");
    }

    for (unsigned int i = 0; i < row_cnt; i++) {
      free(maze[i]);
    }
    free(maze);
  }

  return (0);
}

