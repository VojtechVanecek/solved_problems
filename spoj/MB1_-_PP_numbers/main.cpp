// MB1 - PP numbers

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <vector>

#define MAX 1000000

bool isPalindrome(unsigned int in);
unsigned int digitProduct(unsigned int in);
int main(void) {

  std::vector<unsigned int> palindromes;
  std::vector<unsigned int> primes;

  bool *sieve = (bool *)malloc(sizeof(bool) * MAX);
  memset(sieve, true, sizeof(bool) * MAX);

  for (unsigned int i = 2; i < MAX; i++) {
    if (sieve[i]) {
      primes.push_back(i);
      if (isPalindrome(i)) {
        palindromes.push_back(i);
      }
      for (unsigned int j = i + i; j < MAX; j += i)
        sieve[j] = false;
    }
  }

  unsigned int casesCount, input;
  scanf("%u", &casesCount);
  while (casesCount--) {

    scanf("%u", &input);
    printf("%u %u\n", palindromes.at(input - 1),
           primes.at(digitProduct(palindromes.at(input - 1)) - 1));
  }

  free(sieve);
  return EXIT_SUCCESS;
}
bool isPalindrome(unsigned int in) {

  unsigned int old = in;

  unsigned int sum = 0;
  unsigned int r;
  while (in > 0) {
    r = in % 10;
    sum = (sum * 10) + r;
    in = in / 10;
  }

  return (old == sum);
}
unsigned int digitProduct(unsigned int in) {
  unsigned int ret, prod;

  prod = 1;
  while (in != 0) {

    ret = in % 10;
    if (ret != 0)
      prod *= ret;
    in /= 10;
  }
  return prod;
}

