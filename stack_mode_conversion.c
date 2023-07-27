#include "monty.h"


/**
 * rotate_left - Rotates the top value of a stack_t linked list to the bottom.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @current_line_number: The current working
 * line number of a Monty bytecodes file.
 */
void rotate_left(stack_t **stack, unsigned int current_line_number)
{
stack_t *top, *bottom;


if ((*stack)->next == NULL || (*stack)->next->next == NULL)
return;

top = (*stack)->next;
bottom = (*stack)->next;
while (bottom->next != NULL)
bottom = bottom->next;


top->next->prev = *stack;
(*stack)->next = top->next;
bottom->next = top;
top->next = NULL;
top->prev = bottom;


(void)current_line_number;
}


/**
 * rotate_right - Rotates the bottom value of a stack_t linked list to the top.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @current_line_number: The current working
 * line number of a Monty bytecodes file.
 */
void rotate_right(stack_t **stack, unsigned int current_line_number)
{
stack_t *top, *bottom;


if ((*stack)->next == NULL || (*stack)->next->next == NULL)
return;

top = (*stack)->next;
bottom = (*stack)->next;
while (bottom->next != NULL)
bottom = bottom->next;


bottom->prev->next = NULL;
(*stack)->next = bottom;
bottom->prev = *stack;
bottom->next = top;
top->prev = bottom;


(void)current_line_number;
}


/**
 * set_as_stack - Converts a queue to a stack.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @current_line_number: The current working
 * line number of a Monty bytecodes file.
 */
void set_as_stack(stack_t **stack, unsigned int current_line_number)
{
(*stack)->n = STACK;
(void)current_line_number;
}


/**
 * set_as_queue - Converts a stack to a queue.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @current_line_number: The current working
 * line number of a Monty bytecodes file.
 */
void set_as_queue(stack_t **stack, unsigned int current_line_number)
{
(*stack)->n = QUEUE;
(void)current_line_number;
}
