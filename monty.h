#include "unique_monty.h"

interpreter_context_t bus = {NULL, NULL, NULL, 0};
/**
 * main - function for unique_monty code interpreter
 * @argc: argument count
 * @argv: argument value
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
  char *custom_content = NULL;
  FILE *custom_file;
  size_t custom_size = 0;
  ssize_t custom_read_line = 1;
  stack_custom_t *custom_stack = NULL;
  unsigned int custom_counter = 0;

  if (argc != 2)
    {
      fprintf(stderr, "USAGE: unique_monty file\n");
      exit(EXIT_FAILURE);
    }
  custom_file = fopen(argv[1], "r");
  interpreter_ctx.custom_input_file = custom_file;
  if (!custom_file)
    {
      fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
      exit(EXIT_FAILURE);
    }
  while ((custom_read_line = custom_getline(&custom_content, &custom_size, custom_file)) != -1)
    {
      custom_counter++;
      interpreter_custom_ctx.custom_line_content = custom_content;
      if (custom_read_line > 0)
	{
	  custom_execute(custom_content, &custom_stack, custom_counter, custom_file);
	}
    }
  free(custom_content);
  custom_free_stack(custom_stack);
  fclose(custom_file);

  return (0);
}
