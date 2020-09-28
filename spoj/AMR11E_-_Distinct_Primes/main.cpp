// AMR11E - Distinct Primes

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 3001
#define N 2670

bool hasThree(int a, bool *sieve);
int main(void) {

  bool *sieve = (bool *)malloc(sizeof(bool) * MAX);
  memset(sieve, true, sizeof(bool) * MAX);

  for (int i = 2; (i * i) < MAX; i++) {

    if (sieve[i])
      for (int j = (i * i); j < MAX; j += i)
        sieve[j] = false;
  }

  bool *ans = (bool *)malloc(sizeof(bool) * N);
  memset(ans, false, sizeof(bool) * N);

  for (int j = 30; j < N; j++) {

    if (ans[j])
      continue;

    if (hasThree(j, sieve)) {

      for (int k = j; k < N; k += j)
        ans[k] = true;
    }
  }

  unsigned int casesCount;
  int in;
  scanf("%u", &casesCount);

  while (casesCount--) {
    scanf("%d", &in);

    for (int i = 30, k = 0; i < N; i++) {
      if (ans[i])
        k++;
      if (k == in) {
        printf("%d\n", i);
        break;
      }
    }
  }

  free(ans);
  free(sieve);
  return EXIT_SUCCESS;
}
bool hasThree(int a, bool *sieve) {

  for (int i = 2, k = a, count = 0; i <= a; i++) {
    if (sieve[i] && (k % i) == 0) {
      while ((k % i) == 0)
        k /= i;
      count++;
    }
    if (count >= 3)
      return true;
  }
  return false;
}

