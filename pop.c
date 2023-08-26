#include "unique_monty.h"

/**
 * custom_pop - function that pops the top of the custom_stack
 * @custom_head: double head pointer to the custom_stack
 * @counter: line count
 *
 * Return: nothing
 */
void custom_pop(stack_custom_t **custom_head, unsigned int counter)
{
  stack_custom_t *custom_top = *custom_head;

  if (*custom_head == NULL)
    {
      fprintf(stderr, "L%d: can't pop an empty custom_stack\n", counter);
      fclose(interpreter_custom_ctx.custom_input_file);
      free(interpreter_custom_ctx.custom_line_content);
      custom_free_stack(*custom_head);
      exit(EXIT_FAILURE);
    }
  *custom_head = custom_top->next;
  free(custom_top);
}
