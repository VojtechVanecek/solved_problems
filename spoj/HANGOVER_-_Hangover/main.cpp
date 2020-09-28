// HANGOVER - Hangover

#include <stdio.h>
#include <stdlib.h>

int main(void) {

  double input;
  int out;

  while (scanf("%lf", &input) && input != 0) {

    double i = 2;
    out = 0;
    while (input > 0) {
      input -= (double)(1 / i++);
      out++;
    }
    printf("%d card(s)\n", out);
  }

  return EXIT_SUCCESS;
}

