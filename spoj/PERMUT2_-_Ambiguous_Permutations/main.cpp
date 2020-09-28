// PERMUT2 - Ambiguous Permutations

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isAmbi(int *arr, int size);
int main(void) {

  int count;

  int *numbers = (int *)malloc(sizeof(int));

  while ((scanf("%d", &count)) && (count != 0)) {

    numbers = (int *)realloc(numbers, sizeof(int) * (count + 1));
    for (int i = 1; i <= count; i++)
      scanf("%d", &numbers[i]);

    printf("%s", (isAmbi(numbers, count)) ? "ambiguous" : "not ambiguous");
    putchar('\n');
  }

  free(numbers);
  return EXIT_SUCCESS;
}
bool isAmbi(int *arr, int size) {

  for (int i = 1; i <= size; i++) {
    if (arr[i] == i)
      continue;
    if (arr[arr[i]] != i) {
      return false;
    }
  }

  return true;
}

