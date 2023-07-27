#include "monty.h"

/**
* do_nothing - Does absolutely nothing for the Monty opcode 'nop'.
* @stack: A pointer to the top mode node of a stack_t linked list.
* @current_line_number: The current working
*    line number of a Monty bytecodes file.
*/
void do_nothing(stack_t **stack, unsigned int current_line_number)
{
(void)stack;
(void)current_line_number;
}


/**
* print_char_from_stack_top - Prints the character in the top value
*               node of a stack_t linked list.
* @stack: A pointer to the top mode node of a stack_t linked list.
* @current_line_number: The current working
*        line number of a Monty bytecodes file.
*/
void print_char_from_stack_top(stack_t **stack,
	unsigned int current_line_number)
{
if ((*stack)->next == NULL)
{
set_tokenization_error_code(print_pchar_error_and_exit
(current_line_number, "stack empty"));
return;
}
if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
{
set_tokenization_error_code(print_pchar_error_and_exit(current_line_number,
"value out of range"));
return;
}


printf("%c\n", (*stack)->next->n);
}


/**
* print_string_from_stack_top - Prints the string
*         contained in a stack_t linked list.
* @stack: A pointer to the top mode node of a stack_t linked list.
* @current_line_number: The current working
*           line number of a Monty bytecodes file.
*/
void print_string_from_stack_top(stack_t **stack, unsigned int
current_line_number)
{
stack_t *tmp = (*stack)->next;


while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
{
printf("%c", tmp->n);
tmp = tmp->next;
}


printf("\n");

(void)current_line_number;
}
