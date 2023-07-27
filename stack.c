#include "monty.h"
#include <string.h>

int evaluate_stack_mode(stack_t *stack);


/**
 * free_stack_and_elements - Frees a stack_t stack.
 * @stack: A pointer to the top (stack) or
 *         bottom (queue) of a stack_t.
 */
void free_stack_and_elements(stack_t **stack)
{
stack_t *tmp = *stack;


while (*stack)
{
tmp = (*stack)->next;
free(*stack);
*stack = tmp;
}
}


/**
 * initialize_stack - Initializes a stack_t stack with beginning
 *              stack and ending queue nodes.
 * @stack: A pointer to an unitialized stack_t stack.
 *
 * Return: If an error occurs - EXIT_FAILURE.
 *         Otherwise - EXIT_SUCCESS.
 */
int initialize_stack(stack_t **stack)
{
stack_t *s;


s = malloc(sizeof(stack_t));
if (s == NULL)
return (print_malloc_error_and_exit());


s->n = STACK;
s->prev = NULL;
s->next = NULL;


*stack = s;


return (EXIT_SUCCESS);
}


/**
 * evaluate_stack_mode - Checks if a stack_t linked
 * list is in stack or queue mode.
 * @stack: A pointer to the top (stack) or bottom (queue)
 *         of a stack_t linked list.
 *
 * Return: If the stack_t is in stack mode - STACK (0).
 *         If the stack_t is in queue mode - QUEUE (1).
 *         Otherwise - 2.
 */
int evaluate_stack_mode(stack_t *stack)
{
if (stack->n == STACK)
return (STACK);
else if (stack->n == QUEUE)
return (QUEUE);
return (2);
}
