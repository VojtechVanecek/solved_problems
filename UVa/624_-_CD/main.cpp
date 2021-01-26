// 624 - CD

#include <bits/stdc++.h>

int top_val = 0;
int diff_max;
std::vector<int> ans;
void search(int size, int size_max, std::vector<int> subset, int *all);

int main(void) {

  int tape_len, song_cnt = 0;
  int *song_len = (int *)malloc(sizeof(int) * song_cnt);

  while (scanf("%d %d", &tape_len, &song_cnt) != EOF) {
    song_len = (int *)realloc(song_len, sizeof(int) * song_cnt);

    for (int i = 0; i < song_cnt; i++) {
      if (!(scanf("%u", &song_len[i]))) {
        return (1);
      }
    }

    top_val = tape_len;
    diff_max = INT_MAX;
    std::vector<int> sub;
    search(0, song_cnt + 1, sub, song_len);
    int sum_all = 0;
    for (unsigned int i = 0; i < ans.size(); i++) {
      sum_all += ans.at(i);
      printf("%d ", ans.at(i));
    }
    printf("sum:%d\n", sum_all);
  }

  free(song_len);

  return (0);
}
void search(int size, int size_max, std::vector<int> subset, int *all) {

  if (size == size_max)
    return;

  // procces
  int sum = 0;
  if (!(subset.empty())) {
    for (unsigned int i = 0; i < subset.size(); i++) {
      sum += subset.at(i);
    }
  }

  if (((top_val - sum) >= 0) && ((top_val - sum) <= diff_max)) {
    diff_max = (top_val - sum);
    while (!(ans.empty())) {
      ans.pop_back();
    }
    for (unsigned int i = 0; i < subset.size(); i++) {
      ans.push_back(subset.at(i));
    }
  }

  if (sum < top_val) {

    search(size + 1, size_max, subset, all);
    subset.push_back(all[size]);
    search(size + 1, size_max, subset, all);
    subset.pop_back();
  }
}

