#include "monty.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  char line[100];
  int line_number = 0;

  while (fgets(line, sizeof(line), file)) {
    line_number++;
    char opcode[10];
    int value;

    if (sscanf(line, "%s %d", opcode, &value) == 2 && strcmp(opcode, "push") == 0) {
      push(value);
    } else if (strcmp(opcode, "pall") == 0) {
      pall();
    } else {
      fprintf(stderr, "Error: Invalid opcode at line %d\n", line_number);
      return EXIT_FAILURE;
    }
  }

  fclose(file);
  return EXIT_SUCCESS;
}
