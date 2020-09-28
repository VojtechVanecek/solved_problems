// 11573 - Ocean Currents

#include <bits/stdc++.h>

int main(void) {

  unsigned int rows_cnt, columns_cnt;

  if (!(scanf("%u %u", &rows_cnt, &columns_cnt))) {
    return -1;
  }

  int currs_r[] = {-1, -1, 0, 1, 1, 1, 0, -1};
  int currs_c[] = {0, 1, 1, 1, 0, -1, -1, -1};

  char **ocean = (char **)malloc(sizeof(char *) * (rows_cnt + 2));
  bool **visited = (bool **)malloc(sizeof(bool *) * (rows_cnt + 2));
  unsigned int **distance =
      (unsigned int **)malloc(sizeof(unsigned int *) * (rows_cnt + 2));

  for (unsigned int i = 0; i < (rows_cnt + 2); i++) {
    ocean[i] = (char *)malloc(sizeof(char) * (columns_cnt + 2));
    visited[i] = (bool *)malloc(sizeof(bool) * (columns_cnt + 2));
    distance[i] =
        (unsigned int *)malloc(sizeof(unsigned int) * (columns_cnt + 2));
  }

  for (unsigned int i = 1; i <= rows_cnt; i++) {
    for (unsigned int j = 1; j <= columns_cnt; j++) {
      ocean[i][j] = getchar();
      if (ocean[i][j] == '\n') {
        ocean[i][j] = getchar();
      }
    }

    visited[i][0] = true;
    visited[i][rows_cnt + 1] = true;
  }
  unsigned int trips_cnt;

  if (!(scanf("%u", &trips_cnt))) {
    return -1;
  }

  memset(visited[0], true, sizeof(bool) * (columns_cnt + 2));
  memset(visited[rows_cnt + 1], true, sizeof(bool) * (columns_cnt + 2));

  unsigned int start_r, start_c, end_r, end_c;

  while (trips_cnt--) {

    if (!(scanf("%u%u%u%u", &start_r, &start_c, &end_r, &end_c))) {
      return -1;
    }
    for (unsigned int i = 1; i <= rows_cnt; i++) {
      memset(&visited[i][1], false, sizeof(bool) * columns_cnt);
      memset(&distance[i][1], 0, sizeof(unsigned int) * columns_cnt);
    }

    // bfs

    std::deque<std::pair<unsigned int, unsigned int>> q;
    visited[start_r][start_c] = true;
    distance[start_r][start_c] = 0;
    q.push_back({start_r, start_c});
    while (!(q.empty())) {

      unsigned int pos_r = q.front().first;
      unsigned int pos_c = q.front().second;
      unsigned int curr = ocean[pos_r][pos_c] - '0';
      q.pop_front();

      // proccess
      for (unsigned int i = 0; i < 8; i++) {
        if (!(visited[pos_r + currs_r[i]][pos_c + currs_c[i]])) {
          visited[pos_r + currs_r[i]][pos_c + currs_c[i]] = true;
          if (i == curr) {
            distance[pos_r + currs_r[i]][pos_c + currs_c[i]] =
                distance[pos_r][pos_c];
            q.push_front({pos_r + currs_r[i], pos_c + currs_c[i]});
          } else {
            distance[pos_r + currs_r[i]][pos_c + currs_c[i]] =
                distance[pos_r][pos_c] + 1;
            q.push_back({pos_r + currs_r[i], pos_c + currs_c[i]});
          }

        } else {
          if (i == curr) {
            if (distance[pos_r + currs_r[i]][pos_c + currs_c[i]] >
                distance[pos_r][pos_c]) {
              distance[pos_r + currs_r[i]][pos_c + currs_c[i]] =
                  distance[pos_r][pos_c];
              q.push_front({pos_r + currs_r[i], pos_c + currs_c[i]});
            }

          } else {
            if (distance[pos_r + currs_r[i]][pos_c + currs_c[i]] >
                (distance[pos_r][pos_c] + 1)) {
              distance[pos_r + currs_r[i]][pos_c + currs_c[i]] =
                  distance[pos_r][pos_c] + 1;
              q.push_back({pos_r + currs_r[i], pos_c + currs_c[i]});
            }
          }
        }
      }
    }
    printf("%u\n", distance[end_r][end_c]);
  }
  for (unsigned int i = 0; i < (rows_cnt + 2); i++) {
    free(visited[i]);
    free(ocean[i]);
    free(distance[i]);
  }
  free(distance);
  free(visited);
  free(ocean);
  return 0;
}

