#include "monty.h"


/**
 * push_to_stack - Pushes a value to a stack_t linked list.
 * @stack: A pointer to the top
 * mode node of a stack_t linked list.
 * @current_line_number: The current working
 * line number of a Monty bytecodes file.
 */
void push_to_stack(stack_t **stack, unsigned int current_line_number)
{
stack_t *temp, *new_node;
int i;


new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
set_tokenization_error_code(print_malloc_error_and_exit());
return;
}


if (op_toks[1] == NULL)
{
set_tokenization_error_code
(print_push_integer_error_and_exit(current_line_number));
return;
}


for (i = 0; op_toks[1][i]; i++)
{
if (op_toks[1][i] == '-' && i == 0)
continue;
if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
{
set_tokenization_error_code
(print_push_integer_error_and_exit(current_line_number));
return;
}
}
new_node->n = atoi(op_toks[1]);


if (evaluate_stack_mode(*stack) == STACK) /* STACK mode insert at front */
{
temp = (*stack)->next;
new_node->prev = *stack;
new_node->next = temp;
if (temp)
temp->prev = new_node;
(*stack)->next = new_node;
}
else /* QUEUE mode insert at end */
{
temp = *stack;
while (temp->next)
temp = temp->next;
new_node->prev = temp;
new_node->next = NULL;
temp->next = new_node;
}
}


/**
 * print_stack - Prints the values of a stack_t linked list.
 * @stack: A pointer to the top
 * mode node of a stack_t linked list.
 * @current_line_number: The current working
 * line number of a Monty bytecodes file.
 */
void print_stack(stack_t **stack, unsigned int current_line_number)
{
stack_t *temp = (*stack)->next;


while (temp)
{
printf("%d\n", temp->n);
temp = temp->next;
}
(void)current_line_number;
}


/**
 * print_top_of_stack - Prints the top
 * value of a stack_t linked list.
 * @stack: A pointer to the top
 * mode node of a stack_t linked list.
 * @current_line_number: The current working
 * line number of a Monty bytecodes file.
 */
void print_top_of_stack(stack_t **stack, unsigned int current_line_number)
{
if ((*stack)->next == NULL)
{
set_tokenization_error_code
(print_pint_error_and_exit(current_line_number));
return;
}


printf("%d\n", (*stack)->next->n);
}




/**
 * pop_from_stack - Removes the top
 * value element of a stack_t linked list.
 * @stack: A pointer to the top
 * mode node of a stack_t linked list.
 * @current_line_number: The current working
 * line number of a Monty bytecodes file.
 */
void pop_from_stack(stack_t **stack, unsigned int current_line_number)
{
stack_t *next = NULL;


if ((*stack)->next == NULL)
{
set_tokenization_error_code
(print_pop_error_and_exit(current_line_number));
return;
}


next = (*stack)->next->next;
free((*stack)->next);
if (next)
next->prev = *stack;
(*stack)->next = next;
}


/**
 * swap_stack_top - Swaps the top
 * two value elements of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @current_line_number: The current working
 * line number of a Monty bytecodes file.
 */
void swap_stack_top(stack_t **stack, unsigned int current_line_number)
{
stack_t *temp;


if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_tokenization_error_code
(print_short_stack_error_and_exit(current_line_number, "swap"));
return;
}


temp = (*stack)->next->next;
(*stack)->next->next = temp->next;
(*stack)->next->prev = temp;
if (temp->next)
temp->next->prev = (*stack)->next;
temp->next = (*stack)->next;
temp->prev = *stack;
(*stack)->next = temp;
}
