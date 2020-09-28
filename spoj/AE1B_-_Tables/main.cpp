// AE1B - Tables

#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

int main(void) {

  unsigned int boxCount, screwPerTable, tableCount;
  scanf("%u %u %u", &boxCount, &screwPerTable, &tableCount);

  unsigned int *screws =
      (unsigned int *)malloc(sizeof(unsigned int) * boxCount);

  for (unsigned int i = 0; i < boxCount; i++) {
    scanf("%u", &screws[i]);
  }

  std::sort(screws, screws + boxCount);

  int need = (screwPerTable * tableCount);
  int sum = 0;

  for (int i = (boxCount - 1); i >= 0; i--) {

    need = need - screws[i];
    sum++;
    if (need <= 0) {
      break;
    }
  }

  printf("%d\n", sum);
  free(screws);
  return EXIT_SUCCESS;
}

