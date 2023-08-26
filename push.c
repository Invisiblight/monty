#include "monty.h"
#include <stdlib.h>

void push(int value) {
  if (stack.top >= STACK_MAX_SIZE) {
    fprintf(stderr, "Error: Stack overflow\n");
    exit(EXIT_FAILURE);
  }
  stack.data[stack.top++] = value;
}
