// 10161 - Ant on a Chessboard

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <limits>

#define MAX 44723

int main(void) {

  long int *arr = (long int *)malloc(sizeof(long int) * MAX);

  arr[1] = 1;
  for (unsigned long int i = 2; i < MAX; i++) {

    arr[i] = pow(i, 2) - (i - 1);
  }

  long int in;
  while (scanf("%li", &in) && in) {

    for (long int i = 1; i < MAX; i++) {

      if ((in >= arr[i] - (i - 1)) && (in <= arr[i] + (i - 1))) {

        // even
        if ((i % 2) == 0) {
          if (in < arr[i]) {

            printf("%li %li\n", i - (arr[i] - in), i);
            break;

          } else {

            printf("%li %li\n", i, i - (in - arr[i]));
            break;
          }

        }
        // odd
        else {
          if (in < arr[i]) {
            printf("%li %li\n", i, i - (arr[i] - in));
            break;

          } else {

            printf("%li %li\n", i - (in - arr[i]), i);
            break;
          }
        }

        break;
      }
    }
  }

  free(arr);

  return 0;
}

