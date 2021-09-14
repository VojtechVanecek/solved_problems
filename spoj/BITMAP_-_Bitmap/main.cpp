// BITMAP - Bitmap

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <queue>

#define DIR_COUNT 4
int dir_h[] = {0, 0, -1, 1};
int dir_v[] = {1, -1, 0, 0};

int main(void) {

  int cases_cnt;
  if (!(scanf("%d", &cases_cnt))) {
    return (1);
  }

  int line_cnt, column_cnt;

  while (cases_cnt--) {
    if (!(scanf("%d %d", &line_cnt, &column_cnt))) {
      return (1);
    }

    bool **pixels = (bool **)malloc(sizeof(bool *) * line_cnt);
    bool **visited = (bool **)malloc(sizeof(bool *) * line_cnt);
    int **distance = (int **)malloc(sizeof(int *) * line_cnt);

    for (int i = 0; i < line_cnt; i++) {
      pixels[i] = (bool *)malloc(sizeof(bool) * column_cnt);
      visited[i] = (bool *)malloc(sizeof(bool) * column_cnt);
      memset(visited[i], false, sizeof(bool) * column_cnt);
      distance[i] = (int *)malloc(sizeof(int) * column_cnt);
      memset(distance[i], 0, sizeof(int) * column_cnt);
    }

    getchar();
    for (int i = 0; i < line_cnt; i++) {
      for (int j = 0; j < column_cnt; j++) {
        pixels[i][j] = (getchar() == '1');
      }
      getchar();
    }

    std::queue<std::pair<int, int>> q;
    for (int i = 0; i < line_cnt; i++) {
      for (int j = 0; j < column_cnt; j++) {
        if (pixels[i][j]) {
          while (!(q.empty()))
            q.pop();
          visited[i][j] = true;
          distance[i][j] = 0;
          q.push({i, j});

          while (!(q.empty())) {
            int curr_line = q.front().first;
            int curr_column = q.front().second;
            q.pop();

            for (int k = 0; k < DIR_COUNT; k++) {
              int neig_pixel_v = curr_line + dir_v[k];
              int neig_pixel_h = curr_column + dir_h[k];
              if ((neig_pixel_v >= 0 && neig_pixel_v < line_cnt) &&
                  (neig_pixel_h >= 0 && neig_pixel_h < column_cnt) &&
                  (!(visited[neig_pixel_v][neig_pixel_h]) ||
                   (distance[neig_pixel_v][neig_pixel_h] >
                    distance[curr_line][curr_column] + 1))) {
                visited[neig_pixel_v][neig_pixel_h] = true;
                distance[neig_pixel_v][neig_pixel_h] =
                    distance[curr_line][curr_column] + 1;
                q.push({neig_pixel_v, neig_pixel_h});
              }
            }
          }
        }
      }
    }

    for (int i = 0; i < line_cnt; i++) {
      for (int j = 0; j < column_cnt; j++) {
        printf("%d ", distance[i][j]);
      }
      putchar('\n');
    }

    for (int i = 0; i < line_cnt; i++) {
      free(pixels[i]);
      pixels[i] = NULL;
      free(visited[i]);
      visited[i] = NULL;
      free(distance[i]);
      distance[i] = NULL;
    }
    free(pixels);
    pixels = NULL;
    free(visited);
    visited = NULL;
    free(distance);
    distance = NULL;
  }

  return (0);
}

