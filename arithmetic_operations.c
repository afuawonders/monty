#include "monty.h"

/**
* add_stack_top_two - Adds the top two values of a stack_t linked list.
* @stack: A pointer to the top mode node of a stack_t linked list.
* @current_line_number: The current working line
* number of a Monty bytecodes file.
*
* Description: The result is stored in the second value node
*              from the top and the top value  is removed.
*/
void add_stack_top_two(stack_t **stack, unsigned int current_line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_tokenization_error_code(print_short_stack_error_and_exit
(current_line_number, "add"));
return;
}


(*stack)->next->next->n += (*stack)->next->n;
pop_from_stack(stack, current_line_number);
}


/**
* subtract_stack_top_two - Subtracts the second value from the top of
*             a stack_t linked list by the top value.
* @stack: A pointer to the top mode node of a stack_t linked list.
* @current_line_number: The current working
* line number of a Monty bytecodes file.
*
* Description: The result is stored in the second value node
*              from the top and the top value is removed.
*/
void subtract_stack_top_two(stack_t **stack, unsigned int current_line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_tokenization_error_code(print_short_stack_error_and_exit
(current_line_number, "sub"));
return;
}

(*stack)->next->next->n -= (*stack)->next->n;
pop_from_stack(stack, current_line_number);
}


/**
* divide_stack_top_two - Divides the second value from the top of
*             a stack_t linked list by the top value.
* @stack: A pointer to the top mode node of a stack_t linked list.
* @current_line_number: The current working line
* number of a Monty bytecodes file.
*
* Description: The result is stored in the second value node
*              from the top and the top value is removed.
*/
void divide_stack_top_two(stack_t **stack, unsigned int current_line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_tokenization_error_code(print_short_stack_error_and_exit
(current_line_number, "div"));
return;
}


if ((*stack)->next->n == 0)
{
set_tokenization_error_code(print_divide_by_zero_error_and_exit
(current_line_number));
return;
}


(*stack)->next->next->n /= (*stack)->next->n;
pop_from_stack(stack, current_line_number);
}


/**
* multiply_stack_top_two - Multiplies the second value from the top of
*             a stack_t linked list by the top value.
* @stack: A pointer to the top mode node of a stack_t linked list.
* @current_line_number: The current working line
* number of a Monty bytecodes file.
*
* Description: The result is stored in the second value node
*              from the top and the top value is removed.
*/
void multiply_stack_top_two(stack_t **stack, unsigned int current_line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_tokenization_error_code(print_short_stack_error_and_exit
(current_line_number, "mul"));
return;
}


(*stack)->next->next->n *= (*stack)->next->n;
pop_from_stack(stack, current_line_number);
}


/**
* modulo_stack_top_two - Computes the modulus of the second value from the
*             top of a stack_t linked list  by the top value.
* @stack: A pointer to the top mode node of a stack_t linked list.
* @current_line_number: The current working
* line number of a Monty bytecodes file.
*
* Description: The result is stored in the second value node
*              from the top and the top value is removed.
*/
void modulo_stack_top_two(stack_t **stack, unsigned int current_line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_tokenization_error_code(print_short_stack_error_and_exit
(current_line_number, "mod"));
return;
}


if ((*stack)->next->n == 0)
{
set_tokenization_error_code(print_divide_by_zero_error_and_exit
(current_line_number));
return;
}


(*stack)->next->next->n %= (*stack)->next->n;
pop_from_stack(stack, current_line_number);
}
