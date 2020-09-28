// AMR10G - Christmas Play

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quick_sort(unsigned int *arr, int count_n);
void arr_print(unsigned int *arr, unsigned int len);
unsigned int min_dif(unsigned int *arr, unsigned int count_n,
                     unsigned int sol_count);

int main(void) {

  unsigned int cases_count;
  scanf("%u", &cases_count);

  unsigned int *height = (unsigned int *)malloc(sizeof(unsigned int));
  unsigned int children_count, soldier_count; // N K

  for (int i = 0; i < cases_count; i++) {

    scanf("%u %u", &children_count, &soldier_count);
    height =
        (unsigned int *)realloc(height, children_count * sizeof(unsigned int));
    assert(height);

    for (int j = 0; j < children_count; j++) {

      scanf("%u", &height[j]);
    }

    // sort
    quick_sort(height, children_count);

    printf("%u\n", min_dif(height, children_count, soldier_count));

    memset(height, 0, children_count * sizeof(unsigned int));
  }

  free(height);
  return (EXIT_SUCCESS);
}
void quick_sort(unsigned int *arr, int count_n) {
  if (count_n < 2)
    return;
  unsigned int p = arr[count_n / 2];
  unsigned int *l = arr;
  unsigned int *r = arr + count_n - 1;
  while (l <= r) {
    if (*l < p) {
      l++;
    } else if (*r > p) {
      r--;
    } else {
      unsigned int t = *l;
      *l = *r;
      *r = t;
      l++;
      r--;
    }
  }
  quick_sort(arr, r - arr + 1);
  quick_sort(l, arr + count_n - l);
}

unsigned int min_dif(unsigned int *arr, unsigned int count_n,
                     unsigned int sol_count) {

  unsigned int diff = 1000000000;

  for (unsigned int i = 0, j = (sol_count - 1); j < count_n; i++, j++) {

    if (diff > (arr[j] - arr[i])) {

      diff = (arr[j] - arr[i]);
    }
  }

  return (diff);
}

