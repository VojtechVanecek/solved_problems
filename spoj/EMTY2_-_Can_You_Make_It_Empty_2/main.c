// EMTY2 - Can You Make It Empty 2

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  unsigned short int cases_count;
  scanf("%hd", &cases_count);

  char temp;
  getchar();
  bool empt = true;

  for (int i = 0, null_req = 0; i < cases_count; i++, null_req = 0) {

    empt = true;
    for (int j = 0; (temp = getchar()) && (temp != '\n'); j++) {
      if (empt) {
        if (temp == '1') {
          null_req += 2;
        } else {

          null_req--;
        }

        if (null_req < 0) {
          empt = false;
        }
      }
    }

    if (null_req != 0) {
      empt = false;
    }

    printf("Case %d: %s\n", (i + 1), ((empt) ? "yes" : "no"));
  }

  return (EXIT_SUCCESS);
}

