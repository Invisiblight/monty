#include "monty.h"
#include <stdlib.h>

int pop(void) {
  if (stack.top == 0) {
    fprintf(stderr, "Error: Stack underflow\n");
    exit(EXIT_FAILURE);
  }
  return stack.data[--stack.top];
}
