// SNGINT - Encode Integer

#include <bits/stdc++.h>

int main(void) {

  unsigned int cases_cnt;

  if (!(scanf("%u", &cases_cnt))) {
    return -1;
  }
  std::vector<unsigned int> div;

  unsigned int in;
  while (cases_cnt--) {
    scanf("%u", &in);

    bool pos = true;
    if (in == 0) {
      printf("10\n");
      pos = false;
    }
    if (in == 1) {
      printf("1\n");
      pos = false;
    }

    div.clear();
    while (in != 1 && (pos)) {
      unsigned int temp = in;
      for (unsigned int i = 9; i > 1; i--) {
        while ((in % i) == 0) {

          in /= i;
          div.push_back(i);
        }
      }
      if (temp == in) {
        printf("-1\n");
        pos = false;
      }
    }

    if (pos) {
      std::sort(div.begin(), div.end());

      for (unsigned int i = 0; i < div.size(); i++) {

        printf("%u", div.at(i));
      }
      putchar('\n');
    }
  }

  return 0;
}

