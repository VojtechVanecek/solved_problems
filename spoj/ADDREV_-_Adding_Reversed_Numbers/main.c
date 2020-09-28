// ADDREV - Adding Reversed Numbers

#include <stdio.h>
#include <stdlib.h>

unsigned int number_reverse(unsigned int num);

int main() {

  int cases_count;
  scanf("%d", &cases_count);

  unsigned int in_a, in_b;
  for (int i = 0; i < cases_count; i++) {

    scanf("%u %u", &in_a, &in_b);

    printf("%u\n", number_reverse(number_reverse(in_a) + number_reverse(in_b)));
  }

  return (EXIT_SUCCESS);
}

unsigned int number_reverse(unsigned int num) {

  unsigned int reversed_number = 0;

  while (num > 0) {

    reversed_number *= 10;
    reversed_number += num % 10;

    num /= 10;
  }
  return reversed_number;
}

