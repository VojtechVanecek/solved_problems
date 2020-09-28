// FACEFRND - Friends of Friends

#include <stdio.h>
#include <stdlib.h>

int main(void) {

  unsigned short int bob_friends_count;
  scanf("%hd", &bob_friends_count);

  unsigned short int *bob_friends_list = (unsigned short int *)malloc(
      sizeof(unsigned short int) * bob_friends_count);

  unsigned short int *bob_f_o_f_list =
      (unsigned short int *)malloc(sizeof(unsigned short int));
  unsigned short int f_o_f_count = 0;

  for (int i = 0, j = 0, temp = 0; i < bob_friends_count; i++) {
    scanf("%hd", &bob_friends_list[i]);

    scanf("%d", &temp);
    f_o_f_count += temp;

    bob_f_o_f_list = (unsigned short int *)realloc(
        bob_f_o_f_list, sizeof(unsigned short int) * f_o_f_count);

    for (; j < f_o_f_count; j++) {

      scanf("%hd", &bob_f_o_f_list[j]);
    }
  }

  for (int i = 0; i < bob_friends_count; i++) {

    for (int j = 0; j < f_o_f_count; j++) {

      if (bob_f_o_f_list[j] == bob_friends_list[i])
        bob_f_o_f_list[j] = 10000;
    }
  }

  for (int i = 0; i < f_o_f_count; i++) {

    if (bob_f_o_f_list[i] == 10000) {

      continue;

    } else {

      for (int j = (i + 1); j < f_o_f_count; j++) {

        if (bob_f_o_f_list[i] == bob_f_o_f_list[j]) {

          bob_f_o_f_list[j] = 10000;
        }
      }
    }
  }

  int f_o_f = 0;

  for (int i = 0; i < f_o_f_count; i++) {

    if (bob_f_o_f_list[i] != 10000)
      f_o_f++;
  }

  printf("%d\n", f_o_f);

  free(bob_f_o_f_list);
  free(bob_friends_list);
  return (EXIT_SUCCESS);
}

