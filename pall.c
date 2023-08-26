#include "monty.h"
#include <stdio.h>

void pall(void) {
  for (int i = stack.top - 1; i >= 0; i--) {
    printf("%d\n", stack.data[i]);
  }
}
