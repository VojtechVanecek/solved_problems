// 10020 - Minimal coverage

#include <bits/stdc++.h>

#include <algorithm>
#include <vector>

int main(void) {

  unsigned int cases_cnt;
  if (!(scanf("%u", &cases_cnt))) {
    return (1);
  }

  std::vector<std::pair<int, int>> segs;
  std::vector<std::pair<int, int>> min;

  int length, start, end;
  while (cases_cnt--) {

    if (!(scanf("%d", &length))) {
      return (1);
    }

    segs.clear();
    while (true) {
      if (!(scanf("%d %d", &start, &end))) {
        return (1);
      }
      if ((start == 0) && (end == 0)) {
        break;
      } else {
        if (end > 0) {

          segs.push_back({start, end});
        }
      }
    }

    sort(segs.begin(), segs.end());

    int curr = 0;
    bool possible = true;

    min.clear();

    while (curr < length) {
      // find the longest
      int max = 0;
      int idx_max = -1;
      for (unsigned int i = 0; (i < segs.size()) && (segs.at(i).first <= curr);
           i++) {

        if ((segs.at(i).second) > max) {
          max = (segs.at(i).second);
          idx_max = i;
        }
      }
      if (idx_max >= 0) {
        curr = max;
        min.push_back({segs.at(idx_max).first, segs.at(idx_max).second});
        segs.erase(segs.begin() + idx_max);
      } else {
        possible = false;
        break;
      }
    }

    if (possible) {
      printf("%lu\n", min.size());
      for (unsigned int i = 0; i < min.size(); i++) {
        printf("%d %d\n", min.at(i).first, min.at(i).second);
      }
    } else {
      printf("0\n");
    }
    if (cases_cnt != 0)
      putchar('\n');
  }

  return (0);
}

