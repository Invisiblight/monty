#include "unique_monty.h"

/**
 * custom_push - function that adds node to the custom_stack
 * @custom_head: double head pointer to the custom_stack
 * @counter: line count
 *
 * Return: nothing
 */
void custom_push(stack_custom_t **custom_head, unsigned int counter)
{
  int i, m = 0, flag = 0;

  if (!interpreter_custom_ctx.custom_argument)
    {
      fprintf(stderr, "L%d: usage: custom_push integer\n", counter);
      fclose(interpreter_custom_ctx.custom_input_file);
      free(interpreter_custom_ctx.custom_line_content);
      custom_free_stack(*custom_head);
      exit(EXIT_FAILURE);
    }
  if (interpreter_custom_ctx.custom_argument[0] == '-')
    m++;
  for (; interpreter_custom_ctx.custom_argument[m] != '\0'; m++)
    {
      if (interpreter_custom_ctx.custom_argument[m] > '9' || interpreter_custom_ctx.custom_argument[m] < '0')
	flag = 1;
    }
  if (flag == 1)
    {
      fprintf(stderr, "L%d: usage: custom_push integer\n", counter);
      fclose(interpreter_custom_ctx.custom_input_file);
      free(interpreter_custom_ctx.custom_line_content);
      custom_free_stack(*custom_head);
      exit(EXIT_FAILURE);
    }
  i = atoi(interpreter_custom_ctx.custom_argument);
  if (interpreter_custom_ctx.custom_stack_or_queue_mode == 0)
    custom_addnode(custom_head, i);
  else
    custom_addqueue(custom_head, i);
}
