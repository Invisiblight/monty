#include "unique_monty.h"

/**
 * custom_pall - function that prints everything in the custom_stack
 * @custom_head: double head pointer to the custom_stack
 * @counter: unused line count
 *
 * Return: nothing
 */
void custom_pall(stack_custom_t **custom_head, unsigned int counter)
{
  stack_custom_t *custom_current = *custom_head;
  (void)counter;

  while (custom_current)
    {
      printf("%d\n", custom_current->value);
      custom_current = custom_current->next;
    }
}
