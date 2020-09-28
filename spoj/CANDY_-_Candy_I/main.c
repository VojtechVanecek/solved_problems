// CANDY - Candy I

#include <stdio.h>
#include <stdlib.h>

#define END_FLAG -1

int main(void) {

  int packet_count;
  int *can_count = (int *)malloc(sizeof(int));
  // assert(can_count);

  unsigned long long int arr_sum = 0;
  unsigned int relaxed_arr_ele;
  unsigned int operation_count = 0;

  while (scanf("%d", &packet_count) && (packet_count != END_FLAG)) {

    can_count = (int *)realloc(can_count, sizeof(int) * packet_count);

    for (int i = 0; i < packet_count; i++) {

      scanf("%d", &can_count[i]);
      arr_sum += can_count[i];
    }

    if (!(arr_sum % packet_count)) {

      relaxed_arr_ele = arr_sum / packet_count;

      for (int i = 0; i < packet_count; i++) {

        if (can_count[i] < relaxed_arr_ele) {

          operation_count += relaxed_arr_ele - can_count[i];
        }
      }
      printf("%u\n", operation_count);

    } else {

      printf("%d\n", END_FLAG);
    }

    operation_count = 0;
    arr_sum = 0;
  }

  free(can_count);
  return (EXIT_SUCCESS);
}

