#include "monty.h"

/**
* print_pop_error_and_exit - Prints pop error messages for empty stacks.
* @current_line_number: Line number in script where error occured.
*
* Return: (EXIT_FAILURE) always.
*/
int print_pop_error_and_exit(unsigned int current_line_number)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", current_line_number);
return (EXIT_FAILURE);
}


/**
* print_pint_error_and_exit - Prints pint error messages for empty stacks.
* @current_line_number: Line number in Monty bytecodes
*       file where error occurred
*
* Return: (EXIT_FAILURE) always.
*/
int print_pint_error_and_exit(unsigned int current_line_number)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", current_line_number);
return (EXIT_FAILURE);
}


/**
* print_short_stack_error_and_exit - Prints monty math function error messages
*                     for stacks/queues smaller than two nodes.
* @current_line_number: Line number in Monty bytecodes
*                     file where error occurred
* @op: Operation where the error occurred.
*
* Return: (EXIT_FAILURE) always.
*/
int print_short_stack_error_and_exit(unsigned int
current_line_number, char *op)
{
fprintf(stderr, "L%u: can't %s, stack too short\n",
current_line_number, op);
return (EXIT_FAILURE);
}


/**
* print_divide_by_zero_error_and_exit - Prints division
*       error messages for division by 0.
* @current_line_number: Line number in Monty
* bytecodes file where error occurred.
*
* Return: (EXIT_FAILURE) always.
*/
int print_divide_by_zero_error_and_exit(unsigned int current_line_number)
{
fprintf(stderr, "L%u: division by zero\n", current_line_number);
return (EXIT_FAILURE);
}


/**
* print_pchar_error_and_exit - Prints pchar error messages for empty stacks
*               empty stacks and non-character values.
* @current_line_number: Line number in Monty bytecodes
*               file where error occurred
* @message: The corresponding error message to print.
*
* Return: (EXIT_FAILURE) always.
*/
int print_pchar_error_and_exit(unsigned int current_line_number, char *message)
{
fprintf(stderr, "L%u: can't pchar, %s\n", current_line_number, message);
return (EXIT_FAILURE);
}
