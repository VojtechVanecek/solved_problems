// PTIME - Prime Time

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  unsigned int in;
  scanf("%u", &in);

  bool *sieve = (bool *)malloc(sizeof(bool) * (in + 1));
  memset(sieve, true, sizeof(bool) * (in + 1));

  unsigned int *fraction =
      (unsigned int *)malloc(sizeof(unsigned int) * (in + 1));
  memset(fraction, 0, sizeof(unsigned int) * (in + 1));

  for (unsigned int i = 2; (i * i) <= in; i++) {
    if (sieve[i])
      for (unsigned int j = (i * i); j <= in; j += i)
        sieve[j] = false;
  }

  for (unsigned int i = 2; i <= in; i++) {

    for (unsigned int j = 2, k = i; j <= in; j++) {
      if ((sieve[j]) && ((k % j) == 0))
        while ((k % j) == 0) {
          k /= j;
          fraction[j]++;
        }
    }
  }

  bool first = true;
  for (unsigned int i = 0; i <= in; i++) {
    if (fraction[i]) {
      if (first) {
        printf("%u^%u", i, fraction[i]);
        first = false;
      } else {

        printf(" * %u^%u", i, fraction[i]);
      }
    }
  }
  putchar('\n');

  free(fraction);
  free(sieve);
  return EXIT_SUCCESS;
}

