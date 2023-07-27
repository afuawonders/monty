#include "monty.h"
/**
* print_usage_and_exit - Prints usage error messages.
*
* Return: (EXIT_FAILURE) always.
*/
int print_usage_and_exit(void)
{
fprintf(stderr, "USAGE: monty file\n");
return (EXIT_FAILURE);
}


/**
* print_malloc_error_and_exit - Prints malloc error messages.
*
* Return: (EXIT_FAILURE) always.
*/
int print_malloc_error_and_exit(void)
{
fprintf(stderr, "Error: malloc failed\n");
return (EXIT_FAILURE);
}


/**
* print_file_open_error_and_exit - Prints file
* opening error messages w/ file name.
* @filename: Name of file failed to open
*
* Return: (EXIT_FAILURE) always.
*/
int print_file_open_error_and_exit(char *filename)
{
fprintf(stderr, "Error: Can't open file %s\n", filename);
return (EXIT_FAILURE);
}


/**
* print_unknown_instruction_error_and_exit - Prints unknown
*     instruction error messages.
* @operationcodes: operationcodes where error occurred.
* @current_line_number: Line number in Monty bytecodes file where error occured
*
* Return: (EXIT_FAILURE) always.
*/
int print_unknown_instruction_error_and_exit(char *operationcodes,
unsigned int current_line_number)
{
fprintf(stderr, "L%u: unknown instruction %s\n",
current_line_number, operationcodes);
return (EXIT_FAILURE);
}


/**
* print_push_integer_error_and_exit - Prints invalid
*      push_to_stack argument error messages.
* @current_line_number: Line number in Monty
* bytecodes file where error occurred
*
* Return: (EXIT_FAILURE) always.
*/
int print_push_integer_error_and_exit(unsigned int current_line_number)
{
fprintf(stderr, "L%u: usage: push integer\n", current_line_number);
return (EXIT_FAILURE);
}
