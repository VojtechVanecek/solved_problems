// GERGOVIA - Wine trading in Gergovia

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <deque>
#include <vector>

int main(void) {

  int inhabitantCount;
  unsigned long long int moves;
  std::deque<long long int> q;

  while ((scanf("%d", &inhabitantCount)) && (inhabitantCount != 0)) {

    for (int i = 0, j = 0; i < inhabitantCount; i++) {
      scanf("%d", &j);
      q.push_back(j);
    }

    moves = 0;
    long long int temp;
    while (!(q.size() == 1)) {

      temp = q.back();
      moves += abs(temp);
      q.pop_back();
      q.back() += temp;
    }

    printf("%llu\n", moves);
  }

  return (EXIT_SUCCESS);
}

