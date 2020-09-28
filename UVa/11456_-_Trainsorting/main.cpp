// 11456 - Trainsorting

#include <algorithm>
#include <malloc.h>
#include <stdio.h>

int main(void) {

  unsigned int *in = (unsigned int *)malloc(sizeof(unsigned int));
  unsigned int *len_lis = (unsigned int *)malloc(sizeof(unsigned int));
  unsigned int *len_lds = (unsigned int *)malloc(sizeof(unsigned int));

  unsigned int cases_cnt;

  if (!(scanf("%u", &cases_cnt)))
    return 1;

  unsigned int car_cnt;
  while (cases_cnt--) {

    if (!(scanf("%u", &car_cnt)))
      return 1;

    in = (unsigned int *)realloc(in, sizeof(unsigned int) * car_cnt);

    for (int i = car_cnt - 1; i >= 0; i--) {
      if (!(scanf("%u", &in[i])))
        return 1;
    }

    // LIS
    len_lis = (unsigned int *)realloc(len_lis, sizeof(unsigned int) * car_cnt);
    for (unsigned int j = 0; j < car_cnt; j++) {

      len_lis[j] = 1;
      for (unsigned int k = 0; k < j; k++) {
        if (in[k] < in[j]) {
          len_lis[j] = std::max(len_lis[j], len_lis[k] + 1);
        }
      }
    }

    // LDS
    len_lds = (unsigned int *)realloc(len_lds, sizeof(unsigned int) * car_cnt);
    for (unsigned int j = 0; j < car_cnt; j++) {
      len_lds[j] = 1;
      for (unsigned int k = 0; k < j; k++) {
        if (in[j] < in[k]) {
          len_lds[j] = std::max(len_lds[j], len_lds[k] + 1);
        }
      }
    }

    unsigned int max_len = 0;
    for (unsigned int i = 0, j = car_cnt - 1; (i < car_cnt) && (j >= 0);
         i++, j--) {
      max_len = (max_len < (len_lis[i] + len_lds[i] - 1))
                    ? (len_lis[i] + len_lds[i] - 1)
                    : max_len;
    }

    printf("%u\n", max_len);
  }

  free(len_lds);
  free(len_lis);
  free(in);

  return 0;
}

